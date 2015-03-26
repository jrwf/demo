<?php
function demo_db_select(){

  $output = 'vypis ';

  $uid = 1;
  $result = db_query('SELECT n.nid, n.title, n.created FROM {node} n WHERE n.uid = :uid ORDER BY n.created DESC', 0, 10, array(':uid' => $uid));
  foreach ($result as $record) {
    // Perform operations on $record->title, etc. here.
    $output .= $record->nid . ' - ' . $record->title . '<br />';
  }

  $output .= '';

  $query_parameters = drupal_get_query_parameters();
  if (!empty($query_parameters['test'])) {
    $parametr = $query_parameters['test'];
  }

  $output .= $parametr;
  $output .= l('odkaz', 'demo/db-select', array('query' => array('test' => 'cosi-kdesi')));
  $query = db_select('node', 'n');
  $query->fields('n', array('nid', 'title', 'created'));
  $query->condition('type', 'article');
  $query->range(0, 10); // jako LIMIT
  $query->orderBy('n.title', 'ASC');
  $query->addTag('node_access');
  $query->execute();

  $result = $query->execute();
  foreach ($result as $record) {
    $rows[] = array(
      array(
        'data' => $record->title,
        ),
      array(
        'data' => format_date($record->created, 'custom', 'd-m-Y'),
        // 'data' => date_format($record->created),
        ),
      array(
        'data' => $record->nid,
        ),
      array(
        'data' => l('Editovat', 'node/' . $record->nid . '/edit'),
        ),
    );
  }

  $output .= theme('table', array(
      'header' => $header,
      'rows' => $rows,
  ));
  return $output;
}
/* End of file fiel.php */
