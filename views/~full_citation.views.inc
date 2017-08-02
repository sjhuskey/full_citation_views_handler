<?php 

/**
 * Implements hook_views_data().
 * Cribbed from https://ohthehugemanatee.org/blog/2013/12/26/44497-people-are-wrong-how-to-never-use-views-php/
 * and the Biblio module.
 */
function full_citation_views_data() {
  // Build an array named after each DB table you're describing. In our case,
  // just full_citation_table.
        /***** Defining the full citation table *****/
        $data = array();
        $data['table']['group'] = t('Full Citation');
        
        $data['citation'] = array (
            'title' => t('DLL Citation'),
            'help' => t("Display the full citation for a node."),
            'field' => array(
                'handler' => 'full_citation_handler_citation',
            ),
        );
        $result = db_query('SELECT node.title AS node_title, 
                                                node.nid AS nid, 
                                                node.language AS node_language, 
                                                node.created AS node_created, 
                                                \'node\' AS field_data_field_creator_node_entity_type, 
                                                \'node\' AS field_data_field_dll_authors_node_entity_type, 
                                                \'node\' AS field_data_field_dll_works_node_entity_type, 
                                                \'node\' AS field_data_field_pagination_node_entity_type, 
                                                \'node\' AS field_data_field_place_of_publication_node_entity_type, 
                                                \'node\' AS field_data_field_publication_node_entity_type, 
                                                \'node\' AS field_data_field_publisher_node_entity_type, 
                                                \'node\' AS field_data_field_record_title_node_entity_type, 
                                                \'node\' AS field_data_field_record_type_node_entity_type, 
                                                \'node\' AS field_data_field_volume_node_entity_type, 
                                                \'node\' AS field_data_field_item_type_node_entity_type, 
                                                \'node\' AS field_data_field_source_work_node_entity_type 
                                                FROM {node} node
                                                WHERE (( (node.status = \'1\') AND (node.type IN  (\'ldlt_bibliography\')) ))');
        
        foreach ($result as $field) {
            $data[$field->name] = array(
                'title'     => $field->title,
                'help'      => "Display the " . $field->title,
                'field'     => array('handler' => 'full_citation_handler_field'),
                'sort'      => array('handler' => 'views_handler_sort'),
                'filter'    => array('handler' => 'views_handler_filter_string'),
                'argument'  => array('handler' => 'views_handler_argument_string')
                );
        }
       
       'citation' => array(
        'title' => t('Full Citation'),
        'help' => t("The Full Citation."),
        'field' => array(
        'handler' => 'full_citation_handler_field_citation',
        'click sortable' => TRUE,
        ),
    ),
   );
  return $data;
}