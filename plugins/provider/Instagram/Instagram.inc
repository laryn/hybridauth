<?php
/**
 * @file
 * HybridAuth Instagram specific settings.
 */

/**
 * @todo Please document this function.
 * @see http://drupal.org/node/1354
 */
function hybridauth_provider_instagram_configuration_form_callback(&$form, $provider_id) {
  $form['vtabs']['application']['hybridauth_provider_' . $provider_id . '_keys_id']['#title'] = t('Client ID');
  $form['vtabs']['application']['hybridauth_provider_' . $provider_id . '_keys_secret']['#title'] = t('Client secret');
  unset($form['vtabs']['application']['hybridauth_provider_' . $provider_id . '_keys_key']);
}
