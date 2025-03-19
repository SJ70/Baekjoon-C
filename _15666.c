#include <stdio.h>

int n, m;

int numsCnt = 0;
int nums[8];
int isContained[10001];

int result[8];

void dfs(int depth, int idx) {
  if (depth == m) {
    for (int i=0; i<m; i++) {
      printf("%d ", result[i]);
    }
    printf("\n");
    return;
  }

  for (int i=idx; i<numsCnt; i++) {
    result[depth] = nums[i];
    dfs(depth+1, i);
  }
}

int main() {

  // input
  scanf("%d %d", &n, &m);
  for (int i=0; i<n; i++) {
    int num;
    scanf("%d", &num);
    if (isContained[num] == 0) {
      isContained[num] = 1;
      nums[numsCnt] = num;
      numsCnt++;
    }
  }

  // sort
  for (int i=0; i<numsCnt-1; i++) {
    for (int j=i+1; j<numsCnt; j++) {
      if (nums[i] > nums[j]) {
        int tmp = nums[i];
        nums[i] = nums[j];
        nums[j] = tmp;
      }
    }
  }

  dfs(0, 0);

  return 0;
}