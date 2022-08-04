/*************************
 *Stephen Mills & Sydney Trout
 *CPSC 2310 F21 Section 001
 *smills3@clemson.edu & sltrout@clemson.edu
 *************************/

#include "ppm.h"

header_t readHeader(FILE* inFile) {
  header_t head;
  fscanf(inFile, "%s %d %d %d ", head.magicNum, &head.width, &head.height, &head.maxVal);
  return head;
}

pixel_t** readPixel(FILE* inFile, header_t head) {
  pixel_t** pix;
  pix = (pixel_t**)malloc(head.width * head.height * sizeof(pixel_t));
  while (!EOF) {
    fscanf(inFile, "%c%c%c", &(*pix)->r, &(*pix)->g, &(*pix)->b);
  }

  return pix;
}

void writeHeader(FILE* outFile, header_t head) {
  fprintf(outFile, "%s\n%d %d\n%d\n", head.magicNum, head.width, head.height, head.maxVal);
}

void writePixels(FILE* outFile, pixel_t** pix, header_t head) {
  for (int i = 0; i < head.width; i++) {
    for (int j = 0; j < head.height; j++) {
      fprintf(outFile, "%c%c%c", (*pix)->r, (*pix)->g, (*pix)->b);
    }
  }
}

void ckws_comments (FILE *);
void freeMemory(pixel_t** pix, header_t head) {
  for (int i = 0; i < head.width; i++) {
    for (int j = 0; j < head.height; j++) {
      free(*pix);
    }
  }
  free(pix);
}