// 691E - Xor-sequences
// Take O(n^2) to generate a matrix M where M[i][j] = 1 if a[i]^a[j] fulfills the bit
// condition and 0 otherwise. We interpret this as the adjacency matrix of a graph of
// the input numbers where two number-vertices are connected if they can be adjacent
// in an xor-sequence. To find the number of paths through this graph touching k vertices
// and therefore going through k-1 edges (which is the number of length-k xor-sequences),
// we calculate M^{k-1} using the logarithmic time power algorithm for O(n^3 log k). Total
// time complexity is O(n^3 log k).
#include <bits/stdc++.h>
#define MOD 1000000007
using namespace std;
typedef unsigned long long ll;
int n; ll k;
ll a[100];
ll mat[100][100], orig[100][100], cpy[100][100];
void mmul(ll mat1[100][100], ll mat2[100][100], ll cpy[100][100]) {
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      cpy[i][j] = 0;
      for (int q = 0; q < n; q++) {
        cpy[i][j] += mat1[i][q] * mat2[q][j] % MOD;
        cpy[i][j] %= MOD;
      }
    }
  }
}
void mpow(ll q) {
  if (q <= 1) return;
  mpow(q / 2LL);
  mmul(mat, mat, cpy);
  for (int i = 0; i < n; i++) for (int j = 0; j < n; j++) mat[i][j] = cpy[i][j];
  if (q % 2) {
    mmul(mat, orig, cpy);
    for (int i = 0; i < n; i++) for (int j = 0; j < n; j++) mat[i][j] = cpy[i][j];
  }
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cin >> n >> k;
  if (k == 1) return cout << n << "\n", 0;
  for (int i = 0; i < n; i++) cin >> a[i];
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      mat[i][j] = orig[i][j] = ((__builtin_popcountll(a[i]^a[j]) % 3) == 0);
    }
  }
  mpow(k-1);
  ll s = 0;
  for (int i = 0; i < n; i++) for (int j = 0; j < n; j++) s += mat[i][j], s %= MOD;
  cout << (s%MOD+MOD)%MOD << "\n";
}
