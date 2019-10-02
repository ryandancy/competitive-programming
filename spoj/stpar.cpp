// STPAR - Street Parade
// We just simulate it: take from approach or side street if it has the one we're looking for,
// move from approach to side if neither does, if approach is empty we can't.

#include <iostream>
#include <stack>
#include <queue>

using namespace std;

queue<int> approach;
stack<int> side;

bool possible() {
  int looking = 1;
  while (!approach.empty() || !side.empty()) {
    if (!approach.empty() && approach.front() == looking) {
      approach.pop();
      looking++;
    } else if (!side.empty() && side.top() == looking) {
      side.pop();
      looking++;
    } else {
      if (approach.empty()) return false; // ran out
      side.push(approach.front());
      approach.pop();
    }
  }
  return true;
}

int main() {
  while (1) {
    int n;
    cin >> n;
    if (n == 0) break;
    
    int lm;
    for (int i = 0; i < n; i++) {
      cin >> lm;
      approach.push(lm);
    }
    
    cout << (possible() ? "yes" : "no") << endl;
    
    // clear approach & side
    approach = queue<int>();
    side = stack<int>();
  }
}
