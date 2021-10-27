void preTransmission()
{
  digitalWrite(MAX485_DE_pin, HIGH);
}

void postTransmission()
{
  digitalWrite(MAX485_DE_pin, LOW);
}

void callback_WRITE_MULTIPLE_COILS(uint16_t slave_ID, uint16_t FC_code, uint16_t start_address, uint16_t len)
{
  digitalWrite(connection_indicator_LED_pin, HIGH);
  if (modbusTCP_Serial_debug)
  {
    debug_serial_port.print("slave_ID = ");
    debug_serial_port.print(slave_ID);
    debug_serial_port.print(" | FC_code = ");
    debug_serial_port.print(FC_code);
    debug_serial_port.print(" | start_address = ");
    debug_serial_port.print(start_address);
    debug_serial_port.print(" | len = ");
    debug_serial_port.println(len);
  }
  digitalWrite(connection_indicator_LED_pin, LOW);
}

void callback_WRITE_MULTIPLE_REGISTERS(uint16_t slave_ID, uint16_t FC_code, uint16_t start_address, uint16_t len)
{
  digitalWrite(connection_indicator_LED_pin, HIGH);
  if (modbusTCP_Serial_debug)
  {
    debug_serial_port.print("slave_ID = ");
    debug_serial_port.print(slave_ID);
    debug_serial_port.print(" | FC_code = ");
    debug_serial_port.print(FC_code);
    debug_serial_port.print(" | start_address = ");
    debug_serial_port.print(start_address);
    debug_serial_port.print(" | len = ");
    debug_serial_port.println(len);
  }
  digitalWrite(connection_indicator_LED_pin, LOW);
}

void callback_WRITE_SINGLE_REGISTER(uint16_t slave_ID, uint16_t FC_code, uint16_t start_address, uint16_t data)
{
  digitalWrite(connection_indicator_LED_pin, HIGH);
  if (modbusTCP_Serial_debug)
  {
    debug_serial_port.print("slave_ID = ");
    debug_serial_port.print(slave_ID);
    debug_serial_port.print(" | FC_code = ");
    debug_serial_port.print(FC_code);
    debug_serial_port.print(" | start_address = ");
    debug_serial_port.print(start_address);
    debug_serial_port.print(" | data = ");
    debug_serial_port.println(data);
  }

  if (FC_code == 6)
  {
    if (slave_ID == this_node_virtual)
    {

    }
    else
    {
      node.begin(slave_ID, RS485_serial_port);
      resault = node.writeSingleRegister(start_address, data);
      if (modbusRTU_Serial_debug)
      {
        debug_serial_port.print("writeSingleRegister");
        debug_serial_port.print(" | resault : ");
        debug_serial_port.println(resault, HEX);
      }
    }
  }
  digitalWrite(connection_indicator_LED_pin, LOW);
}

void callback_READ_COILS(uint16_t slave_ID, uint16_t FC_code, uint16_t start_address, uint16_t coil_num)
{
  digitalWrite(connection_indicator_LED_pin, HIGH);
  if (modbusTCP_Serial_debug)
  {
    debug_serial_port.print("slave_ID = ");
    debug_serial_port.print(slave_ID);
    debug_serial_port.print(" | FC_code = ");
    debug_serial_port.print(FC_code);
    debug_serial_port.print(" | start_address = ");
    debug_serial_port.print(start_address);
    debug_serial_port.print(" | coil_num = ");
    debug_serial_port.println(coil_num);
  }
  if (FC_code == 1)
  {
    if (slave_ID == this_node_virtual)
    {
      for (int k = start_address; k < start_address + coil_num; k++)
      {
        //        pinMode(Header_pins[k], INPUT_PULLDOWN);
        //        Mb.C[k] = digitalRead(Header_pins[k]);
      }
    }
    else
    {
      node.begin(slave_ID, RS485_serial_port);
      resault = node.readCoils(start_address, coil_num);
      if (modbusRTU_Serial_debug)
      {
        debug_serial_port.print("readCoils");
        debug_serial_port.print(" | resault : ");
        debug_serial_port.println(resault, HEX);
      }
      if (resault == node.ku8MBSuccess)
      {
        for (int k = start_address; k < start_address + coil_num; k++)
        {
          Mb.C[k] = (1 << (k - start_address)) & node.getResponseBuffer(0);
        }
      }
    }
  }
  digitalWrite(connection_indicator_LED_pin, LOW);
}

void callback_WRITE_SINGLE_COIL(uint16_t slave_ID, uint16_t FC_code, uint16_t start_address, uint16_t data)
{
  digitalWrite(connection_indicator_LED_pin, HIGH);
  if (modbusTCP_Serial_debug)
  {
    debug_serial_port.print("slave_ID = ");
    debug_serial_port.print(slave_ID);
    debug_serial_port.print(" | FC_code = ");
    debug_serial_port.print(FC_code);
    debug_serial_port.print(" | start_address = ");
    debug_serial_port.print(start_address);
    debug_serial_port.print(" | data = ");
    debug_serial_port.println(data);
  }


  if (FC_code == 5)
  {
    if (slave_ID == this_node_virtual)
    {
      //pinMode(Header_pins[start_address], OUTPUT);
      //digitalWrite(Header_pins[start_address], data);
    }
    else
    {
      node.begin(slave_ID, RS485_serial_port);
      resault = node.writeSingleCoil(start_address, data);
      if (modbusRTU_Serial_debug)
      {
        debug_serial_port.print("writeSingleCoil");
        debug_serial_port.print(" | resault : ");
        debug_serial_port.println(resault, HEX);
      }
    }
  }
  digitalWrite(connection_indicator_LED_pin, LOW);
}

void callback_READ_REG(uint16_t slave_ID, uint16_t FC_code, uint16_t start_address, uint16_t reg_num)
{
  digitalWrite(connection_indicator_LED_pin, HIGH);
  if (modbusTCP_Serial_debug)
  {
    debug_serial_port.print("slave_ID = ");
    debug_serial_port.print(slave_ID);
    debug_serial_port.print(" | FC_code = ");
    debug_serial_port.print(FC_code);
    debug_serial_port.print(" | start_address = ");
    debug_serial_port.print(start_address);
    debug_serial_port.print(" | reg_num = ");
    debug_serial_port.println(reg_num);
  }

  if (FC_code == 3)
  {
    if (slave_ID == this_node_virtual)
    {

    }
    else
    {
      node.begin(slave_ID, RS485_serial_port);
      resault = node.readHoldingRegisters(start_address, reg_num);
      if (modbusRTU_Serial_debug)
      {
        debug_serial_port.print("readHoldingRegisters");
        debug_serial_port.print(" | resault : ");
        debug_serial_port.println(resault, HEX);
      }
      if (resault == node.ku8MBSuccess)
      {
        for (int k = start_address; k < start_address + reg_num; k++)
        {
          Mb.R[k] = node.getResponseBuffer(k - start_address);
        }
      }
      else
      {
        for (int k = start_address; k < start_address + reg_num; k++)
        {
          Mb.R[k] = -1;
        }
      }
    }
  }
  if (FC_code == 4)
  {
    if (slave_ID == this_node_virtual)
    {

      if (start_address == 41)
      {
        if (reg_num == 1)
        {
          Mb.R[41] = send_me_input_pins_data(41, 1);
        }
      }

      if (start_address == 61)
      {
        if (reg_num == 1)
        {
          Mb.R[61] = buffer.size();
        }
      }

      if (start_address == 1)
      {
        val2.int64format = millis();
        Mb.R[1] = val2.byteformat[0];
        Mb.R[2] = val2.byteformat[1];
        Mb.R[3] = val2.byteformat[2];
        Mb.R[4] = val2.byteformat[3];
      }

      if (start_address == 5)
      {
        analog_read_vale = analogRead(LM35_pin);
        analog_voltage = analog_read_vale * (3.3 / 4095);
        temperature_value = analog_voltage * 100.0;

        Mb.R[5] = val.byteformat[0];
        Mb.R[6] = val.byteformat[1];
      }
    }
    else
    {
      node.begin(slave_ID, RS485_serial_port);
      resault = node.readInputRegisters(start_address, reg_num);
      if (modbusRTU_Serial_debug)
      {
        debug_serial_port.print("readInputRegisters");
        debug_serial_port.print(" | resault : ");
        debug_serial_port.println(resault, HEX);
      }
      if (resault == node.ku8MBSuccess)
      {
        for (int k = start_address; k < start_address + reg_num; k++)
        {
          Mb.R[k] = node.getResponseBuffer(k - start_address);
        }
      }
      else
      {
        for (int k = start_address; k < start_address + reg_num; k++)
        {
          Mb.R[k] = -1;
        }
      }
    }
  }
  digitalWrite(connection_indicator_LED_pin, LOW);
}
