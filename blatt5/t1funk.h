#ifndef MY_HEADER_H
#define MY_HEADER_H
#include <stdio.h>

#define COLOR_RESET  printf("\x1B[0m")
#define COLOR_RED    printf("\x1B[31m")
#define COLOR_GREEN  printf("\x1B[32m")
#define COLOR_YELLOW printf("\x1B[33m")
#define COLOR_CYAN   printf("\x1B[36m")

extern const int field[9][9];


extern int playfield[9][9];



void printfield(int z, int s, int n,int wrong);

void printinstructions(void);

int checkline(int playfield[9][9]);

#endif
