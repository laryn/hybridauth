<?php
/**
 * @file
 * HybridAuth Google specific settings.
 */

/**
 * @todo Please document this function.
 * @see http://drupal.org/node/1354
 */
function hybridauth_provider_google_configuration_form_callback(&$form, $provider_id) {
  $form['vtabs']['application']['hybridauth_provider_' . $provider_id . '_keys_id']['#title'] = t('Client ID');
  unset($form['vtabs']['application']['hybridauth_provider_' . $provider_id . '_keys_id']['#description']);
  unset($form['vtabs']['application']['hybridauth_provider_' . $provider_id . '_keys_key']);
  $form['vtabs']['application']['hybridauth_provider_' . $provider_id . '_keys_secret']['#title'] = t('Client secret');
  unset($form['vtabs']['application']['hybridauth_provider_' . $provider_id . '_keys_secret']['#description']);

  $origin_uri_parts = parse_url(url('<front>', array('absolute' => TRUE)));
  $form['vtabs']['application']['#description'] = t('<p>Enter your Client ID and Client secret. You can get these by creating a new application at <a href="!apps_uri">!apps_uri</a>.</p>'
    . '<p>You must set <strong>Authorized Redirect URIs</strong> to <strong>%redirect_uri</strong>.</p>'
    . '<p>You must set <strong>Authorized JavaScript Origins</strong> to <strong>%origin_uri</strong>.</p>'
    . '<p>You must enable <strong>Contacts API</strong> and <strong>Google+ API</strong> for your project at <a href="!apps_uri">!apps_uri</a> under APIs & auth -> APIs.</p>',
    array(
    '!apps_uri' => 'https://console.developers.google.com',
    '%redirect_uri' => url('hybridauth/endpoint', array('absolute' => TRUE, 'query' => array('hauth.done' => 'Google'), 'language' => _hybridauth_language_default())),
    '%origin_uri' => $origin_uri_parts['scheme'] . '://' . $origin_uri_parts['host'],
  )
  );

  $form['vtabs']['advanced'] = array(
    '#type' => 'fieldset',
    '#title' => 'Advanced settings',
  );
  $form['vtabs']['advanced']['hybridauth_provider_' . $provider_id . '_scope'] = array(
    '#type' => 'textfield',
    '#title' => t('Scope'),
    '#default_value' => config_get('hybridauth.settings', 'hybridauth_provider_' . $provider_id . '_scope'),
    '#size' => 150,
  );
}

/**
 * @todo Please document this function.
 * @see http://drupal.org/node/1354
 */
function hybridauth_provider_google_configuration_callback(&$config, $provider_id) {
  if (empty($config['scope'])) {
    $config['scope'] = hybridauth_provider_google_scope_default();
  }
}

/**
 * @todo Please document this function.
 * @see http://drupal.org/node/1354
 */
function hybridauth_provider_google_scope_default() {
  return 'https://www.googleapis.com/auth/userinfo.profile https://www.googleapis.com/auth/userinfo.email';
}
