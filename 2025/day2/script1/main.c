#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void) {
  FILE *file;
  char c;
  char buf[256];
  char str[256];

  file = fopen("input.txt", "r");
  int i = 0;
  long long sum = 0;
  while ((c = fgetc(file))) {
    if (c == ',' || c == '\n' || c == '\0' || c == EOF) {
      if (c == ',' || c == EOF) {
        buf[i] = '\0';
        int j = strcspn(buf, "-");
        buf[j] = '\0';
        long long num1 = atoll(buf);
        long long num2 = atoll(&buf[j + 1]);
        while (num1 <= num2) {
          sprintf(str, "%lld", num1);
          int len = strcspn(str, "\0");
          if (len % 2 == 0) {
            long long n = atoll(&str[len / 2]);
            str[len / 2] = '\0';
            long long m = atoll(str);
            if (m == n) {
              sprintf(str, "%lld%lld", m, m);
              long long num = atoll(str);
              sum += num;
            }
          }
          num1 += 1;
        }

        i = 0;
        if (c == EOF) {
          break;
        }
      }
    } else {
      buf[i] = c;
      i += 1;
    }
  }
  printf("%lld\n", sum);
  fclose(file);
  return 0;
}
