# Plugin QuickItemEdit pour Koha

Ce programme met à disposition des plugins de recherche par code-barre/numéro d'inventaire ou numéro de notice pour Firefox (searchplugins).  
On peut facilement les ajouter à son navigateur pour une utilisation dans l'interface professionnelle.   

Quel intérêt ?

- Pour le traitement des exemplaires  
  => en lançant une recherche sur un code-barre/numéro d'inventaire on atteint directement le formulaire d'édition de l'exemplaire correspondant dans Koha.  
  C'est un fonction pratique lorsqu'on a une modification à répliquer sur tout un charriot de documents.

- Pour retrouver une notice biblio à partir de son seul numéro  
  => Il suffit d'entrer le numéro et de cliquer au choix sur le moteur opac ou pro.

## Prérequis

* Koha version 20.05 et plus.  
* Dans le fichier de configuration de Koha, vous devez également activer l'utilisation des plugins :  
    ```
    <enable_plugins>1</enable_plugins>  
  ``` 
* Enfin, les utilisateurs doivent avoir la permission d'utiliser les plugins Outils.  

## Installation
Téléchargez le fichier kpz à partir de la [page des releases](https://github.com/biblibre/koha-plugin-quick-item-edit/releases/).  
L'installation se fait dans le module *Outils* de Koha, menu *Outils de plugins*.  

### Si vous rencontrez un problème de permissions, vous devrez installer manuellement  
1. Transférez le fichier kpz dans le répertoire des plugins de votre install Koha (voir l'emplacement dans koha-conf.xml) et décompressez :  
`unzip koha-plugin-quick-item-edit-[version].kpz`

2. Initialisez la prise en charge du plugin  
`./[KOHADIR]/misc/devel/install_plugins.pl`  

### Relance du serveur HTTP et de Plack 

à adapter selon votre install :

```
sudo systemctl reload [apache2|nginx]  
sudo systemctl reload koha-plack@staff.service
``` 
 
## Configuration

Modifiez, si vous le désirez, les étiquettes qui désigneront vos searchplugins. 
En tout état de cause, validez la configuration.
 
##  Ajout d'un plugin de recherche dans Firefox
La procédure à suivre (simple) est détaillée dans la page *Lancer l'outil* et l'ajout des searchplugins doit se faire à partir de cette page.

## Ajout dans Chrome
Chrome ne permet pas l'utilisation d'une barre de recherche dédiée. L'intérêt est donc moindre mais on peut tout de même créer des raccourcis de recherche. Voir la description dans la page *Lancer l'outil*.

##  Désinstallation
Pour désinstaller QuickItemEdit, utiliser la fonction *Désinstaller* du bouton *Actions*.  
A noter que la désinstallation via l'interface web laisse visiblement en place le répertoire des templates du plugin.  
Il est donc recommandé de supprimer en ligne de commande tout le contenu restant du plugin avant toute réinstallation.  

## Références

Modèle de référence pour les plugins koha :    
https://github.com/bywatersolutions/dev-koha-plugin-kitchen-sink  
Pour les templates multilingues :    
https://github.com/BULAC/koha-plugin-mannequin  
Opensearch :   
https://developer.mozilla.org/en-US/docs/Web/OpenSearch

