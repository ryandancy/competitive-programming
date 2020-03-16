// 920F - SUM and REPLACE
// Precompute D(x) in O(N log N) where N=10^6 with sieve of Eratosthenes.
// Note that D(1) = 1, D(2) = 2, and for all other x, D(D(D(...D(x))) goes to 2 very
// fast (within ~6 iterations). Thus we can do this in O(n log n) on type 1 queries
// and use a union-find structure to skip ranges of 2s and 1s in O(log n).
// Time complexity: O(N log N + Kn log n + m) where the average element takes K iterations
// to go to 2.
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int f[1000001], sv[1000001]={0};
int a[300001];
int uf[300001]={0},e[300001]={0},sz[300001]={0};
int n, Q;
ll bit[3000001];
void add(int x, int v) {
  while (x <= n) {
    bit[x]+=v;
    x+=x&-x;
  }
}
ll sum(int x) {
  ll r = 0;
  while (x > 0) {
    r+=bit[x];
    x-=x&-x;
  }
  return r;
}
inline int find(int x) {
  while (uf[x]!=x)x=uf[x];
  return x;
}
void unite(int x, int y) {
  x=find(x);
  y=find(y);
  if (x==y)return;
  if (sz[x]<sz[y])swap(x,y);
  sz[x]+=sz[y];
  uf[y]=x;
  e[x]=max(e[x],e[y]);
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  for (int i=2;i<=1000000;i++) {
    if (!sv[i]) {
      for (int j=2*i;j<=1000000;j+=i) {
        sv[j]=i;
      }
    }
  }
  f[0]=0;
  f[1]=1;
  for (int i=2;i<=1000000;i++) {
    if (!sv[i])f[i]=2;
    else {
      f[i]=1;
      int k=i,p;
      while (sv[k]) {
        p=sv[k];
        int c=0;
        while (p==sv[k]) {
          k/=sv[k];
          c++;
        }
        f[i]*=c+1+(k==p);
      }
      if (k!=p)f[i]*=2;
    }
  }
  scanf("%d %d\n", &n, &Q);
  for (int i=1;i<=n;i++){scanf("%d", a+i);}
  for (int i=1;i<=n;i++)add(i,a[i]);
  for (int i=1;i<=n;i++){
    if (a[i]<=2) {
      uf[i]=i;
      sz[i]=1;
      e[i]=i;
      if (i>1&&a[i-1]<=2){
        unite(i,i-1);
      }
    }
  }
  while (Q--) {
    int t, l, r;
    scanf("%d %d %d\n", &t, &l, &r);
    if (t==1) {
      for (int i=l;i<=r;i++){
        if (a[i]<=2){
          i=e[find(i)];
          continue;
        }
        int diff=f[a[i]]-a[i];
        add(i,diff);
        a[i]=f[a[i]];
        if (a[i]<=2) {
          uf[i]=i;
          sz[i]=1;
          e[i]=i;
          if (i>1&&a[i-1]<=2){
            unite(i,i-1);
          }
          if (i<n&&a[i+1]<=2){
            unite(i,i+1);
          }
        }
      }
    } else {
      printf("%lld\n", sum(r)-sum(l-1));
    }
  }
}
