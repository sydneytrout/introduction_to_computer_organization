/*************************
 *Trinh Tran & Sydney Trout
 *CPSC 2310 F21 Section 002
 *trinht@clemson.edu & sltrout@clemson.edu
 *************************/

#include "shape.h"
#include "ppm.h"
#include <string.h>

header_t readHeader(FILE* inFile) {
    header_t header;
    //reads in the header data from the input file
    fscanf(inFile, "%s %d %d %d", header.magicNum, &header.width, 
                                           &header.height, &header.maxVal);
    return header;
}

void writeHeader(FILE* outFile, header_t header) {
    //writes the header data to the output file
    fprintf(outFile, "%s\n%d %d %d\n",  header.magicNum, header.width,
                                        header.height, header.maxVal);
}

void writePixels(FILE* out, header_t header, Node *list, pixel_t bColor) {
    int row = header.height;
    int col = header.width;
    Point test;
    int hit = 0;
    //loops through all of the pixels in the output file
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            test.x = j;
            test.y = i;
            hit = 0;
            //loops through the linked list to see if the point is in any of
            //the shapes
            for (Node *n = list; n != NULL; n=n->next) {
                if (strcmp(whatShape(n->shape), "Circle") == 0) {
                    if(isHitCir(n->shape.circle, test)) {
                        hit = 1;
                   }
                }
                else if (strcmp(whatShape(n->shape), "Triangle") == 0) {
                    if (isHitTri(n->shape.triangle, test)) {
                        hit = 1;
                    }
                }
                else if (strcmp(whatShape(n->shape), "Quadrilateral") == 0) {
                    if (isHitQud(n->shape.quadrilateral, test)) {
                        hit = 1;
                    }
                }
                //outputs the color of the shape if it is within a shape
                if (hit) {
                    fprintf(out, "%c%c%c", n->color.r, n->color.g, n->color.b);
                    break;
                }
            }
            //outputs the background color if it is not in a shape
            if (!hit) {
                fprintf(out, "%c%c%c", bColor.r, bColor.g, bColor.b);
            }
        }
    }

}



