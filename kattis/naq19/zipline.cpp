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
  while (n--) {
    ld w, g, h, r;
    cin >> w >> g >> h >> r;
    cout << setprecision(30);
    cout << fixed << sqrtl(w*w+(h-g)*(h-g)) << " ";
    if (g == r && h == r) {
    cout << fixed << sqrtl(w*w+(h-g)*(h-g)) << "\n";
    } else {
      ld x = w*(g-r)/(g+h-2*r);
      ld maxl = sqrtl((g-r)*(g-r)+x*x)+sqrtl((h-r)*(h-r)+(w-x)*(w-x));
      cout << fixed << maxl << "\n";
    }
  }
}
