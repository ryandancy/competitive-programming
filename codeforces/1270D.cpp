// 1270D - Strange Device
// Couldn't get this during the competition, but here goes
// We only have to consider the first k+1 elements of a
// We ask n questions, each consisting of 1..k+1 without
// each element from 1 to k+1 in turn. We discard the indices and
// keep track of the numbers and how often they appear.
// There will only be two distinct numbers. If the most frequent is
// less than the less frequent, m is the number of times the less frequent
// one appeared; otherwise, it is the number of times the more frequent one
// appeared. Simple, sigh. Lesson: overcomplication.
#include <bits/stdc++.h>
using namespace std;
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n, k;
  cin >> n >> k;
  int f = -1, fc = 0, s = -1, sc = 0;
  for (int i = 1; i <= k+1; i++) {
    cout << "? ";
    for (int j = 1; j <= k+1; j++) {
      if (i == j) continue;
      cout << j;
      if (j != k+1 && !(i == k+1 && j == k)) cout << ' ';
    }
    cout << endl;
    int ni, nv;
    cin >> ni;
    if (ni == -1) return 0;
    cin >> nv;
    if (f == -1) f = nv;
    if (nv == f) fc++;
    else {
      if (s == -1) s = nv;
      if (nv == s) sc++;
      else assert(false);
    }
  }
  if (fc < sc) {swap(fc, sc); swap(f, s);}
  cout << "! " << (f < s ? sc : fc) << endl;
}
