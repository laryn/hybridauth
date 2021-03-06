<?php
/**
 * @file
 * Zocial icon pack.
 */

/**
 * Plugin declaration.
 */
$plugin = array(
  'title' => t('Zocial'),
  'initialize_callback' => 'hybridauth_zocial_initialize_callback',
  'icon_classes_callback' => 'hybridauth_zocial_icon_classes_callback',
);

/**
 * @todo Please document this function.
 * @see http://drupal.org/node/1354
 */
function hybridauth_zocial_initialize_callback(&$element) {
  $path = 'sites/all/libraries/zocial';
  if (module_exists('libraries')) {
    $path = libraries_get_path('zocial');
  }
  $element['#attached']['css'][] = $path . '/css/zocial.css';
}

/**
 * @todo Please document this function.
 * @see http://drupal.org/node/1354
 */
function hybridauth_zocial_icon_classes_callback(&$classes, $provider_id) {
  $additional_classes = array('zocial', 'icon');
  if ($provider_id == 'Vkontakte') {
    $additional_classes[] = 'vk';
  }
  $classes = array_merge($classes, $additional_classes);
}
