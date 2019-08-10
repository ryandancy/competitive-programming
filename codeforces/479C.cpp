// 479C - Exams
// Sort ascending primarily by recorded day, secondarily by min day
// Then simply iterate and choose minimum possible day at each point
// Overall O(n log n)

#include <iostream>
#include <utility>
#include <algorithm>

using namespace std;

pair<int, int> es[5000];

int main() {
  int n;
  cin >> n;
  for (int i = 0; i < n; i++) cin >> es[i].first >> es[i].second;
  sort(es, es+n);
  
  int day = 0;
  for (int i = 0; i < n; i++) {
    if (day <= es[i].second) day = es[i].second;
    else day = es[i].first;
  }
  
  cout << day << "\n";
}
