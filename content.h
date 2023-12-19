#define WIDTH 20
#define HEIGHT 4

#define COIN_PLEASE 0
#define THINKING 1
const char MESSAGES[][HEIGHT][WIDTH+1] = {{
    "*                  *",
    "  Get your fortune  ",
    "  BEWARE!           ",
    "*                  *"
  }, {
    "                    ",
    "  * * THINKING * *  ",
    "                    ",
    "                    "
  }};

const char FORTUNES[][HEIGHT][WIDTH+1] = {
 {
    "Absolutely... not.  ",
    "                    ",
    "Unless you bribe me ",
    "with cookies.       "
  }, {
    "                    ",
    "Yes, but only on    ",
    "days that end in 'Y'",
    "                    "
  }, {
    "                    ",
    "No, unless you're   ",
    "a wizard.           ",
    "                    "
  }, {
    "                    ",
    "Maybe. Ask your     ",
    "coffee first.       ",
    "                    "
  }, {
    "                    ",
    "Sure, but only if   ",
    "you do a little     ",
    "dance first.        "
  }, {
    "                    ",
    "                    ",
    "If I say yes, will  ",
    "you stop asking?    "
  }, {
    "                    ",
    "Not just no, but    ",
    "super no.           ",
    "                    "
  }, {
    "                    ",
    "Yes, but in an      ",
    "alternate universe. ",
    "                    "
  }, {
    "                    ",
    "                    ",
    "My sources say      ",
    "ask again later.    "
  }, {
    "                    ",
    "                    ",
    "Signs point to a    ",
    "hesitant yes.       "
  }
};

const int numFortunes = sizeof(FORTUNES) / sizeof(FORTUNES[0]);
