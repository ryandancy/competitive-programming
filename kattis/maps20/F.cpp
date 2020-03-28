#include <bits/stdc++.h>
#define MOD 1000000007
#define INF 1000000000
#define EPS 1e-9
#define PI 3.1415926535897932384626433832795L
#ifndef DEBUG
#define debug(args...)
#else
#include "debug.h"
#endif
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
#ifdef DEBUG
  freopen("inp.txt", "r", stdin);
#endif
  int n;
  cin>>n;
  vector<string> v;
  string s;
  getline(cin,s);
  for (int i=0;i<n;i++){
    getline(cin, s);
    for (int i=0;i<s.size();i++){
      if (s[i]=='-')s[i]=' ';
      else if (isupper(s[i])) s[i]=tolower(s[i]);
    }
    debug(s);
    v.push_back(s);
  }
  sort(v.begin(), v.end());
  auto it = unique(v.begin(), v.end());
  cout<<distance(v.begin(), it)<<"\n";
}
