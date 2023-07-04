<div id="breadcrumbs"><a href="/cgi-bin/koha/mainpage.pl">Home</a> &rsaquo; <a href="/cgi-bin/koha/plugins/plugins-home.pl">Plugins</a> &rsaquo; QuickItemEdit &rsaquo; Configuration</div>

[% UNLESS ( staffurl ) %]
<div class="dialog alert"><h4>Configuration has to be validated</h4>The configuration must be validated even if you do not change the labels.</div>
[% END %]
<div id="quickedit">
    <h3>Fast editing of items with Firefox search plugins</h3>

        <!-- Notice our form here has no 'action', this is good, it means that our forms will always get passed back to 'plugins/run.pl'. You could hard code it instead if you prefer -->
    <form method="get">
                <input type="hidden" name="class" value="[% CLASS %]"/>
                <input type="hidden" name="method" value="[% METHOD %]"/>
                <input name="staffurl" type="hidden" value="" />
    <fieldset class="rows desc"><legend>Description</legend>
        <p>This program provides search plugins by barcode/stocknumber or biblionumber for Firefox.<br />
    You can easily <a href="/cgi-bin/koha/plugins/run.pl?class=[% CLASS %]&method=tool">add them to your browser</a> for use in the professional interface.
        </p>
    What's the point ?<br />
        <ul>
        <li><h5>For the processing of items</h5>
        &nbsp;&nbsp;&nbsp;=> By launching a search on a barcode/stocknumber, you directly reach the edition form of the item in Koha.<br />
        This is a handy feature when you have changes to make across an entire document cart.
        </li>
        <li><h5>To find a biblio record from its single biblionumber</h5>
        &nbsp;&nbsp;&nbsp;=> Simply enter the number and click on the opac or staff engine
        </li>
        </ul>
    </fieldset>
    <fieldset class="rows"><legend>Configuration</legend>
        <ul>
            <li> Optionally, modify the labels that will identify search engines in the Firefox search bar<br />
                 and then <i>Validate Configuration.</i>
            </li>
            <li>
                <table>
                    <thead><tr><th>Plugin</th><th>Label in Firefox</th></tr></thead>
                    <tr>
                      <td><label>Item</label></td>
                      <td><input name="itemlabel" value="[% itemlabel %]" type="text"  required="required" /></td>
                    </tr>
                    <tr>
                      <td><label>Record OPAC</label></td>
                      <td><input name="opacbiblabel" value="[% opacbiblabel %]" type="text"  required="required" /></td>
                    </tr>
                      <td><label>Record staff</label></td>
                      <td><input name="staffbiblabel" value="[% staffbiblabel %]" type="text"  required="required" /></td>
                    </tr>
                </table>
                <input type="submit" name="saveconfig" value="Validate config" />
                <p>That's all. These engines can now be installed from the <a href="/cgi-bin/koha/plugins/run.pl?class=[% CLASS %]&method=tool">Launch tool</a> page.</p>
            </li> 
        </ul>
    </fieldset>

    </form>
