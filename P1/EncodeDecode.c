#include "EncodeDecode.h"
#include "utils.h"
#include <stdio.h>
#include <stdlib.h>

void removeDigit(pixel_t** pix, header_t head){
    printf("%d\n", &(*pix)->r);
    uintptr_t removeR = (uintptr_t)(*pix)->r % 10;
    (*pix)->r = (uintptr_t)(*pix)->r - removeR;
    uintptr_t removeG = (uintptr_t)(*pix)->g % 10;
    (*pix)->g = (uintptr_t)(*pix)->g - removeG;
    uintptr_t removeB = (uintptr_t)(*pix)->b % 10;
    (*pix)->b = (uintptr_t)(*pix)->b - removeB;
}

void encodeMsg(FILE* in, FILE* out, char* msg){
    int charCount = 0;
    int bitCount = 0;
    int temp[9];
    header_t head = readHeader(in);
    writeHeader(out, head);
    
}
// void charToBinary(char , int *){

// }

// unsigned char binToCharacter(int*){

// }

// void queue(int, int*, int*);

void dec2bin(int* num, int spaces){
    int temp[spaces];
    int *n = num;
    for(int i=0; n>0; i++){    
        temp[i]=*n%2;    
        *n=*n/2;
    }
}

void decodeMsg(FILE*);
