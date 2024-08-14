#include "../include/square.h"

static void gotoxy(int x, int y)
{
  printf("%c[%d;%df", 0x1B, x, y);
}

tSquare createSquare()
{
  int i, j;
  tSquare square = (tSquare)malloc(sizeof(char *) * ROWS);

  if(square == NULL)
    return NULL;

  for(i = 0; i < ROWS; i++)
  {
    square[i] = (char *)malloc(sizeof(char) * COLUMNS);

    if(square[i] == NULL)
      return NULL;
  }

  for(i = 0; i < ROWS; i++)
  {
    for(j = 0; j < COLUMNS; j++)
      square[i][j] = ((i == 0 || i == ROWS - 1) || (j == 0 || j == COLUMNS - 1)) ? '*' : ' ';
  }

  return square;
}

void printSquare(tCoordinate *coordinate, tSquare square)
{
  int i, j;

  for(i = 0; i < ROWS; i++)
  {
    for(j = 0; j < COLUMNS; j++)
    {
      gotoxy(i + coordinate->y, j + coordinate->x);
      printf("%c", square[i][j]);
    }

    puts("");
  }
}

void destroySquare(char **square)
{
  int i = 0;

  for(; i < ROWS; i++)
    free(square[i]);

  free(square);
}
