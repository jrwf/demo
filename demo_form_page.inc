<?php

function demo_form_page() {
  $output = 'Vzorova stranka s formularem.';
  $output .= drupal_render(drupal_get_form('demo_form_page_form'));
  return $output;
}

/**
  * Vzorova stranka s formularem.
 */
function demo_form_page_form($form, &$form_state) {

  $form['jmeno'] = array(
    '#type' => 'textfield',
    '#title' => t('Jmeno:'),
    '#required' => TRUE,
    '#description' => t('Vlozte jmeno.'),
    '#size' => 20,
    '#prefix' => '<div class="nejaka-trida">',
    '#suffix' => '</div>',
  );

    $form['submit'] = array(
      '#value' => 'Odeslat',
      '#type' => 'submit',
    );
  return $form;
}

function demo_form_page_form_validate($form, &$form_state) {
  if($form_state['values']['jmeno'] == 'test') {
    form_set_error('jmeno', t('Vlozene jmeno nemuze byt "test".'));
  }
}

/**
  * Ukladame do databaze.
 */
function demo_form_page_form_submit($form, &$form_state) {
  $jmeno = $form_state['values']['jmeno'];
  drupal_set_message('Ulozeno.');

  db_insert('demo_form')
    ->fields(array(
      'jmeno' => $jmeno,
    ))
    ->execute();
  drupal_set_message('Do databaze bylo ulozeno: ' . $jmeno, $status = 'status');
}

?>
