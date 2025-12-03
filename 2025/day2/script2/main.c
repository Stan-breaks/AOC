#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NUMS 1000

int main(void) {

  FILE *file;
  char c;
  char buf[256];
  char str[256];

  file = fopen("input.txt", "r");
  int i = 0;
  long long seen[MAX_NUMS];
  int seen_count;
  long long sum = 0;
  while ((c = fgetc(file))) {
    if (c == ',' || c == '\n' || c == '\0' || c == EOF) {
      if (c == ',' || c == EOF) {
        buf[i] = '\0';
        int j = strcspn(buf, "-");
        buf[j] = '\0';
        long long num1 = atoll(buf);
        long long num2 = atoll(&buf[j + 1]);
        long long last_num = -1;
        while (num1 <= num2) {
          sprintf(str, "%lld", num1);
          int len = strcspn(str, "\0");
          for (int i = 1; i < len; i++) {
            if (len % i == 0) {
              char temp = str[i];
              str[i] = '\0';

              char str1[] = "";
              for (int j = 0; j < len / i; j++) {
                strcat(str1, str);
              }

              str[i] = temp;
              long long num = atoll(str1);
              int already_seen = 0;
              for (int k = 0; k < seen_count; k++) {
                if (seen[k] == num) {
                  already_seen = 1;
                  break;
                }
              }
              if (!already_seen && seen_count < MAX_NUMS && num >= num1 &&
                  num <= num2) {
                seen[seen_count] = num;
                seen_count++;
              }
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
  for (int i = 0; i < seen_count; i++) {
    sum+=seen[i];
  }
  printf("%lld\n", sum);
  fclose(file);
  return 0;
}
