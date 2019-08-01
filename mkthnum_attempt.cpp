// MKTHNUM - K-th number
// Mo's algorithm with order statistic tree - O(n sqrt(n) log(n))
// Essentially a reimplementation of std::set
// It is too slow but I want to commit it because it took too long
// and also the pointer manipulation is cool

#include <iostream>
#include <algorithm>
#include <vector>
// #include <cassert>

using namespace std;

// bool OUTPUT=false;

struct query {
  int l, r, k;
};

struct node {
  int size = 1, val;
  node *left = nullptr, *right = nullptr;
  node(int val) : val(val) {}
  void destruct() {
    delete this->left;
    delete this->right;
  }
};

node *root = nullptr;
int i = 0;

void insert(int val) { // guaranteed that it's not already in it
  //if (OUTPUT) cout << "inserting " << val << endl;
  node **curr = &root;
  while (*curr) {
    (*curr)->size++;
    int currval = (*curr)->val;
    if (val < currval) {
      curr = &(*curr)->left;
    } else {
      //if (OUTPUT) cout << val << endl;
      //assert((*curr)->val != val);
      curr = &(*curr)->right;
    }
  }
  *curr = new node(val);
}

void erase(int val) { // guaranteed that it's in it
  //if (OUTPUT) cout << "erasing " << val << endl;
  node **curr = &root;
  while ((*curr)->val != val) { // find val
    (*curr)->size--;
    int currval = (*curr)->val;
    if (val < currval) {
      curr = &(*curr)->left;
    } else {
      curr = &(*curr)->right;
    }
    //assert(curr);
    //assert(*curr);
  }
  // if (OUTPUT) cout << "ok" << endl;
  //cout << (*curr)->val << " | ";
  if ((*curr)->left && (*curr)->right) {
    // 2 children - replace with successor or predecessor based on parity
    // (we do both to try to maintain balance)
    (*curr)->size--;
    if (val % 2) {
      // cout << "del 2, succ" << endl;
      node **succ = &(*curr)->right;
      while ((*succ)->left) {
        (*succ)->size--;
        succ = &(*succ)->left;
      }
      (*curr)->val = (*succ)->val;
      if ((*succ)->right) {
        node *right = (*succ)->right;
        delete *succ;
        *succ = right;
      } else {
        delete *succ;
        *succ = nullptr;
      }
    } else {
      // cout << "del 2, pred" << endl;
      node **pred = &(*curr)->left;
      while ((*pred)->right) {
        (*pred)->size--;
        pred = &(*pred)->right;
      }
      (*curr)->val = (*pred)->val;
      if ((*pred)->left) {
        node *left = (*pred)->left;
        delete *pred;
        *pred = left;
      } else {
        delete *pred;
        *pred = nullptr;
      }
    }
  } else if ((*curr)->left || (*curr)->right) {
    // cout << "del 1" << endl;
    // 1 child: delete and replace
    node *child = (*curr)->left ? (*curr)->left : (*curr)->right;
    delete *curr;
    *curr = child;
  } else {
    // cout << "del 0" << endl;
    // no children: just delete
    delete *curr;
    *curr = nullptr;
  }
}

int select(int i) { // get ith order statistic
  node **curr = &root;
  while (*curr) {
    int lsize = (*curr)->left ? (*curr)->left->size : 0;
    // cout << i << ", " << lsize << endl;
    if (i == lsize) {
      return (*curr)->val;
    } else if (i < lsize) {
      curr = &(*curr)->left;
    } else {
      curr = &(*curr)->right;
      i -= lsize + 1;
    }
  }
  return -1;
}

int arr[100000];
query qs[5000];
int qans[5000];
vector<int> qidxs[350];

int qidxcomp(int qi1, int qi2) {
  return qs[qi1].r < qs[qi2].r;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  
  int N, Q;
  cin >> N >> Q;
  
  int bs = 1;
  while (bs*bs < N) bs++;
  
  for (int i = 0; i < N; i++) cin >> arr[i];
  
  for (int i = 0; i < Q; i++) {
    cin >> qs[i].l >> qs[i].r >> qs[i].k;
    //cout << qs[i].l << ", " << bs << ", " << qs[i].l/bs << endl;
    qidxs[qs[i].l/bs].emplace_back(i);
  }
  
  //cout << "hello" << endl;
  
  int cl = -1, cr = -1;
  //int j = 0;
  
  for (int b = 0; b <= N/bs; b++) {
    sort(qidxs[b].begin(), qidxs[b].end(), qidxcomp);
    for (int& qi : qidxs[b]) {
      query& q = qs[qi];
      //cout << "qi=" << qi << ", j=" << j++ << " | [cl, cr] = [" << cl << ", " << cr << "]; [q.l, q.r] = [" << q.l << ", " << q.r << "]" << " | q.k=" << q.k << endl;
      //OUTPUT = false; //qi == 1571 || qi == 1918;
      if ((cl < q.l && cr < q.l) || (cl > q.r && cr > q.r)) {
        delete root; root = nullptr;
        for (int i = q.l; i <= q.r; i++) {
          //if (OUTPUT) cout << "insert arr[" << i-1 << "] = " << arr[i-1] << endl;
          insert(arr[i-1]);
        }
      } else {
        // removals first for speed?
        for (int i = cl; i < q.l; i++) {
          //if (OUTPUT) cout << "erase arr[" << i-1 << "] = " << arr[i-1] << endl;
          erase(arr[i-1]);
        }
        for (int i = cr; i > q.r; i--) {
          //if (OUTPUT) cout << "erase arr[" << i-1 << "] = " << arr[i-1] << endl;
          erase(arr[i-1]);
        }
        // then additions
        for (int i = cl-1; i >= q.l; i--) {
          //if (OUTPUT) cout << "insert arr[" << i-1 << "] = " << arr[i-1] << endl;
          insert(arr[i-1]);
        }
        for (int i = cr+1; i <= q.r; i++) {
          //if (OUTPUT) cout << "insert arr[" << i-1 << "] = " << arr[i-1] << endl;
          insert(arr[i-1]);
        }
      }
      cl = q.l; cr = q.r;
      //root->print(); cout << endl;
      //cout << "selecting for query " << qi << endl;
      qans[qi] = select(q.k-1);
    }
  }
  
  // print answers
  for (int i = 0; i < Q; i++) {
    cout << qans[i] << "\n";
  }
  cout << "total ops: " << i << endl;
  
  delete root;
}
