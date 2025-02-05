#include <limits.h>
#include <stdio.h>
#include <string.h>

inline int min(int x, int y) { return x > y ? y : x; }

int N, Cmin = INT_MAX;
int c[30][30];
int visited[30];
int path[30];
int cur = 0, best = INT_MAX;

int Check(int k, int v) {
  if (visited[v])
    return 0;
  if (cur + c[path[k - 1]][v] > best)
    return 0;

  return 1;
}

void Try(int k) {
  for (int v = 1; v <= N; v++) {
    if (Check(k, v)) {
      path[k] = v;
      visited[v] = 1;
      cur += c[path[k - 1]][v];

      if (k == N) {
        best = min(cur + c[v][0], best);
        // printf("Best: %d\nPath: ", best);
        // for (int i = 0; i <= N; i++)
        //   printf("%d ", path[i]);
        // printf("\n");
      } else if (cur + (N - k) * Cmin <= best)
        Try(k + 1);

      cur -= c[path[k - 1]][v];
      visited[v] = 0;
    }
  }
}

void Init() {
  memset(visited, 0, sizeof(visited));
  memset(path, 0, sizeof(path));
}

int main() {
  scanf("%d", &N);
  N -= 1;

  for (int i = 0; i <= N; i++) {
    for (int j = 0; j <= N; j++) {
      scanf("%d", &c[i][j]);
      if (i != j)
        Cmin = min(Cmin, c[i][j]);
    }
  }

  Init();
  Try(1);
  printf("%d\n", best);
}