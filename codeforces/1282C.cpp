// 1282C - Petya and Exam
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
struct qu {ll h; ll mt;} qs[200000];
ll nhb[200000]={0};
bool mtc(qu& a, qu& b) {return a.mt < b.mt;}
int o = 0;
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int CAS;
  cin >> CAS;
  while (CAS--) {
    ll n,t,a,b;
    cin >> n >> t >> a >> b;
    // for (int i = o;i < o+n; i++) cin >> qs[i].i;
    for (int i = o;i < o+n; i++) cin >> qs[i].h;
    for (int i = o;i < o+n; i++) cin >> qs[i].mt;
    sort(qs+o,qs+o+n,mtc);
    ll hc = 0;
    for (int i =o; i< o+n; i++) {
      nhb[i]=hc;
      hc += qs[i].h;
    }
    ll bs=0;
    for (int i = 0; i < n; i++) {
      if (qs[o+i].mt==0)continue;
      ll ct = nhb[i+o]*b + (i-nhb[i+o])*a;
      if (ct>qs[i+o].mt-1) continue;
      ll rt = qs[i+o].mt-ct-1;
      ll hl = hc-nhb[i+o], el = n-i-hl;
      ll nc = min(rt/a,el);
      // debug("nc",nc);
      nc += min((rt-nc*a)/b,hl);
      bs = max(bs, i+nc);
      // debug(i,bs,nc);
    }
    bs = max(bs,hc*b+(n-hc)*a>t?0ll:n);
    cout << bs << '\n';
    o += n;
  }
}
