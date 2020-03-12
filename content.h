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
