// 231A - Team

#include <iostream>

using namespace std;

int main() {
  int n;
  cin >> n;
  
  int s, res = 0;
  for (int i = 0; i < n; i++) {
    int tot = 0;
    for (int j = 0; j < 3; j++) {
      cin >> s;
      tot += s;
    }
    if (tot >= 2) res++;
  }
  
  cout << res << endl;
}
