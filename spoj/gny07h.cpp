// GNY07H - Tiling a Grid With Dominoes

#include <iostream>

using namespace std;

// we use a bitmask: 1 = square facing bottom, 0 = anything else
// rotate to a H-by-4 grid for better time complexity O(n) since it's usually O(n*2^w)
// conditions for the next row being valid given the first row are:
// 1) each 1 in the first must have a 0 under it in the next (down- and up-piece)
// 2) 0s in both first and second must occur in runs of even numbers (left- and right-piece)
// since the width is just 4 we *could* have hardcoded it but this is more general
// we take the 0th row as having 1 valid solution with bitmask 0000 only to start
// the last (Hth) row must be 0000 too, so we check for its validity
// really only two rows of dp are ever used at the same time so we *could* theoretically only
//   use two, but this works

int count(int* dp[], int h) { // dp[bitmask][row] = # solutions
  for (int r = 1; r <= h; r++) {
    for (int bm = 0; bm < 16; bm++) { // *previous* row's bitmask
      if (dp[bm][r-1] == 0) continue;
      
      // go through each possible next bitmask and test if it works
      for (int newBm = 0; (r == h) ? newBm < 1 : newBm < 16; newBm++) {
        int zeroRun = 0;
        for (int sh = 0; sh < 4; sh++) {
          // under every 1 there must be a 0
          if ((bm & (1<<sh)) && (newBm & (1<<sh))) goto nextBm;
          
          // runs of zeros that aren't under ones must be of even length
          if ((bm & (1<<sh)) || (newBm & (1<<sh))) {
            // ending zero run
            if (zeroRun % 2) goto nextBm;
            zeroRun = 0;
          } else zeroRun++;
        }
        if (zeroRun % 2) continue; // can't occur at end either
        
        // this bitmask is valid
        dp[newBm][r] += dp[bm][r-1];
        
        nextBm:;
      }
    }
  }
  
  return dp[0][h];
}

int main() {
  int numCases, h;
  int* dp[16];
  cin >> numCases;
  for (int i = 1; i <= numCases; i++) {
    cin >> h;
    for (int*& arr : dp) {
      arr = new int[h+1];
      fill(arr, arr+h+1, 0);
    }
    dp[0][0] = 1;
    cout << i << " " << count(dp, h) << endl;
    for (int*& arr : dp) {
      delete arr;
    }
  }
}
