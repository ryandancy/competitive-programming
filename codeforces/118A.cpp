// 118A - String Task

#include <iostream>
#include <cctype>
#include <string>

using namespace std;

int main() {
  string a;
  cin >> a;
  for (char c : a) {
    c = tolower(c);
    if (c == 'a' || c == 'o' || c == 'y' || c == 'e' || c == 'u' || c == 'i') continue;
    cout << '.' << c;
  }
  cout << endl;
}
