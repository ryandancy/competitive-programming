// 158A - Next Round

#include <iostream>

using namespace std;

int main() {
  int n, k;
  cin >> n >> k;
  k--;
  
  int c, kp = 0, res = 0;
  for (int i = 0; i < n; i++) {
    cin >> c;
    if (c <= 0) break;
    if (i > k && c < kp) break;
    if (i == k) kp = c;
    res++;
  }
  
  cout << res << endl;
}
