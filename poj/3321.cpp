// POJ is garbage, didn't say it's directed yet TLEs if you treat it as undirected.
#include <iostream>
#include <vector>
#include <cstdio>
using namespace std;
vector<int> adj[100000];
bool v[100000]={false};
int n, e[100000], mp[100000], bit[100001]={0}; // e exclusive
int tst[100000], tsts=0, st[100000], sts=0;
void bit_add(int x, int v) {
  x++;
  while (x<=n) {
    bit[x]+=v;
    x+=x&-x;
  }
}
int bit_sum(int x) {
  x++;
  int res=0;
  while (x>0) {
    res+=bit[x];
    x-=x&-x;
  }
  return res;
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  scanf("%d", &n);
  for (int i=0;i<n;i++) bit_add(i, 1);
  for (int i=0;i<n-1;i++){
    int u, v;
    scanf("%d %d", &u, &v);
    u--, v--;
    adj[u].push_back(v);
  }
  tst[tsts++]=0, st[sts++]=0;
  int cv=0;
  while (sts) {
    int t=tst[--tsts], c=st[--sts];
    if (t==0) {
      if (v[c])continue;
      tst[tsts++]=1, st[sts++]=c;
      mp[c]=cv++;
      v[c]=true;
      for (int i=0;i<adj[c].size();i++) {
        int nb=adj[c][i];
        if (!v[nb]) tst[tsts++]=0, st[sts++]=nb;
      }
    } else {
      e[mp[c]]=cv;
    }
  }
  int m, x; char t;
  scanf("%d", &m);
  while (m--) {
    scanf(" %c %d", &t, &x);
    x=mp[x-1];
    if (t=='C') {
      bit_add(x, v[x] ? -1 : 1);
      v[x]=!v[x];
    } else {
      printf("%d\n", bit_sum(e[x]-1) - bit_sum(x-1));
    }
  }
}
