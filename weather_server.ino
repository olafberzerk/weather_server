/* requires
 * RF24-master
 * SPI
 * Wire
*/

#include <SPI.h>
#include <RF24.h>

#include <Wire.h>
#include <LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcd(0x3F, 2, 1, 0, 4, 5, 6, 7, 3, POSITIVE);  // Set the LCD I2C address

//#include "convert.h" // move convert to server.. yes

RF24 radio(7,8);

byte addresses[][6] = {"1Node","2Node"};
// 1Node = pipe of this server
// 2Node = pipe of the remote note (dht node)

void setup()
{
	//setup the radio
	radio.begin();
	radio.setChannel(100);

	// Set the PA Level low to prevent power supply related issues since this is a
	// getting_started sketch, and the likelihood of close proximity of the devices. RF24_PA_MAX is default.
	/*
	   Set Power Amplifier (PA) level to one of four levels: RF24_PA_MIN, RF24_PA_LOW, RF24_PA_HIGH and RF24_PA_MAX
	   The power levels correspond to the following output levels respectively: NRF24L01: -18dBm, -12dBm,-6dBM, and 0dBm
	 */
	radio.setPALevel(RF24_PA_LOW);

	//radio.openWritingPipe(addresses[0]);
	radio.openReadingPipe(1,addresses[1]);
	// going to read from the transmitter dht

	radio.startListening();


	  Serial.begin(9600);  // Used to type in characters

	  lcd.begin(16,2);   // initialize the lcd for 16 chars 2 lines, turn on backlight

	// ------- Quick 3 blinks of backlight  -------------
	  for(int i = 0; i< 3; i++)
	  {
	    lcd.backlight();
	    delay(250);
	    lcd.noBacklight();
	    delay(250);
	  }
	  lcd.backlight(); // finish with backlight on

	//-------- Write characters on the display ------------------
	// NOTE: Cursor Position: (CHAR, LINE) start at 0
	  lcd.setCursor(0,0); //Start at character 4 on line 0
	  lcd.print("Hello, world!");
	  delay(1000);
	  lcd.setCursor(0,1);
	  lcd.print("HI!YourDuino.com");
	  delay(8000);

	// Wait and then tell user they can start the Serial Monitor and type in characters to
	// Display. (Set Serial Monitor option to "No Line Ending")
	  lcd.clear();
	  lcd.setCursor(0,0); //Start at character 0 on line 0
	  lcd.print("Use Serial Mon");
	  lcd.setCursor(0,1);
	  lcd.print("Type to display");



}

void loop()
{

	char buf[32];
	if(radio.available()){
	  radio.read(&buf,sizeof(buf));
	}


    // when characters arrive over the serial port...
    if (Serial.available()) {
      // wait a bit for the entire message to arrive
      delay(100);
      // clear the screen
      lcd.clear();
      // read all the available characters
      while (Serial.available() > 0) {
        // display each character to the LCD
        lcd.write(Serial.read());
      }
    }

  //power management routine
  /*
  radio.powerDown();
  delay(20000);
  radio.powerUp();
  */
}
