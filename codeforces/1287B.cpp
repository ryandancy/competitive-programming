// 1287B - Hyperset
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int a[1500][30]={{0}};
ll x[1500] = {0};
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n, k;
  cin >> n >> k;
  for (int i = 0; i < n; i++) {
    string s;
    cin >> s;
    for (int j = 0; j < k; j++) {
      x[i] *= 3;
      switch (s[j]) {
        case 'S': a[i][j] = 0; x[i] += 0; break;
        case 'E': a[i][j] = 1; x[i] += 1; break;
        case 'T': a[i][j] = 2; x[i] += 2; break;
      }
    }
  }
  sort(x,x+n);
  ll r = 0;
  for (int i = 0; i < n; i++) {
    for (int j = i+1; j < n; j++) {
      ll w = 0;
      for (int q = 0; q < k; q++) {
        ll d;
        if (a[i][q] == a[j][q]) d = a[i][q];
        else if (a[i][q] == 1 && a[j][q] == 2) d = 0;
        else if (a[i][q] == 2 && a[j][q] == 1) d = 0;
        else if (a[i][q] == 0 && a[j][q] == 1) d = 2;
        else if (a[i][q] == 1 && a[j][q] == 0) d = 2;
        else d = 1;
        w *= 3;
        w += d;
      }
      if (binary_search(x,x+n,w)) r++;
    }
  }
  cout << r/3 << '\n';
}
