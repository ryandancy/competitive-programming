// PALIN - The Next Palindrome
// Simple casework

#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

void inc(string& str) {
  // increment the number represented by str
  int n = str.size() - 1;
  while (str[n] == '9') {
    str[n--] = '0';
    if (n < 0) {
      // it's all 9s
      str[0] = '1';
      str.append("0");
      return;
    }
  }
  str[n]++;
}

void nextPalin(string& str) {
  int n = str.size();
  
  if (n == 1) {
    // Special case - single character
    if (str[0] == '9') {
      str = "11";
    } else {
      str[0]++;
    }
    return;
  }
  
  string half1 = str.substr(0, n/2);
  string half2 = str.substr(n/2 + n%2, n/2);
  
  string half1rev(half1);
  reverse(half1rev.begin(), half1rev.end());
  
  if (half1rev > half2) {
    // try replacing second half with reversed first half
    str.replace(n/2 + n%2, n/2, half1rev);
  } else if (n%2 && str[n/2] != '9') {
    // odd - try incrementing middle digit
    str[n/2]++;
    str.replace(n/2+1, n/2, half1rev);
  } else {
    // increment first half, re-reverse
    if (n%2) str[n/2] = '0';
    
    unsigned oldSize = half1.size();
    inc(half1);
    half1rev = half1;
    reverse(half1rev.begin(), half1rev.end());
    
    if (half1.size() == oldSize) {
      // if half1 didn't increment in length, just replace first and second half with it/reverse
      str.replace(0, n/2, half1);
      str.replace(n/2 + n%2, n/2, half1rev);
    } else {
      // incremented half1 length - half1 is 1000..., so it's special
      str = n%2 ? half1 : half1.substr(0, oldSize); // remove a 0 for 9999 -> 10001 not 100001
      str.append(half1rev);
    }
  }
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  
  int N;
  cin >> N;
  
  string s;
  getline(cin, s); // waste
  for (int i = 0; i < N; i++) {
    getline(cin, s);
    nextPalin(s);
    cout << s << "\n";
  }
}
