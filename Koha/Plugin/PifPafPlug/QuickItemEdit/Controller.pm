package Koha::Plugin::PifPafPlug::QuickItemEdit::Controller;

use Modern::Perl;

use CGI qw( -utf8 );
use C4::Auth qw( get_template_and_user );
use C4::Context;
use Koha::Plugin::PifPafPlug::QuickItemEdit;
use Mojo::Base 'Mojolicious::Controller';

sub get_opensearch_xml {

    my $c = shift->openapi->valid_input or return;
    my $reftype = $c->validation->param('reftype');
    my $plugin = Koha::Plugin::PifPafPlug::QuickItemEdit->new();
    my $cgi = CGI->new();

    my ($staffurl,$itemlabel,$opacbiblabel,$staffbiblabel) = $plugin->getconfig();
    my $shortname = $reftype eq 'itemid' ? $itemlabel : $reftype eq 'staffbib' ? $staffbiblabel : $opacbiblabel;

    my ($template) = get_template_and_user({
            template_name   => $plugin->mbf_path('searchplugin.tt'),
            query => $cgi,
            type => "intranet",
            authnotrequired => 1,
    });
    $template->param(
        'staffurl'  => $staffurl,
        'api_path' => $plugin->{'api_path'},
        'shortname'   => $shortname,
        'reftype'        => $reftype,
        'opensearchdescription' =>1,
    );

    return $c->render(status => 200, text => $template->output(),format => 'xml');

}

1;
