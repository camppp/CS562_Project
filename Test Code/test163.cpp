#include <stdio.h>

// Define the Embedded struct
typedef struct {
  // Define the members of the Embedded struct
} Embedded;

// Define the ReturnStruct
typedef struct {
  unsigned char a;
  Embedded b;
  unsigned char c;
} ReturnStruct;

// Implement the ConstructReturnStruct function
ReturnStruct ConstructReturnStruct(unsigned char a, Embedded b, unsigned char c) {
  ReturnStruct ret;
  ret.a = a;
  ret.b = b;
  ret.c = c;
  return ret;
}

int main() {
  // Example usage
  Embedded emb;  // Initialize the Embedded struct with appropriate values
  ReturnStruct result = ConstructReturnStruct(10, emb, 20);
  printf("a: %d, b: %d, c: %d\n", result.a, result.b, result.c);
  return 0;
}
