#include <bits/stdc++.h>
using namespace std;
int n,x[50];
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int T;
  cin>>T;
  while (T--) {
    cin>>n;
    for (int i=0;i<n;i++)cin>>x[i];
    set<int> d;
    for (int i=0;i<n;i++){
      for (int j=i+1;j<n;j++) {
        d.insert(abs(x[i]-x[j]));
      }
    }
    cout<<d.size()<<'\n';
  }
}
