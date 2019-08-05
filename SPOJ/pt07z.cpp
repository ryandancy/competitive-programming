// PT07Z - Longest path in a tree
// We store 2 ints for each node in the tree:
// the longest total path in the subtree with root at that node, and
// the longest path in the subtree ending at that node.
// Then the following recurrence relation holds:
// longest ending here = max(childrens' longest ending here + 1)
// longest total = max(childrens' longest total, longest ending here + second longest ending here)

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

struct data {
  int longestTotal, longestHere;
};

data longestPath(vector<int> tree[], int node) {
  int longestHere = 0;
  int secondLongestHere = 0;
  int longestChildTotal = 0;
  
  for (int child : tree[node]) {
    data childData = longestPath(tree, child);
    
    if (childData.longestHere + 1 > longestHere) {
      secondLongestHere = longestHere;
      longestHere = childData.longestHere + 1;
    } else if (childData.longestHere + 1 > secondLongestHere) {
      secondLongestHere = childData.longestHere + 1;
    }
    
    if (childData.longestTotal > longestChildTotal) {
      longestChildTotal = childData.longestTotal;
    }
  }
  
  return { max(longestChildTotal, longestHere + secondLongestHere), longestHere };
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(NULL);
  
  int numNodes;
  cin >> numNodes;
  
  vector<int> *tree = new vector<int>[numNodes];
  bool *isRoot = new bool[numNodes];
  fill(isRoot, isRoot+numNodes, true);
  
  int u, v;
  for (int i = 0; i < numNodes; i++) {
    cin >> u >> v;
    tree[u-1].push_back(v-1);
    isRoot[v-1] = false;
  }
  
  // find root
  int root = -1;
  for (int i = 0; i < numNodes; i++) {
    if (isRoot[i] && tree[i].size() > 0) {
      root = i;
      break;
    }
  }
  
  cout << longestPath(tree, root).longestTotal << endl;
  
  return 0;
}
