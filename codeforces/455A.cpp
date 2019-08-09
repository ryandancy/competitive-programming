// 455A - Boredom
// Simple dynamic programming
// The order of the elements doesn't matter; since the range is 10^5,
// it's more efficient to store an array of elements to count.
// Also note that when we take one element, it's always optimal to then take all of them.
// Then the total score from a_k with count c is c*a_k.
// Let f(x) be the maximum score using elements <= x.
// Then f(x) = max(f(x-1), f(x-2) + x*count(x)); we can either not take x
// or take x, thereby ignoring f(x-1).
// We iterate this up to x=10^5 and return f(10^5).

#include <iostream>

using namespace std;

typedef long long ll;

ll t[100001] = {0};
ll dp[100001];

int main() {
  int n;
  cin >> n;
  
  ll e;
  for (int i = 0; i < n; i++) {
    cin >> e;
    t[e]++;
  }
  
  dp[0] = 0;
  dp[1] = t[1];
  for (int e = 2; e <= 100000; e++) {
    dp[e] = max(dp[e-1], dp[e-2] + e*t[e]);
  }
  cout << dp[100000] << endl;
}
