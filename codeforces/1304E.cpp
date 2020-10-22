#include <bits/stdc++.h>
using namespace std;
int n, p[100000][20], d[100000];
vector<int> adj[100000], ch[100000];
bool v[100000]={false};
void adv(int&a, int v) {
  for (int b=0;b<20;b++) {
    if (v&(1<<b)) {
      a=p[a][b];
    }
  }
}
int lca(int a, int b) {
  if (d[a]<d[b])swap(a,b);
  adv(a,d[a]-d[b]);
  if (a==b) return a;
  for (int k=19;k>=0;k--) {
    if (p[a][k]!=p[b][k]) {
      a=p[a][k];
      b=p[b][k];
    }
  }
  return p[a][0];
}
int dst(int a, int b) {
  if (a==b)return 0;
  int l=lca(a,b);
  return d[a]-d[l]+d[b]-d[l];
}
bool ok(int x,int y,int a,int b,int k) {
  int ab=dst(a,b), xy=dst(x,y), ax=dst(a,x), ay=dst(a,y), bx=dst(b,x), by=dst(b,y);
  if (ab<=k&&(k-ab)%2==0) return true;
  int t=ax+1+by;
  if (t<=k&&(k-t)%2==0) return true;
  t=ay+1+bx;
  if (t<=k&&(k-t)%2==0) return true;
  return false;
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cin>>n;
  for (int i=0;i<n-1;i++){
    int a,b;
    cin>>a>>b;
    a--,b--;
    adj[a].push_back(b);
    adj[b].push_back(a);
  }
  p[0][0]=0; d[0]=0;
  stack<int> dfs;
  dfs.push(0);
  while (dfs.size()) {
    int c=dfs.top(); dfs.pop();
    v[c]=true;
    for (int nb:adj[c]) {
      if (v[nb])continue;
      p[nb][0]=c;
      d[nb]=d[c]+1;
      dfs.push(nb);
    }
  }
  for (int k=1;k<20;k++){
    for (int i=0;i<n;i++) {
      p[i][k]=p[p[i][k-1]][k-1];
    }
  }
  int q; cin>>q;
  while (q--) {
    int x,y,a,b,k;
    cin>>x>>y>>a>>b>>k;
    x--,y--,a--,b--;
    if (ok(x,y,a,b,k)) cout<<"YES\n";
    else cout<<"NO\n";
  }
}
