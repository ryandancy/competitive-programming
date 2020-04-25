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
  int T;
  cin>>T;
  while (T--) {
    string s;
    cin>>s;
    vector<int> xs,ys;
    xs.push_back(0); ys.push_back(0);
    int x=0,y=0;
    int mnx=0,mny=0,mxx=0,mxy=0;
    for (char c : s) {
      if (c=='W') {
        ys.push_back(--y);
        if (y<mny)mny=y;
      } else if (c=='A') {
        xs.push_back(--x);
        if (x<mnx)mnx=x;
      } else if (c=='S') {
        ys.push_back(++y);
        if (y>mxy)mxy=y;
      } else if (c=='D') {
        xs.push_back(++x);
        if (x>mxx)mxx=x;
      }
    }
    bool crx=mxx-mnx>1,cry=mxy-mny>1;
    int nr=0,rv=INF;
    for (int v:xs){
      if (v!=mnx&&v!=mxx)continue;
      if (rv==INF)rv=v;
      else if (v!=rv){
        nr++;
        rv=v;
        if (nr>1) {
          crx=false;
          break;
        }
      }
    }
    nr=0,rv=INF;
    for (int v:ys){
      if (v!=mny&&v!=mxy)continue;
      if (rv==INF)rv=v;
      else if (v!=rv){
        nr++;
        rv=v;
        if (nr>1) {
          cry=false;
          break;
        }
      }
    }
    ll xr=mxx-mnx+1, yr=mxy-mny+1;
    if (crx&&cry){
      cout<<(min(xr,yr)-1)*max(xr,yr)<<'\n';
    }else if (crx){
      cout<<(xr-1)*yr<<'\n';
    }else if (cry){
      cout<<xr*(yr-1)<<'\n';
    }else cout<<xr*yr<<'\n';
  }
}
