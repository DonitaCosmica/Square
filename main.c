#include <string.h>
#include <ctype.h>
#include <termios.h>
#include <unistd.h>

#include "./include/square.h"

typedef struct
{
  tCoordinate *currentState;
  tCoordinate *pastState;
  tSquare square;
} tGame;

void activate_no_echo_mode();
void deactivate_no_echo_mode();

int main(int argc, char *argv[])
{
  char key = '\n', opt = '\n', c;
  tGame game;
  game.currentState = intializeCoordinate(1, 1);
  game.pastState = intializeCoordinate(1, 1);
  game.square = createSquare();

  if(game.currentState == NULL || game.square == NULL || game.pastState == NULL)
    return EXIT_FAILURE;

  system("clear");
  printSquare(game.currentState, game.square);

  while(true)
  {
    activate_no_echo_mode();
    key = getchar();
    deactivate_no_echo_mode();
    opt = tolower(key);

    switch(opt)
    {
      case 'a': game.currentState->x--; break;
      case 'd': game.currentState->x++; break;
      case 'w': game.currentState->y--; break;
      case 's': game.currentState->y++; break;
      default:
    }

    while((c = getchar()) != '\n' && c != EOF);

    if(!isTheSamePosition(game.currentState, game.pastState))
    {
      system("clear");
      printSquare(game.currentState, game.square);
      usleep(100000);
    }

    copyCoordinates(game.currentState, game.pastState);
  }

  destroyCoordinate(game.currentState);
  destroyCoordinate(game.pastState);
  destroySquare(game.square);

  if(game.currentState == NULL)
    return EXIT_FAILURE;

  return EXIT_SUCCESS;
}

void activate_no_echo_mode()
{
  struct termios term;
  tcgetattr(STDIN_FILENO, &term);
  term.c_lflag &= ~(ECHO | ICANON);
  tcsetattr(STDIN_FILENO, TCSANOW, &term);
}

void deactivate_no_echo_mode()
{
  struct termios term;
  tcgetattr(STDIN_FILENO, &term);
  term.c_lflag |= (ECHO | ICANON);
  tcsetattr(STDIN_FILENO, TCSANOW, &term);
}
