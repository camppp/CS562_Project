#include <stdio.h>
#include <stdarg.h>
#include <stdlib.h>

char* my_ssprintf(const char* fmt, ...) {
  va_list ap;
  va_start(ap, fmt);
  char buf[4097];
  int len = vsnprintf(buf, 4096, fmt, ap);
  va_end(ap);

  if (len < 0) {
    return NULL;  // Error in formatting
  }

  char* result = (char*)malloc((len + 1) * sizeof(char));
  if (result == NULL) {
    return NULL;  // Memory allocation failed
  }

  for (int i = 0; i < len; i++) {
    result[i] = buf[i];
  }
  result[len] = '\0';

  return result;
}

int main() {
  char* formatted = my_ssprintf("The value of pi is %f", 3.14159);
  if (formatted != NULL) {
    printf("%s\n", formatted);
    free(formatted);
  }

  char* name = "Alice";
  int age = 25;
  char* message = my_ssprintf("%s is %d years old", name, age);
  if (message != NULL) {
    printf("%s\n", message);
    free(message);
  }

  return 0;
}
