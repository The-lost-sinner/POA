# Pillar of Autumn OBC

Hello, the purpose of this project is to give the knowledge and open source code on how to build a flight computer (On Board Computer (OBC)) for an amateur model rocket research project.

![OBC2](Images/OBC2.jpg)
*the name of the rocket is pillar of autumn, in honor of the coolest spaceship of halo reach*



In this repo you will find:
* Source code of cheap arduino on board computers.
* schematic on how to build it.
* the necessary documentation of the code
* References and Bibliography on the sources we used for building this project

### Libraries
For running this project, you will have to download some libraries for arduino :
* [SdFat](https://github.com/greiman/SdFat) - by Bill Greiman
* [MS5611](https://github.com/jarzebski/Arduino-MS5611) - by Korneliusz Jarzebski
* [MPU6050](https://github.com/jarzebski/Arduino-MPU6050) - by Korneliusz Jarzebski
* [BMP280](https://github.com/adafruit/Adafruit_BMP280_Library) - by Adafruit (if you use a chinese version you should change the I2C address from 0x77 to 0x76)

I've  improved the necessary libraries, you'll find it in this repo in `Libraries` folder.

### Schematics
The **OBC1** use the GY86 Sensor, a micro SD module and the HC-06 BT module

![imagen esquematico obc1]()

The **OBC2** is *cheaper*, but the pourpose is *only to register data*, as a replacement for the BT it has a buzzer with alerts. It also has some other funcionalities like activate a servo motor when it dectects free fall.

![imagen esquematico obc2]()

I hope that the information in this repository is a good starting point for your science and technology projects, so if you want to help us developing this, feel free to do so, we will be very happy.


### References
* Bertrand R. (1960). Rocket Manual For Amateurs. Ballantine Books.
* Boyarizo E. y Méndez C. (2017). Diseño y construcción de un microsatélite(CanSat). IES El Burgo de Las Rozas.
* Calamac Projects (2015). “Arduino Rocket Data Logger”. Instructables.com. Recuperado de: https://www.instructables.com/id/Arduino-Rocket-Data-Logger
* Day B., Lumpkin T., Huegele V., Pierce C. (Sin fecha). “Basics of rocketry”. Huntsville Area Rocketry Assiciation (HARA).
* Gómez F. y Leiva.H (2015). “ANÁLISIS DEL RENDIMIENTO DEL PROPELENTE SÓLIDO TIPO AMATEUR MEDIANTE BALLISTIC EVALUATION MOTOR (BEM) Y SELECCIÓN DE LA TOBERA MÁS ADECUADA PARA SU USO EN EL COHETE SONDA LIBERTADOR I”. Fundación universitaria los libertadores. Colombia, Bogotá D.C.
* LabRat Scientific. (2018). “Rocket Stability”. Recuperado de : https://youtu.be/qCzF9OfYahc
* Newton M. (2012). Rocket Anatomy 101. NAR.
* Orlando J. (2012). “Estudio de la trayectoria de un cohete de tres etapas lanzado desde el territorio colombiano”. Universidad Nacional de Colombia, Bogotá. Pag. 80-81.
* Pirateque,M. y Sabogal A. (2011). Más que un sueño, una realidad, Historia de preliminar de la cohetería en Colombia. ASTCOL.
* T. Benson (2014). Brief History of Rockets. NASA. Recuperado de : https://www.grc.nasa.gov/www/k-12/TRC/Rockets/history_of_rockets.html
* Van Milligan T. (2009) “Make a rocket payload bay”. Apogee Rockets. Recuperado de : https://www.youtube.com/watch?v=_ctUCO8GsJ4&index=30&list=PLnX-NFLCOOVkq82xIrfm6KuaVoljTCtob
* Van Milligan T. (Sin fecha). “Pressure Relief Holes”. Apogee preak of flight newsletter, issue 68.


### Bibliography
* Álvarez N., Huérfano R., Ojeda O., (2015) “Diseño e implementación de misión para el lanzamiento de un cohete para tres kilómetros de altura”. Universidad Nacional de Colombia, Bogotá.
* Bonilla J., Ojeda O., Villagrán L., Villamil F., Zorro C. y Cañón M. (2016). “Colombia Aerospacial 2026”. Universidad Nacional de Colombia, Bogotá.
* cansatcompetition.com (2017). CanSat Competition [Vídeo]. Disponible en: http://cansatcompetition.com/CanSat%202017.mp4
* Esero (sin fecha). “2018 UK Cansat Competition Guidelines”. Esero. Pag. 9-10.
* European Space Agency(ESA) (2018). “CanSat Guidelines 2018-109”. ESA.
* Ojeda O. (2016) “The Aerospace development and research group of the Universidad Nacional de Colombia, GIDA-UN. A tool for aerospace education in Colombia”. 67 th International Astronautical Congress (IAC). México, Guadalajara.
* Ricardo P. (2018). “Reto de innovación IEEE 2018 – CanSat para la paz”. Universidad Distrital. Bogotá. Recuperado de : https://ieee.udistrital.edu.co/ieee-innovation-2018/
* Van Milligan T. (2009) “Make your own rocket tube couplers”. Apogee Rockets. Recuperado de : https://www.youtube.com/watch?v=iH3HesegWv0&index=31&list=PLnX-NFLCOOVkq82xIrfm6KuaVoljTCtob
