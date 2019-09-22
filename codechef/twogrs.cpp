// TWOGRS - Two Groups
// Written during Codechef September Cook-Off 2019
#include <bits/stdc++.h>
using namespace std;
bool ex(int a, int b, int c) {
  if ((a+2*b+3*c)%2!=0) return false;
  if (a==0 && c==0 && b==1) return false;
  if (a==1 && c==1 && b==0) return false;
  if (a==1 && b==0 && c==0) return false;
  if (a==0 && b==0 && c==1) return false;
  if (a%2==0 && b%2==0 && c%2==0) return true;
  if (a%2==1 && b%2==1 && c%2==1) return true;
  if (a%2==1 && b%2==0 && b>0 && c%2==1) return true;
  if (a%2==0 && a>0 && b%2==1 && c%2==0) return true;
  if (a%2==1 && a>1 && b%2==0 && c%2==1 && c>0) return true;
  if (a%2==0 && b%2==1 && b>1 && c%2==0 && c>0) return true;
  return false;
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
#ifndef ONLINE_JUDGE
  freopen("inp.txt", "r", stdin);
#endif
  int T;
  cin >> T;
  while (T--) {
    int a, b, c;
    cin >> a >> b >> c;
    cout << (ex(a, b, c) ? "YES" : "NO") << "\n";
  }
}
