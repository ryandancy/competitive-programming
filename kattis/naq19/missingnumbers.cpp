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
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n;
  cin >> n;
  int l = 0, x;
  bool did = false;
  for (int i = 0; i < n; i++) {
    cin >> x;
    if (x != l + 1) {
      l++;
      while (l < x) {
        cout << l << "\n";
        l++;
      }
      did = true;
    }
    l = x;
  }
  if (!did) {
    cout << "good job\n";
  }
}
