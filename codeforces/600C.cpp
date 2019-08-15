// 600C - Make Palindrome
// Solved in 12:45, no WAs
// Since permutations are free, order doesn't matter, so we make an array of the counts
// of each letter. We can make a permutation when there are exactly 0 or 1 odd counts.
// We make a vector of the indices (letters) with odd counts and remove from the highest
// indices and add to the lowest indices until there are 0 or 1 odd counts.
// We then print out a palindrome using the lowest indices first (except for the lone odd,
// if applicable).
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int cnt[26];
vector<int> odds;
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  string s;
  cin >> s;
  for (char c : s) {
    cnt[c-'a']++;
  }
  for (int i = 0; i < 26; i++) {
    if (cnt[i] % 2 != 0) odds.push_back(i);
  }
  int l = 0, r = odds.size()-1;
  while (r-l>0) {
    cnt[odds[l]]++;
    cnt[odds[r]]--;
    l++; r--;
  }
  int lodd = -1;
  for (int i = 0; i < 26; i++) {
    if (cnt[i] % 2 != 0) {
      lodd = i;
      cnt[i]--;
    }
    cnt[i] /= 2;
    for (int j = 0; j < cnt[i]; j++) cout << (char) (i+'a');
  }
  if (lodd != -1) cout << (char) (lodd+'a');
  for (int i = 25; i >= 0; i--) {
    for (int j = 0; j < cnt[i]; j++) cout << (char) (i+'a');
  }
  cout << endl;
}
