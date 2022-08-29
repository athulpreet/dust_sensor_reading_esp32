/*
 * There are three serial ports on the ESP known as U0UXD, U1UXD and U2UXD.
 * 
 * U0UXD is used to communicate with the ESP32 for programming and during reset/boot.
 * U1UXD is unused and can be used for your projects. Some boards use this port for SPI Flash access though
 * U2UXD is unused and can be used for your projects.
 * 
*/

#define RXD2 16
#define TXD2 17

int arr[32]={0};
int value = 0;
int inc=0;
int dust=0;


void setup() {
  // Note the format for setting a serial port is as follows: Serial2.begin(baud-rate, protocol, RX pin, TX pin);
  Serial.begin(115200);

  Serial2.begin(9600, SERIAL_8N1, RXD2, TXD2);
 
}

void loop() { //Choose Serial1 or Serial2 as required
inc=0;
 
  while (Serial2.available()) {
    Serial.println("hi****************************************");
        while(inc<32){
   value = Serial2.read();
    Serial.println(value);
    arr[inc]=value;
    
   
    inc++;
    }
    dust=arr[12]<<8|arr[13];
    Serial.println("");
 Serial.print("DUST :");
  Serial.println(dust);
  }
}
