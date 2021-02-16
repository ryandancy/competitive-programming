#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int t;
  cin>>t;
  while (t--) {
    ll n;
    cin>>n;
    ll x=(ll)sqrt(2*n-1);
    ll res=x/2;
    if (x%2==1) res++;
    res--;
    cout<<res<<'\n';
  }
}
