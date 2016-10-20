//SD Speed test (Arduino 101)

#include <SPI.h>
#include <SD.h>

File testFile;

void setup() {
Serial.begin(9600);
  while (!Serial) {
    ; //wait for serial
  }

  readWriteTest();
}

void readWriteTest() {
    Serial.println("SD init: ");
    if (!SD.begin(4)) {
    Serial.println("initialization failed!");
    return;
  }
  Serial.println("initialization done.");

  //WRITE TEST:
  testFile = SD.open("spdtst4.txt", FILE_WRITE);

  if (testFile) {
    
    unsigned long start_time = millis();
    for(unsigned long c = 0; c< 1024; c++)
    {
        testFile.write(byte(c));
    }
    unsigned long tot_time = millis() - start_time;
    Serial.print("Write time: ");
    Serial.println(tot_time);
    // close the file:
    testFile.close();
  
  } else {
    Serial.println("error opening file");
  }

  //READ TEST:
  testFile = SD.open("spdtst4.txt");
  if (testFile) {
    unsigned long start_time = millis();
    while (testFile.available()) {
      byte b = testFile.read();
    }
    unsigned long tot_time = millis() - start_time;
    Serial.print("Read time: ");
    Serial.println(tot_time);
    // close the file:
    testFile.close();
  } else {
    // if the file didn't open, print an error:
    Serial.println("error opening file for reading");
  }
}

void loop()
{
  
}

