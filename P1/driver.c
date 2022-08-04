#include "ppm.h"
#include "utils.h"
#include "EncodeDecode.h"
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char* argv[])
{
    checkArgs(argc, 2);
    FILE* in = fopen(argv[1], "r");
    checkFile(in);
    FILE* out = fopen(argv[2], "w");
    checkFile(out);
    /*This is my test message.  It can be something different*/
    char* msg = "I hope this works!";
    encodeMsg(in, out, msg);

    FILE* dec = fopen(argv[2], "r");
    checkFile(dec);
    decodeMsg(dec);

    fclose(in);
    fclose(out);
    fclose(dec);

    return EXIT_SUCCESS;
}


