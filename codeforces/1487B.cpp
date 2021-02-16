#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int t;
  cin>>t;
  while (t--) {
    ll n,k;
    cin>>n>>k;
    k--;
    if (n%2==0) {
      cout<<(k%n+1)<<'\n';
      continue;
    }
    ll sk=(n-1)/2;
    ll r=(k+k/sk)%n;
    cout<<r+1<<'\n';
  }
}
