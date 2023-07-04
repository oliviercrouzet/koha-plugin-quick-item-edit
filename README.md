# QuickItemEdit plugin for Koha

[French version](https://github.com/oliviercrouzet/koha-plugin-quick-item-edit/blob/master/README-fr.md) 

This program provides barcode/inventory number or biblionumber search plugins for Firefox.   
You can easily add them to your browser for use in the professional interface of Koha.   
  
What's the point?

- For item processing  
  => By launching a search on a barcode/inventory number, you can directly access the form for editing the item in Koha.  
  This is a handy feature when you have changes to make across an entire document cart.

- To find a bibliographic record by biblionumber  
  => Simply enter the number and click on either the *record OPAC* or *record STAFF* engine.

## Prerequisites

* Koha version 20.05 and higher.  
* In the Koha configuration file, you must also activate the use of plugins:    
    ```
    <enable_plugins>1</enable_plugins>  
  ``` 
* Finally, users must have permission to use the Tools plugins.  

## Installation
Download the kpz file from [releases page](https://github.com/oliviercrouzet/koha-plugin-quick-item-edit/releases).   
Installation is performed in the *Tools* module of Koha, *Plugin Tools* menu.  

### If you encounter a permissions problem, you will have to do the installation manually:    

1. Transfer the kpz file to the plugins directory of your Koha install (see the path in your koha-conf.xml file) and unzip it:  
`unzip koha-plugin-quick-item-edit-[version].kpz`.

2. Init plugin support    
`./[KOHADIR]/misc/devel/install_plugins.pl`  

### Restarting HTTP server and Plack

to adapt to your installation:  
```
sudo systemctl reload [nginx|apache2]
sudo systemctl reload koha-plack@staff.service
```  


 
## Configuration

You may want to modify the labels used to designate your searchplugins.  
In any case, validate the configuration.
 
## Adding a search plugin to Firefox

The procedure to follow (simple) is detailed on the *Launch Tool* page, and the searchplugins must be added from it.

## Adding in Chrome

Chrome does not support a dedicated search bar. It is therefore of less interest, but you can still create search shortcuts. See also the description on the *Launch Tool* page.

## Uninstalling
To uninstall QuickItemEdit, use the *Uninstall* function of the *Actions* button.    
Note that uninstallation via the web interface may leaves the plugin's directory in place.    
It is therefore recommended to delete all remaining plugin content from the command line before reinstalling.

## Credits and Références

Reference model for koha plugins:  
https://github.com/bywatersolutions/dev-koha-plugin-kitchen-sink  
Multilingual templates model:   
https://github.com/BULAC/koha-plugin-mannequin  
Opensearch:  
https://developer.mozilla.org/en-US/docs/Web/OpenSearch

