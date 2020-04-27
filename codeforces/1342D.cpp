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
int co[200001], c[200001], m[200000];
int li[200001];
pii f[200001]; int fs=0;
vector<int> v[200000]; int nv=0;
set<pii> bit[200001]; int bmx[200001]={0};
int bit_get(int x);
void bit_add(int x, int v, int n){
  int o=x;
  x++;
  while (x<=n){
    bit[x].insert({v,o});
    bmx[x]=(--bit[x].end())->second;
    x+=x&-x;
  }
}
void bit_rmv(int x, int v, int n){
  int o=x;
  x++;
  while (x<=n){
    pii c={v,o};
    if (bit[x].count(c)) {
      bit[x].erase(c);
      if (bit[x].size()==0) bmx[x]=-1;
      else bmx[x]=(--bit[x].end())->second;
    }
    x+=x&-x;
  }
}
int bit_get(int x){
  x++;
  int res=0;
  while (x>0){
    res=max(res, bmx[x]);
    x-=x&-x;
  }
  return res;
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n,k;
  cin>>n>>k;
  for (int i=0;i<n;i++)cin>>m[i];
  sort(m,m+n);
  for (int i=0;i<n;){
    int j=i, tc=0;
    while (m[i]==m[j])i++,tc++;
    f[fs].first=m[j];
    f[fs].second=tc;
    fs++;
  }
  for (int i=0;i<fs;i++){
    bit_add(i,f[i].first,fs);
  }
  for (int i=0;i<k;i++)cin>>c[i+1];
  li[0]=-1;
  for (int i=1;i<fs;i++){
    if (c[f[i-1].first]>c[f[i].first])li[i]=i-1;
    else li[i]=li[i-1];
  }
  int tp=0;
  while (tp<n) {
    int pt=0;
    vector<int>& cv=v[nv++];
    for (int i=fs-1;i>=0;i--){
      i=bit_get(i);
      if (i<0)break;
      int av=c[f[i].first]-pt;
      if (av==0) {
        i=li[i];
        if (i<0)break;
        av=c[f[i].first]-pt;
        if (av==0)continue;
      }
      while (av>0&&f[i].second>0){
        cv.push_back(f[i].first);
        f[i].second--;
        av--;
        pt++;
      }
      if (f[i].second==0){
        bit_rmv(i,f[i].first,fs);
      }
    }
    tp+=pt;
  }
  cout<<nv<<"\n";
  for (int i=0;i<nv;i++) {
    cout<<v[i].size()<<' ';
    for (int j=0;j<v[i].size();j++){
      cout<<v[i][j]<<(j==v[i].size()-1?'\n':' ');
    }
  }
}
