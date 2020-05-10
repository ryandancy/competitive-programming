// 2D BIT! Like a normal BIT, but just with 2 for loops. Wow.
// Could also do it with a 2D segment tree but this is cooler.
#include <iostream>
#include <cstdio>
using namespace std;
int bit[1025][1025]={{0}}, s;
void bit_add(int ix, int iy, int v) {
  for (int x=ix+1;x<=s;x+=x&-x) {
    for (int y=iy+1;y<=s;y+=y&-y) {
      bit[x][y]+=v;
    }
  }
}
int bit_sum(int ix, int iy) {
  int res=0;
  for (int x=ix+1;x>0;x-=x&-x) {
    for (int y=iy+1;y>0;y-=y&-y) {
      res+=bit[x][y];
    }
  }
  return res;
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int t;
  scanf("%d %d\n", &t, &s);
  while (scanf("%d", &t), t!=3) {
    if (t==1) {
      int x, y, a;
      scanf("%d %d %d\n", &x, &y, &a);
      bit_add(x, y, a);
    } else {
      int x1, y1, x2, y2;
      scanf("%d %d %d %d\n", &x1, &y1, &x2, &y2);
      printf("%d\n", bit_sum(x2, y2)-bit_sum(x1-1, y2)-bit_sum(x2, y1-1)+bit_sum(x1-1, y1-1));
    }
  }
}
