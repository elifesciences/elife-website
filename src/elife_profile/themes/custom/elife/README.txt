###############################################
# CHROMEGA: An Omega sub-theme :: with color! #
###############################################

Chromega is a sub-theme which extends Omega. You MUST have Omega installed for the theme to work properly.

Features: 
	1. Customizable 960 grid system
	2. HTML5 and CSS3
	3. Responsive Layout 
	4. Color module integration - for easy colorizing of your themes
	5. Panels layouts plugin - for creating custom grid-based panels layouts
	
*********************************
* Getting Started with Chromega *
---------------------------------
Chromega can be used out of the box as a theme, but is really designed to be a starting point 
for all your custom theming needs. To get started, you only need to change some names!
----------------------------------------------------------------------------------------------
| 1. Duplicate chromega directory, and name it with whatever you want your theme to be called. 
|	
\	* Example: sites/all/themes/chromega copy ----> sites/all/themes/MY_THEME
	

| 2. Rename chromega.info to reflect your theme name. Then, open the file and change the name 
|    to your theme's name, and change the description to something that reflects your theme. 
|	
|	* Example: MY_THEME/chromega.info ----> MY_THEME/MY_THEME.info
|		***					name = chromega 		----> my theme
\		***					description = ....	----> a description of my custom theme 	
	
	
| 3. Open the file: template.php and replace anywhere it says "chromega" with your theme name. 
|	
|	* Example: function chromega_form_alter(&$form, &$form_state, $form_id) --->
\	 					 function MY_THEME_form_alter(&$form, &$form_state, $form_id)
	 					 

| 4. Open the file: theme-settings.php and replace anywhere it says "chromega" with your theme name. 
|	
|	* Example: function chromega_form_system_theme_settings_alter(&$form, &$form_state) --->
\            function MY_THEME_form_system_theme_settings_alter(&$form, &$form_state) 


| 5. In the css directory, you will see four css files that begin with chromega-alpha-default. 
|    Rename each "chromega" with your theme's name, replacing underscores with hyphens. 
|	
|	* Example: chromega-alpha-default-narrow.css ---> MY-THEME-alpha-default-narrow.css
| 					 chromega-alpha-default-normal.css ---> MY-THEME-alpha-default-normal.css
|						 chromega-alpha-default-wide.css 	 ---> MY-THEME-alpha-default-wide.css
\						 chromega-alpha-default.css 			 ---> MY-THEME-alpha-default.css

| 6. Finally, enable your new theme! Go to admin/appearance and click "Enable and Set Default".

