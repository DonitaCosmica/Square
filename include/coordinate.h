#ifndef COORDINATE_H
#define COORDINATE_H

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct
{
  int x;
  int y;
} tCoordinate;

tCoordinate *intializeCoordinate(int, int);
bool isTheSamePosition(tCoordinate*, tCoordinate*);
void copyCoordinates(tCoordinate*, tCoordinate*);
void destroyCoordinate(tCoordinate*);

#endif
