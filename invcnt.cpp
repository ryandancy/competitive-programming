// INVCNT - Inversion Count
// O(n log n) using binary indexed tree (BIT)
// If b is the array underlying the BIT, then for a new value a,
// total encountered - sum(b[1..a]) is the number of values greater than a
// before a in the list (i.e. inversions using a)
// We then increment b[a]
// A BIT is used to do this in logarithmic time, giving O(n log n)

#include <iostream>

using namespace std;

int bit[10000001];

void inc_bit(int pos) {
  for (int i = pos; i <= 10000000; i += i&-i) bit[i]++;
}

int sum_bit(int pos) {
  int sum = 0;
  for (int i = pos; i > 0; i -= i&-i) sum += bit[i];
  return sum;
}

int main() {
  int t;
  cin >> t;
  for (int cas = 0; cas < t; cas++) {
    fill(bit, bit+10000001, 0);
    
    int n;
    cin >> n;
    
    int a;
    long long res = 0;
    for (int total = 0; total < n; total++) {
      cin >> a;
      res += total - sum_bit(a); // add number of previously encountered numbers greater than a
      inc_bit(a);
    }
    
    cout << res << endl;
  }
}
