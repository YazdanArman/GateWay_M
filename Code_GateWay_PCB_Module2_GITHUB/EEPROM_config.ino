void read_and_apply_settings_from_EEPROM()
{
  EEPROM.read(EEPROM_ADRESS_IP_1st_Byte, &IP_1st_Byte);
  ip[0] = IP_1st_Byte;
  EEPROM.read(EEPROM_ADRESS_IP_2nd_Byte, &IP_2nd_Byte);
  ip[1] = IP_2nd_Byte;
  EEPROM.read(EEPROM_ADRESS_IP_3rd_Byte, &IP_3rd_Byte);
  ip[2] = IP_3rd_Byte;
  EEPROM.read(EEPROM_ADRESS_IP_4th_Byte, &IP_4th_Byte);
  ip[3] = IP_4th_Byte;

  EEPROM.read(EEPROM_ADRESS_MAC_1st_Byte, &MAC_1st_Byte);
  mac[0] = MAC_1st_Byte;
  EEPROM.read(EEPROM_ADRESS_MAC_2nd_Byte, &MAC_2nd_Byte);
  mac[1] = MAC_2nd_Byte;
  EEPROM.read(EEPROM_ADRESS_MAC_3rd_Byte, &MAC_3rd_Byte);
  mac[2] = MAC_3rd_Byte;
  EEPROM.read(EEPROM_ADRESS_MAC_4th_Byte, &MAC_4th_Byte);
  mac[3] = MAC_4th_Byte;
  EEPROM.read(EEPROM_ADRESS_MAC_5th_Byte, &MAC_5th_Byte);
  mac[4] = MAC_5th_Byte;
  EEPROM.read(EEPROM_ADRESS_MAC_6th_Byte, &MAC_6th_Byte);
  mac[5] = MAC_6th_Byte;

  delay(1000);
  Ethernet.begin(mac, ip);
  delay(1000);

  EEPROM.read(EEPROM_ADRESS_RS485_serial_baud_rate, &RS485_serial_baud_rate);
  EEPROM.read(EEPROM_ADRESS_RS485_serial_setting, &RS485_serial_setting);
  RS485_serial_port.begin(baud_list[RS485_serial_baud_rate], serial_config_list[RS485_serial_setting]);

  EEPROM.read(EEPROM_ADRESS_num_of_sensor_per_station, &num_of_sensor_per_station);
  EEPROM.read(EEPROM_ADRESS_station_address, &station_address);
  EEPROM.read(EEPROM_ADRESS_PLC_offset, &PLC_offset);

  EEPROM.read(EEPROM_ADRESS_onboard_inputs_data_type, &onboard_inputs_data_type);
  set_inputs_data_type(onboard_inputs_data_type);

  if (config_Serial_debug)
  {
    debug_serial_port.println("*************************************************************");
    debug_serial_port.println("read_and_apply_settings_from_EEPROM()");
    debug_serial_port.print("EEPROM_ADRESS_IP_1st_Byte = ");
    debug_serial_port.print(EEPROM_ADRESS_IP_1st_Byte);
    debug_serial_port.print(" | IP_1st_Byte = ");
    debug_serial_port.println(IP_1st_Byte);
    debug_serial_port.print("EEPROM_ADRESS_IP_2nd_Byte = ");
    debug_serial_port.print(EEPROM_ADRESS_IP_2nd_Byte);
    debug_serial_port.print(" | IP_2nd_Byte = ");
    debug_serial_port.println(IP_2nd_Byte);
    debug_serial_port.print("EEPROM_ADRESS_IP_3rd_Byte = ");
    debug_serial_port.print(EEPROM_ADRESS_IP_3rd_Byte);
    debug_serial_port.print(" | IP_3rd_Byte = ");
    debug_serial_port.println(IP_3rd_Byte);
    debug_serial_port.print("EEPROM_ADRESS_IP_4th_Byte = ");
    debug_serial_port.print(EEPROM_ADRESS_IP_4th_Byte);
    debug_serial_port.print(" | IP_4th_Byte = ");
    debug_serial_port.println(IP_4th_Byte);
    debug_serial_port.print("EEPROM_ADRESS_MAC_1st_Byte = ");
    debug_serial_port.print(EEPROM_ADRESS_MAC_1st_Byte);
    debug_serial_port.print(" | MAC_1st_Byte = ");
    debug_serial_port.println(MAC_1st_Byte, HEX);
    debug_serial_port.print("EEPROM_ADRESS_MAC_2nd_Byte = ");
    debug_serial_port.print(EEPROM_ADRESS_MAC_2nd_Byte);
    debug_serial_port.print(" | MAC_2nd_Byte = ");
    debug_serial_port.println(MAC_2nd_Byte, HEX);
    debug_serial_port.print("EEPROM_ADRESS_MAC_3rd_Byte = ");
    debug_serial_port.print(EEPROM_ADRESS_MAC_3rd_Byte);
    debug_serial_port.print(" | MAC_3rd_Byte = ");
    debug_serial_port.println(MAC_3rd_Byte, HEX);
    debug_serial_port.print("EEPROM_ADRESS_MAC_4th_Byte = ");
    debug_serial_port.print(EEPROM_ADRESS_MAC_4th_Byte);
    debug_serial_port.print(" | MAC_4th_Byte = ");
    debug_serial_port.println(MAC_4th_Byte, HEX);
    debug_serial_port.print("EEPROM_ADRESS_MAC_5th_Byte = ");
    debug_serial_port.print(EEPROM_ADRESS_MAC_5th_Byte);
    debug_serial_port.print(" | MAC_5th_Byte = ");
    debug_serial_port.println(MAC_5th_Byte, HEX);
    debug_serial_port.print("EEPROM_ADRESS_MAC_6th_Byte = ");
    debug_serial_port.print(EEPROM_ADRESS_MAC_6th_Byte);
    debug_serial_port.print(" | MAC_6th_Byte = ");
    debug_serial_port.println(MAC_6th_Byte, HEX);
    debug_serial_port.print("EEPROM_ADRESS_RS485_serial_baud_rate = ");
    debug_serial_port.print(EEPROM_ADRESS_RS485_serial_baud_rate);
    debug_serial_port.print(" | RS485_serial_baud_rate = ");
    debug_serial_port.print(RS485_serial_baud_rate);
    debug_serial_port.print(" --> ");
    debug_serial_port.println(baud_list[RS485_serial_baud_rate]);
    debug_serial_port.print("EEPROM_ADRESS_RS485_serial_setting = ");
    debug_serial_port.print(EEPROM_ADRESS_RS485_serial_setting);
    debug_serial_port.print(" | RS485_serial_setting = ");
    debug_serial_port.print(RS485_serial_setting);
    debug_serial_port.print(" --> ");
    debug_serial_port.print(serial_config_list[RS485_serial_setting]);
    debug_serial_port.print(" --> ");
    if (RS485_serial_setting == 0)
      debug_serial_port.println("SERIAL_8N1");
    if (RS485_serial_setting == 1)
      debug_serial_port.println("SERIAL_8N2");
    if (RS485_serial_setting == 2)
      debug_serial_port.println("SERIAL_9N1");
    if (RS485_serial_setting == 3)
      debug_serial_port.println("SERIAL_9N2");
    if (RS485_serial_setting == 4)
      debug_serial_port.println("SERIAL_8E1");
    if (RS485_serial_setting == 5)
      debug_serial_port.println("SERIAL_8E2");
    if (RS485_serial_setting == 6)
      debug_serial_port.println("SERIAL_8O1");
    if (RS485_serial_setting == 7)
      debug_serial_port.println("SERIAL_8O2");
    debug_serial_port.print("EEPROM_ADRESS_num_of_sensor_per_station = ");
    debug_serial_port.print(EEPROM_ADRESS_num_of_sensor_per_station);
    debug_serial_port.print(" | num_of_sensor_per_station = ");
    debug_serial_port.println(num_of_sensor_per_station);
    debug_serial_port.print("EEPROM_ADRESS_station_address = ");
    debug_serial_port.print(EEPROM_ADRESS_station_address);
    debug_serial_port.print(" | station_address = ");
    debug_serial_port.println(station_address);
    debug_serial_port.print("EEPROM_ADRESS_PLC_offset = ");
    debug_serial_port.print(EEPROM_ADRESS_PLC_offset);
    debug_serial_port.print(" | PLC_offset = ");
    debug_serial_port.println(PLC_offset);
    debug_serial_port.print("onboard_inputs_data_type = ");
    debug_serial_port.println(onboard_inputs_data_type, BIN);
    debug_serial_port.println("done");
    debug_serial_port.println("*************************************************************");
  }
}

void first_time_EEPROM_write()
{
  EEPROM.write(EEPROM_ADRESS_IP_1st_Byte, ip_first[0]);
  EEPROM.write(EEPROM_ADRESS_IP_2nd_Byte, ip_first[1]);
  EEPROM.write(EEPROM_ADRESS_IP_3rd_Byte, ip_first[2]);
  EEPROM.write(EEPROM_ADRESS_IP_4th_Byte, ip_first[3]);

  EEPROM.write(EEPROM_ADRESS_MAC_1st_Byte, mac_first[0]);
  EEPROM.write(EEPROM_ADRESS_MAC_2nd_Byte, mac_first[1]);
  EEPROM.write(EEPROM_ADRESS_MAC_3rd_Byte, mac_first[2]);
  EEPROM.write(EEPROM_ADRESS_MAC_4th_Byte, mac_first[3]);
  EEPROM.write(EEPROM_ADRESS_MAC_5th_Byte, mac_first[4]);
  EEPROM.write(EEPROM_ADRESS_MAC_6th_Byte, mac_first[5]);

  EEPROM.write(EEPROM_ADRESS_RS485_serial_baud_rate, 5);         //19200
  EEPROM.write(EEPROM_ADRESS_RS485_serial_setting, 4);           //SERIAL_8E1

  EEPROM.write(EEPROM_ADRESS_num_of_sensor_per_station, num_of_sensor_per_station_first);
  EEPROM.write(EEPROM_ADRESS_station_address, station_address_first);
  EEPROM.write(EEPROM_ADRESS_PLC_offset, PLC_offset_first);

  EEPROM.write(EEPROM_ADRESS_onboard_inputs_data_type, onboard_inputs_data_type_first);

  if (config_Serial_debug)
  {
    debug_serial_port.println("*************************************************************");
    debug_serial_port.println("first_time_EEPROM_write()");
    debug_serial_port.print("EEPROM_ADRESS_IP_1st_Byte = ");
    debug_serial_port.print(EEPROM_ADRESS_IP_1st_Byte);
    debug_serial_port.print(" | IP_1st_Byte = ");
    debug_serial_port.println(ip_first[0]);
    debug_serial_port.print("EEPROM_ADRESS_IP_2nd_Byte = ");
    debug_serial_port.print(EEPROM_ADRESS_IP_2nd_Byte);
    debug_serial_port.print(" | IP_2nd_Byte = ");
    debug_serial_port.println(ip_first[1]);
    debug_serial_port.print("EEPROM_ADRESS_IP_3rd_Byte = ");
    debug_serial_port.print(EEPROM_ADRESS_IP_3rd_Byte);
    debug_serial_port.print(" | IP_3rd_Byte = ");
    debug_serial_port.println(ip_first[2]);
    debug_serial_port.print("EEPROM_ADRESS_IP_4th_Byte = ");
    debug_serial_port.print(EEPROM_ADRESS_IP_4th_Byte);
    debug_serial_port.print(" | IP_4th_Byte = ");
    debug_serial_port.println(ip_first[3]);
    debug_serial_port.print("EEPROM_ADRESS_MAC_1st_Byte = ");
    debug_serial_port.print(EEPROM_ADRESS_MAC_1st_Byte);
    debug_serial_port.print(" | MAC_1st_Byte = ");
    debug_serial_port.println(mac_first[0], HEX);
    debug_serial_port.print("EEPROM_ADRESS_MAC_2nd_Byte = ");
    debug_serial_port.print(EEPROM_ADRESS_MAC_2nd_Byte);
    debug_serial_port.print(" | MAC_2nd_Byte = ");
    debug_serial_port.println(mac_first[1], HEX);
    debug_serial_port.print("EEPROM_ADRESS_MAC_3rd_Byte = ");
    debug_serial_port.print(EEPROM_ADRESS_MAC_3rd_Byte);
    debug_serial_port.print(" | MAC_3rd_Byte = ");
    debug_serial_port.println(mac_first[2], HEX);
    debug_serial_port.print("EEPROM_ADRESS_MAC_4th_Byte = ");
    debug_serial_port.print(EEPROM_ADRESS_MAC_4th_Byte);
    debug_serial_port.print(" | MAC_4th_Byte = ");
    debug_serial_port.println(mac_first[3], HEX);
    debug_serial_port.print("EEPROM_ADRESS_MAC_5th_Byte = ");
    debug_serial_port.print(EEPROM_ADRESS_MAC_5th_Byte);
    debug_serial_port.print(" | MAC_5th_Byte = ");
    debug_serial_port.println(mac_first[4], HEX);
    debug_serial_port.print("EEPROM_ADRESS_MAC_6th_Byte = ");
    debug_serial_port.print(EEPROM_ADRESS_MAC_6th_Byte);
    debug_serial_port.print(" | MAC_6th_Byte = ");
    debug_serial_port.println(mac_first[5], HEX);
    debug_serial_port.print("EEPROM_ADRESS_RS485_serial_baud_rate = ");
    debug_serial_port.print(EEPROM_ADRESS_RS485_serial_baud_rate);
    debug_serial_port.print(" | RS485_serial_baud_rate = ");
    debug_serial_port.print(5);
    debug_serial_port.print(" --> ");
    debug_serial_port.println(baud_list[5]);
    debug_serial_port.print("EEPROM_ADRESS_RS485_serial_setting = ");
    debug_serial_port.print(EEPROM_ADRESS_RS485_serial_setting);
    debug_serial_port.print(" | RS485_serial_setting = ");
    debug_serial_port.print(4);
    debug_serial_port.print(" --> ");
    debug_serial_port.print(serial_config_list[4]);
    debug_serial_port.print(" --> ");
    if (4 == 4)
      debug_serial_port.println("SERIAL_8E1");
    debug_serial_port.print("EEPROM_ADRESS_num_of_sensor_per_station = ");
    debug_serial_port.print(EEPROM_ADRESS_num_of_sensor_per_station);
    debug_serial_port.print(" | num_of_sensor_per_station = ");
    debug_serial_port.println(num_of_sensor_per_station_first);
    debug_serial_port.print("EEPROM_ADRESS_station_address = ");
    debug_serial_port.print(EEPROM_ADRESS_station_address);
    debug_serial_port.print(" | station_address = ");
    debug_serial_port.println(station_address_first);
    debug_serial_port.print("EEPROM_ADRESS_PLC_offset = ");
    debug_serial_port.print(EEPROM_ADRESS_PLC_offset);
    debug_serial_port.print(" | PLC_offset = ");
    debug_serial_port.println(PLC_offset_first);
    debug_serial_port.print("onboard_inputs_data_type = ");
    debug_serial_port.println(onboard_inputs_data_type, BIN);
    debug_serial_port.println("done");
    debug_serial_port.println("*************************************************************");
  }
}

void write_setting_to_EEPROM()
{
  IP_1st_Byte = Mb.R[ModbusTCP_ADRESS_IP_1st_Byte];
  if (IP_1st_Byte >= 0 && IP_1st_Byte <= 255)
    EEPROM.write(EEPROM_ADRESS_IP_1st_Byte, IP_1st_Byte);

  IP_2nd_Byte = Mb.R[ModbusTCP_ADRESS_IP_2nd_Byte];
  if (IP_2nd_Byte >= 0 && IP_2nd_Byte <= 255)
    EEPROM.write(EEPROM_ADRESS_IP_2nd_Byte, IP_2nd_Byte);

  IP_3rd_Byte = Mb.R[ModbusTCP_ADRESS_IP_3rd_Byte];
  if (IP_3rd_Byte >= 0 && IP_3rd_Byte <= 255)
    EEPROM.write(EEPROM_ADRESS_IP_3rd_Byte, IP_3rd_Byte);

  IP_4th_Byte = Mb.R[ModbusTCP_ADRESS_IP_4th_Byte];
  if (IP_4th_Byte >= 0 && IP_4th_Byte <= 255)
    EEPROM.write(EEPROM_ADRESS_IP_4th_Byte, IP_4th_Byte);

  ////////////////////////////////////////////////////////////////////////////////////////////////////
  MAC_1st_Byte = Mb.R[ModbusTCP_ADRESS_MAC_1st_Byte];
  if (MAC_1st_Byte >= 0 && MAC_1st_Byte <= 255)
    EEPROM.write(EEPROM_ADRESS_MAC_1st_Byte, MAC_1st_Byte);

  MAC_2nd_Byte = Mb.R[ModbusTCP_ADRESS_MAC_2nd_Byte];
  if (MAC_2nd_Byte >= 0 && MAC_2nd_Byte <= 255)
    EEPROM.write(EEPROM_ADRESS_MAC_2nd_Byte, MAC_2nd_Byte);

  MAC_3rd_Byte = Mb.R[ModbusTCP_ADRESS_MAC_3rd_Byte];
  if (MAC_3rd_Byte >= 0 && MAC_3rd_Byte <= 255)
    EEPROM.write(EEPROM_ADRESS_MAC_3rd_Byte, MAC_3rd_Byte);

  MAC_4th_Byte = Mb.R[ModbusTCP_ADRESS_MAC_4th_Byte];
  if (MAC_4th_Byte >= 0 && MAC_4th_Byte <= 255)
    EEPROM.write(EEPROM_ADRESS_MAC_4th_Byte, MAC_4th_Byte);

  MAC_5th_Byte = Mb.R[ModbusTCP_ADRESS_MAC_5th_Byte];
  if (MAC_5th_Byte >= 0 && MAC_5th_Byte <= 255)
    EEPROM.write(EEPROM_ADRESS_MAC_5th_Byte, MAC_5th_Byte);

  MAC_6th_Byte = Mb.R[ModbusTCP_ADRESS_MAC_6th_Byte];
  if (MAC_6th_Byte >= 0 && MAC_6th_Byte <= 255)
    EEPROM.write(EEPROM_ADRESS_MAC_6th_Byte, MAC_6th_Byte);

  /////////////////////////////////////////////////////////////////////////////////////////////////
  RS485_serial_baud_rate = Mb.R[ModbusTCP_ADRESS_RS485_serial_baud_rate];
  if (RS485_serial_baud_rate >= 0 && RS485_serial_baud_rate <= 10)
    EEPROM.write(EEPROM_ADRESS_RS485_serial_baud_rate, RS485_serial_baud_rate);

  RS485_serial_setting = Mb.R[ModbusTCP_ADRESS_RS485_serial_setting];
  if (RS485_serial_setting >= 0 && RS485_serial_setting <= 7)
    EEPROM.write(EEPROM_ADRESS_RS485_serial_setting, RS485_serial_setting);

  //////////////////////////////////////////////////////////////////////////////////////////
  num_of_sensor_per_station = Mb.R[ModbusTCP_ADRESS_num_of_sensor_per_station];
  EEPROM.write(EEPROM_ADRESS_num_of_sensor_per_station, num_of_sensor_per_station);

  station_address = Mb.R[ModbusTCP_ADRESS_station_address];
  EEPROM.write(EEPROM_ADRESS_station_address, station_address);

  PLC_offset = Mb.R[ModbusTCP_ADRESS_PLC_offset];
  EEPROM.write(EEPROM_ADRESS_PLC_offset, PLC_offset);
  //////////////////////////////////////////////////////////////////////////////////////////
  onboard_inputs_data_type = Mb.R[ModbusTCP_ADRESS_onboard_inputs_data_type];
  EEPROM.write(EEPROM_ADRESS_onboard_inputs_data_type, onboard_inputs_data_type);


  if (config_Serial_debug)
  {
    debug_serial_port.println("*************************************************************");
    debug_serial_port.println("write_setting_to_EEPROM()");
    debug_serial_port.print("EEPROM_ADRESS_IP_1st_Byte = ");
    debug_serial_port.print(EEPROM_ADRESS_IP_1st_Byte);
    debug_serial_port.print(" | IP_1st_Byte = ");
    debug_serial_port.println(IP_1st_Byte);
    debug_serial_port.print("EEPROM_ADRESS_IP_2nd_Byte = ");
    debug_serial_port.print(EEPROM_ADRESS_IP_2nd_Byte);
    debug_serial_port.print(" | IP_2nd_Byte = ");
    debug_serial_port.println(IP_2nd_Byte);
    debug_serial_port.print("EEPROM_ADRESS_IP_3rd_Byte = ");
    debug_serial_port.print(EEPROM_ADRESS_IP_3rd_Byte);
    debug_serial_port.print(" | IP_3rd_Byte = ");
    debug_serial_port.println(IP_3rd_Byte);
    debug_serial_port.print("EEPROM_ADRESS_IP_4th_Byte = ");
    debug_serial_port.print(EEPROM_ADRESS_IP_4th_Byte);
    debug_serial_port.print(" | IP_4th_Byte = ");
    debug_serial_port.println(IP_4th_Byte);
    debug_serial_port.print("EEPROM_ADRESS_MAC_1st_Byte = ");
    debug_serial_port.print(EEPROM_ADRESS_MAC_1st_Byte);
    debug_serial_port.print(" | MAC_1st_Byte = ");
    debug_serial_port.println(MAC_1st_Byte, HEX);
    debug_serial_port.print("EEPROM_ADRESS_MAC_2nd_Byte = ");
    debug_serial_port.print(EEPROM_ADRESS_MAC_2nd_Byte);
    debug_serial_port.print(" | MAC_2nd_Byte = ");
    debug_serial_port.println(MAC_2nd_Byte, HEX);
    debug_serial_port.print("EEPROM_ADRESS_MAC_3rd_Byte = ");
    debug_serial_port.print(EEPROM_ADRESS_MAC_3rd_Byte);
    debug_serial_port.print(" | MAC_3rd_Byte = ");
    debug_serial_port.println(MAC_3rd_Byte, HEX);
    debug_serial_port.print("EEPROM_ADRESS_MAC_4th_Byte = ");
    debug_serial_port.print(EEPROM_ADRESS_MAC_4th_Byte);
    debug_serial_port.print(" | MAC_4th_Byte = ");
    debug_serial_port.println(MAC_4th_Byte, HEX);
    debug_serial_port.print("EEPROM_ADRESS_MAC_5th_Byte = ");
    debug_serial_port.print(EEPROM_ADRESS_MAC_5th_Byte);
    debug_serial_port.print(" | MAC_5th_Byte = ");
    debug_serial_port.println(MAC_5th_Byte, HEX);
    debug_serial_port.print("EEPROM_ADRESS_MAC_6th_Byte = ");
    debug_serial_port.print(EEPROM_ADRESS_MAC_6th_Byte);
    debug_serial_port.print(" | MAC_6th_Byte = ");
    debug_serial_port.println(MAC_6th_Byte, HEX);
    debug_serial_port.print("EEPROM_ADRESS_RS485_serial_baud_rate = ");
    debug_serial_port.print(EEPROM_ADRESS_RS485_serial_baud_rate);
    debug_serial_port.print(" | RS485_serial_baud_rate = ");
    debug_serial_port.print(RS485_serial_baud_rate);
    debug_serial_port.print(" --> ");
    debug_serial_port.println(baud_list[RS485_serial_baud_rate]);
    debug_serial_port.print("EEPROM_ADRESS_RS485_serial_setting = ");
    debug_serial_port.print(EEPROM_ADRESS_RS485_serial_setting);
    debug_serial_port.print(" | RS485_serial_setting = ");
    debug_serial_port.print(RS485_serial_setting);
    debug_serial_port.print(" --> ");
    debug_serial_port.print(serial_config_list[RS485_serial_setting]);
    debug_serial_port.print(" --> ");
    if (RS485_serial_setting == 0)
      debug_serial_port.println("SERIAL_8N1");
    if (RS485_serial_setting == 1)
      debug_serial_port.println("SERIAL_8N2");
    if (RS485_serial_setting == 2)
      debug_serial_port.println("SERIAL_9N1");
    if (RS485_serial_setting == 3)
      debug_serial_port.println("SERIAL_9N2");
    if (RS485_serial_setting == 4)
      debug_serial_port.println("SERIAL_8E1");
    if (RS485_serial_setting == 5)
      debug_serial_port.println("SERIAL_8E2");
    if (RS485_serial_setting == 6)
      debug_serial_port.println("SERIAL_8O1");
    if (RS485_serial_setting == 7)
      debug_serial_port.println("SERIAL_8O2");
    debug_serial_port.print("EEPROM_ADRESS_num_of_sensor_per_station = ");
    debug_serial_port.print(EEPROM_ADRESS_num_of_sensor_per_station);
    debug_serial_port.print(" | num_of_sensor_per_station = ");
    debug_serial_port.println(num_of_sensor_per_station);
    debug_serial_port.print("EEPROM_ADRESS_station_address = ");
    debug_serial_port.print(EEPROM_ADRESS_station_address);
    debug_serial_port.print(" | station_address = ");
    debug_serial_port.println(station_address);
    debug_serial_port.print("EEPROM_ADRESS_PLC_offset = ");
    debug_serial_port.print(EEPROM_ADRESS_PLC_offset);
    debug_serial_port.print(" | PLC_offset = ");
    debug_serial_port.println(PLC_offset);
    debug_serial_port.print("onboard_inputs_data_type = ");
    debug_serial_port.println(onboard_inputs_data_type, BIN);
    debug_serial_port.println("done");
    debug_serial_port.println("*************************************************************");
  }
}
