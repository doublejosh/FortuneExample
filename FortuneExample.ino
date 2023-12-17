#include <Wire.h> 
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27,20,4);

#include "content.h"

const int TRIGGER_PIN = D8, // Uno: 8, Wemos: D8
          ANALOG_PIN = A0;

// SCL - (Uno: 5, Wemos: D1)
// SDA - (Uno: 4, Wemos: D2)
// Trigger - 3v

// APP GLOBALS...

#define WIDTH 20
#define HEIGHT 4

const int DELAY_QUICK = 250,
        DELAY_FORTUNE = 9000,
         THINK_BLINKS = 10;

// STANDARD...

void setup(void) {
	Serial.begin(115200);

	lcd.init();
	lcd.backlight();

	// Enabled true random.
	randomSeed(analogRead(ANALOG_PIN));
	// Allow using trigger pin.
	pinMode(TRIGGER_PIN, INPUT); // Uno: INPUT_PULLUP, Wemos: INPUT
	// Initial message.
	paint(MESSAGES[COIN_PLEASE], 0);
}
 
void loop(void) {
	const int trigger = digitalRead(TRIGGER_PIN);
	// When pin gets triggered, show a fortune.
	if (trigger == HIGH) {
		// Pick random fortune.
		int f = random(numFortunes);
		showFortune(f);
	}
}

// APPLICATION...

void showFortune(int f) {
	// Pretend to compute the fortune.
	for (int s=0; s < THINK_BLINKS; s++) {
		paint(MESSAGES[THINKING], DELAY_QUICK);
		lcd.clear();
		delay(DELAY_QUICK);
	}

	// Output the fortune.
	Serial.print("Printing fortune: ");
	Serial.println(f);
	paint(FORTUNES[f], DELAY_FORTUNE);
	lcd.clear();
	paint(MESSAGES[COIN_PLEASE], 0);
}

void paint (const char screen[HEIGHT][WIDTH+1], int wait) {
	lcd.noDisplay();
	lcd.clear();

	// Loop through rows.
	int lines = HEIGHT;
	for (int i = 0; i < lines; i++) {
		// Start at first column.
		lcd.setCursor(0, i);
		lcd.print(String(screen[i]));
	}

	lcd.display();
	delay(wait);
}
