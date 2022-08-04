/*************************
 *Trinh Tran & Sydney Trout
 *CPSC 2310 F21 Section 002
 *trinht@clemson.edu & sltrout@clemson.edu
 *************************/

#ifndef PPM_H
#define PPM_H

#include "structures.h"
#include <stdio.h>
#include <stdlib.h>

/*
* Parameters - inFile - input file that the function reads the header from
* Return - returns the header_t struct containing the image data
* This function reads the header data in from the input file and stores it
* in a header_t
*/
header_t readHeader(FILE* inFile);

/*
* Parameters - outFile - output file that the function prints the
*              header data to
*              head - header_t that the function prints
* Return - no return but prints the header data to the output file
* This function writes the header data from header_t to the output file
*/
void writeHeader(FILE* outFile, header_t head);

/*
* Parameters - out - output file that the function prints the data to
*              header - holds the header data with the height and width
*              of the file
*              list - linked list that you are looping through to output data
*              bColor - pixel that holds the background color of the image
* Return - no return but prints the shape data to the output file
* This function writes the shape data from the linked list to the output file
*/
void writePixels(FILE* outFile, header_t header, Node *list, pixel_t bColor);

#endif