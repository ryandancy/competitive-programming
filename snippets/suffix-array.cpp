#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> pll;

// A suffix array SA of a string s is an array where each element SA[i]
// represents the suffix of s from SA[i] to the end of the string (i.e. s[SA[i]:])
// and the suffixes are *sorted lexicographically*.
// For example, the suffix array of "GATAGACA$" is:
//  i  SA[i]  suffix
//  0  8      $
//  1  7      A$
//  2  5      ACA$
//  3  3      AGACA$
//  4  1      ATAGACA$
//  5  6      CA$
//  6  4      GACA$
//  7  0      GATAGACA$
//  8  2      TAGACA$
// An $ or another char not appearing in the string must be appended so no suffix is
// a prefix of any other (avoid index-out-of-bounds).
// See CP3 6.6.4-5.

// Build a suffix array: O(n log n) where n = s.size()
// s.push_back('$');
vector<ll> suffix_array(string& s) {
  ll n=s.size(), alph=256; // alphabet size
  vector<ll> cnt(max(n,alph)), p(n), c(n);
  for (auto c:s) cnt[c]++;
  for (ll i=1;i<alph;i++) cnt[i]+=cnt[i-1];
  for (ll i=0;i<n;i++) p[--cnt[s[i]]]=i;
  for (ll i=1;i<n;i++) c[p[i]]=c[p[i-1]]+(s[p[i]]!=s[p[i-1]]);
  vector<ll> c2(n), p2(n);
  for (ll k=0;(1<<k)<n;k++) {
    ll cls=c[p[n-1]]+1;
    fill(cnt.begin(),cnt.begin()+cls,0);
    for (ll i=0;i<n;i++) p2[i]=(p[i]-(1<<k)+n)%n;
    for (ll i=0;i<n;i++) cnt[c[i]]++;
    for (ll i=1;i<cls;i++) cnt[i]+=cnt[i-1];
    for (ll i=n-1;i>=0;i--) p[--cnt[c[p2[i]]]]=p2[i];
    c2[p[0]]=0;
    for (ll i=1;i<n;i++) {
      pll b1={c[p[i]],c[(p[i]+(1<<k))%n]};
      pll b2={c[p[i-1]],c[(p[i-1]+(1<<k))%n]};
      c2[p[i]]=c2[p[i-1]]+(b1!=b2);
    }
    c.swap(c2);
  }
  return p;
}

// The longest common prefix array LCP for a suffix array SA and string s is
// an array where LCP[i] is the length of the longest common prefix between
// SA[i] and SA[i-1]. LCP[0] = 0. For example, with "GATAGACA$":
//  i  SA[i]  LCP[i]  suffix
//  0  8      0       $
//  1  7      0       A$
//  2  5      1       ACA$
//  3  3      1       AGACA$
//  4  1      1       ATAGACA$
//  5  6      0       CA$
//  6  4      0       GACA$
//  7  0      2       GATAGACA$
//  8  2      0       TAGACA$

// Build longest common prefix array: O(n) where n = s.size()
// p must be suffix array of s
vector<ll> lcp(string& s, vector<ll>& p) {
  ll n=s.size();
  vector<ll> ans(n-1), pi(n);
  for (ll i=0;i<n;i++) pi[p[i]] = i;
  ll lst=0;
  for (ll i=0;i<n-1;i++) {
    if (pi[i]==n-1) continue;
    while (s[i+lst]==s[p[pi[i]+1]+lst]) lst++;
    ans[pi[i]]=lst;
    lst=max(0ll,lst-1);
  }
  return ans;
}

// Applications:
// * Count occurrences of T in S: build suffix array in O(|S|log|S|), then query
// by binary searching lower/upper bounds in O(|T|log|S|).
// * Longest repeating substring: max of LCP array. O(n).
// * Longest common substring of S and T: add unique chars to end of S and T
// (S += '$', T += '#'), then build SA and LCP, go through adjacent suffixes
// and find max LCP where the adjacent suffixes are from different strings.
//   ll lcs=0;
//   for (ll i=1;i<n;i++) if ((sa[i]<m)!=(sa[i-1]<m)) lcs=max(lcs,lcp[i]);
// For >2 strings: use a 2-pointer sliding window and find min LCP in windows
// which contain suffixes from all strings.
