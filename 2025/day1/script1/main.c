#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void) {
  FILE *file;
  char ch;
  file = fopen("input.txt", "r");

  char buffer[256];
  int dial = 50;
  int ans = 0;
  while (fgets(buffer, sizeof(buffer), file) != NULL) {
    buffer[strcspn(buffer, "\n")] = '\0';
    char dir = buffer[0];
    int num = atoi(&buffer[1]);
    if (dir == 'R') {
      dial += num;
    } else {
      dial -= num;
    }
    while (dial > 99) {
      dial -= 100;
    }
    while (dial < 0) {
      dial += 100;
    }
    if (dial == 0) {
      ans += 1;
    }
  }
  printf("%d", ans);
  fclose(file);
  return 0;
}
