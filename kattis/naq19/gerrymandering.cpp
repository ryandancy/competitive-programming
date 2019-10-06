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
ll dva[1001] = {0}, dvb[1001] = {0};
ll wa=0, wb=0, v=0;
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int p, d;
  cin >> p >> d;
  int cd, a, b;
  for (int i = 0; i < p; i++) {
    cin >> cd >> a >> b;
    dva[cd] += a;
    dvb[cd] += b;
  }
  for (int cd = 1; cd <= d; cd++) {
    int cwa, cwb;
    if (dva[cd]>dvb[cd]) {
      cwb = dvb[cd];
      cwa = dva[cd] - (dva[cd]+dvb[cd])/2 - 1;
      cout << "A ";
    } else {
      cwa = dva[cd];
      cwb = dvb[cd] - (dva[cd]+dvb[cd])/2 - 1;
      cout << "B ";
    }
    wa += cwa;
    wb += cwb;
    v += dva[cd] + dvb[cd];
    cout << cwa << " " << cwb << "\n";
  }
  ld e = ((ld) (wa>wb ? wa-wb : wb-wa)) / ((ld) (v));
  cout << setprecision(15) << fixed << e << "\n";
}
