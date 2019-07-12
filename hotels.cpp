// HOTELS - Hotels Along the Croatian Coast

#include <iostream>

using namespace std;

int main() {
  int n, m;
  cin >> n >> m;
  
  int *hotels = new int[n];
  for (int i = 0; i < n; i++) {
    cin >> hotels[i];
  }
  
  int *p1, *p2;
  p1 = p2 = hotels;
  int sum = hotels[0];
  int maxSum = sum;
  
  do {
    // advance p2
    p2++;
    while (p2 < hotels + n && sum + *p2 <= m) sum += *p2++;
    p2--;
    
    if (sum > maxSum) maxSum = sum;
    
    // advance p1
    sum -= *p1++;
  } while (p1 < hotels + n);
  
  cout << maxSum << endl;
}
