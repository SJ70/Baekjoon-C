#include <stdio.h>

int arr[1000000];
int size = 0;

int isEmpty() {
  return size == 0;
}

void add(int value) {
  arr[size++] = value;
}

int peek() {
  return arr[size-1];
}

int poll() {
  return arr[--size];
}

int getSize() {
  return size;
}


int main() {

  int n;
  scanf("%d", &n);
  getchar();

  for (int i=0; i<n; i++) {

    int command, value;
    scanf("%d", &command);

    switch (command) {
      case 1 : 
        scanf("%d", &value);
        getchar();
        add(value);
        break;

      case 2 : 
        printf("%d\n", isEmpty() ? -1 : poll());
        getchar();
        break;

      case 3 : 
        printf("%d\n", getSize());
        getchar();
        break;

      case 4 : 
        printf("%d\n", isEmpty());
        getchar();
        break;

      case 5 : 
        printf("%d\n", isEmpty() ? -1 : peek());
        getchar();
        break;

      default:
        break;
    }
    
  }

  return 0;

}