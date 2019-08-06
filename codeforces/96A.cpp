// 96A - Football

#include <iostream>

using namespace std;

int main() {
  string s;
  cin >> s;
  
  int run = 0;
  char curr = s[0];
  for (char c : s) {
    if (c == curr) {
      run++;
    } else {
      if (run >= 7) break;
      curr = c;
      run = 1;
    }
  }
  
  cout << (run >= 7 ? "YES" : "NO") << endl;
}
