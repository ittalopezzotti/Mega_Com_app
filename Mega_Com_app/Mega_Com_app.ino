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

<<<<<<< Updated upstream
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
=======
  /*|||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||| 
   ****I PREPARE THE COMMUNICATIONS PORT WITH SERIAL 1 CELLULAR BLUETOOTH****
   ***PTO 16 (RXD) 17 (TXD) ARDUINO MEGA************************************************* 
  |||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||| */
  Serial2.begin(9600);  //Tx2 and Rx2  /Connected to Bluetooth Module HC-05 (Bluetooth 2.0)
  Serial2.println("press \"a\" or \"A\" to switch ON the LED"); //To mobile
  delay(100);
     /*|||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||| 
   ****READING DATA PC PREPARED THE COMMUNICATIONS PORT WITH SERIAL****
   ***PTO 0 (RXD) 1 (TXD) ARDUINO MEGA************************************************* 
  |||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||| */
  Serial.begin(9600);  //Tx and Rx  pc mode
  delay(100);
  Serial.println("AT\r"); //access \n\r
  pinMode(9, OUTPUT);  //Set Pin 9 as Output (Connected to LED)
  delay(500);
>>>>>>> Stashed changes
  Serial.flush();       // Clear receive buffer.
}

void loop() {
  // put your main code here, to run repeatedly:
  
  if(Serial2.available()>0)
  {
    int buffer_value = Serial2.read();
    if(buffer_value == 'a' || buffer_value == 'A')
    {
      //digitalWrite(13, HIGH);    //Turn ON LED
      digitalWrite(9, HIGH);    //Turn ON LED
      Serial2.println("LED ON"); //Bluetooth Terminal on Mobile
    }
    else if(buffer_value == 'b' || buffer_value == 'B')
    {
       digitalWrite(9, LOW);    //Turn ON LED
      Serial2.println("LED OFF"); //Bluetooth Terminal on Mobile 
    }
  }
}
 
