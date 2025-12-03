#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void) {
  FILE *file;
  char buffer[256];
  file = fopen("input.txt", "r");
  int sum = 0;
  while (fgets(buffer, sizeof(buffer), file) != NULL) {
    buffer[strcspn(buffer, "\n")] = '\0';
    int len = strlen(buffer);

   
  }
  printf("%d\n", sum);
  return 0;
}

