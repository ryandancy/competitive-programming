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
ll p[100000],c[100000];
bool sf[100000]={false};
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
#ifndef ONLINE_JUDGE
  freopen("inp.txt", "r", stdin);
#endif
  ll n;
  cin>>n;
  for (ll i=0;i<n;i++)cin>>p[i]>>c[i],p[i]--;
  for (ll i=0;i<n;i++){
    if (c[i]==0){
      sf[i]=true;
      if (p[i]!=-1)sf[p[i]]=true;
    }
  }
  vector<ll> ns;
  for (ll i=0;i<n;i++)if (!sf[i])ns.push_back(i);
  // cout<<ns.size()<<'\n';
  for (ll i=0;i<ns.size();i++) {
    cout<<ns[i]+1<<(i==ns.size()-1?'\n':' ');
  }
  if (ns.empty())cout<<"-1\n";
}
