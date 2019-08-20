// 1204D2 - Kirk and a Binary String (hard version)
// It is safe to set a 1 in position i to 0 if for all j in [i, n), setting the 1 to 0
// will not affect the longest nondecreasing subsequence of the subsegment [i, j]. This occurs iff
// the longest nondecreasing subsequence has no zeroes in it, which occurs iff the number of 1s in
// the subsegment is strictly greater than the number of 0s. Thus, for each 1 in the string, we
// must test if there exists a subsegment starting at the position of the 1 which has a majority
// of 0s. This algorithm accomplishes this by letting a '1' be represented by 1 and a '0' by -1.
// Then if the sum of any range starting at the position of a 1 has a zero or negative value,
// we cannot replace the 1 with a 0. For each 0 in the string, we store the prefix sum up to that
// point, as well as its position, in a priority queue (prioritizing lower prefix sums, then lower
// positions). This takes O(n log n) time since storing an item in a priority queue takes O(log n)
// time. Then, we iterate over each 1 in the string. We pop any sum-positions with positions less
// than the current 1; the top of the priority queue is then the lowest prefix sum in a position
// that can be accessed by subsegments starting at this 1. We add an offset calculated by the
// number of 1s and 0s seen thus far which turns a prefix sum into a sum from this position.
// Then, if the sum is greater than 0, it is safe to replace the 1 with a 0; else, we cannot.
// This takes O(n) time; the total time complexity is then O(n log n).
// Written during Codeforces Round #581 (Div. 2)
#include <bits/stdc++.h>
using namespace std;
bool ok[100000];
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
#ifndef ONLINE_JUDGE
  freopen("inp.txt", "r", stdin);
#endif
  string s;
  cin >> s;
  int n = s.size();
  fill_n(ok, n, false);
  int i = 0;
  while (i < n && s[i] != '1') i++;
  if (i == n) { cout << s << "\n"; return 0; } // all zeroes
  int c = 1;
  priority_queue<pair<int, int>, vector<pair<int, int> >, greater<pair<int, int> > > los;
  for (int j = i+1; j < n; j++) {
    c += (s[j]=='1' ? 1 : -1);
    if (s[j]=='0') los.push({c, j});
  }
  ok[i] = los.empty() || los.top().first > 0;
  int off = -1;
  for (int j = i+1; j < n; j++) {
    if (s[j]=='1') {
      if (los.empty()) { ok[j] = true; continue; } // avoid a mystery segfault
      while (!los.empty() && los.top().second < j) los.pop();
      if (los.empty() || los.top().first + off > 0) ok[j] = true;
      off--;
    } else {
      off++;
    }
  }
  string nu;
  for (int i = 0; i < n; i++) {
    if (s[i] == '0' || (s[i]=='1' && ok[i])) {
      nu += '0';
    } else nu += '1';
  }
  cout << nu << '\n';
}
