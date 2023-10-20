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
**Version:    Version III *********************************************************************************************************
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
void setup() {
  // put your setup code here, to run once:
  //Serial.begin(9600); //Tx0 and Rx0  //Set Baud Rate to 9600 for Serial Communication Tx0 and Rx0
  Serial3.begin(9600);  //Tx1 and Rx1  //Connected to Bluetooth Module HC-05 (Bluetooth 2.0)
  //Serial2;  //Tx2 and Rx2
  //Serial3;  //Tx3 and Rx3

  pinMode(9, OUTPUT);  //Set Pin 13 as Output (Connected to LED)
 
//  Serial.println("press \"a\" or \"A\" to switch ON the LED");  //To Desktop
//  Serial.println("press \"b\" or \"B\" to switch OFF the LED");
  Serial3.println("press \"a\" or \"A\" to switch ON BLUE  the LED"); //To mobile
  Serial3.println("press \"b\" or \"B\" to switch OFF BLUE the LED");
}

void loop() {
  // put your main code here, to run repeatedly:
  
  if(Serial3.available()>0)
  {
    int buffer_value = Serial3.read();
    if(buffer_value == 'a' || buffer_value == 'A')
    {   digitalWrite(9, HIGH);    //Turn ON LED
//      Serial.println("LED BLU ON");  //Arduino Terminal of Desktop 
      Serial3.println("LED BLU ON"); //Bluetooth Terminal on Mobile
    }
    else if(buffer_value == 'b' || buffer_value == 'B')
    {
        digitalWrite(9, LOW);    //Turn ON LED
//      Serial.println("LED OFF");  //Arduino Terminal on Desktop
      Serial3.println("LED BLU OFF"); //Bluetooth Terminal on Mobile 
    }
  }
}
 
