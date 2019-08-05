// KNAPSACK - The Knapsack Problem

#include <iostream>

using namespace std;

int main() {
  int capacity, numItems;
  cin >> capacity >> numItems;
  
  int weight, value;
  int weights[2000], values[2000];
  for (int i = 0; i < numItems; i++) {
    cin >> weight >> value;
    weights[i] = weight;
    values[i] = value;
  }
  
  int *sackValues = new int[capacity+1];
  fill(sackValues, sackValues+capacity+1, 0);
  
  for (int k = 0; k < numItems; k++) {
    for (int x = capacity; x >= 0; x--) {
      // can we make x adding item k? sackValues[x] is value not adding item k
      int newWeight = x - weights[k];
      if (newWeight >= 0 && (newWeight == 0 || sackValues[newWeight] > 0)) {
        if (sackValues[newWeight] + values[k] > sackValues[x]) {
          sackValues[x] = sackValues[newWeight] + values[k];
        }
      }
    }
  }
  
  int maxValue = 0;
  for (int i = 0; i <= capacity; i++) {
    if (sackValues[i] > maxValue) {
      maxValue = sackValues[i];
    }
  }
  
  cout << maxValue << endl;
}
