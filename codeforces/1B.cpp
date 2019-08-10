// 1B - Spreadsheets
// Strange, mostly trial-and-errored base conversion-esque algorithm

#include <iostream>
#include <string>
#include <sstream>

using namespace std;

typedef unsigned long long ll;

int main() {
  int n;
  cin >> n;
  
  string s;
  for (int i = 0; i < n; i++) {
    cin >> s;
    if (s.empty()) {
      i--;
      continue;
    }
    ll cpos = s.find('C');
    if (s[0] == 'R' && s[1] <= '9' && cpos != string::npos) {
      ll r = stoull(s.substr(1, cpos-1));
      ll c = stoull(s.substr(cpos+1, s.length()-cpos-1));
      stringstream o;
      while (c > 0) {
        if (c % 26 == 0) {
          o << 'Z';
          c--;
        } else {
          o << (char) (c%26+'A'-1);
        }
        c /= 26;
      }
      string a(o.str());
      string b(a.rbegin(), a.rend());
      cout << b << r << "\n";
    } else {
      ll j, c = 0;
      for (j = 0; j < s.length() && s[j] >= 'A' && s[j] <= 'Z'; j++) {
        c *= 26;
        c += (s[j] == 'Z' ? 26 : s[j]-'A'+1);
      }
      cout << 'R' << s.substr(j, s.length()-j) << 'C' << c << '\n';
    }
  }
}
