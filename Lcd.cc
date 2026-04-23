#include <Arduino.h>
#include "Lcd.h"
#include "DFRobot_RGBLCD1602.h"

/*!
 * @file Roll.ino
 * @brief Roll show 'hello, world!'.
 * @copyright	Copyright (c) 2010 DFRobot Co.Ltd (http://www.dfrobot.com)
 * @licence     The MIT License (MIT)
 * @maintainer [yangfeng](feng.yang@dfrobot.com)
 * @version  V1.0
 * @date  2021-09-24
 * @url https://github.com/DFRobot/DFRobot_RGBLCD1602
 */

/*
Change the RGBaddr value based on the hardware version
-----------------------------------------
       Moudule        | Version| RGBAddr|
-----------------------------------------
  LCD1602 Module      |  V1.0  | 0x60   |
-----------------------------------------
  LCD1602 Module      |  V1.1  | 0x6B   |
-----------------------------------------
  LCD1602 RGB Module  |  V1.0  | 0x60   |
-----------------------------------------
  LCD1602 RGB Module  |  V2.0  | 0x2D   |
-----------------------------------------
*/

DFRobot_RGBLCD1602 lcd(/*RGBAddr*/0x60 ,/*lcdCols*/16,/*lcdRows*/2);  //16 characters and 2 lines of show

void Lcd::setup(int currentTime) {
    /**
     *  @brief initialize the LCD and master IIC
     */ 
    lcd.init();
    // Print a message to the LCD.
    lcd.print("Do I Wanna Know - Arctic Monkeys");
    initialTime = currentTime;

}

void Lcd::update(int currentTime) {

  // discard unwanted cases
  if(initialTime + speed > currentTime) return;

  initialTime = currentTime;

  if(currentState <= 30){
    lcd.scrollDisplayLeft();
    currentState++;
    return;
  }

  if(currentState <=58){
    lcd.scrollDisplayRight();
    currentState++;
    return;
  }

  if(currentState <=(58+16)){
    lcd.scrollDisplayLeft();
    currentState++;
    return;
  }
  currentState = 0;
    // scroll 31 positions (string length) to the left
    // to move it offscreen left:
    // initialTime = currentTime;
  //   if(initialTime + speed >= currentTime){
  //     if(currentState <= 30){
  //       currentState++;
  //       initialTime = currentTime;
  //     // for (int positionCounter = 0; positionCounter < 31; positionCounter++) {
  //         /**
  //         *  @brief scroll left to display
  //         */
  //         lcd.scrollDisplayLeft();//scroll one position left
  //     // }
  //     return;
  //   }
  //   // scroll 29 positions (string length + show length) to the right
  //   // to move it offscreen right:
  //   if(currentState == 1){
  //     currentState++;
  //     initialTime = currentTime;
  //     for (int positionCounter = 0; positionCounter < 29; positionCounter++) {
  //         /**
  //         *  @brief scroll right to display
  //         */
  //         lcd.scrollDisplayRight();//scroll one position right
  //         // wait a bit:
  //     }
  //     return;
  //   }
  //   // scroll 16 positions (show length + string length) to the left
  //   // to move it back to center:
  //   if(currentState == 2){
  //     currentState = 0;
  //     initialTime = currentTime;
  //     for (int positionCounter = 0; positionCounter < 16; positionCounter++) {
  //         // scroll one position left:
  //         lcd.scrollDisplayLeft();
  //         // wait a bit:
  //     }
  //   }
  // }
}

