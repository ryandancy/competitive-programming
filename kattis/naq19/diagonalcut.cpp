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
ll gcd(ll a, ll b) {
  if (b == 0) return a;
  return gcd(b, a%b);
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  ll N, M;
  cin >> N >> M;
  ll g = gcd(N, M);
  if (N/g % 2 == 1 && M/g % 2 == 1) {
    cout << g << "\n";
  } else {
    cout << "0\n";
  }
  
}
