#ifndef SQUARE_H
#define SQUARE_H

#include <stdio.h>
#include <stdlib.h>
#include "./coordinate.h"

#define ROWS 4
#define COLUMNS (ROWS * 2)

typedef char** tSquare;

tSquare createSquare();
void printSquare(tCoordinate*, tSquare);
void destroySquare(tSquare);

#endif
