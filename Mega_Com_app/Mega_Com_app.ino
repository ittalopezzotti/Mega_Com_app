/**********************************************************************************************************************************
 ************************** PROJECT:: Monitoraggio della qualità dell'aria per settore*** PROTOTIPO::HASNECOD**********************
*************1) HAT SENSOR NETWORK FOR CONTAMINANT DETECTION***********************************************************************
*************2) MATERIALS, PROCEDURE AND CONSTRUCTION OF A SENSORIZED HAT**********************************************************
****** 3) DATA ACQUISITION, GLOBAL POSITIONING AND ARTIFICIAL VISION USING A HAT-MOUNTED SYSTEM WITH CAMERA AND GPRS***************
***********************************************************************************************************************************
******************************************************Authors**********************************************************************
********************************************* ITTALO PEZZOTTI ESCOBAR**************************************************************
********************************************* GIOVANNI PAOLO VIGANO ***************************************************************
********************************************* FABRIZIO SILVA **********************************************************************
********************************************* GIANNI PEZZOTTI ESCOBAR**************************************************************
******Name file: Mega_Com_app.ino******* || Ver:: 1.0.*****************************************************************************
**Address File   :D:\0_0_2_Repository_GIT_SourceTree\Mega_Com_app******************************************************************
**File analisis:D:\0_0_2_Repository_GIT_SourceTree\Hasnecood\1_Bluetooth_Mega_Hasnecod_28092023\1_Bluetooth_Mega_Hasnecod_28092023*
**Name file github:::  E:\1_0_3_Firmware_Publicaciones\Mega_Com_App****************************************************************
**Version:    Version II***********************************************************************************************************
*********OBJECTIVE OF THE PROGRAM:::: TRANSMISSION OF SENSOR DATA IN DIFFERENT MODALITIES******************************************
*********MODALITIES: CELL PHONE, TABLET, SERVER, COMPUTER**************************************************************************
**********************************************************************************************************************************/
/*Configuration HASNECOD 07072022
  ==================================================
  :::::::  OUTPUT ACTUATORS :::::::::::::::::::::
  :::::::ARDUINO MEGA PIN-OUT:::::::::::::::::::
  ==================================================
  =====================================
  ::::::::::I2C BUS CONTROL DEVICES::::
  =====================================
  :::::::::    BLUETOOTH     ::::::::::
  :::::::::  HC-05 ||HC-06   ::::::::::
  BLUETOOTH_NAME:: HASNE_TABLET
  PIN 14 (TX3)  || EAGLE BLUE_P1 (RX)
  PIN 15 (RX3)  || EAGLE BLUE_P2 (TX)
  ||||||||||||||||||||||||||||||||||||||
  =====================================
  ||||||||||||||||||||||||||||||||||||||
  =====================================*/

//Include the SoftwareSerial library
#include "SoftwareSerial.h"

//Create a new software  serial
SoftwareSerial bluetooth1(2, 3); // TX, RX (Bluetooth)
SoftwareSerial bluetooth2(4, 5); // TX, RX (Bluetooth)
//SoftwareSerial bluetooth2(1, 0); // TX, RX (Bluetooth)
  
const int ledPin = 13; // the pin that the LED is attached to
const int ledPin2 = 12; // the pin that the LED is attached to
int incomingByte;      // a variable to read incoming serial data into
int incomingByte2;      // a variable to read incoming serial data into
void setup() {
  //Initialize the software serial
  Serial.begin(9600);
  bluetooth1.begin(9600);
  
  bluetooth2.begin(9600);
 // bluetooth.begin(9600);
  
  // initialize the LED pin as an output:
  pinMode(ledPin, OUTPUT);
}



void loop() {
  // see if there's incoming serial data:
  if ((bluetooth1.available() > 0) || (bluetooth2.available()) > 0)
  {
    // read the serial buffer:
    incomingByte = bluetooth1.read();
    // if  N turn on the LED:
    if (incomingByte == 'N') {
      digitalWrite(ledPin, HIGH);
      bluetooth1.println("LED: ON");
    }
    // if  N turn OFF the LED:
    if (incomingByte == 'M') {
      digitalWrite(ledPin, LOW);
      bluetooth1.println("LED: OFF");
    }
  }

  // incoming serial data:
 // else if (bluetooth2.available() > 0) {
    // read the serial buffer:
    incomingByte2 = bluetooth2.read();
   // if  N turn on the LED:
    if (incomingByte2 == 'G') {
      digitalWrite(ledPin2, HIGH);
      bluetooth2.println("LED: ON");
    }
   // if  N turn OFF the LED:
    if (incomingByte2 == 'W') {
      digitalWrite(ledPin2, LOW);
      bluetooth2.println("LED: OFF");
    }
  }

 
