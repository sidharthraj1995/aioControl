/************************************
 *      CONTROL IO HEADER FILE      *
 * GENERAL IO STATES AND CONDITIONS *
 ************************************/
#ifndef A_CONTROLIO_h
#define A_CONTROLIO_h

#include <Arduino.h>
#include <Logging.h>
#include <enum.h>

/* DO NOT CHANGE ANY DEFINEs BELOW */

/**************************
 * GENERAL LOGICAL STATES *
 **************************/
#define DIO_LOW 0
#define DIO_HIGH 1

/*****************************
 * GENERAL DIGITAL IO STATES *
 *****************************/
#define DIO_ON_II DIO_HIGH
#define DIO_OFF_II DIO_LOW
#define DIO_LE_II DIO_LOW  // Transition from OFF to ON
#define DIO_TE_II DIO_HIGH // Transition from ON to OFF

/****************************
 * GENERAL NC AND NO STATES *
 ****************************/
#define DIO_NO_ON_II DIO_HIGH
#define DIO_NO_OFF_II DIO_LOW

#define DIO_NC_ON_II DIO_LOW
#define DIO_NC_OFF_II DIO_HIGH

/**********************
 * GENERAL ANALOG IOS *
 **********************/
#define AIO_II DIO_LOW

// Length of Controller Name string
#define MAX_CTL_NAME 10

// Length of Sensor Name string
#define MAX_SENSOR_NAME 10

// Max quantity of allowed sensors to be connected to a controller simulteneously
#define MAX_QTY_SENSOR 5


enum ioType
{
    TYPE_DEFAULT = 0,
    TYPE_INPUT,
    TYPE_OUTPUT
};

/******************
 * GPIO PORT TYPES *
 ******************/
enum portType
{
    PORT_DEFAULT = 0,
    PORT_DIN,  // Digital Input
    PORT_DOUT, // Digital Output
    PORT_AIN,  // Analog Input
    PORT_AOUT, // Analog Output
    PORT_INTP  // Interrupt pin
};

enum PIN_MODE
{
    PIN_DEFAULT = 0,
    PIN_OUTPUT,
    PIN_INPUT,
    PIN_INPUT_PULLUP,
    PIN_INPUT_PULLDOWN
};

/**************************
 * GENERAL HARDWARE TYPES *
 **************************/
enum controllerType
{
    CTL_DEFAULT = 0,
    CTL_GENERAL,         // Hardware Type General
    CTL_ESP01,           // ESP-01
    CTL_ESP8266,         // ESP8266 General devKit
    CTL_ESP12E,          // ESP8266 type 12E
    CTL_ESP12F,          // ESP8266 type 12F
    CTL_ESP32,           // ESP32 General devKit
    CTL_ESP32_CAM,       // ESP32 Cam devKit
    CTL_ARDUINO_UNO,     // Arduino Uno
    CTL_ARDUINO_MEGA,    // Arduino Mega
    CTL_ARDUINO_LEONARDO // Arduino Leonardo
};

/*************************
 *  GENERAL NODE TYPES   *
 *************************/
enum nodeType
{
    NODE_DEFAULT = 0,
    NODE_DIGITAL,
    NODE_ANALOG
};

/*************************
 *   CUSTOM STRUCTURES   *
 * TO DEFINE CONTROLLERS *
 *      AND SENSORS      *
 *************************/
// todo  this struct needs more variables and information
typedef struct
{
    char Name[MAX_CTL_NAME]; // Name of the Controller
    controllerType Type;     // Type of Controller
    uint16_t pinsUsed;       // Total Number of GPIO pins used, set to -1 for no sensors
} OBJ_CONTROLLER;

// todo  finish this struct, add all info and organize it
typedef struct
{
    char Name[MAX_SENSOR_NAME]; // Name of the sensor
    ioType SensorType;          // Type: Input or output
    nodeType SignalType;        // Digital or Analog
    CTL_LIST masterCTL;         // Connected Controller
    byte PIN;                   // Connected PIN
    PIN_MODE senMode;           // Specific the mode type
} OBJ_SENSOR;

#endif