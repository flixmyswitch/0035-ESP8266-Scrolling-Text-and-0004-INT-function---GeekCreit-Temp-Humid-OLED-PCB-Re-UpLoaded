/* This is just information baout the GeekCreit board.  All this is not used by the ESP8266 it just information that will help you understand what is going on.  Down below you will see alot
 *  of these lines // these are just comment to explain the code, again the ESP8266 does not read these, but they will help you in the future when you return to the code
 *  
 *  WARNING - we are using the  https://www.banggood.com/custlink/DDmGAbYJrM This is an afflicate link
      BECAREFULL - check if you use another make of OLED that the pins are the same.
       *** WARNING ***  Some OLED screens have the POSITIVE and NEGATIVE reveresed  *** WARNING ***
         As the board has STRANGE SDL AND SCL PINS WE HAVE TO CHANGE THEM IN THE CODE BELOW

         Written by Andy Shrimpton Jan 2020. ******  Basic code to get the Oled to show some data  ******
*/

#include <Wire.h>                                                         // Include the libaries that are needed.  Libaries are written by clever people and when used its reduces 
                                                                          // the amount of code we have to write.

#include <Adafruit_SSD1306.h>

// OLED display wire address                                              // We need to the the WIRE libary the address of the OLED
#define OLED_ADDR   0x3C                                                  // Some oled may have a different address you can try 0x3D if not printed on the reverse of the oled screen
#define SCREEN_WIDTH 128                                                  // OLED display width, in pixels
#define SCREEN_HEIGHT 64                                                  // OLED display height, in pixels
#define OLED_RESET 1                                                      // Reset pin number (or -1 if sharing Arduino reset pin)


Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET); // setting up the OLED using the information above

// IMPORTANT FOR THIS GEEKCREIT BOARD the standard SDL and SCL pins are not wired up as normal so we use this command too
// to wire to use pins 2 of the SDA and pin 14 of SCL using the Wire.begin(2,14) command below

void setup() {
  
// Declaration for an SSD1306 display connected to I2C (SDA, SCL pins)                                                                            
Wire.begin(2,14);                                                         // scl gpio14  SDA gpio 02 here we change where the SDA and SCL pins look to get there data on a 
                                                                          // D1 mini its normally SCL GPIO 5, SDA GPIO 4

Serial.begin(9600);                                                       // Send and receive at 9600 baud
  
// initialize and clear display
  display.begin(SSD1306_SWITCHCAPVCC, OLED_ADDR);                         // Lets start the display ready to recieve information to display
  display.display();                                                      // Send it the the OLED it will draw the Adafruit logo. We do this to show support the Adafruit
  delay(2000);                                                            // Wait 2000 mill seconds which is 1 second 

  display.clearDisplay();                                                 // Clear the buffer
  display.display();                                                      // Send it the the OLED it will draw the Adafruit logo as the buffer is CLEARED the screen will be blank
  delay(1000);                                                            // Wait 1000 mill seconds which is 1 second 

     
}                                                                         // The end of the SETUP

void loop() {                                                             // put your main code here, to run repeatedly:

// display a pixel in each corner of the screen                           // The buffer and screen or now cleared, lets prepare some more data to send to the oled
  display.drawPixel(0, 0, WHITE);                                         // put a single pixel at x=0, y=0
  display.drawPixel(127, 0, WHITE);                                       // put a single pixel at x=127, y=0
  display.drawPixel(0, 63, WHITE);                                        // put a single pixel at x=0, y=63
  display.drawPixel(127, 63, WHITE);                                      // put a single pixel at x=127, y=63 
                             
                                                                          // No Pixel "dots" have been writen to the oled yet this will only happen with the last line of code
                                                                          
// display a line of text                                                 // Lets get some text ready to send to the OLED
  display.setTextSize(2);                                                 // Lets use a larger font so we can read it
  display.setTextColor(WHITE);                                            // Set the text colour, not the way colout is spelt in the code the arerican way
  display.setCursor(30,0);                                                // Position the text with X,Y cordinates. As we are using the upper part of the OLED the HELLO will be in yellow
  display.println("Hello");                                               // We want to print on the oled HELLO
  display.setCursor(25,20);                                               // Move the cursor to another position
  display.println("World!");                                              // We want to print on the oled World
  display.setTextSize(1);                                                 // Lets change the font size to small
  display.setCursor(22,42);                                               // Move the cursor to another position
  display.println("It's working");                                        // We want to print It's working on the OLED
                                                                          //nothing is dispaly yet you have to add the next line to do that, we have only loaded it into memory
  
                                                                          
  display.display();                                                      // update display with all of the above graphics and text without this line on thing will be displayed
  
}                                                                         // end of the code
