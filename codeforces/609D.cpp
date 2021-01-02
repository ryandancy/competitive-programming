#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n,m,k,s,a[2][200000],x[2][200000],nx[2]={0},*sx[2][200000],mn[2][200000],mnl[2][200000],gi[2][200000];
vector<pll> rv;
bool ok(ll d, bool p=false) {
  if (p) rv.clear();
  ll me[2],ml[2];
  for (int i=0;i<2;i++)me[i]=mn[i][d],ml[i]=mnl[i][d];
  ll sl=s,pt[2]={0,0};
  for (int i=0;i<k;i++) {
    ll u;
    if (pt[0]==nx[0]){
      u=me[1]* *sx[1][pt[1]++]; if (p) rv.push_back({gi[1][sx[1][pt[1]-1]-x[1]]+1,ml[1]+1});}
    else if (pt[1]==nx[1]){
      u=me[0]* *sx[0][pt[0]++]; if (p) rv.push_back({gi[0][sx[0][pt[0]-1]-x[0]]+1,ml[0]+1});}
    else if (me[0]* *sx[0][pt[0]]<me[1]* *sx[1][pt[1]]){
      u=me[0]* *sx[0][pt[0]++]; if (p) rv.push_back({gi[0][sx[0][pt[0]-1]-x[0]]+1,ml[0]+1});}
    else {
      u=me[1]* *sx[1][pt[1]++]; if (p) rv.push_back({gi[1][sx[1][pt[1]-1]-x[1]]+1,ml[1]+1});}
    sl-=u;
    if (sl<0)return false;
  }
  return true;
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cin>>n>>m>>k>>s;
  for (int i=0;i<n;i++)cin>>a[0][i];
  for (int i=0;i<n;i++)cin>>a[1][i];
  for (int i=0;i<2;i++){
    mn[i][0]=a[i][0];
    mnl[i][0]=0;
    for (int j=1;j<n;j++) {
      mn[i][j]=min(mn[i][j-1],a[i][j]);
      if (mn[i][j-1]<a[i][j])mnl[i][j]=mnl[i][j-1];
      else mnl[i][j]=j;
    }
  }
  for (int i=0;i<m;i++) {
    ll t,c;
    cin>>t>>c;
    t--;
    sx[t][nx[t]]=&x[t][nx[t]];
    gi[t][nx[t]]=i;
    x[t][nx[t]++]=c;
  }
  for (int i=0;i<2;i++)sort(sx[i],sx[i]+nx[i],[&](ll*q,ll*w){return *q<*w;});
  ll l=0,r=n-1;
  while (l<=r) {
    ll md=l+(r-l)/2;
    if (ok(md)) r=md-1;
    else l=md+1;
  }
  if (l>=n)cout<<"-1\n";
  else {
    ok(l,true);
    cout<<l+1<<'\n';
    for (pll&w:rv) {
      cout<<w.first<<' '<<w.second<<'\n';
    }
  }
}
