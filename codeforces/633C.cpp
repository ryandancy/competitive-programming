// HASHING FFS
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> pll;
#define A1 921281269LL
#define B1 1000000409LL
#define A2 999279733LL
#define B2 1005012527LL
#define fi first
#define se second
string w[100000];
pair<pll,int> wh[100000];
ll h1[10000]={0}, h2[10000]={0}, q1[10000]={0}, q2[10000]={0};
int dp[10000], dpf[10000]; list<int> p;
ll hsh1(int a, int b) {
  if (a<=0)return h1[b-1];
  return ((h1[b-1]-h1[a-1]*q1[b-a]%B1)%B1+B1)%B1;
}
ll hsh2(int a, int b) {
  if (a<=0)return h2[b-1];
  return ((h2[b-1]-h2[a-1]*q2[b-a]%B2)%B2+B2)%B2;
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
#ifndef ONLINE_JUDGE
  freopen("inp.txt", "r", stdin);
#endif
  int n; string t;
  cin>>n>>t;
  int m; cin>>m;
  for (int i=0;i<m;i++){
    cin>>w[i];
    for (int j=w[i].length()-1;j>=0;j--) {
      char c=w[i][j];
      if (c>='A'&&c<='Z')c-='A',c+='a';
      wh[i].fi.fi*=A1, wh[i].fi.fi+=c, wh[i].fi.fi%=B1;
      wh[i].fi.se*=A2, wh[i].fi.se+=c, wh[i].fi.se%=B2;
    }
    wh[i].se=i;
  }
  sort(wh,wh+m);
  q1[0]=1, q2[0]=1;
  for (int i=0;i<n;i++) {
    h1[i]=((i>0?h1[i-1]:0)*A1+t[i])%B1;
    h2[i]=((i>0?h2[i-1]:0)*A2+t[i])%B2;
    if (i>0) q1[i]=q1[i-1]*A1, q1[i]%=B1;
    if (i>0) q2[i]=q2[i-1]*A2, q2[i]%=B2;
  }
  p.push_back(n);
  for (int i=n-1;i>=0;i--) {
    dpf[i]=dp[i]=-1;
    for (int&j:p) {
      pll hs{hsh1(i,j),hsh2(i,j)};
      auto it=lower_bound(wh,wh+m,pair<pll,int>{hs,0});
      if (it==wh+m) continue;
      pll th; int k;
      tie(th,k)=*it;
      if (hs==th) {
        dp[i]=k;
        dpf[i]=j;
        p.push_front(i);
        break;
      }
    }
  }
  if (dp[0]==-1) return cout<<"Kernel panic\n",0;
  int i=0;
  string res;
  while (i<n) {
    if (res.length()>0)res+=' ';
    res+=w[dp[i]];
    i=dpf[i];
  }
  cout<<res<<'\n';
}
