// 1300D - Aerodynamic
// The condition holds when opposite side vectors are equal/opposite. O(n).
#include <bits/stdc++.h>
using namespace std;
int x[100000], y[100000];
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n;
  cin >> n;
  if (n%2)return cout<<"no\n",0;
  for (int i=0;i<n;i++) cin>>x[i]>>y[i];
  for (int i=0;i<n/2;i++) {
    int j=i+n/2;
    if (abs(x[(i+1)%n]-x[i])!=abs(x[(j+1)%n]-x[j])||abs(y[(i+1)%n]-y[i])!=abs(y[(j+1)%n]-y[j])) return cout<<"no\n",0;
  }
  cout<<"yes\n";
}
