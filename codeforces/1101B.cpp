// 1101B - Accordion
// We find the requisite starting and end bits of the accordion such that the centre is as wide as possible.
// If this is possible, we count the '|'s in between. O(n).
#include <bits/stdc++.h>
using namespace std;
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
#ifndef ONLINE_JUDGE
  freopen("inp.txt", "r", stdin);
#endif
  string s;
  cin >> s;
  int n = s.size();
  int fb;
  for (fb = 0; fb < n && s[fb] != '['; fb++);
  if (fb==n) return cout << "-1\n", 0;
  int fc;
  for (fc = fb; fc < n && s[fc] != ':'; fc++);
  if (fc==n) return cout << "-1\n", 0;
  int lb;
  for (lb = n-1; lb >= 0 && s[lb] != ']'; lb--);
  if (lb==0 || lb < fb) return cout << "-1\n", 0;
  int lc;
  for (lc = lb; lc >= 0 && s[lc] != ':'; lc--);
  if (lc==0 || lc <= fc) return cout << "-1\n", 0;
  int res = 4;
  for (int i = fc+1; i < lc; i++) {
    if (s[i]=='|') res++;
  }
  cout << res << "\n";
}
