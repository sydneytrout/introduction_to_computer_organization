/*************************
 *Trinh Tran & Sydney Trout
 *CPSC 2310 F21 Section 002
 *trinht@clemson.edu & sltrout@clemson.edu
 *************************/

#ifndef SHAPE_H
#define SHAPE_H

#include <stdio.h>
#include <stdlib.h>
#include "structures.h"
#include "ppm.h"



/*
* Parameters - head - node that you are placing data at the end of
*              shape - shape that you are adding to the end of the linked list
               color - color of the shape you are adding to the linked list
* Return - return the head pointer of the linked list with the new shape and
* color added to the end
* This function adds shapes and their respective colors to the end of the
* linked list
*/
Node *insert(Node *head, Shape shape, pixel_t color);

/*
* Parameters - inFile - file that you are reading the data in from
* Return - head pointer to the completed linked list with all of the shapes
* This function reads in the data from the input file and creates a 
* linked list of shapes
*/
Node* makeList(FILE * inFile);

/*
* Parameters - inFile - file that you are reading the data in from
* Return - the pixel that stroes the data of the background color
* This function reads the background color from the input file and
* stores it in a pixel
*/
pixel_t readBackgroundColor(FILE *inFile);

/*
* Parameters - circle - circle shape that you are checking if the 
*              point is in
*              test - point that you are testing to see if it is
*              in the circle
* Return - 1 or 0 based on whether the point is in the circle
* This function returns 1 or 0 based on whether the point is in the circle
*/
int isHitCir(Circle circle, Point test);

/*
* Parameters - triangle - triangle shape that you are checking if the 
*              point is in
*              test - point that you are testing to see if it is
*              in the triangle
* Return - 1 or 0 based on whether the point is in the triangle
* This function returns 1 or 0 based on whether the point is in the triangle
*/
int isHitTri(Triangle triangle, Point test);

/*
* Parameters - qud - quadrilateral shape that you are checking if the 
*              point is in
*              test - point that you are testing to see if it is
*              in the quadrilateral
* Return - 1 or 0 based on whether the point is in the quadrilateral
* This function returns 1 or 0 based on whether the point is in the 
* quadrilateral
*/
int isHitQud(Quadrilateral qud, Point test);

/*
* Parameters - shape - shape that you are trying to figure out if it is a
*              circle, triangle, or quadrilateral
* Return - character pointer that holds the word circle, triangle, 
* quadrilateral, or -1
* This function a character pointer that holds the word circle, triangle, 
* quadrilateral, or -1
*/
char *whatShape(Shape shape);


#endif