#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;
string a[1000000];
int sz[1000000], w[1000000], rs[1000000]={0};
vector<pii> ch[1000001];
list<int> x; int cs=0;
void slither() {
  rs[x.front()]=cs;
  int lst=x.back();
  x.pop_back();
  cs-=w[x.back()];
  int of=x.front();
  for (pii&y:ch[of]){
    cs+=y.second;
    x.push_front(y.first);
    slither();
    x.pop_front();
    cs-=y.second;
  }
  cs+=w[x.back()];
  x.push_back(lst);
}
void build(int t, int lft) {
  x.push_front(t);
  if (lft==0) {
    slither();
    x.pop_front();
    return;
  }
  for (pii&y:ch[t]) {
    cs+=y.second;
    rs[y.first]=cs;
    build(y.first, lft-1);
    cs-=y.second;
  }
  x.pop_front();
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
#ifndef ONLINE_JUDGE
  freopen("inp.txt", "r", stdin);
#endif
  int n, rw, c;
  cin>>n>>rw>>c;
  for (int i=0;i<n;i++)cin>>a[i], sz[i]=a[i].size();
  int l=0,r=0,v=0;
  while (l<n) {
    while (r<n&&v+sz[r]+(v!=0)<=c) {
      v+=sz[r]+(v!=0);
      r++;
    }
    w[l]=r-l;
    v-=sz[l]+1;
    if (v<0)v=0;
    if (l==r)r++;
    l++;
  }
  for (int i=0;i<n;i++){
    if (w[i]) ch[i+w[i]].push_back({i,w[i]});
  }
  for (int i=n;i>=0;i--){
    if (i==n||w[i]==0) build(i, rw);
  }
  int bst=0,bi=-1;
  for (int i=0;i<n;i++){
    if (rs[i]>bst) {
      bst=rs[i];
      bi=i;
    }
  }
  int i=bi, u=rw;
  while (i<n&&u) {
    for (int j=0;j<w[i];j++) cout<<a[i+j]<<(j==w[i]-1?'\n':' ');
    i+=w[i];
    u--;
  }
}
