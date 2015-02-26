<?php

function demo_theme_table() {
  $output = 'table';

  // Tabulka
  $header = array(
    array('data' => 'Titulek'),
    array('data' => 'Odkaz'),
    array('data' => 'form'),
  );

  $content = array();
  $query = new EntityFieldQuery();
  $result = $query->entityCondition('entity_type', 'node')
    ->entityCondition('bundle', 'article')
    ->propertyCondition('status', 1)
    ->pager(10)
    ->range(0, 10)
    ->addMetaData('account', user_load(1))
    ->execute();
  $nodes = node_load_multiple(array_keys($result['node']));

  foreach ($nodes as $uzel) {
    $rows[] = array(
      array('data' => l($uzel->title, 'node/' .$uzel->nid)),
      array('data' => l('edit', 'node/' . $uzel->nid . '/edit')),
      array('data' => 'formular'),
    );
  }
  $output .= theme('table', array('header' => $header, 'rows' => $rows));
  return $output;
}

?>
