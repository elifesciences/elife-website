##################################
# Chromega Custom Panels Layouts #
##################################

Chromega is already set up to check this directory for custom panel layouts. 
If a panels page is used, it will apply custom classes to the #page wrapper. 

***********************************
* Creating a Custom Panels Layout *
-----------------------------------
Following are instructions on how to create a custom panels layout. 
I have included an example that uses Omega's 960 grid classes to demonstrate this process. 

1. Make a new folder in the panels/layouts/ directory with the name of your custom layout. 
   Inside this folder, create a new .inc file with the same name as the directory. 
	 
	 * EXAMPLE: panels/layouts/chromega_panels_example/chromega_panels_example.inc 
	 
	 
2. Inside the .inc file you need to call hook_panels_layouts(). 
   The naming convention for this hook is MY_THEME_NAME_PANELS_LAYOUT_NAME_panels_layouts() 
   
   * EXAMPLE: chromega_chromega_panels_example_panels_layouts(){} 
   *** In the example you will find the file to copy, and anywhere you see "chromega_panels_example", 
   		 replace with the name of your custom panels layout. 
   		 The example file also provides a further description of each item in the array. 
   		 
3. Also required in this directory is your tpl.php file which will control the markup of your panels layout. 
	 
	 * IMPORTANT: in your tpl.php file, you must replace any underscores with hyphens. 
	 * EXAMPLE: I named my custom layout "chromega_panels_example", so my theme name is "chromega_panels_example". 
	          Therefore, I created a file named chromega-panels-example.tpl.php where I put my layout markup. 

4. You may optionally include a preview icon of your layout for the "Panels Layouts" Administration section, 
   as well as a css file to be invoked while editing your panels page in the standard admin editor 
   	(ie: NOT panels-in-place-editor)