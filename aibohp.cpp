// AIBOHP - Aibohphobia

#include <iostream>
#include <string>

using namespace std;

int dp[6101][6101];

int minadd(string& word, int l, int r) { // [l, r]
  if (dp[l][r] != -1) return dp[l][r];
  int res;
  if (word[l-1] == word[r-1]) {
    res = (l == r - 1) ? 0 : minadd(word, l+1, r-1);
  } else {
    res = min(minadd(word, l, r-1), minadd(word, l+1, r)) + 1;
  }
  dp[l][r] = res;
  return res;
}

int main() {
  int t, len;
  cin >> t;
  string word;
  for (int i = 0; i < t; i++) {
    cin >> word;
    len = word.length();
    for (int i = 0; i <= len; i++) {
      fill_n(dp[i], len+1, -1);
      dp[i][i] = 0;
    }
    cout << minadd(word, 1, len) << endl;
  }
}
