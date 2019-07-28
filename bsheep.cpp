// BSHEEP - Build the Fence
// Andrew's algorithm for convex hull, using complex numbers for coordinates

#include <cmath>
#include <iostream>
#include <algorithm>
#include <complex>
#include <vector>
#define X real
#define Y imag

using namespace std;

struct ewe { // named so as not to conflict with the variable sheep; they're all female right?
  int idx;
  complex<int> xy;
};

ewe sheep[100000];

bool turnsLeft(complex<int> a, complex<int> b, complex<int> c) {
  return (conj(b-a)*(c-b)).Y() >= 0; // also get rid of straight lines
}

vector<ewe> halfAndrews(int n, bool left) {
  // use Andrew's algorithm to make half of the hull
  // the constant ternaries on left are to sort sheep only once
  vector<ewe> half;
  ewe first = sheep[left ? 0 : n - 1];
  half.push_back(first);
  
  ewe curr, last = first, secondLast;
  
  // I apologize for the ternary mess
  for (int i = left ? 1 : n - 2; left ? i < n : i >= 0; left ? i++ : i--) {
    curr = sheep[i];
    
    // skip duplicate points; if left, we skip all but first, and if not, we skip all but last
    // (this is so we use the lowest idx)
    if (left ? curr.xy == last.xy : i > 0 && curr.xy == sheep[i-1].xy) continue;
    
    while (half.size() > 1 && turnsLeft(secondLast.xy, last.xy, curr.xy)) {
      // eliminate left and straight turns
      half.erase(half.end() - 1);
      last = half[half.size() - 1];
      secondLast = half[half.size() - 2];
    }
    
    secondLast = last;
    last = curr;
    half.push_back(curr);
  }
  
  return half;
}

vector<ewe> andrews(int n) {
  // sort first by y, then by x (for weird format)
  sort(sheep, sheep+n, [&] (ewe a, ewe b) {
    if (a.xy.Y() < b.xy.Y()) return true;
    if (a.xy.Y() > b.xy.Y()) return false;
    if (a.xy.X() < b.xy.X()) return true;
    if (a.xy.X() > b.xy.X()) return false;
    return a.idx < b.idx; // lowest index is representative of duplicates
  });
  
  // get each half-hull
  vector<ewe> left = halfAndrews(n, true);
  vector<ewe> right = halfAndrews(n, false);
  
  // combine the half-hulls
  right.erase(right.end() - 1);
  left.erase(left.end() - 1);
  left.insert(left.end(), right.begin(), right.end()); // append right to left
  return left;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  
  int T;
  cin >> T;
  
  for (int t = 0; t < T; t++) {
    int n;
    cin >> n;
    
    // read in sheep
    int x, y;
    for (int i = 0; i < n; i++) {
      cin >> x >> y;
      sheep[i].idx = i;
      sheep[i].xy.X(x);
      sheep[i].xy.Y(y);
    }
    
    // get the convex hull via Andrew's algorithm
    vector<ewe> hull = andrews(n);
    int h = hull.size();
    
    // calculate circumference
    double circum = 0;
    ewe s1, s2;
    int dx, dy;
    for (int i = 0; i < h; i++) {
      s1 = hull[i];
      s2 = hull[(i+1)%h];
      dx = s1.xy.X() - s2.xy.X();
      dy = s1.xy.Y() - s2.xy.Y();
      circum += sqrt(dx*dx + dy*dy);
    }
    
    // print in this weird order to satisfy annoying counterclockwise requirement
    printf("%.2f\n", circum);
    printf("%d ", hull[0].idx + 1);
    for (int i = h - 1; i > 0; i--) {
      printf("%d", hull[i].idx + 1);
      if (i > 1) printf(" ");
    }
    printf("\n\n");
  }
}
