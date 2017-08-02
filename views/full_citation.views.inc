<?php
/**
 * @file
 * Views definitions for Full Citation.
 * Cribbed from https://kalamuna.atlassian.net/wiki/display/KALA/Custom+Views+Field+Handler
 */
 
/**
 * Implementation of hook_views_handlers() to register all of the basic handlers
 * views uses.
 */
function full_citation_views_handlers() {
  return array(
    'info' => array(
      'path' => drupal_get_path('module', 'full_citation'),
    ),
    'handlers' => array(
      // The name of my handler
      'full_citation_handler_custom_field' => array(
        // The name of the handler we are extending.
        'parent' => 'views_handler_field',
      ),
    ),
  );
}
 
/**
 * Implements hook_views_data().
 */
function full_citation_views_data() {
  $data = array();
  // Add Full Citation group
  $data['full_citation']['table']['group'] = t('Full Citation');
  $data['full_citation']['table']['join'] = array(
    // #global is a special flag which lets a table appear all the time.
    '#global' => array(),
  );
  // Add custom field
  $data['full_citation']['custom_field'] = array(
    'title' => t('Full Citation field'),
    'help' => t('Provides a full citation of the bibliographical data.'),
    'field' => array(
      'handler' => 'full_citation_handler_custom_field',
    ),
  );
  return $data;
}