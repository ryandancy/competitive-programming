// 1278B - A and B
// Generate triangular numbers and match to the next highest one with
// the same parity as the difference. Turns out this is the pattern.
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll trg[50000];
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  for (ll i = 0; i < 50000; i++) {
    trg[i] = i*(i+1)/2;
  }
  int T;
  cin >> T;
  while (T--) {
    ll a, b;
    cin >> a >> b;
    ll d = max(a,b) - min(a,b);
    if (d==0) {
      cout << "0\n";
      continue;
    }
    if (d==1) {cout << "1\n"; continue;}
    int i = lower_bound(trg,trg+50000,d)-trg;
    while (d%2 != trg[i]%2) i++;
    cout << i << '\n';
  }
}
