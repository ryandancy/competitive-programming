// I refuse to waste more time optimizing this for POJ to accept it.
// Time complexity O((n+m+k)a(n)) where a(n) is the inverse Ackermann function.
#include <iostream>
#include <string>
#include <vector>
#include <list>
#include <queue>
#include <stack>
#include <map>
#include <set>
#include <cassert>
#include <cmath>
#include <cstdio>
#include <algorithm>
#define MOD 1000000007
#define INF 1000000000
#define EPS 1e-9
#define PI 3.1415926535897932384626433832795L
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
int uf[40000], xd[40000]={0}, yd[40000]={0}, sz[40000];
bool v[40000]={false};
vector<int> adj[40000], adstx[40000], adsty[40000];
int ff1[40000], ff2[40000], fl[40000]; char fd[40000];
pii qf[10000];
bool bad[10000]={false};
vector<int> qpi[40000];
int st[40000], sts=0;
int find(int x) {
  return x==uf[x]?x:uf[x]=find(uf[x]);
}
void unite(int x, int y){
  x=find(x), y=find(y);
  if (sz[x]<sz[y])swap(x,y);
  uf[y]=x;
  sz[x]+=sz[y];
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n, m;
  scanf("%d %d", &n, &m);
  for (int i=0;i<n;i++)uf[i]=i, sz[i]=1;
  for (int i=0;i<m;i++){
    scanf("%d %d %d %c", ff1+i, ff2+i, fl+i, fd+i);
    ff1[i]--, ff2[i]--;
  }
  int k;
  scanf("%d", &k);
  for (int i=0;i<k;i++){
    int j;
    scanf("%d %d %d", &qf[i].first, &qf[i].second, &j);
    qf[i].first--, qf[i].second--, j--;
    qpi[j].push_back(i);
  }
  for (int i=0;i<m;i++){
    int f1=ff1[i], f2=ff2[i], l=fl[i]; char d=fd[i];
    int x=0, y=0;
    switch (d) {
      case 'N': y=l; break;
      case 'S': y=-l; break;
      case 'E': x=l; break;
      case 'W': x=-l; break;
    }
    unite(f1, f2);
    adj[f1].push_back(f2);
    adstx[f1].push_back(x);
    adsty[f1].push_back(y);
    adj[f2].push_back(f1);
    adstx[f2].push_back(-x);
    adsty[f2].push_back(-y);
    for (int qi=0; qi<qpi[i].size(); qi++) {
      int q=qpi[i][qi];
      if (find(qf[q].first)!=find(qf[q].second)) bad[q]=true;
    }
  }
  for (int i=0;i<n;i++){
    if (v[i]) continue;
    int r=find(i);
    if (v[r]) continue;
    sts=0;
    st[sts++]=r;
    xd[r]=yd[r]=0;
    while (sts) {
      int c=st[--sts];
      if (v[c]) continue;
      v[c]=true;
      for (int j=0;j<adj[c].size();j++) {
        int nb=adj[c][j];
        if (v[nb]) continue;
        xd[nb]=xd[c]+adstx[c][j];
        yd[nb]=yd[c]+adsty[c][j];
        st[sts++]=nb;
      }
    }
  }
  for (int q=0;q<k;q++) {
    if (bad[q]) { printf("-1\n"); continue; }
    int f1=qf[q].first, f2=qf[q].second;
    printf("%d\n",abs(xd[f1]-xd[f2])+abs(yd[f1]-yd[f2]));
  }
}
