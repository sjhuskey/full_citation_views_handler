<?php

/**
 * @file
 * Definition of full_citation_handler_field_citation.
 */

/**
 * Provide the full citation of an item.
 *
 * @ingroup views_filter_handlers
 */
class full_citation_handler_field_citation extends views_handler_field {
  /**
  * Render the citation
  */
  public function render($values) {
    $output = '';
    $item = $values->node;
    
    if ($item->field_item_type_tid == 3884) {
        $output = '<div class="full-citation">' . $item->field_creator . $item->field_date . '"' . $item->field_record_title . '"' . '<em>' . $item->field_publication . '</em>' .
        $item->field_volume . ': ' . $item->field_pagination . '.' . '</div>';
        
        return $output;
    }
    else {
        echo "Why do you think you can use PHP?";
    }    
}