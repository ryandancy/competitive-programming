// TBATTLE - Thor vs Frost Giants

// We determine the prime factors of N as an unordered_map, then store unordered_maps for each giant's
// prime factors. We then use sliding-window pointers to find the minimum separation.

#include <bits/stdc++.h>
using namespace std;

void detPfacs(unordered_map<int, int>& pfacs, int n) {
  for (int f = 2; f <= (int) sqrt(n); f++) {
    if (n % f == 0) {
      detPfacs(pfacs, f);
      detPfacs(pfacs, n / f);
      return;
    }
  }
  pfacs[n]++; // it'll create it if it doesn't exist
}

bool isSuperset(unordered_map<int, int>& big, unordered_map<int, int>& small) {
  for (auto& it : small) {
    if (!big.count(it.first) || big[it.first] < it.second) {
      return false;
    }
  }
  return true;
}

void add(unordered_map<int, int>& curr, unordered_map<int, int>& addend, int mul = 1) {
  for (auto& it : addend) {
    curr[it.first] += mul * it.second;
  }
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  
  int N;
  cin >> N;
  
  unordered_map<int, int> pfacs;
  detPfacs(pfacs, N);
  
  unordered_map<int, int> *elems = new unordered_map<int, int>[N];
  
  int elem;
  for (int i = 0; i < N; i++) {
    cin >> elem;
    if (elem == 1) continue;
    for (auto& it : pfacs) {
      for (int e = elem; e % it.first == 0; e /= it.first) {
        elems[i][it.first]++;
      }
    }
  }
  
  unordered_map<int, int> *p1, *p2; // both inclusive
  p1 = p2 = elems;
  
  // idea is to slide p2 right until we get >= map, then slide p1 until we don't, then minimized
  // continue until we get a smallest one or reach the end
  
  unordered_map<int, int> curr;
  int minA, minB;
  minA = minB = -1;
  int sep = 1000000000;
  while (1) {
    while (1) {
      if (p2 >= elems+N) goto done;
      add(curr, *++p2);
      if (isSuperset(curr, pfacs)) break;
    }
    
    do {
      add(curr, *++p1, -1);
    } while(isSuperset(curr, pfacs));
    
    if (p2 - p1 < sep) {
      minA = p1 - elems; minB = p2 - elems;
      sep = p2 - p1;
    }
  }
  
  done:
  if (minA >= 0) {
    cout << minA << " " << minB << endl;
  } else {
    cout << "-1" << endl;
  }
}
