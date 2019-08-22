// 1207E - XOR Guessing
// Since we don't know which number is picked, the same thing must be true for each number.
// We can derive the answer by having all 100 numbers in the first round have their least
// significant 7 bits all be 1s (or, I suppose, 0s), and all 100 in the second have their
// 8th through 13th bits all be 1s. Then, we take the first 7 bits of the number received
// in the first round and the 8th through 13th bits from the number from the second round,
// invert them (since XOR flips bits), and mask them together to derive the original number.
// Written during Codeforces Educational Round #71
#include <bits/stdc++.h>
using namespace std;
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout << "? ";
  for (unsigned i=0;i<100;i++) {
    cout<<(127U+(i<<7U));
    if (i<99) cout << " ";
  }
  cout << endl;
  unsigned a; cin >> a;
  cout << "? ";
  for (unsigned i=0;i<100;i++) {
    cout << ((127U<<7U)+i);
    if (i<99) cout << " ";
  }
  cout << endl;
  unsigned b; cin >> b;
  unsigned res = ((~a)&127U)+((~b)&16256U);
  cout << "! " << res << endl;
}
