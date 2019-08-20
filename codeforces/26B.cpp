// 26B - Regular Bracket Sequence
// The idea is that since we don't actually have to *generate* the regular sequence, but merely
// have to find its length, we can assume that certain transformations will be done.
// In particular, if '(' is represented by 1 and ')' by -1, then the following holds true for
// a regular bracket sequence: the total sum is 0, and there exists no negative prefix sum.
// Thus, if we obtain the most negative prefix sum and the total prefix sum, we can assume
// that we must remove enough ')'s to make the lowest prefix sum 0. This increases the total
// by the inverse of the lowest prefix sum. Then, we must remove enough '('s to make the
// total 0 (i.e. subtract the new total from the result). This yields the answer.
// Time complexity - O(n) finding total sum and lowest prefix sum, O(1) calculation - overall O(n).
// Once again, I am unable to distinguish substrings from subsequences. Sigh.

#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  string s;
  cin >> s;
  
  // Find lowest prefix sum and total sum - O(n)
  int lowest = 0;
  int tot = 0;
  for (char c : s) {
    tot += (c=='(' ? 1 : -1);
    if (tot < lowest) lowest = tot;
  }
  
  // Calculate answer
  int res = s.size();
  res += lowest;
  tot -= lowest;
  res -= tot;
  cout << res << "\n";
}
