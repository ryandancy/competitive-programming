// 4C - Registration system
// We *could* make a trie, but a map solution works and is shorter

#include <iostream>
#include <unordered_map>
#include <string>

using namespace std;

unordered_map<string, int> m;

int main() {
  int n;
  cin >> n;
  
  string s;
  for (int i = 0; i < n; i++) {
    cin >> s;
    if (m.count(s)) {
      s += to_string(++m[s]);
      cout << s << "\n";
    } else {
      m[s] = 0;
      cout << "OK\n";
    }
  }
}
