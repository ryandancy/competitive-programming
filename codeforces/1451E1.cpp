#include <bits/stdc++.h>
#define MOD 1000000007
#define INF 1000000000
#define EPS 1e-9
#define PI 3.1415926535897932384626433832795L
#ifdef ONLINE_JUDGE
#define debug(args...) (0)
#else
#include "debug.h"
#endif
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
ll xo[1<<16]={0};
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  ll n;
  cin>>n;
  for (ll i=1;i<n;i++) {
    cout<<"XOR 1 "<<i+1<<endl; cout.flush();
    cin>>xo[i];
  }
  ll aob,aoc;
  cout<<"OR 1 2"<<endl; cout.flush();
  cin>>aob;
  cout<<"OR 1 3"<<endl; cout.flush();
  cin>>aoc;
  ll aab = aob^xo[1];
  ll aac = aoc^xo[2];
  ll a=aab|aac|(aab&aac&(xo[1]^xo[2]));
  cout<<"! ";
  for (ll i=0;i<n;i++) {
    cout<<(a^xo[i]);
    if (i<n-1)cout<<' ';
  }
  cout<<endl;
  cout.flush();
}
