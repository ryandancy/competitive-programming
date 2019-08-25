// 1208C - Magic Grid
// We organize each consecutive group of 16 numbers into the following structure, where the number in a cell is
// the residue of the number there modulo 16:
// 0 1 2 3
// 4 5 6 7
// 8 9 10 11
// 12 13 14 15
// This block is a magic square with each row and column XORing to 0. We then combine these blocks.
// Written (in way too much time) during Manthan Codefest '19.
#include <bits/stdc++.h>
using namespace std;
int arr[1000][1000];
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
#ifndef ONLINE_JUDGE
  freopen("inp.txt", "r", stdin);
#endif
  int n;
  cin >> n;
  int i=0;
  for (int x=0;x<n;x+=4) {
    for (int y=0;y<n;y+=4) {
      for (int a=x;a<x+4;a++) {
        for (int b=y;b<y+4;b++) {
          arr[a][b]=i++;
        }
      }
    }
  }
  for (int x=0;x<n;x++) {
    for (int y=0;y<n;y++) {
      cout << arr[x][y];
      if (y<n-1) cout << " ";
    }
    cout << "\n";
  }
}
