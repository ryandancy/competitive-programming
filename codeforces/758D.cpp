// freakin integer overflow man
#include <bits/stdc++.h>
#define MOD 1000000007
#define INF 1000000000000000001
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
#define T18 1000000000000000001ll
ll dp[60];
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
#ifndef ONLINE_JUDGE
  freopen("inp.txt", "r", stdin);
#endif
  ll n;string k;
  cin>>n>>k;
  if (k=="0")return cout<<"0\n",0;
  for (ll i=0;i<k.size();i++) {
    dp[i]=INF;
    ll cv=0;
    for (ll j=i,p=1,X=0;j>=0&&X<=18;j--,p*=10,X++) {
      cv+=(k[j]-'0')*p;
      if (cv>=n) break;
      if (k[j]=='0'&&p>1) continue;
      if (j>0&&dp[j-1]>=T18/n+(T18%n!=0)) continue;
      dp[i]=min(dp[i],(j==0?0:dp[j-1]*n)+cv);
    }
    debug(i,dp[i]);
  }
  cout<<dp[k.size()-1]<<'\n';
}
