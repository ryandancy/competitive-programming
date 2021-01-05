#include <bits/stdc++.h>
#define MOD 1000000007
using namespace std;
typedef long long ll;
ll n, p;
set<ll> c;
string ac;
ll hb=-1,ls=-1;
ll fexp(ll x) {
  if (x==0)return 1;
  if (x==1)return 2;
  ll r=fexp(x/2);
  r*=r;
  r%=MOD;
  if (x%2)r*=2,r%=MOD;
  return r;
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cin>>n;
  ll ru=0,np=0;
  while (n--) {
    cin>>ac>>p;
    if (ac=="ADD") {
      c.insert(p);
      if (hb==-1||(p>hb&&p<ls)) np++;
    } else {
      auto it=c.lower_bound(p);
      if (hb==-1 || (p>=hb&&p<=ls)) {
        if (hb==-1||(p>hb&&p<ls)) ru++;
        if (it==c.begin())hb=0;
        else hb=*--it, ++it;
        ++it;
        if (it==c.end())ls=INF;
        else ls=*it;
        --it;
        c.erase(it);
        np=0;
        if (c.empty()) hb=ls=-1;
      } else {
        return cout<<"0\n",0;
      }
    }
  }
  cout<<(fexp(ru)%MOD*(np+1)%MOD+MOD)%MOD<<'\n';
}
