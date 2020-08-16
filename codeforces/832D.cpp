#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
vector<int> adj[100000];
bool v[100000]={false};
int d[100000]={0}, p[100000][20]={{0}};
void adv(int&x, int v) {
  for (int k=0;k<20;k++) {
    if (v&(1<<k)) x=p[x][k];
  }
}
int lca(int a, int b) {
  if (d[a]<d[b]) swap(a,b);
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
int lb(int a, int b) {
  int l=lca(a,b);
  return d[a]-d[l] + d[b]-d[l] + 1;
}
bool ok(int a, int b, int c, int o, int ab, int bc, int ac) {
  int ao=lca(a,o),bo=lca(b,o),co=lca(c,o);
  return (
    (ab==ao||ab==bo) &&
    (ac==ao||ac==co) &&
    (bc==bo||bc==co)
  );
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n, Q;
  cin>>n>>Q;
  for (int i=1;i<n;i++) {
    int x;
    cin>>x;
    x--;
    adj[i].push_back(x);
    adj[x].push_back(i);
  }
  stack<int> stk;
  stk.push(0);
  d[0]=0; v[0]=true; p[0][0]=0;
  while (stk.size()) {
    int c=stk.top(); stk.pop();
    for (int&nb:adj[c]) {
      if (!v[nb]){
        stk.push(nb);
        d[nb]=d[c]+1;
        p[nb][0]=c;
        v[nb]=true;
      }
    }
  }
  for (int k=1;k<20;k++) {
    for (int i=0;i<n;i++) {
      p[i][k]=p[p[i][k-1]][k-1];
    }
  }
  for (int q=0;q<Q;q++) {
    int a,b,c;
    cin>>a>>b>>c;
    a--,b--,c--;
    if (a==b&&b==c) {
      cout<<"1\n";
      continue;
    }
    int ab=lca(a,b);
    int bc=lca(b,c);
    int ac=lca(a,c);
    int cm=ok(a,b,c,ab,ab,bc,ac)?ab:ok(a,b,c,bc,ab,bc,ac)?bc:ac;
    cout<<max(max(lb(a,cm),lb(b,cm)),lb(c,cm))<<'\n';
  }
}
