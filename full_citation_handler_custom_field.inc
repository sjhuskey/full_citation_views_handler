<?php
/**
 * @file
 * Definition of full_citation_handler_custom_field
 * Cribbed from https://kalamuna.atlassian.net/wiki/display/KALA/Custom+Views+Field+Handler
 */
  
/**
 * Provides a custom views field.
 */
class full_citation_handler_custom_field extends views_handler_field {
function option_definition() {
    $options = parent::option_definition();
    return $options;
  }
  
  function options_form(&$form, &$form_state) {
    parent::options_form($form, $form_state);
  }
  
  function query() {
    // do nothing -- to override the parent query.
  }
  
  function render($data) {
    // If the devel module is enabled, you may view all of the
    // data provided by fields previously added in your view.
    // dpm($data);
    // Insert PHP code here, or display greeting.
    $output = t("Hello World!");
    return $output;
    }
 }