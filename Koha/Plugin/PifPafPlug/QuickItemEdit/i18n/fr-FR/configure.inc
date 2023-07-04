<div id="breadcrumbs"><a href="/cgi-bin/koha/mainpage.pl">Home</a> &rsaquo; <a href="/cgi-bin/koha/plugins/plugins-home.pl">Plugins</a> &rsaquo; QuickItemEdit &rsaquo; Configuration</div>

[% UNLESS ( staffurl ) %]
<div class="dialog alert"><h4>Configuration à valider</h4>La configuration doit être validée même si vous ne modifiez pas les étiquettes.</div>
[% END %]
<div id="quickedit">
    <h3>Edition rapide des exemplaires grâce aux plugins de recherche Firefox</h3>

        <!-- Notice our form here has no 'action', this is good, it means that our forms will always get passed back to 'plugins/run.pl'. You could hard code it instead if you prefer -->
    <form method="get">
                <input type="hidden" name="class" value="[% CLASS %]"/>
                <input type="hidden" name="method" value="[% METHOD %]"/>
                <input name="staffurl" type="hidden" value="" />
    <fieldset class="rows desc"><legend>Description</legend>
        <p>Ce programme met à disposition des plugins de recherche par code-barre/numéro d'inventaire ou numéro de notice pour Firefox (searchplugins).<br />
    On peut facilement les <a href="/cgi-bin/koha/plugins/run.pl?class=[% CLASS %]&method=tool">ajouter à son navigateur</a> pour une utilisation dans l'interface professionnelle.
        </p>
    Quel intérêt ?<br />
        <ul>
        <li><h5>Pour le traitement des exemplaires</h5>
        &nbsp;&nbsp;&nbsp;=> en lançant une recherche sur un code-barre/numéro d'inventaire on atteint directement le formulaire d'édition de l'exemplaire correspondant dans Koha.<br />
    C'est un fonction pratique lorsqu'on a une modification à répliquer sur une série de documents qui doivent être controlés physiquement.
        </li>
        <li><h5>Pour retrouver une notice biblio à partir de son seul numéro</h5>
        &nbsp;&nbsp;&nbsp;=>Il suffit d'entrer le numéro et de cliquer au choix sur le moteur opac ou pro
        </li>
        </ul>
    </fieldset>
    <fieldset class="rows"><legend>Configuration</legend>
        <ul>
            <li> Modifiez, si vous le souhaitez, les étiquettes qui identifieront les moteurs de recherche dans la barre de recherche Firefox<br />
                 puis <i>Validez la configuration</i>.
            </li>
            <li>
                <table>
                    <thead><tr><th>Plugin</th><th>Etiquette dans Firefox</th></tr></thead>
                    <tr>
                      <td><label>Item</label></td>
                      <td><input name="itemlabel" value="[% itemlabel %]" type="text"  required="required" /></td>
                    </tr>
                    <tr>
                      <td><label>Record OPAC side</label></td>
                      <td><input name="opacbiblabel" value="[% opacbiblabel %]" type="text"  required="required" /></td>
                    </tr>
                      <td><label>Record staff side</label></td>
                      <td><input name="staffbiblabel" value="[% staffbiblabel %]" type="text"  required="required" /></td>
                    </tr>
                </table>
                <input type="submit" name="saveconfig" value="Validez la configuration" />
                <p>C'est tout. Ces moteurs sont désormais installables à partir de la page <a href="/cgi-bin/koha/plugins/run.pl?class=[% CLASS %]&method=tool">Lancer l'outil</a>.</p>
            </li> 
        </ul>
    </fieldset>

    </form>
