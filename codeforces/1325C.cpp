#include <bits/stdc++.h>
#define MOD 1000000007
#define INF 1000000000
#define EPS 1e-9
#define PI 3.1415926535897932384626433832795L
#ifdef ONLINE_JUDGE
#define debug(args...)
#else
#include "debug.h"
#endif
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
#define p(a,b) ((a)<(b)?make_pair((a),(b)):make_pair((b),(a)))
vector<int> adj[100000];
pii io[100000];
pii sp[100000]; int spl=0;
int x[100000]={0};
int d[100000]={0};
// unordered_map<pii,int,hash_pair> v;
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
#ifndef ONLINE_JUDGE
  freopen("inp.txt", "r", stdin);
#endif
  int n;
  // cin >> n;
  scanf("%d\n",&n);
  for (int i=0;i<n-1;i++) {
    int a, b;
    // cin>>a>>b;
    scanf("%d %d\n",&a,&b);
    a--,b--;
    adj[a].push_back(b);
    adj[b].push_back(a);
    if (a>b)swap(a,b);
    io[i].first=a;
    io[i].second=b;
  }
  d[0]=1;
  queue<int> q;
  q.push(0);
  while (q.size()) {
    int c=q.front();q.pop();
    for (int nb:adj[c]) {
      if (d[nb]==0) {
        d[nb]=d[c]+1;
        q.push(nb);
      }
    }
  }
  int l1=-1, l2=-1;
  for (int i=0;i<n&&(l1<0||l2<0);i++) {
    // debug(i,adj[i].size());
    if (adj[i].size()==1) {
      (l1<0?l1:l2)=i;
    }
  }
  // v[p(l1,adj[l1][0])]=0;
  // v[p(l2,adj[l2][0])]=1;
  // debug(l1,l2);
  int c1=l1,c2=l2;
  int& l=(d[c1]>d[c2])?c1:c2;
  int o1=-1,o2=-1;
  int lst1=-1,lst2=-1;
  int& lst=(d[c1]>d[c2])?lst1:lst2;
  while (d[c1]!=d[c2]&&(o1<0||o2<0)) {
    // debug(c1,c2);
    if (adj[l].size()==1) {
      lst=l;
      l=adj[l][0];
    } else {
      int cnt=-1;
      for (int nb:adj[l]) {
        if (d[nb]<d[l])cnt=nb;
        if (d[nb]>d[l]&&nb!=lst&&nb!=c1&&nb!=c2) {
          o1=l,o2=nb;
          break;
        }
      }
      if (o1<0) {
        lst=l;
        l=cnt;
      }
    }
  }
  while (c1!=c2&&(o1<0||o2<0)) {
    if (adj[c1].size()==1) {
      lst1=c1;
      c1=adj[c1][0];
    } else {
      int cnt=-1;
      for (int nb:adj[c1]) {
        if (d[nb]<d[c1])cnt=nb;
        if (d[nb]>d[c1]&&nb!=lst1&&nb!=lst2&&nb!=c1&&nb!=c2) {
          o1=c1,o2=nb;
          break;
        }
      }
      if (o1<0) {
        lst1=c1;
        c1=cnt;
      }
    }
    if (o1>=0||o2>=0)break;
    if (adj[c2].size()==1) {
      lst2=c2;
      c2=adj[c2][0];
    } else {
      int cnt=-1;
      for (int nb:adj[c2]) {
        if (d[nb]<d[c2])cnt=nb;
        if (d[nb]>d[c2]&&nb!=lst1&&nb!=lst2&&nb!=c1&&nb!=c2) {
          o1=c2,o2=nb;
          break;
        }
      }
      if (o1<0) {
        lst2=c2;
        c2=cnt;
      }
    }
  }
  if (o1<0&&o2<0&&c1==c2) {
    for (int nb:adj[c2]) {
      if (nb!=lst1&&nb!=lst2) {
        o1=c2,o2=nb;
        break;
      }
    }
  }
  if (o1<0&&o2<0) {
    for (int i=0;i<n-1;i++) {
      printf("%d\n",i);
    }
    return 0;
  }
  int s=4;
  for (int i=0;i<n-1;i++) {
    if (io[i].first==l1||io[i].second==l1) {
      x[i]=1;
    } else if (io[i].first==l2||io[i].second==l2) {
      x[i]=2;
    } else if ((io[i].first==o1&&io[i].second==o2)||(io[i].second==o1&&io[i].first==o2)) {
      x[i]=3;
    } else if (!x[i]) {
      x[i]=s++;
    }
    printf("%d\n",x[i]-1);
  }
}
