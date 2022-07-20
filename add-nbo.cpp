#include <stddef.h>
#include <stdint.h>
#include <stdio.h>

uint32_t read_file(char* file){
  uint8_t buffer[4];
  uint32_t res = 0;
  FILE *fp;

  fp = fopen(file, "rb");
  fread(buffer, 1, 4, fp);

  uint32_t* p = reinterpret_cast<uint32_t*>(buffer);
	uint32_t n = *p;

  fclose(fp);

  res =
    ((n & 0x000000FF) << 24) |
    ((n & 0x0000FF00) << 8) |
    ((n & 0x00FF0000) >> 8) |
    ((n & 0xFF000000) >> 24);
  return res;
}

int main(int argc, char* argv[]) {
  uint32_t a = 0, b = 0, c = 0;
  a = read_file(argv[1]);
  b = read_file(argv[2]);
  c = a + b;

  printf("%d(0x%x) + %d(0x%x) = %d(0x%x)", a, a, b, b, c, c);
  return 0;

}
