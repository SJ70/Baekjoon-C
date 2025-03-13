#include <stdio.h>

typedef struct Node {
  int idx;
  int move;
  struct Node* left;
  struct Node* right;
} Node;

Node nodes[1000];

int main() {
  int size;
  scanf("%d", &size);

  // 노드 초기화
  for (int i=0; i<size; i++) {
    nodes[i].idx = i;
    scanf("%d", &(nodes[i].move));
  }

  // 노드 연결
  for (int i=0; i<size-1; i++) {
    nodes[i].right = &nodes[i+1];
  }
  for (int i=1; i<size; i++) {
    nodes[i].left = &nodes[i-1];
  }
  nodes[0].left = &nodes[size-1];
  nodes[0].right = &nodes[1];

  // 이동
  Node* cur = &nodes[0];
  for (int i=0; i<size; i++) {
    printf("%d ", (cur->idx + 1));
    cur->left->right = cur->right;
    cur->right->left = cur->left;

    int dir = cur->move > 0 ? 1 : -1;
    int dist = cur->move * dir;
    for (int j=0; j<dist; j++) {
      if (dir == 1) {
        cur = cur->right;
      }
      else {
        cur = cur->left;
      }
    }
  }
}