// 158B - Taxi
// O(n log n) - sort, then "top up" each to 4

#include <iostream>
#include <algorithm>

using namespace std;

int s[100000];
int taxis[4] = {0};

int main() {
  int n;
  cin >> n;
  for (int i = 0; i < n; i++) cin >> s[i];
  sort(s, s+n);
  for (int i = n-1; i >= 0; i--) {
    for (int j = 4-s[i]; j > 0; j--) {
      if (taxis[j-1]) {
        taxis[j-1]--;
        taxis[j+s[i]-1]++;
        goto nextgroup;
      }
    }
    taxis[s[i]-1]++;
    nextgroup:;
  }
  cout << taxis[0] + taxis[1] + taxis[2] + taxis[3] << endl;
}
