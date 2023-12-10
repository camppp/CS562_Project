typedef struct {
  unsigned char a;
  Embedded b;
  unsigned char c;
} ReturnStruct;

typedef struct {
  // Define the Embedded struct here
} Embedded;

ReturnStruct ConstructReturnStruct(unsigned char a, Embedded b, unsigned char c) {
  ReturnStruct result;
  result.a = a;
  result.b = b;
  result.c = c;
  return result;
}
