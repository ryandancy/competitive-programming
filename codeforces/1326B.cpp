#include <bits/stdc++.h>
using namespace std;
int b[200000], a[200000];
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n;
  cin>>n;
  for (int i=0;i<n;i++)cin>>b[i];
  int mx=0;
  for (int i=0;i<n;i++){
    a[i]=b[i]+mx;
    mx=max(mx,a[i]);
  }
  for (int i=0;i<n;i++)cout<<a[i]<<(i==n-1?'\n':' ');
}
