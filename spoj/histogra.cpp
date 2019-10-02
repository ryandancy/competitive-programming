// HISTOGRA - Largest Rectangle in a Histogram
// O(n) algorithm using stacks
// We maintain 2 stacks - one for heights (hs), one for indexes (idxs).
// idxs stores the index at which h in hs begins.
// When a new height h comes in, we pop all hs/idxs where hs.top() < h
// and evaluate the rectangle as hs.top() * (i - idxs.top()) where i is
// the index of the new height.
// Then, if the current height is strictly greater than the new hs.top()
// (to prevent useless duplication), we push h to hs and the smallest idx
// popped from idxs to idxs (to enable rectangles that start lower down).
// (We do this at the end too).
// This is O(n) - each height is processed twice, once as a main height
// and once in the stack.

#include <iostream>
#include <stack>

using namespace std;

typedef long long ll;

stack<ll> hs;
stack<ll> idxs;

int main() {
  ll n;
  cin >> n;
  
  while (n) {
    ll h, best = 0;
    
    for (ll i = 0; i < n; i++) {
      cin >> h;
      ll newi = i;
      while (!hs.empty() && h < hs.top()) {
        newi = idxs.top();
        best = max(best, hs.top() * (i - newi));
        hs.pop();
        idxs.pop();
      }
      if (hs.empty() || h > hs.top()) {
        hs.push(h);
        idxs.push(newi);
      }
    }
    
    while (!hs.empty()) {
      best = max(best, hs.top() * (n - idxs.top()));
      hs.pop();
      idxs.pop();
    }
    
    cout << best << endl;
    
    cin >> n;
  }
}
