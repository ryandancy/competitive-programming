#include <bits/stdc++.h>
using namespace std;
int n,a[100];
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int t;
  cin>>t;
  while (t--) {
    cin>>n;
    for (int i=0;i<n;i++)cin>>a[i];
    sort(a,a+n);
    int lo=a[0],res=0;
    for (int i=0;i<n;i++) if (a[i]!=lo) res++;
    cout<<res<<'\n';
  }
}
