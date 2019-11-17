#include <bits/stdc++.h>
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
// int d[100000] = {0};
bool in[1000000] = {false};
int nt[1000000] = {0};
vector<int> te;
vector<int> o;
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
#ifndef ONLINE_JUDGE
  freopen("inp.txt", "r", stdin);
#endif
  int n;
  cin >> n;
  int e;
  int ni = 0;
  for (int i = 0; i < n; i++) {
    cin >> e;
    if (e>0) {
      if (in[e]) {return cout << -1 << "\n", 0;}
      in[e] = true;
      nt[e]++;
      te.push_back(e);
      ni++;
    } else {
      if (!in[-e]) return cout << "-1\n", 0;
      in[-e] = false;
      ni--;
    }
    if (i==n-1 && ni != 0) return cout << "-1\n", 0;
    if (ni == 0) {
      for (int& a : te) {
        if (nt[a] > 1) {
          return cout << "-1\n", 0;
        }
      }
      for (int& a : te) {
        nt[a] = 0;
      }
      te.clear();
      o.push_back(i);
    }
    nxt:;
  }
  if (o.size() == 0) return cout << "-1\n", 0;
  cout << o.size() << "\n";
  for (int i = 0; i < o.size(); i++) {
    cout << o[i]-(i==0 ? -1 : o[i-1]) << (i == o.size()-1 ? "\n" : " ");
  }
}
