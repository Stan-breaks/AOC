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

    int num = 0;
    for (int i = 0; i < len - 1; i++) {
      for (int j = i + 1; j < len; j++) {
        char str[3];
        str[0] = buffer[i];
        str[1] = buffer[j];
        str[2] = '\0';
        int n = atoi(str);
        if (n > num) {
          num = n;
        }
      }
    }
    sum += num;
  }
  printf("%d\n", sum);
  return 0;
}
