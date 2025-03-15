#include <stdio.h>

int n, b;
char str[100];

int main() {
  scanf("%d", &n);
  scanf("%d", &b);

  str[99] = '\0';
  int i = 98;
  for (; n>0; i--) {
    int value = n % b;
    str[i] = (value > 9) ? (value - 10 + 'A') : '0' + value;
    n /= b;
  }

  printf("%s\n", &str[i + 1]);

  return 0;
}