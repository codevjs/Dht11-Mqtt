// Auto generated code by esphome
// ========== AUTO GENERATED INCLUDE BLOCK BEGIN ===========
#include "esphome.h"
using namespace esphome;
using std::isnan;
using std::min;
using std::max;
logger::Logger *logger_logger;
web_server_base::WebServerBase *web_server_base_webserverbase;
captive_portal::CaptivePortal *captive_portal_captiveportal;
wifi::WiFiComponent *wifi_wificomponent;
mdns::MDNSComponent *mdns_mdnscomponent;
ota::OTAComponent *ota_otacomponent;
using namespace sensor;
mqtt::MQTTClientComponent *mqtt_mqttclientcomponent;
using namespace mqtt;
api::APIServer *api_apiserver;
using namespace api;
using namespace json;
preferences::IntervalSyncer *preferences_intervalsyncer;
dht::DHT *dht_dht;
esphome::esp8266::ESP8266GPIOPin *esphome_esp8266_esp8266gpiopin;
sensor::Sensor *sensor_sensor;
mqtt::MQTTSensorComponent *mqtt_mqttsensorcomponent;
sensor::Sensor *sensor_sensor_2;
mqtt::MQTTSensorComponent *mqtt_mqttsensorcomponent_2;
const uint8_t ESPHOME_ESP8266_GPIO_INITIAL_MODE[16] = {255, 255, INPUT, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255};
const uint8_t ESPHOME_ESP8266_GPIO_INITIAL_LEVEL[16] = {255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255};
#define yield() esphome::yield()
#define millis() esphome::millis()
#define micros() esphome::micros()
#define delay(x) esphome::delay(x)
#define delayMicroseconds(x) esphome::delayMicroseconds(x)
// ========== AUTO GENERATED INCLUDE BLOCK END ==========="

void setup() {
  // ========== AUTO GENERATED CODE BEGIN ===========
  // esp8266:
  //   board: d1_mini
  //   framework:
  //     version: 3.0.2
  //     source: ~3.30002.0
  //     platform_version: platformio/espressif8266 @ 3.2.0
  //   restore_from_flash: false
  //   board_flash_mode: dout
  esphome::esp8266::setup_preferences();
  // async_tcp:
  //   {}
  // esphome:
  //   name: dht11
  //   build_path: .esphome/build/dht11
  //   platformio_options: {}
  //   includes: []
  //   libraries: []
  //   name_add_mac_suffix: false
  App.pre_setup("dht11", __DATE__ ", " __TIME__, false);
  // logger:
  //   id: logger_logger
  //   baud_rate: 115200
  //   tx_buffer_size: 512
  //   deassert_rts_dtr: false
  //   hardware_uart: UART0
  //   level: DEBUG
  //   logs: {}
  //   esp8266_store_log_strings_in_flash: true
  logger_logger = new logger::Logger(115200, 512, logger::UART_SELECTION_UART0);
  logger_logger->pre_setup();
  logger_logger->set_component_source("logger");
  App.register_component(logger_logger);
  // web_server_base:
  //   id: web_server_base_webserverbase
  web_server_base_webserverbase = new web_server_base::WebServerBase();
  web_server_base_webserverbase->set_component_source("web_server_base");
  App.register_component(web_server_base_webserverbase);
  // captive_portal:
  //   id: captive_portal_captiveportal
  //   web_server_base_id: web_server_base_webserverbase
  captive_portal_captiveportal = new captive_portal::CaptivePortal(web_server_base_webserverbase);
  captive_portal_captiveportal->set_component_source("captive_portal");
  App.register_component(captive_portal_captiveportal);
  // wifi:
  //   ap:
  //     ssid: Dht11 Fallback Hotspot
  //     password: '12345678'
  //     id: wifi_wifiap
  //     ap_timeout: 1min
  //   id: wifi_wificomponent
  //   domain: .local
  //   reboot_timeout: 15min
  //   power_save_mode: NONE
  //   fast_connect: false
  //   output_power: 20.0
  //   networks:
  //   - ssid: Morbius
  //     password: CAPSLOCK
  //     id: wifi_wifiap_2
  //     priority: 0.0
  //   use_address: dht11.local
  wifi_wificomponent = new wifi::WiFiComponent();
  wifi_wificomponent->set_use_address("dht11.local");
  wifi::WiFiAP wifi_wifiap_2 = wifi::WiFiAP();
  wifi_wifiap_2.set_ssid("Morbius");
  wifi_wifiap_2.set_password("CAPSLOCK");
  wifi_wifiap_2.set_priority(0.0f);
  wifi_wificomponent->add_sta(wifi_wifiap_2);
  wifi::WiFiAP wifi_wifiap = wifi::WiFiAP();
  wifi_wifiap.set_ssid("Dht11 Fallback Hotspot");
  wifi_wifiap.set_password("12345678");
  wifi_wificomponent->set_ap(wifi_wifiap);
  wifi_wificomponent->set_ap_timeout(60000);
  wifi_wificomponent->set_reboot_timeout(900000);
  wifi_wificomponent->set_power_save_mode(wifi::WIFI_POWER_SAVE_NONE);
  wifi_wificomponent->set_fast_connect(false);
  wifi_wificomponent->set_output_power(20.0f);
  wifi_wificomponent->set_component_source("wifi");
  App.register_component(wifi_wificomponent);
  // mdns:
  //   id: mdns_mdnscomponent
  //   disabled: false
  mdns_mdnscomponent = new mdns::MDNSComponent();
  mdns_mdnscomponent->set_component_source("mdns");
  App.register_component(mdns_mdnscomponent);
  // ota:
  //   password: ''
  //   id: ota_otacomponent
  //   safe_mode: true
  //   port: 8266
  //   reboot_timeout: 5min
  //   num_attempts: 10
  ota_otacomponent = new ota::OTAComponent();
  ota_otacomponent->set_port(8266);
  ota_otacomponent->set_auth_password("");
  ota_otacomponent->set_component_source("ota");
  App.register_component(ota_otacomponent);
  if (ota_otacomponent->should_enter_safe_mode(10, 300000)) return;
  // sensor:
  // mqtt:
  //   broker: 34.101.163.175
  //   port: 1883
  //   id: mqtt_mqttclientcomponent
  //   username: ''
  //   password: ''
  //   discovery: true
  //   discovery_retain: true
  //   discovery_prefix: homeassistant
  //   discovery_unique_id_generator: legacy
  //   discovery_object_id_generator: none
  //   use_abbreviations: true
  //   topic_prefix: dht11
  //   keepalive: 15s
  //   reboot_timeout: 15min
  //   birth_message:
  //     topic: dht11/status
  //     payload: online
  //     qos: 0
  //     retain: true
  //   will_message:
  //     topic: dht11/status
  //     payload: offline
  //     qos: 0
  //     retain: true
  //   shutdown_message:
  //     topic: dht11/status
  //     payload: offline
  //     qos: 0
  //     retain: true
  //   log_topic:
  //     topic: dht11/debug
  //     qos: 0
  //     retain: true
  mqtt_mqttclientcomponent = new mqtt::MQTTClientComponent();
  mqtt_mqttclientcomponent->set_component_source("mqtt");
  App.register_component(mqtt_mqttclientcomponent);
  mqtt_mqttclientcomponent->set_broker_address("34.101.163.175");
  mqtt_mqttclientcomponent->set_broker_port(1883);
  mqtt_mqttclientcomponent->set_username("");
  mqtt_mqttclientcomponent->set_password("");
  mqtt_mqttclientcomponent->set_discovery_info("homeassistant", mqtt::MQTT_LEGACY_UNIQUE_ID_GENERATOR, mqtt::MQTT_NONE_OBJECT_ID_GENERATOR, true);
  mqtt_mqttclientcomponent->set_topic_prefix("dht11");
  mqtt_mqttclientcomponent->set_birth_message(mqtt::MQTTMessage{
      .topic = "dht11/status",
      .payload = "online",
      .qos = 0,
      .retain = true,
  });
  mqtt_mqttclientcomponent->set_last_will(mqtt::MQTTMessage{
      .topic = "dht11/status",
      .payload = "offline",
      .qos = 0,
      .retain = true,
  });
  mqtt_mqttclientcomponent->set_shutdown_message(mqtt::MQTTMessage{
      .topic = "dht11/status",
      .payload = "offline",
      .qos = 0,
      .retain = true,
  });
  mqtt_mqttclientcomponent->set_log_message_template(mqtt::MQTTMessage{
      .topic = "dht11/debug",
      .payload = "",
      .qos = 0,
      .retain = true,
  });
  mqtt_mqttclientcomponent->set_keep_alive(15);
  mqtt_mqttclientcomponent->set_reboot_timeout(900000);
  // api:
  //   password: ''
  //   id: api_apiserver
  //   port: 6053
  //   reboot_timeout: 15min
  api_apiserver = new api::APIServer();
  api_apiserver->set_component_source("api");
  App.register_component(api_apiserver);
  api_apiserver->set_port(6053);
  api_apiserver->set_password("");
  api_apiserver->set_reboot_timeout(900000);
  // json:
  //   {}
  // preferences:
  //   id: preferences_intervalsyncer
  //   flash_write_interval: 60s
  preferences_intervalsyncer = new preferences::IntervalSyncer();
  preferences_intervalsyncer->set_write_interval(60000);
  preferences_intervalsyncer->set_component_source("preferences");
  App.register_component(preferences_intervalsyncer);
  // sensor.dht:
  //   platform: dht
  //   pin:
  //     number: 2
  //     mode:
  //       input: true
  //       analog: false
  //       output: false
  //       open_drain: false
  //       pullup: false
  //       pulldown: false
  //     inverted: false
  //     id: esphome_esp8266_esp8266gpiopin
  //   temperature:
  //     name: Temperature
  //     disabled_by_default: false
  //     mqtt_id: mqtt_mqttsensorcomponent
  //     id: sensor_sensor
  //     force_update: false
  //     unit_of_measurement: °C
  //     accuracy_decimals: 1
  //     device_class: temperature
  //     state_class: measurement
  //   humidity:
  //     name: Humidity
  //     disabled_by_default: false
  //     mqtt_id: mqtt_mqttsensorcomponent_2
  //     id: sensor_sensor_2
  //     force_update: false
  //     unit_of_measurement: '%'
  //     accuracy_decimals: 0
  //     device_class: humidity
  //     state_class: measurement
  //   update_interval: 3s
  //   id: dht_dht
  //   model: AUTO_DETECT
  dht_dht = new dht::DHT();
  dht_dht->set_update_interval(3000);
  dht_dht->set_component_source("dht.sensor");
  App.register_component(dht_dht);
  esphome_esp8266_esp8266gpiopin = new esphome::esp8266::ESP8266GPIOPin();
  esphome_esp8266_esp8266gpiopin->set_pin(2);
  esphome_esp8266_esp8266gpiopin->set_inverted(false);
  esphome_esp8266_esp8266gpiopin->set_flags(gpio::Flags::FLAG_INPUT);
  dht_dht->set_pin(esphome_esp8266_esp8266gpiopin);
  sensor_sensor = new sensor::Sensor();
  App.register_sensor(sensor_sensor);
  sensor_sensor->set_name("Temperature");
  sensor_sensor->set_disabled_by_default(false);
  sensor_sensor->set_device_class("temperature");
  sensor_sensor->set_state_class(sensor::STATE_CLASS_MEASUREMENT);
  sensor_sensor->set_unit_of_measurement("\302\260C");
  sensor_sensor->set_accuracy_decimals(1);
  sensor_sensor->set_force_update(false);
  mqtt_mqttsensorcomponent = new mqtt::MQTTSensorComponent(sensor_sensor);
  mqtt_mqttsensorcomponent->set_component_source("mqtt");
  App.register_component(mqtt_mqttsensorcomponent);
  dht_dht->set_temperature_sensor(sensor_sensor);
  sensor_sensor_2 = new sensor::Sensor();
  App.register_sensor(sensor_sensor_2);
  sensor_sensor_2->set_name("Humidity");
  sensor_sensor_2->set_disabled_by_default(false);
  sensor_sensor_2->set_device_class("humidity");
  sensor_sensor_2->set_state_class(sensor::STATE_CLASS_MEASUREMENT);
  sensor_sensor_2->set_unit_of_measurement("%");
  sensor_sensor_2->set_accuracy_decimals(0);
  sensor_sensor_2->set_force_update(false);
  mqtt_mqttsensorcomponent_2 = new mqtt::MQTTSensorComponent(sensor_sensor_2);
  mqtt_mqttsensorcomponent_2->set_component_source("mqtt");
  App.register_component(mqtt_mqttsensorcomponent_2);
  dht_dht->set_humidity_sensor(sensor_sensor_2);
  dht_dht->set_dht_model(dht::DHT_MODEL_AUTO_DETECT);
  // socket:
  //   implementation: lwip_tcp
  // network:
  //   {}
  // =========== AUTO GENERATED CODE END ============
  App.setup();
}

void loop() {
  App.loop();
}
