// 1236C - Labs
// Written during Codeforces Round #593
#include <bits/stdc++.h>
#define MOD 1000000007
#define INF 1000000000
#define EPS 1e-9
#define PI 3.1415926535897932384626433832795L
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
int a[300][300];
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
#ifndef ONLINE_JUDGE
  freopen("inp.txt", "r", stdin);
#endif
  int n;
  cin >> n;
  if (n % 2 == 0) {
    int i = 1;
    for (int y = 0; y < n; y++) {
      for (int x = 0; x < n/2; x++) {
        a[y][x] = i++;
      }
    }
    for (int y = n-1; y >= 0; y--) {
      for (int x = n/2; x < n; x++) {
        a[y][x] = i++;
      }
    }
  } else {
    int i = 1;
    for (int x = 0; x <= n/2; x++) {
      for (int y = 0; y < n; y++) {
        a[y][x] = i++;
      }
    }
    for (int x = n/2+1; x < n; x++) {
      for (int y = n-1; y >= 0; y--) {
        a[y][x] = i++;
      }
    }
  }
  for (int y = 0; y < n; y++) {
    for (int x = 0; x < n; x++) {
      cout << a[y][x];
      if (x < n-1) cout << ' ';
    }
    cout << '\n';
  }
}
