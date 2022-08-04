/*************************
 *Trinh Tran & Sydney Trout
 *CPSC 2310 F21 Section 002
 *trinht@clemson.edu & sltrout@clemson.edu
 *************************/

#include "ppm.h"
#include "shape.h"

int main(int argc, char *argv[]) { 
    Node *shapeList = NULL;
    //opens the input file
    FILE *in = fopen(argv[1], "r");

    //reads in the header
    header_t header = readHeader(in);
    //creates the linked list
    shapeList = makeList(in);
    //reads in the background color
    pixel_t bColor = readBackgroundColor(in);

    //writes the data to the output files
    FILE *out = fopen(argv[2], "w");
    writeHeader(out, header);
    writePixels(out, header, shapeList, bColor);    

    
    return 0;
}