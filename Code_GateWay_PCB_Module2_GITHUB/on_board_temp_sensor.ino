
void temperature_handler()
{
  analog_read_vale = analogRead(LM35_pin);
  analog_voltage = analog_read_vale * (3.3 / 4095);
  temperature_value = analog_voltage * 100.0;

  temperature_filter_val1 = temperature_value;
  temperature_filter_SUM1 = temperature_filter_SUM1 - temperature_filter_READINGS1[temperature_filter_INDEX1];
  temperature_filter_VALUE1 = temperature_filter_val1;
  temperature_filter_READINGS1[temperature_filter_INDEX1] = temperature_filter_VALUE1;
  temperature_filter_SUM1 = temperature_filter_SUM1 + temperature_filter_VALUE1;
  temperature_filter_INDEX1 = (temperature_filter_INDEX1 + 1) % temperature_filter_WINDOW_SIZE;
  temperature_filter_AVERAGED1 = round(10 * (temperature_filter_SUM1 / temperature_filter_WINDOW_SIZE)) / 10.0;

  //  val.floatformat = temperature_filter_AVERAGED1;
  //  Mb.R[5] = val.byteformat[0];
  //  Mb.R[6] = val.byteformat[1];
}

void temperature_update()
{
  val.floatformat = temperature_filter_AVERAGED1;
  Mb.R[5] = val.byteformat[0];
  Mb.R[6] = val.byteformat[1];
}
