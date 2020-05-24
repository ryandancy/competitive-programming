// the best debugger is a good night's sleep
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n;
  cin>>n;
  string v;
  cout<<"0 1"<<endl;
  n--;
  cin>>v;
  bool inv=v[0]=='b';
  ll l=1,r=1000000000;
  ll w=0,b=1000000000;
  while (n--) {
    ll m=l+(r-l)/2ll;
    cout<<m<<" 1"<<endl;
    cin>>v;
    bool q=v[0]=='b';
    if (inv) q=!q;
    if (q) r=b=m;
    else l=w=m;
  }
  if (b==-1||w==-1) cout<<"0 0 1 0"<<endl;
  else cout<<w<<" 0 "<<b<<" 2"<<endl;
}
