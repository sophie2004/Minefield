#include <RGBmatrixPanel.h>

#define CLK  8   
#define OE   9
#define LAT 10
#define A   A0
#define B   A1
#define C   A2


RGBmatrixPanel matrix(A, B, C, CLK, LAT, OE, false);

const int kPinBtn1 = A5;  // Button 1
const int kPinBtn2 = A4;  // Button 2
const int kPinBtn3 = A3;  // Button 3

void setup()
{
  pinMode(kPinBtn1, INPUT); // Button 1 as Input
  pinMode(kPinBtn2, INPUT); // Button 2 as Input
  pinMode(kPinBtn3, INPUT); // Button 3 as Input

  digitalWrite(kPinBtn1, HIGH); // Pullup
  digitalWrite(kPinBtn2, HIGH); // Pullup
  digitalWrite(kPinBtn3, HIGH); // Pullup
  Serial.begin(9600);
  matrix.begin();

  Serial.print("hello");
}
  

void loop() {
  
  if (digitalRead(kPinBtn1) == LOW){
    matrix.fillScreen(matrix.Color333(0, 0, 0)); // clears screen
    matrix.fillCircle(23, 7, 7, matrix.Color333(7, 0, 7)); 
// draws circle
  }

  if (digitalRead(kPinBtn2) == LOW){
    matrix.fillScreen(matrix.Color333(0, 0, 0)); // clears screen
    matrix.drawLine(0, 0, 31, 15, matrix.Color333(7, 0, 0)); // draws x
    matrix.drawLine(31, 0, 0, 15, matrix.Color333(7, 0, 0));
  }
  
  if (digitalRead(kPinBtn3) == LOW){
    matrix.fillScreen(matrix.Color333(0, 7, 0)); // fills screen green
   
  }
  
}

