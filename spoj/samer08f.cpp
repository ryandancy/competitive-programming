// SAMER08F - Feynman

#include <iostream>

using namespace std;

int main() {
  int n;
  cin >> n;
  while (n) {
    cout << n*(n+1)*(2*n+1)/6 << endl;
    cin >> n;
  }
  return 0;
}
