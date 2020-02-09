// 1300E - Water Balance
// Stack-based approach (implemented with linked list):
// Repeatedly add incoming values onto the stack (represented as fractions),
// whenever the top of the stack is less than the one below it, combine by adding
// the top and bottom of the fractions. The fraction is the value and the denominator
// is the number of places with that value. O(n): each value interacts with the stack
// (pushing/being combined) at most twice.
#include <bits/stdc++.h>
using namespace std;
typedef double ld;
struct f {ll n,d;};
list<f> a;
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n;
  cin >> n;
  for (int i = 0; i < n; i++) {
    f x;
    cin >> x.n, x.d=1;
    a.push_back(x);
  }
  auto it=a.begin();
  while (it != a.end()) {
    while (it!=a.begin()) {
      ll cn=it->n, cd=it->d;
      --it;
      if (!(cn*it->d<cd*it->n)){++it;break;}
      it->n+=cn;
      it->d+=cd;
      ++it;
      it = a.erase(it);
      --it;
    }
    ++it;
  }
  for (f&x:a){
    ld d=((ld)x.n)/((ld)x.d);
    for (int i=0;i<x.d;i++) printf("%.12f\n",d);
  }
}
