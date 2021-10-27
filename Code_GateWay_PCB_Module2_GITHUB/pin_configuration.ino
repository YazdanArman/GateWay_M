void pin_configuration() {
  pinMode(connection_indicator_LED_pin, OUTPUT);
  pinMode(heart_beat_LED_pin, OUTPUT);

  digitalWrite(connection_indicator_LED_pin, LOW);
  digitalWrite(heart_beat_LED_pin, LOW);

  pinMode(sensor_1, INPUT_PULLDOWN); //Sensor 1
  pinMode(sensor_2, INPUT_PULLDOWN); //Sensor 2
  pinMode(sensor_3, INPUT_PULLDOWN); //Sensor 3
  pinMode(sensor_4, INPUT_PULLDOWN); //Sensor 4

  pinMode(LM35_pin, INPUT_ANALOG);

  pinMode(MAX485_DE_pin, OUTPUT);
  digitalWrite(MAX485_DE_pin, LOW);

  pinMode(config_mode_enb_pin, INPUT_PULLUP);

  //  pinMode(on_board_led, OUTPUT);

}
