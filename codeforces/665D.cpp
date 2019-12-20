// 665D - Simple Subset
// First, I spent way too long trying to turn this into a graph theory problem.
// It's convertible if you represent the given array as the vertices of a graph and
// connect vertices if their numbers sum to a prime, and then you have to find the
// maximum clique in the graph. But the maximum clique problem is NP-complete, so d'oh.
// However (courtesy of the editorial) if a solution {a,b,c} contains at most one 1,
// then there cannot be two even elements, as they would sum to an even number greater
// than 2, which is composite, and there cannot be two odd elements for the same reason.
// Therefore such a solution cannot exist and we just twiddle with the number of 1s until
// we find the solution. Sieve of Eratosthenes is used to find primes <= 2*10^6. ~O(n^2).
#include <bits/stdc++.h>
using namespace std;
bool c[2000001] = {false};
int a[1000];
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  for (int p = 2; p < 2000000; p++) {
    if (c[p]) continue;
    for (int k = 2*p; k <= 2000000; k += p) {
      c[k] = true;
    }
  }
  int n;
  cin >> n;
  int n1 = 0;
  for (int i = 0; i < n; i++) {
    cin >> a[i];
    if (a[i] == 1) n1++;
  }
  if (n1 >= 2) {
    for (int i = 0; i < n; i++) {
      if (a[i] != 1 && !c[a[i]+1]) {
        cout << n1+1 << "\n";
        for (int j = 0; j < n1; j++) cout << "1 ";
        cout << a[i] << "\n";
        return 0;
      }
    }
    cout << n1 << "\n";
    for (int j = 0; j < n1; j++) cout << 1 << (j==n1-1?"\n":" ");
    return 0;
  }
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      if (i == j) continue;
      if (!c[a[i]+a[j]]) {
        cout << "2\n" << a[i] << ' ' << a[j] << "\n";
        return 0;
      }
    }
  }
  cout << "1\n" << a[0] << "\n";
  return 0;
}
