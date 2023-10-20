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
**Version:    Version IV *********************************************************************************************************
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

  Serial1.begin(9600);  //Tx1 and Rx1  //Connected to Bluetooth Module HC-05 (Bluetooth 2.0)
  Serial.setTimeout(3000); //Set el Timeout en 3 segundos para Serial.find()
 Serial.println("AT\r"); //PROBAR CON \n\r
  
 delay(2000);
  

  pinMode(13, OUTPUT);  //Set Pin 13 as Output (Connected to LED)
  pinMode(9, OUTPUT);  //Set Pin 13 as Output (Connected to LED)
  pinMode(8, OUTPUT);  //Set Pin 13 as Output (Connected to LED)

  Serial1.println("press \"a\" or \"A\" to switch ON the LED"); //To mobile
  Serial1.println("press \"b\" or \"B\" to switch OFF the LED");
    delay(500);
  Serial.flush();       // Clear receive buffer.
}

void loop() {
  // put your main code here, to run repeatedly:
  
  if(Serial1.available()>0)
  {
    int buffer_value = Serial1.read();
    if(buffer_value == 'a' || buffer_value == 'A')
    {
      //digitalWrite(13, HIGH);    //Turn ON LED
      digitalWrite(9, HIGH);    //Turn ON LED
//      Serial.println("LED ON");  //Arduino Terminal of Desktop 
      Serial1.println("LED ON"); //Bluetooth Terminal on Mobile
    }
    else if(buffer_value == 'b' || buffer_value == 'B')
    {
     // digitalWrite(13, LOW);      //Turn OFF LED
      digitalWrite(9, LOW);    //Turn ON LED
//      Serial.println("LED OFF");  //Arduino Terminal on Desktop
      Serial1.println("LED OFF"); //Bluetooth Terminal on Mobile 
    }
  }
}
 
