<?php

function demo_email(){
  $output = '';
  $output .= drupal_render(drupal_get_form('demo_email_form'));
  return $output;
}

/**
  * Form
 */
function demo_email_form($form, &$form_state) {

  $form['jmeno'] = array(
    '#type' => 'textfield',
    '#title' => t('Jmeno'),
    '#required' => TRUE,
    '#description' => t('Jmeno'),
    '#size' => 20,
  );  

  $form['email'] = array(
    '#type' => 'textfield',
    '#title' => t('E-mail'),
    '#required' => TRUE,
    '#description' => t('E-mail'),
    '#size' => 20,
  );

  $form['zprava'] = array(
    '#type' => 'textarea',
    '#title' => t('Zprava'),
    '#description' => t('Zprava'),
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

/**
  * Ukladani
 */
function demo_email_form_submit($form, &$form_state) {
  $jmeno = $form_state['values']['jmeno'];
  $email = $form_state['values']['email'];
  $zprava = $form_state['values']['zprava'];
  drupal_set_message('Odeslano.');

  db_insert('demo_email')
    ->fields(array(
      'jmeno' => $jmeno,
      'email' => $email,
      'zprava' => $zprava,
    ))
    ->execute();
  drupal_set_message('odesláno', $status = 'status');

  drupal_mail(
    'demo',
    'demo',
    $account->mail,
    user_preferred_language($account),
    $form_state['values'],
    $data,
    variable_get('site_mail', NULL),
    TRUE
  );

}

function demo_mail($key, &$message, $params) {
  switch ($key) {
  case 'demo':
    $account = $params['account'];
    $subject = variable_get('demo_email_subject', 'Administrativni varovani');
    $body = variable_get('demo_email_text', 'Upozorneni');
    if (variable_get('demo_bcc', FAlSE)) {
      $admin_mail = variable_get('site_mail', NULL);
      $message['headers']['bcc'] = $admin_mail;
    }

    $message['to'] = $account->mail;
    $message['subject'] = $subject;
    $message['body'][] = $body;
    break;
  }
}

?>
