// ABCDEF - ABCDEF
// Rearranged, we find how many times a*b+c = d*(e+f), d != 0
// To do this, in two O(n^3) phases, we first count values of a*b+c,
// then for each d*(e+f), we add the count found in the previous phase.

#include <iostream>
#include <unordered_map>

using namespace std;

int S[100];
unordered_map<long long, long long> abc(1000000);

int main() {
  int N;
  cin >> N;
  for (int i = 0; i < N; i++) cin >> S[i];
  
  for (int x = S[0], xi = 0; xi < N; x = S[++xi]) {
    for (int y = S[0], yi = 0; yi < N; y = S[++yi]) {
      for (int z = S[0], zi = 0; zi < N; z = S[++zi]) {
        abc[x*y+z]++;
      }
    }
  }
  
  long long res = 0;
  for (int x = S[0], xi = 0; xi < N; x = S[++xi]) {
    for (int y = S[0], yi = 0; yi < N; y = S[++yi]) {
      for (int z = S[0], zi = 0; zi < N; z = S[++zi]) {
        if (x != 0 && abc.count(x*(y+z))) {
          res += abc[x*(y+z)];
        }
      }
    }
  }
  
  cout << res << endl;
}
