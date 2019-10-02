// RMQSQ - Range Minimum Query

// ans[a][b] contains the min of [a,b] and is defined when b-a+1 (length of [a,b]) is a power of 2
// then any arbitrary query [i,j] can be broken into [i,i+w-1] and [j-w+1,j]
// where w is the largest power of 2 such that w <= b-a+1

#include <iostream>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  
  int N;
  cin >> N;
  
  int **ans = new int*[N];
  for (int i = 0; i < N; i++) {
    ans[i] = new int[N];
    cin >> ans[i][i];
  }
  
  for (int p = 2; p <= N; p *= 2) {
    for (int o = 0; o <= N - p; o++) {
      ans[o][o+p-1] = min(ans[o][o+p/2-1], ans[o+p/2][o+p-1]);
    }
  }
  
  int Q;
  cin >> Q;
  int a, b;
  for (int i = 0; i < Q; i++) {
    cin >> a >> b;
    int w = 1;
    while (b-a+1 > 2*w) w *= 2; // w is largest power of 2 less than b-a+1
    cout << min(ans[a][a+w-1], ans[b-w+1][b]) << endl;
  }
}
