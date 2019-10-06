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
ld a[100];
ld probs[101];
ld nprobs[101] = {0};
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n;
  cin >> n;
  for (int i = 0; i < n; i++) {
    int c;
    cin >> c;
    a[i] = c/100.0L;
  }
  sort(a, a+n);
  reverse(a, a+n);
  probs[1] = a[0];
  probs[0] = 1 - a[0];
  ld res = a[0];
  for (int k = 1; k < n; k++) {
    for (int i = 0; i <= n; i++) {
      nprobs[i] += probs[i] * (1-a[k]);
      nprobs[i+1] += probs[i] * a[k];
    }
    for (int q = 0; q <= n; q++) {
      probs[q] = nprobs[q];
      nprobs[q] = 0;
    }
    ld nres = 0;
    for (int i = 1; i <= n; i++) {
      nres += probs[i] * pow((ld) i, (ld) (i) / (ld) (k+1));
    }
    if (nres > res) res = nres;
  }
  cout << setprecision(15) << fixed << res << "\n";
}
