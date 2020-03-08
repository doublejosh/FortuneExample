#include <LiquidCrystal.h>

// HARDWARE...

const int TRIGGER_PIN = D8,
          ANALOG_PIN = A0;

const int displayRS = D5,
          displayEN = D0,
          displayD4 = D1,
          displayD5 = D2,
          displayD6 = D3,
          displayD7 = D4;
LiquidCrystal lcd(
  displayRS, displayEN, displayD4, displayD5, displayD6, displayD7
);
#define WIDTH 20
#define HEIGHT 4

// APP GLOBALS...

const int DELAY_QUICK = 250,
      DELAY_FORTUNE = 9000;

const char FORTUNES[][HEIGHT][WIDTH+1] = {{
    "A hunch is just     ",
    "creativity trying to",
    "tell you something. ",
    "                    "
  }, {
    "                    ",
    "A soft voice may be ",
    "awfully persuasive. ",
    "                    "
  }, {
    "                    ",
    "Adventure can be    ",
    "real happiness.     ",
    "                    ",
  }, {
    "At the touch of love",
    "everyone becomes a  ",
    "poet.               ",
    "                    "
  }, {
    "A friend is a       ",
    "present you give    ",
    "yourself.           ",
    "                    "
  }};
const int numFortunes = sizeof(FORTUNES) / sizeof(FORTUNES[0]);

#define COIN_PLEASE 0
#define THINKING 1
const char MESSAGES[][HEIGHT][WIDTH+1] = {{
    "*                  *",
    "  Feed me quarters  ",
    "  get your fortune  ",
    "*                  *"
  }, {
    "                    ",
    "  * * THINKING * *  ",
    "                    ",
    "                    "
  }};

// STANDARD...

void setup(void) {
	// Define screen size.
	lcd.begin(WIDTH, HEIGHT);
	// Allows debug monitoring.
	Serial.begin(115200);
	// Enabled true random.
	randomSeed(analogRead(ANALOG_PIN));
	// Allow using trigger pin.
	pinMode(TRIGGER_PIN, INPUT);
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
	for (int s=0; s < 10; s++) {
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
	int lines = sizeof(screen);
	for (int i = 0; i < lines; i++) {
		// Start at first column.
		lcd.setCursor(0, i);
		lcd.print(String(screen[i]));
	}

	lcd.display();
	delay(wait);
}
