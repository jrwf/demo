<?php

function demo_page() {
  $output = 'demo page';
  $content = array();
  $query = new EntityFieldQuery();
  $result = $query->entityCondition('entity_type', 'node')
    ->entityCondition('bundle', 'article')
    ->propertyCondition('status', 1)
    ->pager(5)
    ->range(0, 10)
    ->addMetaData('account', user_load(1))
    ->execute();
  $nodes = node_load_multiple(array_keys($result['node']));
  $content = node_view_multiple($nodes, 'teaser');
  $data = array(
    'content'=> $content,
    'pager'=> array(
      '#markup'=> theme('pager'),
      '#weight'=>10
    ));

  $output .= render($data);

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
    $data .= l($uzel->title, 'node/' . $uzel->nid) . '<br />';
  }

  $output .= render($data);
  return $output;
}

?>
