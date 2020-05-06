#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  ll d, k, a, b, t;
  cin>>d>>k>>a>>b>>t;
  if (k>=d) return cout<<a*d<<'\n', 0;
  cout<<min(a*k+b*(d-k), min(a*d+t*(d/k-(d%k==0)), a*(d-d%k)+t*(d/k-1)+b*(d%k)))<<'\n';
}
