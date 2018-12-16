/*
Sensor que se usa : GY-86
MPU6050 : https://github.com/jarzebski/Arduino-MPU6050 by Korneliusz Jarzebski
MS5611 :  https://github.com/jarzebski/Arduino-MS5611 by Korneliusz Jarzebski

Codigos de referencia : 
Arduino Rocket Data Logger : https://www.instructables.com/id/Arduino-Rocket-Data-Logger/
*/

#include <Wire.h>
#include <SPI.h>
#include <SD.h>
#include <MPU6050.h>
#include <MS5611.h>

//Variables memoria SD
File myFile;
int pinCS = 4; // Pin 4 on Arduino Uno

//Declaramos los Sensores
MPU6050 mpu;
MS5611 ms5611;


//Variables MPU6050
// Timers
float timeStep = 0.1;

// Pitch, Roll and Yaw values
float pitch = 0;
float roll = 0;
float yaw = 0;

//variables caida libre
boolean ledState = false;
boolean freefallDetected = false;
int freefallBlinkCount = 0;

//Varaibles MS5611
double referencePressure;

void setup()
{ Serial.begin(38400);

// SD Card Initialization
  pinMode(pinCS, OUTPUT);  
  
  if (SD.begin()) 
  {
    Serial.println("SD card is ready to use.");
  } else
  {
    Serial.println("SD card initialization failed");
    return;
  }
  

  // Initialize MPU6050
  while(!mpu.begin(MPU6050_SCALE_2000DPS, MPU6050_RANGE_16G))
  {
    Serial.println("Could not find a valid MPU6050 sensor, check wiring!");
    delay(500);
  }

  
  // Calibrate gyroscope. The calibration must be at rest.
  mpu.calibrateGyro();

  // Set threshold sensivty. Default 3.
  // If you don't want use threshold, comment this line or set 0.
  mpu.setThreshold(3);

  

  mpu.setDHPFMode(MPU6050_DHPF_5HZ);

  mpu.setFreeFallDetectionThreshold(17);
  mpu.setFreeFallDetectionDuration(2);  

  pinMode(5, OUTPUT);
  digitalWrite(5, LOW);
  
  attachInterrupt(0, doInt, RISING);

  
  // Initialize MS5611 sensor
  Serial.println("Initialize MS5611 Sensor");

  while(!ms5611.begin(MS5611_ULTRA_HIGH_RES))
  {
    Serial.println("Could not find a valid MS5611 sensor, check wiring!");
    delay(500);
  }

  // Get reference pressure for relative altitude
  referencePressure = ms5611.readPressure();

  // Check settings
  checkSettings();
   
}



void loop()
{  
  // Read normalized values gyro
  Vector norm = mpu.readNormalizeGyro();
 // lee la aceleracion
  Vector rawAccel = mpu.readRawAccel();
  Vector normAccel = mpu.readNormalizeAccel();
  //lee la actividad xd
  Activites act = mpu.readActivites();

  // Calculate Pitch, Roll and Yaw
  pitch = pitch + norm.YAxis * timeStep;
  roll = roll + norm.XAxis * timeStep;
  yaw = yaw + norm.ZAxis * timeStep;
  
  float tempMPU6050 = mpu.readTemperature();

  // Calcula los valores del MS5611
  // Read true temperature & Pressure
  double realTemperature = ms5611.readTemperature(true);
  long realPressure = ms5611.readPressure(true);

  // Calculate altitude
  float absoluteAltitude = ms5611.getAltitude(realPressure);
  float relativeAltitude = ms5611.getAltitude(realPressure, referencePressure);
  if(relativeAltitude < -2){relativeAltitude = 0;}
 
 //Pone todos los valores como una cadena
  String coma = String(',');
  String Pitch = String(pitch);
  String Roll = String(roll);
  String Yaw = String(yaw);
  String Xnorm = String(normAccel.XAxis);
  String Ynorm = String(normAccel.YAxis);
  String Znorm = String(normAccel.ZAxis-2);
  String Temp1 = String(tempMPU6050);
  String Temp2 = String(realTemperature); 
  String Presion = String(realPressure);
  String Altura = String(relativeAltitude); 
  String Caida = String(act.isFreeFall); 
  String timer = String (millis());
  
  String datos = String(Pitch+coma+Roll+coma+Yaw+coma+Xnorm+coma+Ynorm+coma+Znorm+coma+Temp1+coma+Temp2+coma+Presion+coma+Altura+coma+Caida+coma+timer);
  Serial.println(datos);

  if (freefallDetected)
  {
    ledState = !ledState;

    digitalWrite(5, ledState);

    freefallBlinkCount++;

    if (freefallBlinkCount == 20)
    {
      freefallDetected = false;
      ledState = false;
      digitalWrite(5, ledState);
    }
  }
  
  //Guarda los datos en la tarjeta SD
  myFile = SD.open("test.txt", FILE_WRITE);
  if (myFile) {    
    myFile.println(datos);
    myFile.close();
  }
  // if the file didn't open, print an error:
  else {
    Serial.println("error opening test.txt");
  }

  // Wait to full timeStep period
  delay(50);
}
