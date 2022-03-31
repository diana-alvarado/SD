/*
  Listfiles
 
 This example shows how print out the files in a 
 directory on a SD card 
 	
 The circuit:
 * SD card attached to SPI bus as follows:
 ** MOSI - pin 11
 ** MISO - pin 12
 ** CLK - pin 13
 ** CS - pin 4

 created   Nov 2010
 by David A. Mellis
 modified 9 Apr 2012
 by Tom Igoe
 modified 2 Feb 2014
 by Scott Fitzgerald
 
 This example code is in the public domain.

 */
#include <SPI.h>
#include <SD.h>

File root;
int eleccion = 0;

void setup()
{
  // Open serial communications and wait for port to open:
  Serial.begin(9600);
  SPI.setModule(0);


  Serial.print("Initializing SD card...");
  // On the Ethernet Shield, CS is pin 4. It's set as an output by default.
  // Note that even if it's not used as the CS pin, the hardware SS pin
  // (10 on most Arduino boards, 53 on the Mega) must be left as an output
  // or the SD library functions will not work.
  pinMode(PA_3, OUTPUT);

  if (!SD.begin(PA_3)) {
    Serial.println("initialization failed!");
    return;
  }
  Serial.println("initialization done.");

  root = SD.open("/");

  printDirectory(root, 0);

  Serial.println("done!");
  Serial.println("Bienvenido Maestro Pokémon, hoy inicia tu aventura, selecciona a tu compañero");
  Serial.println("1. Bulbasaur");
  Serial.println("2. Charmander");
  Serial.println("3. Squirtle");
}

void loop()
{
  if(Serial.available() > 0){
    eleccion = Serial.read();
  }
  imagenes();
}

void printDirectory(File dir, int numTabs) {
   while(true) {
     
     File entry =  dir.openNextFile();
     if (! entry) {
       // no more files
       break;
     }
     for (uint8_t i=0; i<numTabs; i++) {
       Serial.print('\t');
     }
     Serial.print(entry.name());
     if (entry.isDirectory()) {
       Serial.println("/");
       printDirectory(entry, numTabs+1);
     } else {
       // files have sizes, directories do not
       Serial.print("\t\t");
       Serial.println(entry.size(), DEC);
     }
     entry.close();
   }
}

void imagenes(){
  switch(eleccion){
    
    case 49:
      root = SD.open("BULBAS~1.TXT");
      if(root){
        Serial.println("");
        Serial.println("");
        Serial.println("Felicidades, tu compañero es Bulbasaur");
        while(root.available()){
          Serial.write(root.read());
        }
        root.close();
      }
      else{
        Serial.println("Bulbasaur no quiere ir contigo");
        Serial.println("Elige a otro compañero:");
        Serial.println("1. Bulbasaur");
        Serial.println("2. Charmander");
        Serial.println("3. Squirle");
      }
      Serial.println("Felicidades, ya tienes tu primer pokemón, ve a iniciar tu aventura!");
      Serial.println("");
      Serial.println("");
      Serial.println("Bienvenido Maestro Pokemon,hoy inicia tu aventura, selecciona a tu compañero");
      Serial.println("1. Bulbasaur");
      Serial.println("2. Charmander");
      Serial.println("3. Squirtle");
      break;

    case 50:
      root = SD.open("CHARMA~1.TXT");
      if(root){
        Serial.println("");
        Serial.println("");
        Serial.println("Felicidades, tu compañero es Charmander");
        while(root.available()){
          Serial.write(root.read());
        }
        root.close();
      }
      else{
        Serial.println("Charmander no quiere ir contigo");
        Serial.println("Elige a otro compañero:");
        Serial.println("1. Bulbasaur");
        Serial.println("2. Charmander");
        Serial.println("3. Squirle");
      }
      Serial.println("Felicidades, ya tienes tu primer pokemón, ve a iniciar tu aventura!");
      Serial.println("");
      Serial.println("");
      Serial.println("Bienvenido Maestro Pokemon,hoy inicia tu aventura, selecciona a tu compañero");
      Serial.println("1. Bulbasaur");
      Serial.println("2. Charmander");
      Serial.println("3. Squirtle");
      break;
    case 51:
      Serial.println("");
      Serial.println("");
      root = SD.open("SQUIRTLE.TXT");
      if(root){
        Serial.println("Felicidades, tu compañero es Squirtle");
        while(root.available()){
          Serial.write(root.read());
        }
        root.close();
      }
      else{
        Serial.println("Squirtle no quiere ir contigo");
        Serial.println("Elige a otro compañero:");
        Serial.println("1. Bulbasaur");
        Serial.println("2. Charmander");
        Serial.println("3. Squirle");
      }
      Serial.println("Felicidades, ya tienes tu primer pokemón, ve a iniciar tu aventura!");
      Serial.println("");
      Serial.println("");
      Serial.println("Bienvenido Maestro Pokemon,hoy inicia tu aventura, selecciona a tu compañero");
      Serial.println("1. Bulbasaur");
      Serial.println("2. Charmander");
      Serial.println("3. Squirtle");
      break;
  }

  
}
