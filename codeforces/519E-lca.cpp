// 519E - A and B lecture rooms
// Nth parent / LCA in O(log n) with O(n log n) preprocessing.
#include <bits/stdc++.h>
using namespace std;
vector<int> adj[100000];
vector<int> ch[100000]; int p[100000][20], ss[100000], d[100000];
void cpdfs(int c, int ls=-1) {
  if (ls!=-1) ch[ls].push_back(c), d[c]=d[ls]+1;
  else d[c]=0;
  p[c][0]=ls;
  ss[c]=1;
  for (int nb:adj[c]) {
    if (nb!=ls) cpdfs(nb, c), ss[c]+=ss[nb];
  }
}
void av(int& a, int nm) {
  while (nm>0) {
    int fs=__builtin_ffs(nm)-1;
    a=p[a][fs];
    if (a==-1)break;
    nm^=1<<fs;
  }
}
int get_lca(int a, int b){
  if (d[a]>d[b]) swap(a,b);
  av(b,d[b]-d[a]);
  assert(d[a]==d[b]);
  if (a==b)return a;
  for (int k=19;k>=0;k--){
    if (p[a][k]!=p[b][k]){
      a=p[a][k];
      b=p[b][k];
    }
  }
  return p[a][0];
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n;
  cin>>n;
  for (int i=0;i<n-1;i++){
    int a,b;
    cin>>a>>b;
    a--, b--;
    adj[a].push_back(b);
    adj[b].push_back(a);
  }
  for (int i=0;i<n;i++)for(int j=0;j<20;j++)p[i][j]=-1;
  cpdfs(0);
  for (int k=1;k<20;k++) {
    for (int i=0;i<n;i++){
      int nx=p[i][k-1];
      if (nx==-1)continue;
      nx=p[nx][k-1];
      if (nx!=-1)p[i][k]=nx;
    }
  }
  int q;
  cin>>q;
  while (q--){
    int a,b;
    cin>>a>>b;
    a--, b--;
    if (a==b) {cout<<n<<'\n'; continue;}
    int lca=get_lca(a,b);
    int dst=d[a]-d[lca]+d[b]-d[lca]+1;
    if (dst%2==0) {cout<<"0\n";continue;}
    int c=d[a]>d[b]?a:b;
    av(c,dst/2);
    int rs;
    if (c==lca){
      av(a,d[a]-d[lca]-1);
      av(b,d[b]-d[lca]-1);
      rs=n-ss[a]-ss[b];
    } else {
      int f=d[a]>d[b]?a:b;
      av(f,dst/2-1);
      rs=ss[c]-ss[f];
    }
    cout<<rs<<'\n';
  }
}
