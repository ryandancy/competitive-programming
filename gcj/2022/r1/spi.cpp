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
vector<pii> c;
vector<int> s,rc;
ll gr(ll x, ll y, ll n) {
  return min(min(x,y), min(n-1-x,n-1-y));
}
bool ic(ll x, ll y, ll n) {
  return x==y || x==n-1-y;
}
ll lsp(ll i, ll n) {
  // cout<<"LSP: "<<i<<" (cached: "<<s[i]<<")"<<'\n';
  if (s[i]!=-1) return s[i];
  if (i==n*n-1) return s[i]=0;
  int x=c[i].first,y=c[i].second;
  if (ic(x,y,n)) return s[i]=lsp(i+1,n)+1;
  ll r=gr(x,y,n);
  if (x==r) x++;
  else if (y==r) y++;
  else if (n-1-x==r) x--;
  else y--;
  return s[i]=lsp(rc[x+y*n],n)+1;
}
void gsk(vector<pii>&sk, ll i, ll n) {
  if (i==n*n-1) return;
  int x=c[i].first,y=c[i].second;
  if (ic(x,y,n)) {gsk(sk,i+1,n); return;}
  ll r=gr(x,y,n);
  int nx=x,ny=y;
  if (x==r) nx=x+1;
  else if (y==r) ny=y+1;
  else if (n-1-x==r) nx=x-1;
  else ny=y-1;
  int j=rc[nx+ny*n];
  if (j!=i+1) sk.push_back({i,j});
  gsk(sk,j,n);
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  ll N;
  cin>>N;
  for (ll t=1;t<=N;t++) {
    cout<<"Case #"<<t<<": ";
    int n,k;
    cin>>n>>k;
    if (k%2==1) {cout<<"IMPOSSIBLE\n";continue;}
    c.resize(n*n); s.resize(n*n); rc.resize(n*n);
    for (int i=0;i<n*n;i++) s[i]=-1;
    int i=0;
    int x=0,y=0;
    for (int r=0;r<=n/2;r++) {
      int rs=n-2*r;
      for (int j=0;j<rs-1;j++) //cout<<i<<' '<<x<<' '<<y<<'\n',
        c[i++]={x++,y};
      // x--;
      for (int j=0;j<rs-1;j++) //cout<<i<<' '<<x<<' '<<y<<'\n',
        c[i++]={x,y++};
      // y--;
      for (int j=0;j<rs-1;j++) //cout<<i<<' '<<x<<' '<<y<<'\n',
        c[i++]={x--,y};
      // x++;
      for (int j=0;j<rs-1;j++) //cout<<i<<' '<<x<<' '<<y<<'\n',
        c[i++]={x,y--};
      y++;
      x++;
    }
    c[n*n-1]={n/2,n/2};
    for (i=0;i<n*n;i++) rc[c[i].first+c[i].second*n]=i;
    for (i=0;i<=min(n*n-1,k);i++) {
      ll ls = lsp(i,n);
      // cout<<i<<' '<<ls<<'\n';
      if (i+ls==k) {
        vector<pii> sk;
        gsk(sk,i,n);
        cout<<sk.size()<<'\n';
        for (pii&p:sk) {
          cout<<p.first+1<<' '<<p.second+1<<"\n";
        }
        goto nxt;
      }
    }
    cout<<"IMPOSSIBLE\n";
    nxt:;
  }
}
