void print_config()
{
  debug_serial_port.println("*************************************************************");
  debug_serial_port.println("print_config()");
  debug_serial_port.print("This station IP : ");
  debug_serial_port.print(ip[0]);
  debug_serial_port.print(".");
  debug_serial_port.print(ip[1]);
  debug_serial_port.print(".");
  debug_serial_port.print(ip[2]);
  debug_serial_port.print(".");
  debug_serial_port.println(ip[3]);

  debug_serial_port.print("This station MAC : ");
  debug_serial_port.print(mac[0], HEX);
  debug_serial_port.print(".");
  debug_serial_port.print(mac[1], HEX);
  debug_serial_port.print(".");
  debug_serial_port.print(mac[2], HEX);
  debug_serial_port.print(".");
  debug_serial_port.print(mac[3], HEX);
  debug_serial_port.print(".");
  debug_serial_port.print(mac[4], HEX);
  debug_serial_port.print(".");
  debug_serial_port.println(mac[5], HEX);

  debug_serial_port.print("this station RS485 Serial baud rate : ");
  debug_serial_port.println(baud_list[RS485_serial_baud_rate]);

  debug_serial_port.print("this station RS485 Serial setting : ");
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

  debug_serial_port.print("num_of_sensor_per_station = ");
  debug_serial_port.println(num_of_sensor_per_station);

  debug_serial_port.print("station_address = ");
  debug_serial_port.println(station_address);

  debug_serial_port.print("PLC_offset = ");
  debug_serial_port.println(PLC_offset);
  debug_serial_port.print("onboard_inputs_data_type = ");
  debug_serial_port.println(onboard_inputs_data_type, BIN);
  debug_serial_port.println("done");
  debug_serial_port.println("*************************************************************");
}
