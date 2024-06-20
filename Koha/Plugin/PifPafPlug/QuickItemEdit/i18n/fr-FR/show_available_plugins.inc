<div id="breadcrumbs"><a href="/cgi-bin/koha/mainpage.pl">Home</a> &rsaquo; <a href="/cgi-bin/koha/plugins/plugins-home.pl">Plugins</a> &rsaquo; QuickItemEdit &rsaquo; Installation</div>
[% UNLESS ( staffurl || xmlcreated) %]
    <div class="dialog alert"><h4>Configuration à effectuer</h4>Veuillez contacter l'administrateur</div>
[% END %]
<div id="quickitem">
    <h3>Édition immédiate des exemplaires grâce à un plugin de recherche Firefox</h3>
    <p>Les plugins Code-barre, NoticeOPAC et NoticePRO, permettent pour le premier, d'atteindre directement le formulaire d'édition d'un exemplaire à partir du code-barre ou numéro d'inventaire, pour les autres, d'afficher un notice du catalogue à partir de son numéro.</p>
    <h2>1ère installation</h2>
    <p>Vous avez besoin de la barre de recherche de Firefox.<br />
    Cliquez droit tout en haut du navigateur puis sur <i>Personnaliser la barre d'outils</i>.<br />
    Choisissez l'élément <i>Rechercher</i> (celui dont la zone est grisée) :<br />
    <img class="ajoutbarre" src="[% api_path %]/images/ajoutbarre.png"/><br />
    Puis par glisser-déposer, amenez le à droite de la barre d'adresse.<br />
    Vous pourrez régler sa largeur en posant le curseur entre les 2 zones et en le deplaçant sur les côtés.<br />
    Refermez l'onglet de personnalisation.<br /><br />
    La disponibilité d'un plugin de recherche est signalée par un signe + dans un rond vert accolé à la petite loupe.
    Vous n'avez plus qu'à cliquer celle-ci et ajouter le plugin de votre choix :<br /><img class="searchbar" src="[% api_path %]/images/searchbar.png"/><br />
    L'icône du plugin devient alors visible à la suite des moteurs déja installés. En cas de doute, son nom apparait au survol de la souris:<br />
    <span>
    <img class="engines" src="[% api_path %]/images/codebarre.png"/>
    </span>
    </p>
    <h2>Réinstallation</h2>
    <p>Attention, si un plugin de recherche du même nom est déja présent dans Firefox, il faut d'abord le supprimer.<br />
    &nbsp; => Cliquez sur la petite loupe puis sur la roue dentée à droite (<i>Modifier les paramètres de recherche</i>) :<br/>
     <img  class="loupe" src="[% api_path %]/images/loupe.png"/><span class="plus"> + </span><img src="[% api_path %]/images/roue.png"/><br />
    &nbsp;Dans la section <i>Raccourcis de recherche</i> sélectionnez le plugin et cliquez sur <i>Supprimer</i> en bas de la liste.</p>
    <h2>Pour une utilisation répétée, définir votre plugin comme moteur par défaut</h2>
     <p>Si l'on veut utiliser Code-Barre dans le cas d'un traitement d'exemplaires en nombre par exemple, il est plus pratique de le définir comme Moteur par défaut :<br />
    &nbsp; => Cliquez sur la petite loupe puis sur la roue dentée<br/>
    &nbsp;Sélectionnez <i>Code-barre</i> dans la section <i>Moteur de recherche par défaut</i>.<br />
    &nbsp;Désormais, vous n'avez plus qu'à scanner le code-barre ou le n° d'inventaire et presser la touche Entrée pour éditer l'exemplaire dans Koha.</p>

        <!-- Notice our form here has no 'action', this is good, it means that our forms will always get passed back to 'plugins/run.pl'. You could hard code it instead if you prefer -->
<h3>Installation dans Chrome</h3>
<fieldset class="rows install"><legend>Copie de l'url type</legend>
<div class="ui-tabs-panel"  >
  <p>Dans Chrome, il n'y pas de barre de recherche dédiée, mais on peut configurer un nouveau moteur
  en cliquant droit dans la barre de navigation puis <i>Gérer les moteurs de recherche</i><br />
  Dans la section <i>Autres moteurs de recherche</i>, choisissez un nom et une lettre (ou un mot) clé puis copiez une des urls ci-dessous prêtes à l'emploi.<br />
  Vous pourrez ensuite cibler le moteur de votre choix en faisant précéder vos termes de recherche de la lettre clé.
  </p>  
        <ol>
            <li>
                <label for="itemlabel" ><span>Code-barre ou N°inv.</span>&nbsp;:&nbsp;</label>
                <input class="addurl" type="text" readonly="readonly" value="[% staffurl %]/cgi-bin/koha/plugins/run.pl?class=Koha::Plugin::PifPafPlug::QuickItemEdit&method=tool&itemid=%s"/>
            </li>
            <li>
                <label for="opacbiblabel" ><span>Numéro de notice OPAC</span>&nbsp;:&nbsp;</label>
                <input class="addurl" type="text" readonly="readonly" value="[% staffurl %]/cgi-bin/koha/plugins/run.pl?class=Koha::Plugin::PifPafPlug::QuickItemEdit&method=tool&opacbib=%s"/>
            </li>
            <li>
                <label for="staffbiblabel" ><span>Numéro de notice PRO</span>&nbsp;:&nbsp;</label>
                <input class="addurl" type="text" readonly="readonly" value="[% staffurl %]/cgi-bin/koha/plugins/run.pl?class=Koha::Plugin::PifPafPlug::QuickItemEdit&method=tool&staffbib=%s"/>
            </li>
        </ol>
</div>
</fieldset>
