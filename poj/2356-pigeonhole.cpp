// Problem: Given an array of n integers, find a subset that sums to a multiple of n in O(n).
// Solution: prefix sums modulo n. If such a prefix sum is 0, print that prefix of the array.
// Else, since the prefix sums are modulo n and there are n-1 possible values excluding 0,
// the pigeonhole principle guarantees that there are two prefix sums with the same value.
// Then the difference of those prefix sums are 0 modulo n, so find them and print the values
// in the later prefix sum but not the earlier.
// This also proves that there always exists a contiguous subset summing to a multiple of n.

#include <cstdio>

using namespace std;

int a[10000], psc[10000]={0};

int main() {
  int n;
  scanf("%d", &n);
  int ps = 0;
  for (int i = 0; i < n; i++) {
    scanf("%d", a+i);
    ps += a[i], ps %= n;
    if (ps == 0) {
      printf("%d\n", i+1);
      for (int j = 0; j <= i; j++) printf("%d\n", a[j]);
      return 0;
    } else if (++psc[ps] > 1) {
      int j = 0, ps2 = 0;
      while (ps2 != ps) ps2 += a[j++], ps2 %= n;
      printf("%d\n", i-j+1);
      while (j <= i) printf("%d\n", a[j++]);
      return 0;
    }
  }
  
  printf("The pigeonhole principle has fallen, every man for himself!\n");
}
