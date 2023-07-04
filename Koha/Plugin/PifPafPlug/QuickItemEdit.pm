package Koha::Plugin::PifPafPlug::QuickItemEdit;

## It's good practive to use Modern::Perl
use Modern::Perl;

## Required for all plugins
use base qw(Koha::Plugins::Base);

## We will also need to include any Koha libraries we want to access
use CGI qw( -utf8 );
use Koha::Items;
use Mojo::JSON qw( decode_json encode_json );

## Here we set our plugin version
our $VERSION = 1.0;

## Here is our metadata, some keys are required, some are optional
our $metadata = {
    name   => 'QuickItemEdit',
    author => 'Olivier Crouzet',
    description =>'This plugin allows straight edition of an item using a searchplugin from Firefox',
    date_authored   => '2022-12-10',
    date_updated    => '2022-12-10',
    minimum_version => '20.05.00',
    maximum_version => undef,
    version         => $VERSION,
};

## This is the minimum code required for a plugin's 'new' method
## More can be added, but none should be removed
sub new {
    my ( $class, $args ) = @_;

    ## We need to add our metadata here so our base class can access it
    $args->{'metadata'} = $metadata;
    $args->{'metadata'}->{'class'} = $class;

    ## Here, we call the 'new' method for our base class
    ## This runs some additional magic and checking
    ## and returns our actual $self
    my $self = $class->SUPER::new($args);
    $self->{'plugin_dir'} = $self->bundle_path();
    $self->{'api_path'} = "/api/v1/contrib/quickitemedit/static";

    return $self;
}

sub tool {
    my ( $self, $args ) = @_;
    my $cgi = $self->{'cgi'};

    # Redirect barcode/stocknumber query so as to go straight to item edit page.
    if ( $cgi->param('itemid')) {
        my $refnumber = $cgi->param('itemid');
        my $dbh = C4::Context->dbh;
        my $query = "SELECT itemnumber, biblionumber from items where barcode = ? or stocknumber = ?";
        my $sth = $dbh->prepare($query);
        $sth->execute($refnumber,$refnumber);
        my $item = $sth->fetchrow_hashref();
        my $itemnumber = $item->{itemnumber};

        unless ( $itemnumber ){
            print $cgi->redirect("/cgi-bin/koha/catalogue/search.pl?q=$refnumber&idx=null");
            exit;
        } else {
            my $biblionumber = $item->{biblionumber};
            print $cgi->redirect("/cgi-bin/koha/cataloguing/additem.pl?op=edititem&biblionumber=$biblionumber&itemnumber=$itemnumber");
            exit;
        }
    } elsif ( $cgi->param('staffbib') ) {
        my $bibnumber = $cgi->param('staffbib');
        print $cgi->redirect("/cgi-bin/koha/catalogue/detail.pl?biblionumber=$bibnumber");
    } elsif ( $cgi->param('opacbib') ) {
        my $bibnumber = $cgi->param('opacbib');
        my $opacurl = C4::Context->preference("OPACBaseURL");
        print $cgi->redirect("$opacurl/cgi-bin/koha/opac-detail.pl?biblionumber=$bibnumber");
    } else {
        $self->show_available_plugins();
    }

}

sub configure {
    my ( $self, $args ) = @_;
    my $cgi = $self->{'cgi'};

    # Save config in database
    if ( $cgi->param('saveconfig') ) {
        my $staffurl = scalar $cgi->param('staffurl');
        my $itemlabel = scalar $cgi->param('itemlabel');
        my $opacbiblabel = scalar $cgi->param('opacbiblabel');
        my $staffbiblabel = scalar $cgi->param('staffbiblabel');
        my $cfg = {
               'staffurl'      => $staffurl,
               'itemlabel'     => $itemlabel,
               'opacbiblabel'  => $opacbiblabel,
               'staffbiblabel' => $staffbiblabel,
        };

       my $json = encode_json($cfg);
       $self->store_data({ cfg => $json });
    }

    my $template = $self->get_template({ file => 'configure.tt' });

    my ($staffurl,$itemlabel,$opacbiblabel,$staffbiblabel) = $self->getconfig();

    $template->param(
        'staffurl'    => $staffurl,
        'itemlabel'     => $itemlabel,
        'opacbiblabel'  => $opacbiblabel,
        'staffbiblabel' => $staffbiblabel,
        'api_path'      => $self->{'api_path'},

    );
    $self->output_html( $template->output() );
}

sub install() {
    my ( $self, $args ) = @_;
    my $cfg = {
        'itemlabel' => 'Barcode / Stocknumber',
        'opacbiblabel' => 'record OPAC',
        'staffbiblabel' => 'record STAFF',
    };

    my $json = encode_json($cfg);
    $self->store_data({ cfg => $json });
    return 1;
}

sub uninstall() {
    my ( $self, $args ) = @_;
    C4::Context->dbh->do("delete from plugin_data where plugin_class='Koha::Plugin::PifPafPlug::QuickItemEdit'");
    return 1;
}

sub getconfig() {
    my ( $self, $args ) = @_;

    my $confstring = $self->retrieve_data('cfg');
    # work-around for preventing json_decode error on degree sign
    $confstring =~ s/\x{00b0}/°/g; 
    my $cfg = decode_json($confstring); 
    return ( $cfg->{'staffurl'}, $cfg->{'itemlabel'}, $cfg->{'opacbiblabel'}, $cfg->{'staffbiblabel'} );
}

sub show_available_plugins {
    # On that page (run tool), the searchplugins that can be added are displayed on the browser searchbar.
    my ( $self, $args ) = @_;
    my $cgi = $self->{'cgi'};
    my $template = $self->get_template({ file => 'show_available_plugins.tt' });
    my ($staffurl,$itemlabel,$opacbiblabel,$staffbiblabel) = $self->getconfig();
    $template->param(
                'staffurl'      => $staffurl,
                'itemlabel'     => $itemlabel,
                'opacbiblabel'  => $opacbiblabel,
                'staffbiblabel' => $staffbiblabel,
                'api_path'      => $self->{'api_path'},
                );

    $self->output_html( $template->output() );
}

sub api_routes {
    my ( $self, $args ) = @_;

    my $spec_str = $self->mbf_read('openapi.json');
    my $spec     = decode_json($spec_str);

    return $spec;
}

sub api_namespace {
    my ( $self ) = @_;
    return 'quickitemedit';
}

sub static_routes {
    my ( $self, $args ) = @_;

    my $spec_str = $self->mbf_read('staticapi.json');
    my $spec     = decode_json($spec_str);

    return $spec;
}

1;
