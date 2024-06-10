#include <bits/stdc++.h>

using namespace std;

int solutions[92][8], current_solution[8], a, b, i = 0;
// an optimization is to have bitsets to watch the state of rows, diagonals, and
// left diagonals occupied
bitset<30> rw, ld, rd;

void backtrack(int c) {
  if (c == 8 && i < 92) {
    for (int k = 0; k < 8; k++)
      solutions[i][k] = current_solution[k];
    i++;
    return;
  }

  for (int r = 0; r < 8; r++) {
    if (rw[r] || ld[r - c + 8 - 1] || rd[r + c])
      continue;
    rw[r] = ld[r - c + 8 - 1] = rd[r + c] = true;
    current_solution[c] = r;
    backtrack(c + 1);
    rw[r] = ld[r - c + 8 - 1] = rd[r + c] = false;
  }
}

int main() {
  int t, lineCounter;
  scanf("%d", &t);
  // Precompute all values
  memset(current_solution, 0, sizeof current_solution);
  backtrack(0);
  while (t--) {
    scanf("%d %d", &a, &b);
    a--, b--;

    printf("SOLN       COLUMN\n");
    printf(" #      1 2 3 4 5 6 7 8\n\n");
    lineCounter = 0;
    for (int k = 0; k < 92; k++)
      if (solutions[k][b] == a) {
        printf("%2d      %d", ++lineCounter, solutions[k][0] + 1);
        for (int j = 1; j < 8; ++j)
          printf(" %d", solutions[k][j] + 1);
        printf("\n");
      }

    if (t != 0)
      printf("\n");
  }
}
