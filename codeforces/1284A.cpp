#include <bits/stdc++.h>
using namespace std;
string s[20], t[20], sys[400];
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  unsigned int n, m;
  cin>>n>>m;
  for (int i=0;i<n;i++)cin>>s[i];
  for (int i=0;i<m;i++)cin>>t[i];
  int l=n*m/__gcd(n,m);
  for (int a=0,i=0,j=0;a<l;a++,i++,j++,i%=n,j%=m) {
    sys[a]=s[i]+t[j];
  }
  int q;
  cin>>q;
  while (q--) {
    int y;
    cin>>y;
    y--;
    y%=l;
    cout<<sys[y]<<'\n';
  }
}
