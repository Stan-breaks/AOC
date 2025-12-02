#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void) {
  FILE *file;
  char buffer[256];
  file = fopen("input.txt", "r");
  int dial = 50;
  int ans = 0;
  while (fgets(buffer, sizeof(buffer), file) != NULL) {
    buffer[strcspn(buffer, "\n")] = '\0';
    printf("%s", buffer);
    int num = atoi(&buffer[1]);
    int iszero = dial;
    if (buffer[0] == 'R') {
      dial += num;
    } else {
      dial -= num;
    }
    if (dial % 100 == 0) {
      if (dial == 0) {
        ans += 1;
      } else {
        if (dial <= -100) {
          ans+=1;
        }
        ans += abs(dial / 100);
      }
      dial = 0;
      printf("      %d", 0);
      printf("\n");
      continue;
    }
    if (dial > 100) {
      if (iszero != 0) {
        ans += dial / 100;
        printf("      %d", 0);
      } else {
        if (dial > 100) {
          ans += dial / 100;
          printf("      %d", 0);
        }
      }
      dial %= 100;
    }
    if (dial < 0) {
      if (iszero != 0) {
        ans += abs((dial - 100) / 100);
        printf("      %d", 0);
      } else {
        if (dial < -100) {
          ans += abs((dial - 100) / 100) - 1;
          printf("      %d", 0);
        }
      }
      dial = 100 + (dial % 100);
    }
    printf("\n");
  }
  printf("%d", ans);
  return 0;
}
