#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll kb[10000];
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  ll s, k;
  cin>>s>>k;
  kb[0]=1;
  ll sm=1, l=-k+1, r=0;
  while (r<10000&&kb[r]<=s) {
    r++;
    kb[r]=sm;
    if (l>=0)sm-=kb[l];
    l++;
    sm+=kb[r];
  }
  vector<ll> repr{0};
  for (ll i=r;i>=0;i--) {
    if (kb[i]<=s) {
      repr.push_back(kb[i]);
      s-=kb[i];
    }
  }
  if (s!=0)cout<<"PANIC!!\n";
  cout<<repr.size()<<'\n';
  for (int i=0;i<repr.size();i++) {
    cout<<repr[i]<<(i==repr.size()-1?'\n':' ');
  }
}
