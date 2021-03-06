<?php
/**
 * @file
 * HybridAuth BackdropOAuth2 specific settings.
 */

/**
 * Plugin declaration.
 */
$plugin = array(
  'configuration_form_callback' => 'hybridauth_provider_backdropoauth2_configuration_form_callback',
  'configuration_callback' => 'hybridauth_provider_backdropoauth2_configuration_callback',
);

/**
 * @todo Please document this function.
 * @see http://drupal.org/node/1354
 */
function hybridauth_provider_backdropoauth2_configuration_form_callback(&$form, $provider_id) {
  $config = config('hybridauth.settings');
  $app_settings = &$form['vtabs']['application'];

  $app_settings['#description'] = t('<p>Enter the <strong>OAuth2 Server</strong>, <strong>Client ID</strong> and <strong>Client Secret</strong>.<br/>'
    . 'On the server you must set the <strong>Redirect URI</strong> of the client to:<br/>'
    . '<strong>%redirect_uri</strong></p>',
    array(
    '%redirect_uri' => url('hybridauth/endpoint', array('absolute' => TRUE, 'query' => array('hauth.done' => 'BackdropOAuth2'), 'language' => _hybridauth_language_default())),
  )
  );

  unset($app_settings['hybridauth_provider_' . $provider_id . '_keys_key']);
  unset($app_settings['hybridauth_provider_' . $provider_id . '_keys_id']['#description']);
  unset($app_settings['hybridauth_provider_' . $provider_id . '_keys_secret']['#description']);
  $app_settings['hybridauth_provider_' . $provider_id . '_keys_id']['#title'] = t('Client ID');
  $app_settings['hybridauth_provider_' . $provider_id . '_keys_secret']['#title'] = t('Client Secret');

  $app_settings['hybridauth_provider_' . $provider_id . '_oauth2_server'] = array(
    '#type' => 'textfield',
    '#title' => t('OAuth2 Server'),
    '#default_value' => $config->get('hybridauth_provider_' . $provider_id . '_oauth2_server'),
    '#weight' => -10,
  );

  $app_settings['testing'] = array(
    '#type' => 'fieldset',
    '#title' => t('Development settings'),
    '#collapsible' => TRUE,
    '#collapsed' => TRUE,
  );
  $app_settings['testing']['hybridauth_provider_BackdropOAuth2_skipssl'] = array(
    '#type' => 'checkbox',
    '#title' => t('Skip SSL'),
    '#description' => t('Skip checking the SSL certificates.'),
    '#default_value' => $config->get('hybridauth_provider_' . $provider_id . '_skipssl'),
  );
  $app_settings['testing']['hybridauth_provider_BackdropOAuth2_proxy'] = array(
    '#type' => 'textfield',
    '#title' => t('HTTP Proxy'),
    '#description' => t('HTTP proxy (like http://mitmproxy.org/) can be very useful for debug.'),
    '#default_value' => $config->get('hybridauth_provider_' . $provider_id . '_proxy'),
  );
}

/**
 * @todo Please document this function.
 * @see http://drupal.org/node/1354
 */
function hybridauth_provider_backdropoauth2_configuration_callback(&$config, $provider_id) {
  $config = config('hybridauth.settings');
  $config['oauth2_server'] = $config->get('hybridauth_provider_' . $provider_id . '_oauth2_server');
  $config['skip_ssl'] = $config->get('hybridauth_provider_' . $provider_id . '_skipssl');
  $config['http_proxy'] = $config->get('hybridauth_provider_' . $provider_id . '_proxy');
}
