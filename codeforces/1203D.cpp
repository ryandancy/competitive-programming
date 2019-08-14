// 1203D1 and 1203D2 - Remove the Substring (easy and hard versions)
// The idea is that the length of the longest removable substring is
// the largest distance between letters in any subsequence, or between that subsequence
// and the left or right side. For each lowercase Latin letter, we create a vector
// of the positions in s in which that letter shows up. Then, for each letter in t,
// we find the maximum and minimum position in s to which that position in t could
// correspond as part of a full subsequence. To find the minimums, we process t from
// left to right. t[0]'s minimum is its first occurrence, and for t[i], we binary search
// in the vector of the positions in s of t[i-1] for the smallest value strictly larger
// than mins[i-1]. We do the same in reverse to find the maximums. Then, the answer is
// the maximum distance between max[i] and min[i-1] or between min[i] and max[i+1], or
// max[0], or t.size()-min[t.size()-1]-1. Time complexity: O(|s|+|t|).
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
vector<int> cnt[26];
int maxs[200000], mins[200000];
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  string s, t;
  cin >> s >> t;
  int n = t.size(), k = s.size();
  for (int i = 0; i < k; i++) {
    cnt[s[i]-'a'].push_back(i);
  }
  mins[0] = cnt[t[0]-'a'][0];
  for (int i = 1; i < n; i++) {
    mins[i] = *upper_bound(cnt[t[i]-'a'].begin(), cnt[t[i]-'a'].end(), mins[i-1]);
  }
  maxs[n-1] = cnt[t[n-1]-'a'][cnt[t[n-1]-'a'].size()-1];
  for (int i = n-2; i >= 0; i--) {
    auto m = lower_bound(cnt[t[i]-'a'].begin(), cnt[t[i]-'a'].end(), maxs[i+1]);
    if (*m >= maxs[i+1] || m == cnt[t[i]-'a'].end()) --m;
    maxs[i] = *m;
  }
  int res = max(maxs[0], k-mins[n-1]-1);
  for (int i = 1; i < n-1; i++) {
    res = max(res, max(maxs[i] - mins[i-1] - 1, maxs[i+1] - mins[i] - 1));
  }
  cout << res << "\n";
}