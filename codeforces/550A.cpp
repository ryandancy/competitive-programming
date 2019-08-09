// 550A - Two Substrings
// There are a few patterns we deem "overlapping": ABA, BAB, ABAB, and BABA
// These trigger an "overlap" flag instead of AB or BA, since they can stand
// in for AB or BA, but not both.
// This mainly consists of checking the flags for each case of AB, BA, ABA, BAB, ABAB, BABA.
// O(n) though, we go through the string once.

#include <iostream>
#include <string>

using namespace std;

int main() {
  string s;
  cin >> s;
  
  bool ab, ba, olap;
  ab = ba = olap = false;
  for (int i = 0; i < s.size()-1; i++) {
    if (s[i] == 'A' && s[i+1] == 'B') {
      if (i < s.size()-2 && s[i+2] == 'A') {
        if (ab || ba || olap) {
          cout << "YES\n";
          return 0;
        }
        olap = true;
        if (i < s.size()-3 && s[i+3] == 'B') {
          i += 2;
        } else {
          i++;
        }
      } else {
        ab = true;
        if (ba || olap) {
          cout << "YES\n";
          return 0;
        }
      }
    } else if (s[i] == 'B' && s[i+1] == 'A') {
      if (i < s.size()-2 && s[i+2] == 'B') {
        if (ab || ba || olap) {
          cout << "YES\n";
          return 0;
        }
        olap = true;
        if (i < s.size()-3 && s[i+3] == 'A') {
          i += 2;
        } else {
          i++;
        }
      } else {
        ba = true;
        if (ab || olap) {
          cout << "YES\n";
          return 0;
        }
      }
    }
  }
  
  cout << "NO\n";
}
