/*************************
 *Trinh Tran & Sydney Trout
 *CPSC 2310 F21 Section 002
 *trinht@clemson.edu & sltrout@clemson.edu
 *************************/

#include "shape.h"
#include <string.h>
#include <math.h>

Node *makeList(FILE* inFile) {
    int numShapes = 0;
    Shape shape;
    pixel_t color;
    //reads in the number of shapes
    fscanf(inFile, "%d", &numShapes);
    Node *shapeList = NULL;
    int red, green, blue;
    
    //loops through the file for the number of shapes
    for (int i = 0; i < numShapes; i++) {
        char shapeName[15];
        //reads in the shape name
        fscanf(inFile, "%s", shapeName);
        //depending on the shape name, reads in the shape data
        if (strcmp(shapeName, "Circle") == 0){
            fscanf(inFile, "%d %d %d", &shape.circle.center.x,
            &shape.circle.center.y, &shape.circle.radius);
            shape.triangle.one.x = -1;
            shape.quadrilateral.one.x = -1;
        }
        if (strcmp(shapeName, "Triangle") == 0){
            fscanf(inFile, "%d %d", &shape.triangle.one.x,
            &shape.triangle.one.y);
            fscanf(inFile, "%d %d", &shape.triangle.two.x,
            &shape.triangle.two.y);
            fscanf(inFile, "%d %d", &shape.triangle.three.x,
            &shape.triangle.three.y);
            shape.circle.center.x = -1;
            shape.quadrilateral.one.x = -1;
        }
        if (strcmp(shapeName, "Quadrilateral") == 0){
            fscanf(inFile, "%d %d", &shape.quadrilateral.one.x,
            &shape.quadrilateral.one.y);
            fscanf(inFile, "%d %d", &shape.quadrilateral.two.x,
            &shape.quadrilateral.two.y);
            fscanf(inFile, "%d %d", &shape.quadrilateral.three.x,
            &shape.quadrilateral.three.y);
            fscanf(inFile, "%d %d", &shape.quadrilateral.four.x,
            &shape.quadrilateral.four.y);
            shape.circle.center.x = -1;
            shape.triangle.one.x = -1;
        }
        //reads in the color data of the shape
        fscanf(inFile, "%d %d %d", &red, &green, &blue);
            color.r = red;
            color.g = green;
            color.b = blue;
        //inserts the shape data and color into the linked list
        shapeList = insert(shapeList, shape, color);
    }
    return shapeList;
}

char *whatShape(Shape shape) {
    //returns what shape is at that node of the linked list
    if (shape.circle.center.x != -1) return "Circle";
    if (shape.triangle.one.x != -1) return "Triangle";
    if (shape.quadrilateral.one.x != -1) return "Quadrilateral";
    return "-1";
}

Node *insert(Node *head, Shape shape, pixel_t color) {
    //allocates memory in the linked list
    Node *newNode = (Node*) malloc(sizeof(Node));
    newNode->shape = shape;
    newNode->color = color;
    newNode->next = NULL;

    //if it is the start of the list
    if(head == NULL) {
        head = newNode;
        return head;
    }

    //otherwise add to the end of the list
    for (Node *n = head; n != NULL; n = n->next) {
         if (n->next == NULL) {
             n->next = newNode;
             break;
        }
     }

    return head;
}

pixel_t readBackgroundColor(FILE *inFile) {
    pixel_t color;
    int red, green, blue;
    //reads in the background color and stores it in a pixel
    fscanf(inFile, "%*s");
    fscanf(inFile, "%d %d %d", &red, &green, &blue);
    color.r = red;
    color.g = green;
    color.b = blue;

    return color;
}

int isHitCir(Circle circle, Point test) {
    int x = test.x;
    int y = test.y;
    int centerX = circle.center.x;
    int centerY = circle.center.y;
    int r = circle.radius;
    //returns 1 or 0 if the test point is in the circle shape
    return sqrt(pow(x-centerX, 2) + pow(y-centerY, 2)) < r;
}

int isHitTri(Triangle triangle, Point test)
{
    double x = test.x;
    double y = test.y;

    double x1 = triangle.one.x;
    double y1 = triangle.one.y;

    double x2 = triangle.two.x;
    double y2 = triangle.two.y;

    double x3 = triangle.three.x;
    double y3 = triangle.three.y;

    double a = 0, b = 0, c = 0;

    //formulas to compute if test is within the bounds of p1, p2, p3s
    a = ((y2-y3)*(x-x3)+(x3 - x2)*(y - y3))/((y2-y3)*(x1-x3)+(x3-x2)*(y1-y3));
    b = ((y3-y1)*(x-x3)+(x1-x3)*(y-y3))/((y2-y3)*(x1-x3)+(x3-x2)*(y1-y3));
    c = 1 - a - b;

    //check to see if test is in p1, p2, p3
    if (a >= 0 && a <= 1) {
        if (b >= 0 && b <= 1) {
            if (c >= 0 && b <= 1) {
                return 1;
            }
        }
    }
    return 0;
}

int isHitQud(Quadrilateral qud, Point test) {
    Triangle ABC;
    Triangle BCD;
    Triangle ABD;
    Triangle ACD;

    //creates the four triangles that form the quadrilateral
    ABC.one.x = qud.one.x;
    ABC.one.y = qud.one.y;
    ABC.two.x = qud.two.x;
    ABC.two.y = qud.two.y;
    ABC.three.x = qud.three.x;
    ABC.three.y = qud.three.y;

    BCD.one.x = qud.two.x;
    BCD.one.y = qud.two.y;
    BCD.two.x = qud.three.x;
    BCD.two.y = qud.three.y;
    BCD.three.x = qud.four.x;
    BCD.three.y = qud.four.y;

    ABD.one.x = qud.one.x;
    ABD.one.y = qud.one.y;
    ABD.two.x = qud.two.x;
    ABD.two.y = qud.two.y;
    ABD.three.x = qud.four.x;
    ABD.three.y = qud.four.y;

    ACD.one.x = qud.one.x;
    ACD.one.y = qud.one.y;
    ACD.two.x = qud.three.x;
    ACD.two.y = qud.three.y;
    ACD.three.x = qud.four.x;
    ACD.three.y = qud.four.y;

    //returns 1 or 0 if the test point is in the quadrilateral shape
    return isHitTri(ABC, test) || isHitTri(BCD, test) ||
           isHitTri(ABD, test) || isHitTri(ACD, test);
}

