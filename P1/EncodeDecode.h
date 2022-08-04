#ifndef ENCODEDECODE_H
#define ENCODEDECODE_H
#include "ppm.h"
#include "utils.h"
#include <stdio.h>
#include <stdlib.h>

typedef unsigned long uintptr_t;

void removeDigit(pixel_t**, header_t);
void encodeMsg(FILE* in, FILE* out, char* msg);
void charToBinary(char , int *);
unsigned char binToCharacter(int*);
void queue(int, int*, int*);
void dec2bin(int*, int);
void decodeMsg(FILE*);

#endif