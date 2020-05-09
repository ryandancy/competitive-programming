#include <iostream>
#include <cstdio>
using namespace std;
int uf[100000], sz[100000];
bool inv[100000];
void fad(int x, int& r, bool& v) {
  if (x==uf[x]) {
    r=x;
    v=false;
    return;
  }
  fad(uf[x], r, v);
  if (inv[x]) v=!v;
  uf[x]=r;
  inv[x]=v;
}
void diff(int x, int y) {
  int r1, r2; bool v1, v2;
  fad(x, r1, v1); x=r1;
  fad(y, r2, v2); y=r2;
  if (x==y) return;
  if (sz[x]>sz[y])swap(x,y);
  uf[x]=y;
  sz[y]+=sz[x];
  inv[x]=v1==v2;
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int T;
  scanf("%d", &T);
  while (T--) {
    int n, m;
    scanf("%d %d", &n, &m);
    for (int i=0;i<n;i++)uf[i]=i, inv[i]=false, sz[i]=1;
    for (int i=0;i<m;i++) {
      char t; int x, y;
      scanf(" %c %d %d", &t, &x, &y);
      x--, y--;
      if (t=='A') {
        if (x==y) {
          printf("In the same gang.\n");
          continue;
        }
        if (n==2) {
          printf("In different gangs.\n");
          continue;
        }
        int r1, r2; bool v1, v2;
        fad(x, r1, v1);
        fad(y, r2, v2);
        if (r1!=r2) printf("Not sure yet.\n");
        else if (v1==v2) printf("In the same gang.\n");
        else printf("In different gangs.\n");
      } else {
        diff(x,y);
      }
    }
  }
}
