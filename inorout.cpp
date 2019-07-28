// INOROUT - Inside or outside?
// O(NQ) solution using ray sending + complex numbers for vector arithmetic
// The "ray" is implemented as a line segment from the point to out-of-bounds

#include <iostream>
#include <complex>
#include <utility>

// for ease of using complex numbers as vectors
#define X real
#define Y imag

using namespace std;

typedef complex<long long> P;

P pts[3000];
P far(0, 10000000); // 10x limit

int sgn(long long x) { // signum function
  return (x > 0) - (x < 0);
}

bool oppositeSides(P& a1, P& a2, P& b1, P& b2) {
  // are b1 and b2 on opposite sides of a1-a2?
  // (this is true when (a1-a2)x(a1-b1) and (a1-a2)x(a1-b2) have different signs)
  P conjugate = conj(a1-a2);
  int cross1 = sgn((conjugate*(a1-b1)).Y());
  int cross2 = sgn((conjugate*(a1-b2)).Y());
  return cross1 != 0 && cross2 != 0 && cross1 != cross2;
}

bool intersect(P& a1, P& a2, P& b1, P& b2) {
  // do the line segments a1-a2 and b1-b2 intersect?
  return oppositeSides(a1, a2, b1, b2) && oppositeSides(b1, b2, a1, a2);
}

bool onSegment(P& a, P& b1, P& b2) {
  // is a on b1-b2?
  // check on the line defined by b1 and b2
  if ((conj(a-b1)*(b2-a)).Y() != 0) return false;
  
  // check x-coordinates in bounds
  int x1 = b1.X(), x2 = b2.X();
  if (x1 > x2) swap(x1, x2);
  if (!(x1 <= a.X() && a.X() <= x2)) return false;
  
  // check y-coordinates in bounds
  int y1 = b1.Y(), y2 = b2.Y();
  if (y1 > y2) swap(y1, y2);
  return y1 <= a.Y() && a.Y() <= y2;
}

bool inside(P& pt, int N) {
  // count intersections between pt-far and each adjacent pair in O(N) time
  int isecs = 0;
  P a, b;
  
  for (int i = 0; i < N; i++) {
    a = pts[i];
    b = pts[(i+1)%N];
    if (onSegment(pt, a, b)) return true; // on edge = in according to problem statement
    if (intersect(pt, far, a, b)) isecs++;
  }
  
  // even intersections -> out, odd intersections -> in
  return isecs % 2 == 1;
}

int main() {
  int N, Q;
  cin >> N >> Q;
  
  long long x, y;
  for (int i = 0; i < N; i++) {
    cin >> x >> y;
    pts[i] = {x, y};
  }
  
  P pt;
  for (int i = 0; i < Q; i++) {
    cin >> x >> y;
    pt.X(x);
    pt.Y(y);
    
    cout << (inside(pt, N) ? "D" : "F") << endl;
  }
}
