#include <stdio.h>
#include <stdlib.h>

#define ATOI_BUFFER_SIZE 20
char atoiBuffer[ATOI_BUFFER_SIZE];
int atoiBufferIndex = 0;

void convertAndStore(const char* input, int digits) {
  if (atoiBufferIndex + digits + 1 > ATOI_BUFFER_SIZE) {
    atoiBufferIndex = 0;
  }
  char* result = &*(atoiBuffer + atoiBufferIndex);
  atoiBufferIndex = (atoiBufferIndex + digits + 1) % ATOI_BUFFER_SIZE;

  int value = atoi(input);
  snprintf(result, digits + 1, "%d", value);
}

int main() {
  convertAndStore("12345", 5);
  convertAndStore("6789", 4);
  convertAndStore("9876543210", 10);

  for (int i = 0; i < ATOI_BUFFER_SIZE; i++) {
    printf("%c", atoiBuffer[i]);
  }
  printf("\n");

  return 0;
}
