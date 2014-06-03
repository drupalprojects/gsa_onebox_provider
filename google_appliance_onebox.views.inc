<?php
/**
 * @file
 * Views include file with views hooks.
 */

/**
 * Implements hook_views_plugins().
 */
function google_appliance_onebox_views_plugins() {
  $path = drupal_get_path('module', 'google_appliance_onebox');

  $style_defaults = array(
    'path' => $path . '/plugins',
    'parent' => 'google_appliance_onebox',
    'theme' => 'google_appliance_onebox',
    'theme path' => $path . '/theme',
    'theme file' => 'google_appliance_onebox.theme.inc',
    'uses row plugin' => FALSE,
    'uses fields' => TRUE,
    'uses options' => TRUE,
    'type' => 'google_appliance_onebox',
  );

  return array(
    'display' => array(
      'google_appliance_onebox' => array(
        'title' => t('GSA Onebox Feed'),
        'help' => t('Create a feed to act as a Google Search Appliance Onebox provider.'),
        'path' => $path . '/plugins',
        'handler' => 'GoogleApplianceOneboxPluginDisplay',
        'parent' => 'feed',
        'uses hook menu' => TRUE,
        'use ajax' => FALSE,
        'use pager' => FALSE,
        'accept attachments' => FALSE,
        'admin' => t('gsa onebox provider'),
        'help topic' => 'display-gsa-onebox-provider',
      ),
    ),
    'style' => array(
      'google_appliance_onebox' => array(
        // This isn't really a display but is necessary so the file can
        // be included.
        'no ui' => TRUE,
        'handler' => 'GoogleApplianceOneboxPluginStyle',
        'path' => $path . '/plugins',
        'theme path' => $path . '/theme',
        'theme file' => 'google_appliance_onebox.theme.inc',
        'type' => 'normal',
      ),
      'google_appliance_onebox_xml' => array(
        'title' => t('GSA Onebox Provider'),
        'help' => t('Display the view feed.'),
        'handler' => 'GoogleApplianceOneboxPluginStyleXml',
        'headers' => array('Content-Type' => 'text/xml'),
        'additional themes' => array(
          'google_appliance_onebox_xml_header' => 'style',
          'google_appliance_onebox_xml_body' => 'style',
          'google_appliance_onebox_xml_footer' => 'style',
        ),
        'additional themes base' => 'google_appliance_onebox_xml',
      ) + $style_defaults,
    ),
  );
}
