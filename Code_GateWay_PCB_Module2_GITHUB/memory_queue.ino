
void save_to_mem(uint16_t data_2_sava)
{
  buffer.push(data_2_sava);
}

uint16_t read_lastData_from_mem()
{
  uint16_t read_to_return;
  if (buffer.size() > 0)
  {
    read_to_return = buffer.shift();
  }
  else
  {
    read_to_return = 0;
  }

  return read_to_return;
}



void printBuffer() {
  if (buffer.isEmpty())
  {
    debug_serial_port.println("empty");
  }
  else
  {
    debug_serial_port.print("[");
    for (decltype(buffer)::index_t i = 0; i < buffer.size() - 1; i++)
    {
      debug_serial_port.print(buffer[i]);
      debug_serial_port.print(",");
    }
    debug_serial_port.print(buffer[buffer.size() - 1]);
    debug_serial_port.print("] (");
    debug_serial_port.print(buffer.size());
    debug_serial_port.print("/");
    debug_serial_port.print(buffer.size() + buffer.available());
    if (buffer.isFull())
    {
      debug_serial_port.print(" full");
    }
    debug_serial_port.println(")");
  }
}
