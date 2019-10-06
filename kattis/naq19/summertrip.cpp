#include <bits/stdc++.h>
#define MOD 1000000007
#define INF 1000000000
#define EPS 1e-9
#define PI 3.1415926535897932384626433832795L
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
int c[26] = {0};
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  string s;
  cin >> s;
  ll res = 0;
  for (int a = 0; a < s.size()-1; a++) {
    fill_n(c, 26, 0);
    for (int b = a+1; b < s.size(); b++) {
      if (s[b] == s[a]) break;
      if (c[s[b]-'a']++ == 0) res++;
    }
  }
  cout << res << "\n";
}
