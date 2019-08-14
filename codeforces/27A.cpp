// 27A - Next Test
// Simple - sort before incrementing
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int a[3000];
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n;
  cin >> n;
  for (int i = 0; i < n; i++) cin >> a[i];
  sort(a, a+n);
  int id = 1;
  for (int x : a) {
    if (x == id) id++;
    else break;
  }
  cout << id << "\n";
}