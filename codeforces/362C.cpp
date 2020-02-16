// 362C - Insertion Sort
// O(n^2 log n) using binary indexed trees.
#include <bits/stdc++.h>
using namespace std;
int n;
int a[5000];
int bit[5001]={0};
void add(int x, int v) {
  for (int k=x+1;k<=n;k+=k&-k) bit[k]+=v;
}
int get(int x) {
  int r=0;
  for (int k=x+1;k>0;k-=k&-k) r+=bit[k];
  return r;
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
#ifndef ONLINE_JUDGE
  freopen("inp.txt", "r", stdin);
#endif
  cin >> n;
  for (int i=0;i<n;i++) cin>>a[i];
  int c=0;
  for (int i=0;i<n;i++) {
    c += get(n-1)-get(a[i]);
    add(a[i],1);
  }
  int bst=c;
  int bn=0;
  for (int i=0;i<n;i++) {
    fill_n(bit,n+1,0);
    for (int j=i+1;j<n;j++) {
      if (a[i]>a[j]) {
        int d=1+2*(get(a[i])-get(a[j]));
        int nw=c-d;
        if (nw<bst) {
          bst=nw; bn=1;
        } else if (nw==bst) {
          bn++;
        }
      }
      add(a[j],1);
    }
  }
  cout << bst << ' ' << bn << '\n';
}
