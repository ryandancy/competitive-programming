#include <bits/stdc++.h>
#define MOD 1000000007
#define INF 1000000000
#define EPS 1e-9
#define PI 3.1415926535897932384626433832795L
#ifdef ONLINE_JUDGE
#define debug(args...) (0)
#else
#include "debug.h"
#endif
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
#ifndef ONLINE_JUDGE
  freopen("inp.txt", "r", stdin);
#endif
  ll a,b,c,d,n;
  cin>>a>>b>>c>>d>>n;
  vector<ll> x;
  for (ll i=0;i<n;i++){
    ll w;cin>>w;x.push_back(w);
  }
  char att[200][200];
  for (ll i=0;i<200;i++)for (ll j=0;j<200;j++) att[i][j]='.';
  ll row=0,col=0;
  bool gr=true;
  if ((b<d&&b%2==0)||(b>d&&d%2==1)) {
    col=a+c-1;
    gr=false;
  }
  ll i=0;
  while (1) {
    att[row][col]='a'+i;
    x[i]--;
    if (x[i]==0) i++;
    if (i>=x.size()) break;
    bool md=false;
    if (gr) {
      if (col==a+c-1) md=true;
      else if (row>=d&&col==a-1) md=true;
    } else {
      if (col==0) md=true;
      else if (row>=b&&col==a) md=true;
    }
    if (md) {
      row++;
      gr=!gr;
    } else {
      if (gr) col++;
      else col--;
    }
  }
  cout<<"YES\n";
  for (ll i=0;i<max(b,d);i++) {
    for (ll j=0;j<a+c;j++) {
      cout<<att[i][j];
    }
    cout<<'\n';
  }
}
