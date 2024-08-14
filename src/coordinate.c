#include "../include/coordinate.h"

tCoordinate *intializeCoordinate(int x, int y)
{
  tCoordinate *coordinate = (tCoordinate *)malloc(sizeof(tCoordinate));

  coordinate->x = x;
  coordinate->y = y;

  return coordinate;
}

bool isTheSamePosition(tCoordinate *current, tCoordinate *past)
{
  return (current->x == past->x && current->y == past->y);
}

void copyCoordinates(tCoordinate *current, tCoordinate *past)
{
  past->x = current->x;
  past->y = current->y;
}

void destroyCoordinate(tCoordinate *coordinate)
{
  free(coordinate);
}
