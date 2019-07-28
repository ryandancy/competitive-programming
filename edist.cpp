// EDIST - Edit distance
// Dynamic programming with prefix matrix

#include <cstring>
#include <iostream>

using namespace std;

int dists[3000][3000];

int edist(char a[], char b[], int A, int B) {
  if (A == 0 && B == 0) return 0;
  for (int y = 1; y <= B; y++) {
    for (int x = 1; x <= A; x++) {
      dists[y][x] = min(min(dists[y-1][x], dists[y][x-1]) + 1, dists[y-1][x-1] + (a[x-1] != b[y-1]));
    }
  }
  return dists[B][A];
}

int main() {
  for (int i = 0; i < 3000; i++) dists[i][0] = dists[0][i] = i;
  
  int T;
  cin >> T;
  char a[3000], b[3000];
  cin.getline(a, 256); // waste
  for (int t = 0; t < T; t++) {
    cin.getline(a, 3000);
    cin.getline(b, 3000);
    cout << edist(a, b, strlen(a), strlen(b)) << endl;
  }
}
