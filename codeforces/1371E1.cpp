#include <bits/stdc++.h>
using namespace std;
int a[100000],b[100000];
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
#ifndef ONLINE_JUDGE
  freopen("inp.txt", "r", stdin);
#endif
  int n,p;
  cin>>n>>p;
  for (int i=0;i<n;i++)cin>>a[i],b[i]=n-a[i];
  sort(a,a+n);
  sort(b,b+n);
  vector<int> r;
  for (int x=a[0];x<a[n-1];x++){
    for (int i=0;i<n;i++){
      int c=min(n,b[i]+x)-i;
      if (c<=0)goto nxt;
      if (c%p==0)goto nxt;
    }
    r.push_back(x);
    nxt:;
  }
  cout<<r.size()<<'\n';
  for (int i=0;i<r.size();i++){
    cout<<r[i]<<(i==r.size()-1?'\n':' ');
  }
}
