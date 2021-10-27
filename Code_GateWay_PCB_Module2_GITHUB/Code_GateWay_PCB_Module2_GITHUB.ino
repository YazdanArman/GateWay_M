/*
 * this is Final Code
 */

#include <SPI.h>
#include <Ethernet.h>
#include <utility/w5100.h>
#include "Mudbus.h"
#include <ModbusMaster.h>
#include <CircularBuffer.h>
#include <EEPROM.h>

#define MAX485_DE_pin PB1

#define W5100_NSS_pin PA4

#define connection_indicator_LED_pin PB12
#define heart_beat_LED_pin PB13

#define config_mode_enb_pin PA9

#define LM35_pin PA0
uint16_t analog_read_vale = 0;
float analog_voltage = 0;
float temperature_value = 0;

#define debug_serial_port Serial2
#define RS485_serial_port Serial3

#define sensor_1 PA15
#define sensor_2 PB3
#define sensor_3 PA12
#define sensor_4 PA11

#define on_board_led PC13

#define Sensor_1_code 1
#define Sensor_2_code 2
#define Sensor_3_code 3
#define Sensor_4_code 4
#define Sensor_5_code 5              // this is a virtual input on Mb.C[15]

#define DIV_NUM 1000
#define MUL_NUM 1000
#define MAX_TIME 30000

#define rising_edge_val 26000
#define falling_edge_val 13000

const int FIFO_SIZE = 100;

CircularBuffer<int, FIFO_SIZE> buffer;

int first = 0;

int reading_1 = 1;
int reading_2 = 1;
int reading_3 = 1;
int reading_4 = 1;
int reading_5 = 1;

double timeOn_1 = 0;
uint16_t timeOn_1_coded = 0;
uint16_t edge_1_coded = 0;
double StartTime_1 = 0;
double EndTime_1 = 0;
bool recordflag_1 = 0;
int buttonState_1;
int lastButtonState_1 = HIGH;
int lastDebounceTime_1 = 0;

double timeOn_2 = 0;
uint16_t timeOn_2_coded = 0;
uint16_t edge_2_coded = 0;
double StartTime_2 = 0;
double EndTime_2 = 0;
bool recordflag_2 = 0;
int buttonState_2;
int lastButtonState_2 = HIGH;
int lastDebounceTime_2 = 0;

double timeOn_3 = 0;
uint16_t timeOn_3_coded = 0;
uint16_t edge_3_coded = 0;
double StartTime_3 = 0;
double EndTime_3 = 0;
bool recordflag_3 = 0;
int buttonState_3;
int lastButtonState_3 = HIGH;
int lastDebounceTime_3 = 0;

double timeOn_4 = 0;
uint16_t timeOn_4_coded = 0;
uint16_t edge_4_coded = 0;
double StartTime_4 = 0;
double EndTime_4 = 0;
bool recordflag_4 = 0;
int buttonState_4;
int lastButtonState_4 = HIGH;
int lastDebounceTime_4 = 0;

double timeOn_5 = 0;
uint16_t timeOn_5_coded = 0;
uint16_t edge_5_coded = 0;
double StartTime_5 = 0;
double EndTime_5 = 0;
bool recordflag_5 = 0;
int buttonState_5;
int lastButtonState_5 = HIGH;
int lastDebounceTime_5 = 0;

int debounceDelay = 50;
int min_time_to_send = 60;

Mudbus Mb;
ModbusMaster node;

union ByteFloatUnion
{
  uint16_t byteformat[2];
  float floatformat;
};

union ByteINT64Union
{
  uint16_t byteformat[4];
  int64_t int64format;
};


ByteFloatUnion val;
ByteINT64Union val2;

uint8_t mac[]     = {0x90, 0xA2, 0xDA, 0x00, 0x51, 0x06};
uint8_t ip[]      = {192, 168, 1, 238};

uint8_t mac_first[]     = {0x90, 0xA2, 0xDA, 0x00, 0x51, 0x06};
uint8_t ip_first[]      = {192, 168, 1, 238};

#define num_of_sensor_per_station_first 5
#define station_address_first 1
#define PLC_offset_first 40
#define onboard_inputs_data_type_first 938
/*
  // 341 all inputs send on_timer data
  // 853 input 1, 2, 3, 4 send on_timer and input 5 sends edge and on_timer
  // 1023 all inputs send edge and on_timer
  // 938 input 1, 2, 3, 4 send edge and input 5 sends edge and on_timer
*/

unsigned long now;
unsigned long last_sent;
const unsigned long interval = 100;
bool Heart_Beat_state = 0;

int resault;

int this_node_virtual = 13;

bool config_Serial_debug = true;
bool modbusTCP_Serial_debug = true;
bool modbusRTU_Serial_debug = true;
bool onBoard_sensor_data_Serial_debug = true;

bool config_mode_enb = false;

byte incomingByte;
bool flag = 0;

uint16_t ModbusTCP_ADRESS_config_change_flag = 10;

uint16_t IP_1st_Byte;
uint16_t EEPROM_ADRESS_IP_1st_Byte = 1;
uint16_t ModbusTCP_ADRESS_IP_1st_Byte = 1;

uint16_t IP_2nd_Byte;
uint16_t EEPROM_ADRESS_IP_2nd_Byte = 2;
uint16_t ModbusTCP_ADRESS_IP_2nd_Byte = 2;

uint16_t IP_3rd_Byte;
uint16_t EEPROM_ADRESS_IP_3rd_Byte = 3;
uint16_t ModbusTCP_ADRESS_IP_3rd_Byte = 3;

uint16_t IP_4th_Byte;
uint16_t EEPROM_ADRESS_IP_4th_Byte = 4;
uint16_t ModbusTCP_ADRESS_IP_4th_Byte = 4;

uint16_t MAC_1st_Byte;
uint16_t EEPROM_ADRESS_MAC_1st_Byte = 5;
uint16_t ModbusTCP_ADRESS_MAC_1st_Byte = 5;

uint16_t MAC_2nd_Byte;
uint16_t EEPROM_ADRESS_MAC_2nd_Byte = 6;
uint16_t ModbusTCP_ADRESS_MAC_2nd_Byte = 6;

uint16_t MAC_3rd_Byte;
uint16_t EEPROM_ADRESS_MAC_3rd_Byte = 7;
uint16_t ModbusTCP_ADRESS_MAC_3rd_Byte = 7;

uint16_t MAC_4th_Byte;
uint16_t EEPROM_ADRESS_MAC_4th_Byte = 8;
uint16_t ModbusTCP_ADRESS_MAC_4th_Byte = 8;

uint16_t MAC_5th_Byte;
uint16_t EEPROM_ADRESS_MAC_5th_Byte = 9;
uint16_t ModbusTCP_ADRESS_MAC_5th_Byte = 9;

uint16_t MAC_6th_Byte;
uint16_t EEPROM_ADRESS_MAC_6th_Byte = 10;
uint16_t ModbusTCP_ADRESS_MAC_6th_Byte = 10;

uint16_t RS485_serial_baud_rate;
uint16_t EEPROM_ADRESS_RS485_serial_baud_rate = 11;
uint16_t ModbusTCP_ADRESS_RS485_serial_baud_rate = 11;
uint32 baud_list[] = {300,          //0
                      1200,         //1
                      2400,         //2
                      4800,         //3
                      9600,         //4
                      19200,        //5
                      38400,        //6
                      57600,        //7
                      74880,        //8
                      115200,       //9
                      230400        //10
                     };

uint16_t RS485_serial_setting;
uint16_t EEPROM_ADRESS_RS485_serial_setting = 12;
uint16_t ModbusTCP_ADRESS_RS485_serial_setting = 12;
uint8_t serial_config_list[] = {SERIAL_8N1,           //0
                                SERIAL_8N2,           //1
                                SERIAL_9N1,           //2
                                SERIAL_9N2,           //3
                                SERIAL_8E1,           //4
                                SERIAL_8E2,           //5
                                SERIAL_8O1,           //6
                                SERIAL_8O2            //7
                               };

uint16_t num_of_sensor_per_station;
uint16_t EEPROM_ADRESS_num_of_sensor_per_station = 13;
uint16_t ModbusTCP_ADRESS_num_of_sensor_per_station = 13;

uint16_t station_address;
uint16_t EEPROM_ADRESS_station_address = 14;
uint16_t ModbusTCP_ADRESS_station_address = 14;

uint16_t PLC_offset;
uint16_t EEPROM_ADRESS_PLC_offset = 15;
uint16_t ModbusTCP_ADRESS_PLC_offset = 15;

uint8_t  onboard_inputs_data_type_array[num_of_sensor_per_station_first];
uint16_t onboard_inputs_data_type;
uint16_t EEPROM_ADRESS_onboard_inputs_data_type = 16;
uint16_t ModbusTCP_ADRESS_onboard_inputs_data_type = 16;

#define temperature_filter_WINDOW_SIZE 200

int temperature_filter_INDEX1 = 0;
float temperature_filter_VALUE1 = 0;
float temperature_filter_SUM1 = 0;
float temperature_filter_READINGS1[temperature_filter_WINDOW_SIZE];
float temperature_filter_AVERAGED1 = 0;
float temperature_filter_val1 = 0;

void setup()
{
  enableDebugPorts();
  Serial.end();

  serial_debug_init();

  pin_configuration();

  config_mode_enb = !digitalRead(config_mode_enb_pin);

  Ethernet.init(W5100_NSS_pin);

  if (0)
    first_time_EEPROM_write();

  read_and_apply_settings_from_EEPROM();

  if (config_Serial_debug)
  {
    print_config();
  }

  node.preTransmission(preTransmission);
  node.postTransmission(postTransmission);

  Mb.TCP_callback_READ_REG(callback_READ_REG);
  Mb.TCP_callback_WRITE_SINGLE_COIL(callback_WRITE_SINGLE_COIL);
  Mb.TCP_callback_READ_COILS(callback_READ_COILS);
  Mb.TCP_callback_WRITE_MULTIPLE_COILS(callback_WRITE_MULTIPLE_COILS);
  Mb.TCP_callback_WRITE_MULTIPLE_REGISTERS(callback_WRITE_MULTIPLE_REGISTERS);
  Mb.TCP_callback_WRITE_SINGLE_REGISTER(callback_WRITE_SINGLE_REGISTER);
}

void loop()
{
  Mb.Run();

  input_timing_handler();
  temperature_handler();

  //  if (Mb.available_flag == 1)
  //  {
  //    Mb.available_flag = 0;
  //  }

  //  digitalWrite(on_board_led, !Mb.C[15]);

  if (Mb.C[ModbusTCP_ADRESS_config_change_flag] == 1)
  {
    //go to config mode
    write_setting_to_EEPROM();
    read_and_apply_settings_from_EEPROM();

    if (config_Serial_debug)
    {
      print_config();
    }

    Mb.C[ModbusTCP_ADRESS_config_change_flag] = 0;
  }


  now = millis();
  if (now - last_sent >= interval)
  {
    last_sent = now;
    Heart_Beat_state ^= 1;
    digitalWrite(heart_beat_LED_pin, Heart_Beat_state);

    temperature_update();
  }

  delay(10);
}
