// ONP - Transform the Expression
// Ad-hoc recursive solution

#include <iostream>
#include <string>
#include <vector>

using namespace std;

const char OPS[] = "^/*-+";

string rpn(string& str, int& x) {
  vector<string> rpns;
  vector<char> ops;
  
  bool startBracket = str[x] == '(';
  if (startBracket) x++;
  
  // parse it recursively
  while (startBracket ? str[x] != ')' : x < str.length()) {
    if ('a' <= str[x] && str[x] <= 'z') {
      rpns.push_back(string(1, str[x]));
    } else if (str[x] == '(') {
      rpns.push_back(rpn(str, x));
    } else { // operator
      ops.push_back(str[x]);
    }
    x++;
  }
  
  // create overall rpn by combining rpns into rpns[0]
  for (const char& op : OPS) {
    for (int i = 0; i < ops.size(); i++) {
      if (ops[i] == op) {
        ops.erase(ops.begin() + i);
        rpns[i].append(rpns[i+1]);
        rpns[i].append(string(1, op));
        rpns.erase(rpns.begin() + i + 1);
        i--;
      }
    }
  }
  
  return rpns[0];
}

int main() {
  int T, x;
  cin >> T;
  string expr;
  for (int t = 0; t < T; t++) {
    cin >> expr;
    x = 0; // for reference
    cout << rpn(expr, x) << endl;
  }
}
