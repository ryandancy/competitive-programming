  #include <bits/stdc++.h>
  #define MOD 1000000007
  #define INF 1000000000
  #define EPS 0.0000000001L
  #define PI 3.1415926535897932384626433832795L
  using namespace std;
  typedef long long ll;
  typedef long double ld;
  typedef pair<int, int> pii;
  typedef pair<ll, ll> pll;
  struct t {
    ld sl = 0, sr = 0, st = 0;
    ld bl = 0, br = 0, bt = 0;
    ld nl = 0, nr = 0, nt = 0;
    bool empty = true;
  };
  ll n;
  t x[1000001];
  ll a[1000000];
  ll sum = 0;
  void comb(t& a, t& b, t& r) {
    r.empty = false;
    if (b.empty) {
      r.nl = a.nl;
      r.sl = a.sl;
      r.bl = a.bl;
      r.sr = a.sr;
      r.nr = a.nr;
      r.br = a.br;
      r.st = a.st;
      r.bt = a.bt;
      r.nt = a.nt;
      return;
    } else if (a.empty) {
      r.nl = b.nl;
      r.sl = b.sl;
      r.bl = b.bl;
      r.sr = b.sr;
      r.nr = b.nr;
      r.br = b.br;
      r.st = b.st;
      r.bt = b.bt;
      r.nt = b.nt;
      return;
    }
    r.nl = a.nl;
    r.sl = a.sl;
    r.bl = a.bl;
    r.sr = b.sr;
    r.nr = b.nr;
    r.br = b.br;
    ld bc = ((ld)(sum - a.sr - b.sl)) / ((ld)(n-a.nr-b.nl));
    // cout << bc << ' ' << a.bt << ' ' << ' ' << b.bt << '\n';
    if ((bc >= a.bt || a.bt - bc <= EPS) && (bc >= b.bt || b.bt - bc <= EPS)) {
      r.bt = bc;
      r.st = a.sr + b.sl;
      r.nt = a.nr + b.nl;
      if (a.nr == a.nl) {
        r.nl = r.nt;
        r.sl = r.st;
        r.bl = r.bt;
      }
      if (b.nl == b.nr) {
        r.nr = r.nt;
        r.sr = r.st;
        r.br = r.bt;
      }
    } else if (a.bt > b.bt) {
      r.bt = a.bt;
      r.st = a.st;
      r.nt = a.nt;
    } else {
      r.bt = b.bt;
      r.st = b.st;
      r.nt = b.nt;
    }
  }
  int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n;
    int m = 1;
    while (m < n) m *= 2;
    bool allneg = true;
    for (int i = 0; i < n; i++) {
      cin >> a[i];
      sum += a[i];
      if (a[i] > 0) allneg = false;
    }
    if (allneg) {
      cout << "0.00000000\n";
      return 0;
    }
    for (int i = 0; i < n; i++) {
      x[i].sl = x[i].sr = x[i].st = a[i];
      x[i].bl = x[i].br = x[i].bt = ((ld)(sum - a[i])) / ((ld)(n-1));
      x[i].nl = x[i].nr = x[i].nt = 1;
      x[i].empty = false;
    }
    t tmp;
    for (int k = m/2; k >= 1; k /= 2) {
      for (int i = 0; i < k; i++) {
        comb(x[2*i], x[2*i+1], tmp);
        x[i] = tmp;
        // cout << x[i].st << ' ' << x[i].nt << '\n';
        // cout << 2*i << " and " << 2*i+1 << ": " << x[i].bt << "\n";
      }
    }
    // for (int i = 1; i < m+n; i++) {
    //   cout << i << ' ' << x[i].bt << '\n';
    // }
    ld s = x[0].st, gn = x[0].nt;
    // cout << s << " " << gn << "\n";
    cout << setprecision(15) << fixed << max(0.0L, ((ld)(sum-s))/((ld)(n-gn))) << "\n";
  }

