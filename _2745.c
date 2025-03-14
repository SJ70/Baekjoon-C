#include <stdio.h>

char str[10000];
int n;

int main() {
  scanf("%s", &str);
  scanf("%d", &n);
  
  int result = 0;
  for (int i = 0; str[i] != '\0'; i++) {
    result *= n;
    result += (str[i] >= 'A') ? (str[i] - 'A' + 10) : (str[i] - '0');
  }
  printf("%d\n", result);
  return 0;
}