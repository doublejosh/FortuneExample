#define WIDTH 20
#define HEIGHT 4

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

const char FORTUNES[][HEIGHT][WIDTH+1] = {{
    "That hunch is right.",
    "                    ",
    "Your deeper mind is ",
    "worth listening to.  "
  }, {
    "                    ",
    "Your gentle voice is",
    "more persuasive.    ",
    "                    "
  }, {
    "                    ",
    "True adventure is   ",
    "the happiness you   ",
    "seek.               "
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
