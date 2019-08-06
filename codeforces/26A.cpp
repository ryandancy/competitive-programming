// 26A - Almost Prime
// Sieve of Eratosthenes counting prime divisors - O(n log n)

#include <iostream>

using namespace std;

int sieve[3001] = {0}; // 0 -> prime, else -> number of prime divisors

int main() {
  int n, res = 0;
  cin >> n;
  for (int x = 2; x <= n; x++) {
    if (sieve[x]) {
      if (sieve[x] == 2) res++; // exactly 2 prime divisors
    } else { 
      for (int k = 2*x; k <= n; k += x) {
        sieve[k]++;
      }
    }
  }
  cout << res << "\n";
}
