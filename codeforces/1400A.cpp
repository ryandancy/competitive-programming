#include <bits/stdc++.h>
using namespace std;
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
#ifndef ONLINE_JUDGE
  freopen("inp.txt", "r", stdin);
#endif
  int t;
  cin>>t;
  while (t--) {
    int n; string s;
    cin>>n>>s;
    for (int i=0;i<2*n-1;i+=2) {
      cout<<s[i];
    }
    cout<<'\n';
  }
}
