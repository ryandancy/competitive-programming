// 1200E - Compress Words
// The idea is to precompute prefix hashes so that suffix hashes may be calculated in O(1)
// We precompute the prefix hashes for the base string and for the incoming word
// We then compare hashes to find the largest overlap
// Then we add the word to the overall string and extend the hashes to the new part of the string
// A hash ending at each letter is computed at most twice, so this is O(n)
// Note: this was NOT created during the contest

#include <iostream>
#include <string>

using namespace std;

#define A 965174628
#define B 975781372

typedef long long ll;

ll h[1000001];
ll h2[1000001];
ll p[1000001];

inline ll hsh(int a, int b) {
  if (a == 0) return h[b];
  ll res = (h[b] - h[a-1]*p[b-a+1])%B;
  if (res < 0) res += B;
  return res;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  
  p[0] = 1;
  for (int i = 1; i < 1000001; i++) {
    p[i] = (p[i-1]*A)%B;
  }
  
  int n;
  cin >> n;
  
  string s, w;
  cin >> s; n--;
  
  // initialize hashes on first word
  h[0] = s[0];
  for (int i = 1; i < s.length(); i++) {
    h[i] = (h[i-1]*A + s[i])%B;
  }
  
  while (n--) {
    cin >> w;
    
    int slen = s.length(), wlen = w.length();
    
    // generate hashes for w and test against those of s
    int comm = 0;
    h2[0] = w[0];
    if (h2[0] == hsh(slen-1, slen-1)) comm = 1;
    for (int i = 1; i < min(slen, wlen); i++) {
      h2[i] = (h2[i-1]*A + w[i])%B;
      if (h2[i] == hsh(slen-i-1, slen-1)) comm = i+1;
    }
    
    s += w.substr(comm, wlen-comm);
    
    // update main hashes
    for (int i = slen; i < s.length(); i++) {
      h[i] = (h[i-1]*A + s[i])%B;
    }
  }
  
  cout << s << "\n";
}
