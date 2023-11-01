// original code from https://viewsourcecode.org/snaptoken/kilo/02.enteringRawMode.html

#include <termios.h>
#include <unistd.h>
#include <stdlib.h>
#include <ctype.h>
#include <stdio.h>

struct termios orig_termios;

void disableRawMode() {
  tcsetattr(STDIN_FILENO, TCSAFLUSH, &orig_termios);

}

void enableRawMode(){
  //struct termios raw;
  //tcgetattr(STDIN_FILENO, &raw);
  tcgetattr(STDIN_FILENO, &orig_termios);
  atexit(disableRawMode);

  struct termios raw = orig_termios;

  //ICANON turn off canonical mode- read input byte by byte instd of line by line
  //input flags usually start with I- but ICANON is local flag. not input.
  raw.c_iflag &= ~(ICRNL | IXON);
  raw.c_oflag &= ~(OPOST);
  raw.c_lflag &= ~(ECHO | ICANON | IEXTEN | ISIG);

  tcsetattr(STDIN_FILENO, TCSAFLUSH, &raw);

}

int main(){

  enableRawMode();

  char c;
  while (read(STDIN_FILENO, &c, 1) == 1 && c!= 'q');
  {
    if  (iscntrl(c)) {
      printf("%d\r\n,", c);

    }
    else {
      printf("%d ('$c')\r\n", c, c);

    }

  }
  return 0;
}
