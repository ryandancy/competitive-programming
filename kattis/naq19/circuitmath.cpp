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
stack<int> stk;
int mp[26];
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n;
  cin >> n;
  for (int i = 0; i < n; i++) {
    char c;
    cin >> c;
    mp[i] = (c=='T');
  }
  char c;
  while (cin >> c) {
    if (c=='*') {
      int a, b;
      a=stk.top(); stk.pop();
      b=stk.top(); stk.pop();
      stk.push(a&&b);
    } else if (c=='+') {
      
      int a, b;
      a=stk.top(); stk.pop();
      b=stk.top(); stk.pop();
      stk.push(a||b);
    } else if (c=='-') {
      int a=stk.top(); stk.pop();
      stk.push(!a);
    } else {
      stk.push(mp[c-'A']);
    }
  }
  cout << (stk.top()?"T":"F") << "\n";
}
