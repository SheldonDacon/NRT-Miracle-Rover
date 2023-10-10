#include <SoftwareSerial.h>
SoftwareSerial hc06(11,10); //TX connects to 2(RX), RX connects to 3(TX)
String cmd="";
float sensor_val=0;
// constants won't change
const int ENA_PIN = 9; // the Arduino pin connected to the EN1 pin L298N
const int IN1_PIN = 6; // the Arduino pin connected to the IN1 pin L298N
const int IN2_PIN = 7; // the Arduino pin connected to the IN2 pin L298N
const int IN3_PIN = 5; // the Arduino pin connected to the IN2 pin L298N
const int IN4_PIN = 4;  // the Arduino pin connected to the IN2 pin L298N
const int ENB_PIN = 3; // the Arduino pin connected to the EN1 pin L298N
void setup(){
 	//Initialize Serial Monitor
 	Serial.begin(9600);
 	//Initialize Bluetooth Serial Port
 	hc06.begin(9600);
  Serial.print("Test");
  pinMode(ENA_PIN, OUTPUT);
  pinMode(IN1_PIN, OUTPUT);
  pinMode(IN2_PIN, OUTPUT);
  pinMode(IN3_PIN, OUTPUT);
  pinMode(IN4_PIN, OUTPUT);
  pinMode(ENB_PIN, OUTPUT);
}
void loop(){
 	//Read data from HC06
 	while(hc06.available()>0){
 			cmd+=(char)hc06.read();
 	}


//Select function with cmd
 	if(cmd!=""){
 			Serial.print("Command recieved : ");
 			Serial.println(cmd);
 			// We expect ON or OFF from bluetooth
 			if(cmd=="W2"){ //backwards
 							digitalWrite(IN1_PIN, HIGH); // control motor A spins 
              digitalWrite(IN2_PIN, LOW);  // control motor A spins clockwise}
              digitalWrite(IN3_PIN, LOW);              
              digitalWrite(IN4_PIN, HIGH);  // control motor A spins clockwise}
              //delay(1000);
              for (int speed = 0; speed <= 150; speed++) {
                    analogWrite(ENA_PIN, (int)((speed/150)*135)); // control the speed
                    analogWrite(ENB_PIN, (int)((speed/150)*131)); // control the speed
  
    
                    delay(10);
              }
              //delay(1000);
  

 			}else if(cmd=="S2"){ //stop backwards
 							digitalWrite(IN1_PIN, HIGH);   // control motor A spins anti-clockwise
              digitalWrite(IN2_PIN, LOW);  // control motor A spins anti-clockwise
              digitalWrite(IN3_PIN, LOW);   // control motor A spins anti-clockwise
              digitalWrite(IN4_PIN, HIGH);  // control motor A spins anti-clockwise
              //delay(1000);
              for (int speed = 150; speed >= 0; speed--) {
                  analogWrite(ENA_PIN, (int)((speed/150)*135)); // control the speed
                  analogWrite(ENB_PIN, (int)((speed/150)*131)); // control the speed 
                  delay(10);     
              }
              //delay(1000); // stop motor 1 second

 			} if(cmd=="W"){ //forwards
 							digitalWrite(IN1_PIN, LOW); // control motor A spins 
              digitalWrite(IN2_PIN, HIGH);  // control motor A spins clockwise}
              digitalWrite(IN3_PIN, HIGH);              
              digitalWrite(IN4_PIN, LOW);  // control motor A spins clockwise}
              //delay(1000);
              for (int speed = 0; speed <= 150; speed++) {
                    analogWrite(ENA_PIN, (int)((speed/150)*135)); // control the speed
                    analogWrite(ENB_PIN, (int)((speed/150)*131)); // control the speed
  
    
                    delay(10);
              }
              //delay(1000);
  

 			}else if(cmd=="S"){ //stop forwards
 							digitalWrite(IN1_PIN, LOW);   // control motor A spins anti-clockwise
              digitalWrite(IN2_PIN, HIGH);  // control motor A spins anti-clockwise
              digitalWrite(IN3_PIN, HIGH);   // control motor A spins anti-clockwise
              digitalWrite(IN4_PIN, LOW);  // control motor A spins anti-clockwise
              //delay(1000);
              for (int speed = 150; speed >= 0; speed--) {
                  analogWrite(ENA_PIN, (int)((speed/150)*135)); // control the speed
                  analogWrite(ENB_PIN, (int)((speed/150)*131)); // control the speed 
                  delay(10);     
              }
              //delay(1000); // stop motor 1 second

 			}else if(cmd == "A1"){
 							digitalWrite(IN1_PIN, LOW);   // control motor A spins anti-clockwise
              digitalWrite(IN2_PIN, LOW);  // control motor A spins anti-clockwise
              digitalWrite(IN3_PIN, HIGH);   // control motor A spins anti-clockwise
              digitalWrite(IN4_PIN, LOW);  // control motor A spins anti-clockwise
              //delay(1000); 
              for (int speed = 0; speed <= 120; speed++) {
                  analogWrite(ENA_PIN, speed); // control the speed
                  analogWrite(ENB_PIN, speed); // control the speed 
                  delay(10);     
              }

              delay(100);

              for (int speed = 120; speed >= 0; speed--) {
                  analogWrite(ENA_PIN, speed); // control the speed
                  analogWrite(ENB_PIN, speed); // control the speed 
                  delay(10);     
              }
              //delay(1000); // stop motor 1 second
              
      } else if(cmd == "A2"){
 							digitalWrite(IN1_PIN, LOW);   // control motor A spins anti-clockwise
              digitalWrite(IN2_PIN, LOW);  // control motor A spins anti-clockwise
              digitalWrite(IN3_PIN, HIGH);   // control motor A spins anti-clockwise
              digitalWrite(IN4_PIN, LOW);  // control motor A spins anti-clockwise
              //delay(1000); 
              for (int speed = 0; speed <= 120; speed++) {
                  analogWrite(ENA_PIN, speed); // control the speed
                  analogWrite(ENB_PIN, speed); // control the speed 
                  delay(10);     
              }

              delay(200);

              for (int speed = 120; speed >= 0; speed--) {
                  analogWrite(ENA_PIN, speed); // control the speed
                  analogWrite(ENB_PIN, speed); // control the speed 
                  delay(10);     
              }
              //delay(1000); // stop motor 1 second 
      }else if(cmd == "A3"){
 							digitalWrite(IN1_PIN, LOW);   // control motor A spins anti-clockwise
              digitalWrite(IN2_PIN, LOW);  // control motor A spins anti-clockwise
              digitalWrite(IN3_PIN, HIGH);   // control motor A spins anti-clockwise
              digitalWrite(IN4_PIN, LOW);  // control motor A spins anti-clockwise
              //delay(1000); 
              for (int speed = 0; speed <= 120; speed++) {
                  analogWrite(ENA_PIN, speed); // control the speed
                  analogWrite(ENB_PIN, speed); // control the speed 
                  delay(10);     
              }

              delay(300);

              for (int speed = 120; speed >= 0; speed--) {
                  analogWrite(ENA_PIN, speed); // control the speed
                  analogWrite(ENB_PIN, speed); // control the speed 
                  delay(10);     
              }
              //delay(1000); // stop motor 1 second
              
      }else if(cmd == "D1"){
 							digitalWrite(IN1_PIN, LOW);   // control motor A spins anti-clockwise
              digitalWrite(IN2_PIN, HIGH);  // control motor A spins anti-clockwise
              digitalWrite(IN3_PIN, LOW);   // control motor A spins anti-clockwise
              digitalWrite(IN4_PIN, LOW);  // control motor A spins anti-clockwise
              //delay(1000); 
              for (int speed = 0; speed <= 120; speed++) {
                  analogWrite(ENA_PIN, speed); // control the speed
                  analogWrite(ENB_PIN, speed); // control the speed 
                  delay(10);     
              }
              
              delay(100);

              for (int speed = 120; speed >= 0; speed--) {
                  analogWrite(ENA_PIN, speed); // control the speed
                  analogWrite(ENB_PIN, speed); // control the speed 
                  delay(10);     
              }
              //delay(1000); // stop motor 1 second
      } else if(cmd == "D2"){
 							digitalWrite(IN1_PIN, LOW);   // control motor A spins anti-clockwise
              digitalWrite(IN2_PIN, HIGH);  // control motor A spins anti-clockwise
              digitalWrite(IN3_PIN, LOW);   // control motor A spins anti-clockwise
              digitalWrite(IN4_PIN, LOW);  // control motor A spins anti-clockwise
              //delay(1000); 
              for (int speed = 0; speed <= 120; speed++) {
                  analogWrite(ENA_PIN, speed); // control the speed
                  analogWrite(ENB_PIN, speed); // control the speed 
                  delay(10);     
              }
              
              delay(200);

              for (int speed = 120; speed >= 0; speed--) {
                  analogWrite(ENA_PIN, speed); // control the speed
                  analogWrite(ENB_PIN, speed); // control the speed 
                  delay(10);     
              }
              //delay(1000); // stop motor 1 second
      } else if(cmd == "D3"){
 							digitalWrite(IN1_PIN, LOW);   // control motor A spins anti-clockwise
              digitalWrite(IN2_PIN, HIGH);  // control motor A spins anti-clockwise
              digitalWrite(IN3_PIN, LOW);   // control motor A spins anti-clockwise
              digitalWrite(IN4_PIN, LOW);  // control motor A spins anti-clockwise
              //delay(1000); 
              for (int speed = 0; speed <= 120; speed++) {
                  analogWrite(ENA_PIN, speed); // control the speed
                  analogWrite(ENB_PIN, speed); // control the speed 
                  delay(10);     
              }
              
              delay(300);

              for (int speed = 120; speed >= 0; speed--) {
                  analogWrite(ENA_PIN, speed); // control the speed
                  analogWrite(ENB_PIN, speed); // control the speed 
                  delay(10);     
              }
              //delay(1000); // stop motor 1 second
      } else{
 							Serial.println("Invalid Command");
 			}
 			cmd=""; //reset cmd
 	}
 	// Simulate sensor measurement
 	sensor_val=(float)random(256); // random number between 0 and 255	
 	//Write sensor data to HC06
 	hc06.print(sensor_val);
 	delay(100);
}

