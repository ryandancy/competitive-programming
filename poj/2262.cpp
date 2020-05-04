#include <iostream>
#include <string>
#include <vector>
#include <list>
#include <queue>
#include <stack>
#include <cmath>
#include <cstdio>
#include <algorithm>
#define MOD 1000000007
#define INF 1000000000
#define EPS 1e-9
#define PI 3.1415926535897932384626433832795L
#ifdef ONLINE_JUDGE
#define debug(args...)
#else
#include "debug.h"
#endif
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
bool cp[1000001]={false};
vector<int> p;
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
#ifndef ONLINE_JUDGE
  freopen("inp.txt", "r", stdin);
#endif
  cp[2]=true;
  for (int i=2;i<=1000000;i++){
    if (!cp[i]) {
      if (i!=2) p.push_back(i);
      for (int j=2*i;j<=1000000;j+=i) {
        cp[j]=true;
      }
    }
  }
  int n;
  while (cin>>n, n) {
    for (int i=0;i<=p.size();i++) {
      int c=p[i];
      if (!cp[n-c]) {
        cout<<n<<" = "<<c<<" + "<<n-c<<"\n";
        goto nxt;
      }
    }
    cout<<"Goldbach's conjecture is wrong.\n"; // lol
    nxt:;
  }
}
