// PPATH - Prime Path
// Sieve of Eratosthenes for the primes, BFS for each

#include <iostream>
#include <queue>

using namespace std;

bool sieve[10000];
bool visited[9000]; // visited[n-1000] -> n is visited; 9000 to save space

int main() {
  // sieve to find primes less than 10000 in O(n log n)
  fill_n(sieve, 10000, true);
  sieve[0] = sieve[1] = false;
  for (int i = 2; i < 10000; i++) {
    if (sieve[i]) {
      for (int j = 2*i; j < 10000; j += i) {
        sieve[j] = false;
      }
    }
  }
  
  int T; cin >> T;
  int a, b;
  for (int t = 0; t < T; t++) {
    cin >> a >> b;
    
    fill_n(visited, 9000, false);
    visited[a-1000] = true;
    
    // BFS from a for b
    queue<pair<int, int>> q;
    q.push({a, 0});
    pair<int, int> curr;
    while (!q.empty()) {
      curr = q.front();
      q.pop();
      
      if (curr.first == b) {
        cout << curr.second << endl;
        goto nextcase;
      }
      
      // really it would have been easier to use strings/arrays, but this is ok for making neighbours
      for (int mask = 1; mask <= 1000; mask *= 10) {
        int m = curr.first - (curr.first % (10*mask));
        if (mask > 1) m += curr.first % mask;
        for (int o = (mask == 1000) ? 1 : 0; o <= 9; o++) {
          int n = m + mask*o;
          if (n != curr.first && sieve[n] && !visited[n-1000]) {
            q.push({n, curr.second + 1});
            visited[n-1000] = true;
          }
        }
      }
    }
    
    cout << "Impossible" << endl;
    
    nextcase:;
  }
}
