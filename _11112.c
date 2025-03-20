#include <stdio.h>

int distance[9][9][9][9][9][9][9][9];
char visited[9][9][9][9][9][9][9][9];


char queue[200000][8];
int queue_dist[200000];
int queue_rear = 0;

void addQueue(char a, char b, char c, char d, char e, char f, char g, char h, int dist) {
  if (visited[a][b][c][d][e][f][g][h]) {
    return;
  }
  visited[a][b][c][d][e][f][g][h] = 1;
  distance[a][b][c][d][e][f][g][h] = dist;

  queue[queue_rear][0] = a;
  queue[queue_rear][1] = b;
  queue[queue_rear][2] = c;
  queue[queue_rear][3] = d;
  queue[queue_rear][4] = e;
  queue[queue_rear][5] = f;
  queue[queue_rear][6] = g;
  queue[queue_rear][7] = h;
  queue_dist[queue_rear] = dist;
  queue_rear++;
}

int main() {

  addQueue(1,2,3, 4,5,6, 7,8, 0);
  
  for (int j=0; j<queue_rear; j++) {
    char a = queue[j][0];
    char b = queue[j][1];
    char c = queue[j][2];
    char d = queue[j][3];
    char e = queue[j][4];
    char f = queue[j][5];
    char g = queue[j][6];
    char h = queue[j][7];
    char i = 36 - a - b - c - d - e - f - g - h;
    int dist = queue_dist[j];

    dist++;
    if (a == 0) {
      addQueue(d,b,c, a,e,f, g,h, dist);
      addQueue(b,a,c, d,e,f, g,h, dist);
      continue;
    }
    if (b == 0) {
      addQueue(a,e,c, d,b,f, g,h, dist);
      addQueue(b,a,c, d,e,f, g,h, dist);
      addQueue(a,c,b, d,e,f, g,h, dist);
      continue;
    }
    if (c == 0) {
      addQueue(a,b,f, d,e,c, g,h, dist);
      addQueue(a,c,b, d,e,f, g,h, dist);
      continue;
    }
    if (d == 0) {
      addQueue(d,b,c, a,e,f, g,h, dist);
      addQueue(a,b,c, g,e,f, d,h, dist);
      addQueue(a,b,c, e,d,f, g,h, dist);
      continue;
    }
    if (e == 0) {
      addQueue(a,e,c, d,b,f, g,h, dist);
      addQueue(a,b,c, d,h,f, g,e, dist);
      addQueue(a,b,c, e,d,f, g,h, dist);
      addQueue(a,b,c, d,f,e, g,h, dist);
      continue;
    }
    if (f == 0) {
      addQueue(a,b,f, d,e,c, g,h, dist);
      addQueue(a,b,c, d,e,i, g,h, dist);
      addQueue(a,b,c, d,f,e, g,h, dist);
      continue;
    }
    if (g == 0) {
      addQueue(a,b,c, g,e,f, d,h, dist);
      addQueue(a,b,c, d,e,f, h,g, dist);
      continue;
    }
    if (h == 0) {
      addQueue(a,b,c, d,h,f, g,e, dist);
      addQueue(a,b,c, d,e,f, h,g, dist);
      addQueue(a,b,c, d,e,f, g,i, dist);
      continue;
    }
    if (i == 0) {
      addQueue(a,b,c, d,e,i, g,h, dist);
      addQueue(a,b,c, d,e,f, g,i, dist);
      continue;
    }

  }


  int T;
  scanf("%d", &T);
  for (int t=0; t<T; t++) {
    char target[9];
    for (int r=0; r<3; r++) {
      char str[4];
      scanf("%s", &str);
      for (int c=0; c<3; c++) {
        char value = str[c];
        target[r*3+c] = (value=='#') ? 0 : value-'0';
      }
    }

    if (visited[target[0]][target[1]][target[2]][target[3]][target[4]][target[5]][target[6]][target[7]]) {
      printf("%d\n", distance[target[0]][target[1]][target[2]][target[3]][target[4]][target[5]][target[6]][target[7]]);
    }
    else {
      printf("impossible\n");
    }
  }

  return 0;
}