<?php


function demo_hook_access(){
  $output = 'cosi';
  if (user_access('contact view')) {
    $output .= 'Text jen pro nekoho';
  }
  return $output;
}

/* End of file demo_hook_access.inc */
