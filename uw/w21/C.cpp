#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  ll p,w,n;
  cin>>p>>w>>n;
  ll np=0,nw=0;
  for (int i=0;i<n;i++) {
    char c; int b;
    cin>>c>>b;
    if (c=='P') np++;
    else nw++;
  }
  cout<<w*nw+p*np-nw*np<<'\n';
}
