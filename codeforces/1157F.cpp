#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n,b[210000]={0};
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
#ifndef ONLINE_JUDGE
  freopen("inp.txt", "r", stdin);
#endif
  cin>>n;
  for (ll i=0,x;i<n;i++)cin>>x,b[x]++;
  ll bst=0,bl=-1,br=-1,i=0,cs=-1,cv=0;
  for (;i<=200000;i++) {
    if (b[i]>0) {
      cv+=b[i];
      if (cs==-1) cs=i;
      else if (b[i]==1) {
        if (cv>bst) {
          bst=cv;
          bl=cs;
          br=i;
        }
        cv=1;
        cs=i;
      }
    } else {
      if (cv>bst) {
        bst=cv;
        bl=cs;
        br=i-1;
      }
      cv=0;
      cs=-1;
    }
  }
  if (cs!=-1&&cv>bst) {
    bst=cv;
    bl=cs;
    br=200000;
  }
  cout<<bst<<'\n';
  for (i=bl;i<=br;i++) {
    cout<<i<<' '; b[i]--;
  }
  for (i=br;i>=bl;i--) {
    while (b[i]>0) {
      cout<<i<<" ";b[i]--;
    }
  }
  cout<<'\n';
}
