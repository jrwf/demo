<?php

/**
* Form
 */
function demo_formular($form, &$form_state) {

  $form['jmeno'] = array(
    '#type' => 'textfield',
    '#title' => t('Jmeno'),
    '#required' => TRUE,
    '#description' => t('Vlozte jmeno.'),
    '#size' => 20,
    '#prefix' => '<div class="nejaka-trida">',
    '#suffix' => '</div>',
  );

  $form['popis'] = array(
    '#type' => 'textarea',
    '#title' => t('Popis'),
    '#description' => t('Popis'),
    '#cols' => '20',
    '#rows' => '5',
    '#resizable' => TRUE,
  );

    $form['submit'] = array(
      '#value' => 'Odeslat',
      '#type' => 'submit',
    );

  return $form;
}

function demo_formular_validate($form, &$form_state) {
  if($form_state['values']['jmeno'] == 'test') {
    form_set_error('jmeno', t('Jmeno nesmi byt "test".'));
  }
}

/**
  * Ukladame data.
 */
function demo_formular_submit($form, &$form_state) {
  $jmeno = $form_state['values']['jmeno'];
  $popis = $form_state['values']['popis'];
  // $jmeno = $form_state['values']['jmeno'];
  drupal_set_message('Ulozeno.');

  db_insert('demo_form')
    ->fields(array(
      'jmeno' => $jmeno,
      'popis' => $popis,
    ))
    ->execute();
  drupal_set_message('odesláno', $status = 'status');
}

?>
