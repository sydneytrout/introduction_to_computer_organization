/*************************
 *Trinh Tran & Sydney Trout
 *CPSC 2310 F21 Section 002
 *trinht@clemson.edu & sltrout@clemson.edu
 *************************/

#ifndef STRUCTURES_H
#define STRUCTURES_H

typedef struct {
    char magicNum[3];
    int width;
    int height;
    int maxVal;
}header_t;

typedef struct {
    unsigned char r;
    unsigned char g;
    unsigned char b;
}pixel_t;

typedef struct {
    int x, y;
} Point;

typedef struct {
    Point center;
    int radius;
} Circle;

typedef struct {
    Point one, two, three;
} Triangle;

typedef struct {
    Point one, two, three, four;
} Quadrilateral;

typedef struct {
    Circle circle;
    Triangle triangle;
    Quadrilateral quadrilateral;
} Shape;

typedef struct NODE {
    Shape shape;
    pixel_t color;
    struct NODE *next;
}Node;

#endif