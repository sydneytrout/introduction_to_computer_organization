#include "ppm.h"
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
  FILE* in = fopen(argv[1], "r");
  FILE* out = fopen(argv[2], "w");
  header_t head;
  pixel_t** pix;

  head = readHeader(in);
  pix = readPixel(in, head);
  writeHeader(out, head);
  writePixels(out, pix, head);

  freeMemory(pix, head);
  
  fclose(in);
  fclose(out);

  return 0;
}