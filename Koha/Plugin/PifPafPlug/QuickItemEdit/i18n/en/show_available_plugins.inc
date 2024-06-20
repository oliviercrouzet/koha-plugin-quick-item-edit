<div id="breadcrumbs"><a href="/cgi-bin/koha/mainpage.pl">Home</a> &rsaquo; <a href="/cgi-bin/koha/plugins/plugins-home.pl">Plugins</a> &rsaquo; QuickItemEdit &rsaquo; Installation</div>
[% UNLESS ( staffurl || xmlcreated) %]
    <div class="dialog alert"><h4>Configuration has to be done</h4>Contact the administrator</div>
[% END %]
<div id="quickitem">
    <h3>Fast editing of items using a Firefox search plugin</h3>
    <p>The Barcode, recordOPAC and recordSTAFF plugins,  allow for the former, to directly reach the form for editing an item from the barcode or stocknumber, for the others, to display a catalog record from its record number.</p>
    <h2>First installation</h2>
    <p>You need Firefox's search bar:<br />
    Right-click at the top of the browser and select <i>Customize Toolbar.</i><br />
    Select the <i>Search</i> item (the one with the shaded area) :<br />
    <img class="ajoutbarre" src="[% api_path %]/images/ajoutbarre.png"/><br />
    Then drag and drop it to the right of the address bar.<br />
    You will be able to adjust its width by placing the cursor between the 2 zones and moving it to the sides.<br />
    Close the customization tab.<br /><br />
    The availability of a search plugin is indicated by a + sign in a green circle attached to the small magnifying glass.
    All you have to do is click it and add the plugin of your choice : <br /><img class="searchbar" src="[% api_path %]/images/searchbar.png"/><br />
    The plugin icon then becomes visible following the engines already installed. In case of doubt, his name appears on the mouse hover:<br />
    <span>
    <img class="engines" src="[% api_path %]/images/codebarre.png"/>
    </span>
    </p>
    <h2>Reinstallation</h2>
    <p>Be careful, if a search plugin of the same name is already present in Firefox, it must first be removed.<br />
    &nbsp; => Click on the small magnifying glass and then on the gear on the right (<i>Change search parameters</i>) :<br/>
     <img  class="loupe" src="[% api_path %]/images/loupe.png"/><span class="plus"> + </span><img src="[% api_path %]/images/roue.png"/><br />
    &nbsp;In the <i>Search Shortcuts</i> section, select the plugin and click <i>Remove</i> at the bottom of the list.</p>
    <h2>For repeated use, set your plugin as default engine.</h2>
     <p>If you want to use <i>Barcode</i> in the case of bulk items processing for example, it is more practical to define it as the default engine:<br />
    &nbsp; =>  Click on the small magnifying glass.<br/>
    &nbsp;and then select <i>Barcode</i> in the <i>Search engine</i> section.<br />
    &nbsp;Now, all you have to do is scan the barcode or stocknumber and press Enter to edit the item in Koha.</p>

        <!-- Notice our form here has no 'action', this is good, it means that our forms will always get passed back to 'plugins/run.pl'. You could hard code it instead if you prefer -->
<h3>Installation in Chrome</h3>
<fieldset class="rows install"><legend>Copy standard url</legend>
<div class="ui-tabs-panel"  >
  <p>There is no dedicated search bar, but you can configure a new engine by right-clicking in the navigation bar and then
  <i>Manage search engines</i>. In the <i>Other search engines</i> section, choose a name and a letter (or keyword) and copy one of the urls below ready to use.<br />
  You can then target the engine of your choice by prefacing your search terms with the key letter.
  </p>  
        <ol>
            <li>
                <label for="itemlabel" ><span>Barcode / Stocknumber</span>&nbsp;:&nbsp;</label>
                <input class="addurl" type="text" readonly="readonly" value="[% staffurl %]/cgi-bin/koha/plugins/run.pl?class=Koha::Plugin::PifPafPlug::QuickItemEdit&method=tool&itemid=%s"/>
            </li>
            <li>
                <label for="opacbiblabel" ><span>record OPAC</span>&nbsp;:&nbsp;</label>
                <input class="addurl" type="text" readonly="readonly" value="[% staffurl %]/cgi-bin/koha/plugins/run.pl?class=Koha::Plugin::PifPafPlug::QuickItemEdit&method=tool&opacbib=%s"/>
            </li>
            <li>
                <label for="staffbiblabel" ><span>record STAFF</span>&nbsp;:&nbsp;</label>
                <input class="addurl" type="text" readonly="readonly" value="[% staffurl %]/cgi-bin/koha/plugins/run.pl?class=Koha::Plugin::PifPafPlug::QuickItemEdit&method=tool&staffbib=%s"/>
            </li>
        </ol>
</div>
</fieldset>
