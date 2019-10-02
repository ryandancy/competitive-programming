#include <stdio.h>
#include <iostream>
using namespace std;

// GSS1 - Can you answer these queries I
// Using segment tree - https://cp-algorithms.com/data_structures/segment_tree.html
// Python is too slow so here it is in C++

struct segment {
  long long sum, val, prefix, suffix;
};

// merge segments for two adjacent intervals into one for one big interval
void combine(segment& res, const segment& seg1, const segment& seg2) {
  res.sum = seg1.sum + seg2.sum;
  res.val = max(max(max(max(seg1.val, seg2.val), seg1.suffix + seg2.prefix), seg1.suffix), seg2.prefix);
  res.prefix = max(max(seg1.prefix, seg1.sum + seg2.prefix), seg1.sum);
  res.suffix = max(max(seg2.suffix, seg2.sum + seg1.suffix), seg2.sum);
}

void build_tree(segment* tree, int* arr, int idx, int left, int right) {
  if (left == right) {
    tree[idx].sum = tree[idx].val = tree[idx].prefix = tree[idx].suffix = arr[left];
  } else {
    int half = (left + right) / 2;
    build_tree(tree, arr, 2*idx, left, half);
    build_tree(tree, arr, 2*idx + 1, half + 1, right);
    combine(tree[idx], tree[2*idx], tree[2*idx + 1]);
  }
}

void query(segment& res, segment* tree, int idx, int left, int right, int x, int y) {
  int mid = (left + right) / 2;
  if (left == x && right == y) {
    res = tree[idx];
  } else if (x <= mid && y <= mid) {
    query(res, tree, 2*idx, left, mid, x, y);
  } else if (x > mid && y > mid) {
    query(res, tree, 2*idx + 1, mid + 1, right, x, y);
  } else {
    segment leftPart, rightPart;
    query(leftPart, tree, 2*idx, left, mid, x, mid);
    query(rightPart, tree, 2*idx + 1, mid + 1, right, mid + 1, y);
    combine(res, leftPart, rightPart);
  }
}

int main() {
  // lots of IO so fast stdio is needed
  ios::sync_with_stdio(0);
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  
  int len;
  cin >> len;
  
  // Read into base array
  int* arr = new int[len];
  for (int* p = arr; p < arr+len; p++) {
    cin >> *p;
  }
  
  segment* tree = new segment[4*len]; // segment tree
  build_tree(tree, arr, 1, 0, len - 1);
  
  int numQueries;
  cin >> numQueries;
  
  // Read queries
  int x, y;
  segment res;
  for (int i = 0; i < numQueries; i++) {
    cin >> x >> y;
    query(res, tree, 1, 0, len - 1, x-1, y-1);
    cout << res.val << "\n";
  }
  
  return 0;
}
