void input_timing_handler()
{
  reading_1 = !digitalRead(sensor_1);
  reading_2 = !digitalRead(sensor_2);
  reading_3 = !digitalRead(sensor_3);
  reading_4 = !digitalRead(sensor_4);
  reading_5 = !Mb.C[Sensor_5_code + 10];

  if (reading_1 != lastButtonState_1)
    lastDebounceTime_1 = millis();

  if (reading_2 != lastButtonState_2)
    lastDebounceTime_2 = millis();

  if (reading_3 != lastButtonState_3)
    lastDebounceTime_3 = millis();

  if (reading_4 != lastButtonState_4)
    lastDebounceTime_4 = millis();

  if (reading_5 != lastButtonState_5)
    lastDebounceTime_5 = millis();

  if ((millis() - lastDebounceTime_1) > debounceDelay)
    buttonState_1 = reading_1;

  if ((millis() - lastDebounceTime_2) > debounceDelay)
    buttonState_2 = reading_2;

  if ((millis() - lastDebounceTime_3) > debounceDelay)
    buttonState_3 = reading_3;

  if ((millis() - lastDebounceTime_4) > debounceDelay)
    buttonState_4 = reading_4;

  if ((millis() - lastDebounceTime_5) > debounceDelay)
    buttonState_5 = reading_5;

  Mb.C[Sensor_1_code + 10] = !buttonState_1;
  Mb.C[Sensor_2_code + 10] = !buttonState_2;
  Mb.C[Sensor_3_code + 10] = !buttonState_3;
  Mb.C[Sensor_4_code + 10] = !buttonState_4;

  if (!buttonState_1 && !recordflag_1)
  {
    StartTime_1 = millis();
    recordflag_1 = 1;

    edge_1_coded = rising_edge_val + Sensor_1_code + ((station_address - 1) * num_of_sensor_per_station) + PLC_offset;
    if (onboard_inputs_data_type_array[Sensor_1_code - 1] & 2)
    {
      save_to_mem(edge_1_coded);
    }
  }

  if (!buttonState_2 && !recordflag_2)
  {
    StartTime_2 = millis();
    recordflag_2 = 1;

    edge_2_coded = rising_edge_val + Sensor_2_code + ((station_address - 1) * num_of_sensor_per_station) + PLC_offset;
    if (onboard_inputs_data_type_array[Sensor_2_code - 1] & 2)
    {
      save_to_mem(edge_2_coded);
    }
  }

  if (!buttonState_3 && !recordflag_3)
  {
    StartTime_3 = millis();
    recordflag_3 = 1;

    edge_3_coded = rising_edge_val + Sensor_3_code + ((station_address - 1) * num_of_sensor_per_station) + PLC_offset;
    if (onboard_inputs_data_type_array[Sensor_3_code - 1] & 2)
    {
      save_to_mem(edge_3_coded);
    }
  }

  if (!buttonState_4 && !recordflag_4)
  {
    StartTime_4 = millis();
    recordflag_4 = 1;

    edge_4_coded = rising_edge_val + Sensor_4_code + ((station_address - 1) * num_of_sensor_per_station) + PLC_offset;
    if (onboard_inputs_data_type_array[Sensor_4_code - 1] & 2)
    {
      save_to_mem(edge_4_coded);
    }
  }

  if (!buttonState_5 && !recordflag_5)
  {
    StartTime_5 = millis();
    recordflag_5 = 1;

    edge_5_coded = rising_edge_val + Sensor_5_code + ((station_address - 1) * num_of_sensor_per_station) + PLC_offset;
    if (onboard_inputs_data_type_array[Sensor_5_code - 1] & 2)
    {
      save_to_mem(edge_5_coded);
    }
  }

  if (buttonState_1 && recordflag_1)
  {
    EndTime_1 = millis();

    edge_1_coded = falling_edge_val + Sensor_1_code + ((station_address - 1) * num_of_sensor_per_station) + PLC_offset;
    if (onboard_inputs_data_type_array[Sensor_1_code - 1] & 2)
    {
      save_to_mem(edge_1_coded);
    }

    timeOn_1 = EndTime_1 - StartTime_1;
    if (timeOn_1 <= min_time_to_send)
    {
      timeOn_1 = 0;
    }
    timeOn_1_coded = (((check_max(timeOn_1) / DIV_NUM) + 1) * MUL_NUM) + Sensor_1_code + ((station_address - 1) * num_of_sensor_per_station) + PLC_offset;

    if (timeOn_1 != 0)
    {
      if (onboard_inputs_data_type_array[Sensor_1_code - 1] & 1)
      {
        save_to_mem(timeOn_1_coded);
      }
    }

    if (onBoard_sensor_data_Serial_debug)
    {
      debug_serial_port.print("Input 1 : ");
      debug_serial_port.print(timeOn_1);
      debug_serial_port.print(" | coded : ");
      debug_serial_port.print(timeOn_1_coded);
      debug_serial_port.print(" | edge_coded : ");
      debug_serial_port.print(edge_1_coded);

      if (onboard_inputs_data_type_array[Sensor_1_code - 1] & 1)
        debug_serial_port.print(" | On_Time | ");
      if (onboard_inputs_data_type_array[Sensor_1_code - 1] & 2)
        debug_serial_port.print(" | Edge | ");

      debug_serial_port.println();
    }

    recordflag_1 = 0;
    EndTime_1 = 0;
    StartTime_1 = 0;
  }

  if (buttonState_2 && recordflag_2)
  {
    EndTime_2 = millis();

    edge_2_coded = falling_edge_val + Sensor_2_code + ((station_address - 1) * num_of_sensor_per_station) + PLC_offset;
    if (onboard_inputs_data_type_array[Sensor_2_code - 1] & 2)
    {
      save_to_mem(edge_2_coded);
    }

    timeOn_2 = EndTime_2 - StartTime_2;
    if (timeOn_2 <= min_time_to_send)
    {
      timeOn_2 = 0;
    }
    timeOn_2_coded = (((check_max(timeOn_2) / DIV_NUM) + 1) * MUL_NUM) + Sensor_2_code + ((station_address - 1) * num_of_sensor_per_station) + PLC_offset;

    if (timeOn_2 != 0)
    {
      if (onboard_inputs_data_type_array[Sensor_2_code - 1] & 1)
      {
        save_to_mem(timeOn_2_coded);
      }
    }

    if (onBoard_sensor_data_Serial_debug)
    {
      debug_serial_port.print("Input 2 : ");
      debug_serial_port.print(timeOn_2);
      debug_serial_port.print(" | coded : ");
      debug_serial_port.print(timeOn_2_coded);
      debug_serial_port.print(" | edge_coded : ");
      debug_serial_port.print(edge_2_coded);

      if (onboard_inputs_data_type_array[Sensor_2_code - 1] & 1)
        debug_serial_port.print(" | On_Time | ");
      if (onboard_inputs_data_type_array[Sensor_2_code - 1] & 2)
        debug_serial_port.print(" | Edge | ");

      debug_serial_port.println();
    }

    recordflag_2 = 0;
    EndTime_2 = 0;
    StartTime_2 = 0;
  }

  if (buttonState_3 && recordflag_3)
  {
    EndTime_3 = millis();

    edge_3_coded = falling_edge_val + Sensor_3_code + ((station_address - 1) * num_of_sensor_per_station) + PLC_offset;
    if (onboard_inputs_data_type_array[Sensor_3_code - 1] & 2)
    {
      save_to_mem(edge_3_coded);
    }

    timeOn_3 = EndTime_3 - StartTime_3;
    if (timeOn_3 <= min_time_to_send)
    {
      timeOn_3 = 0;
    }
    timeOn_3_coded = (((check_max(timeOn_3) / DIV_NUM) + 1) * MUL_NUM) + Sensor_3_code + ((station_address - 1) * num_of_sensor_per_station) + PLC_offset;

    if (timeOn_3 != 0)
    {
      if (onboard_inputs_data_type_array[Sensor_3_code - 1] & 1)
      {
        save_to_mem(timeOn_3_coded);
      }
    }

    if (onBoard_sensor_data_Serial_debug)
    {
      debug_serial_port.print("Input 3 : ");
      debug_serial_port.print(timeOn_3);
      debug_serial_port.print(" | coded : ");
      debug_serial_port.print(timeOn_3_coded);
      debug_serial_port.print(" | edge_coded : ");
      debug_serial_port.print(edge_3_coded);

      if (onboard_inputs_data_type_array[Sensor_3_code - 1] & 1)
        debug_serial_port.print(" | On_Time | ");
      if (onboard_inputs_data_type_array[Sensor_3_code - 1] & 2)
        debug_serial_port.print(" | Edge | ");

      debug_serial_port.println();
    }

    recordflag_3 = 0;
    EndTime_3 = 0;
    StartTime_3 = 0;
  }

  if (buttonState_4 && recordflag_4)
  {
    EndTime_4 = millis();

    edge_4_coded = falling_edge_val + Sensor_4_code + ((station_address - 1) * num_of_sensor_per_station) + PLC_offset;
    if (onboard_inputs_data_type_array[Sensor_4_code - 1] & 2)
    {
      save_to_mem(edge_4_coded);
    }

    timeOn_4 = EndTime_4 - StartTime_4;
    if (timeOn_4 <= min_time_to_send)
    {
      timeOn_4 = 0;
    }
    timeOn_4_coded = (((check_max(timeOn_4) / DIV_NUM) + 1) * MUL_NUM) + Sensor_4_code + ((station_address - 1) * num_of_sensor_per_station) + PLC_offset;

    if (timeOn_4 != 0)
    {
      if (onboard_inputs_data_type_array[Sensor_4_code - 1] & 1)
      {
        save_to_mem(timeOn_4_coded);
      }
    }

    if (onBoard_sensor_data_Serial_debug)
    {
      debug_serial_port.print("Input 4 : ");
      debug_serial_port.print(timeOn_4);
      debug_serial_port.print(" | coded : ");
      debug_serial_port.print(timeOn_4_coded);
      debug_serial_port.print(" | edge_coded : ");
      debug_serial_port.print(edge_4_coded);

      if (onboard_inputs_data_type_array[Sensor_4_code - 1] & 1)
        debug_serial_port.print(" | On_Time | ");
      if (onboard_inputs_data_type_array[Sensor_4_code - 1] & 2)
        debug_serial_port.print(" | Edge | ");

      debug_serial_port.println();
    }

    recordflag_4 = 0;
    EndTime_4 = 0;
    StartTime_4 = 0;
  }

  if (buttonState_5 && recordflag_5)
  {
    EndTime_5 = millis();

    edge_5_coded = falling_edge_val + Sensor_5_code + ((station_address - 1) * num_of_sensor_per_station) + PLC_offset;
    if (onboard_inputs_data_type_array[Sensor_5_code - 1] & 2)
    {
      save_to_mem(edge_5_coded);
    }

    timeOn_5 = EndTime_5 - StartTime_5;
    if (timeOn_5 <= min_time_to_send)
    {
      timeOn_5 = 0;
    }
    timeOn_5_coded = (((check_max(timeOn_5) / DIV_NUM) + 1) * MUL_NUM) + Sensor_5_code + ((station_address - 1) * num_of_sensor_per_station) + PLC_offset;

    if (timeOn_5 != 0)
    {
      if (onboard_inputs_data_type_array[Sensor_5_code - 1] & 1)
      {
        save_to_mem(timeOn_5_coded);
      }
    }

    if (onBoard_sensor_data_Serial_debug)
    {
      debug_serial_port.print("Input 5 : ");
      debug_serial_port.print(timeOn_5);
      debug_serial_port.print(" | coded : ");
      debug_serial_port.print(timeOn_5_coded);
      debug_serial_port.print(" | edge_coded : ");
      debug_serial_port.print(edge_5_coded);

      if (onboard_inputs_data_type_array[Sensor_5_code - 1] & 1)
        debug_serial_port.print(" | On_Time | ");
      if (onboard_inputs_data_type_array[Sensor_5_code - 1] & 2)
        debug_serial_port.print(" | Edge | ");

      debug_serial_port.println();
    }

    recordflag_5 = 0;
    EndTime_5 = 0;
    StartTime_5 = 0;
  }

  lastButtonState_1 = reading_1;
  lastButtonState_2 = reading_2;
  lastButtonState_3 = reading_3;
  lastButtonState_4 = reading_4;
  lastButtonState_5 = reading_5;
}

void resetrecord_1()
{
  first = millis();
  recordflag_1 = 0;
  timeOn_1 = 0;
}

void resetrecord_2()
{
  first = millis();
  recordflag_2 = 0;
  timeOn_2 = 0;
}

void resetrecord_3()
{
  first = millis();
  recordflag_3 = 0;
  timeOn_3 = 0;
}

void resetrecord_4()
{
  first = millis();
  recordflag_4 = 0;
  timeOn_4 = 0;
}

void resetrecord_5()
{
  first = millis();
  recordflag_5 = 0;
  timeOn_5 = 0;
}


uint16_t check_max(double in_time)
{
  if (in_time >= MAX_TIME)
  {
    return MAX_TIME;
  }
  else
  {
    return in_time;
  }
}

uint16_t send_me_input_pins_data(uint16_t address, uint16_t length)
{
  first = millis();
  uint16_t data_to_send_over_rs485;
  if (address == address)
  {
    for (int i = 0; i < length; i++)
    {
      data_to_send_over_rs485 = read_lastData_from_mem();
      if (data_to_send_over_rs485 != 0)
      {
        if (onBoard_sensor_data_Serial_debug)
        {
          debug_serial_port.println(data_to_send_over_rs485);
        }
      }
    }

    if (!recordflag_1)
      resetrecord_1();

    if (!recordflag_2)
      resetrecord_2();

    if (!recordflag_3)
      resetrecord_3();

    if (!recordflag_4)
      resetrecord_4();

    if (!recordflag_5)
      resetrecord_5();
  }
  return data_to_send_over_rs485;
}



void set_inputs_data_type(uint16_t set_inputs_data_type_in_func)
{
  for (uint8_t index = 0; index < 8; index++)
  {
    uint8_t this_input_type = set_inputs_data_type_in_func & 3;
    onboard_inputs_data_type_array[index] = this_input_type;
    
    if (onBoard_sensor_data_Serial_debug)
    {
      debug_serial_port.print("index : ");
      debug_serial_port.print(index);
      debug_serial_port.print(" | state = ");
      debug_serial_port.println(onboard_inputs_data_type_array[index]);
    }
    
    set_inputs_data_type_in_func = set_inputs_data_type_in_func >> 2;
  }
}
