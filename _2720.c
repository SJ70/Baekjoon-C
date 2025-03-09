#include <stdio.h>


int main() {

  int n;
  scanf("%d", &n);

  for (int t=0; t<n; t++) {
    int value;
    scanf("%d", &value);

    int quarter = value / 25;
    value %= 25;

    int dime = value / 10;
    value %= 10;

    int nickel = value / 5;
    value %= 5;

    int penny = value;
    
    printf("%d %d %d %d\n", quarter, dime, nickel, penny);
  }

  return 0;

}