<?php
/**
 * @file
 * HybridAuth Vkontakte specific settings.
 */

/**
 * @todo Please document this function.
 * @see http://drupal.org/node/1354
 */
function hybridauth_provider_vkontakte_configuration_form_callback(&$form, $provider_id) {
  unset($form['vtabs']['application']['hybridauth_provider_' . $provider_id . '_keys_key']);
}
