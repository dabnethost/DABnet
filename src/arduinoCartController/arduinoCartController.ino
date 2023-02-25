/*
 @file arduinoCartController.ino
 @author Henry Wysong-Grass
 @date 10/28/22

 @brief Drives individual PWM signal to mosfet cart drivers.

 @todo Design physical hardware, test program, test hardware,
       create entirety of data trnsf btwn pi and arduino.
*/

//Pin assignment for PWM control of carts
const int POT_VALUE = A1;     //Pin for potentiometer input

const int CART_ONE = 3;       //Pin for PWM output of cart one
const int CART_TWO = 5;       //Pin for PWM output of cart two
const int CART_THREE = 6;     //Pin for PWM output of cart three

const int ON_OFF = 4;         //Controls whether PWM signal send is on or off
const int CART_CYCLE = 7;     //Cycles on which cart the voltage is being changed

const int LED_INDICATOR = 12; //LED indicator light for 

//Data transfer pin assignment
//const int DCLK = ;
//const int DIN = ;
//const int DEN = ;

//Duty cycles of carts (cV = cart voltage)
int cV1;   
int cV2;
int cV3;

//States of various buttons
int onOffState;
int cartCycle;

void setup() {
    pinMode(CART_ONE, OUTPUT);
    pinMode(CART_TWO, OUTPUT);
    pinMode(CART_THREE, OUTPUT);
    pinMode(LED_INDICATOR, OUTPUT);
    pinMode(A0, INPUT);
    pinMode(ON_OFF, INPUT);
    pinMode(CART_CYCLE, INPUT);
    
//    pinMode(DEN, INPUT);
}

void setPWM ( int cartVal, int pwmVal) {
    analogWrite(cartVal, pwmVal);
}

void setPWM ( int cartVal) {
    int pulseWidth = analogRead(POT_VALUE) / 4; 

    analogWrite(cartVal, pulseWidth);
}

void loop() {
    int pBValue = 0;
    int i = 0;  //index of arrayValue
    int pwmBinaryValue[8];

    /**    don't enable until data sending is figured out
    if ( digitalRead(DEN) == LOW){ 
    */   

        //Add some physical state or debounce to make the button work smoother.
        if ( digitalRead(CART_CYCLE) == HIGH) {
            pBValue++;

            //Quickly blinks LED to indicate that the state has advanced.
            digitalWrite(LED_INDICATOR, LOW);
            delay(50);
            digitalWrite(LED_INDICATOR, HIGH);
        }

        if ( pBValue == 0) {
            digitalWrite(LED_INDICATOR, HIGH);

            digitalWrite(CART_ONE, LOW);
            digitalWrite(CART_TWO, LOW);
            digitalWrite(CART_THREE, LOW);

        } else if ( pBValue == 1) {
            setPWM(CART_ONE);
        } else if ( pBValue == 2){
            setPWM(CART_TWO);
        } else if ( pBValue == 3){
            setPWM(CART_THREE);
        }

    /**
    } else {
        if ( digitalRead(DCLK) == HIGH) {
            if ( i < 8) {
              pwmBinaryValue = digitalRead(DIN);
              i++;
            }
        }
    }
    */
    
}