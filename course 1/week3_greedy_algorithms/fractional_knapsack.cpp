#include <bits/stdc++.h>

using namespace std;

bool sorting(const pair<double,int> &a, const pair<double,int> &b){
  return a.first > b.first;
}

double get_optimal_value(int capacity, vector<int> weights, vector<int> values) {
  double value = 0.0;

  // write your code here
  vector< pair<double, int> > price_per_unit(weights.size());
  for(int i = 0; i<weights.size(); i++){
    price_per_unit[i].first = (values[i])/(double)(weights[i]);
    price_per_unit[i].second = i;
  } 

  sort(price_per_unit.begin(), price_per_unit.end(), sorting);

  for(int i =0; i<weights.size(); i++){
    int index = price_per_unit[i].second;
    if(weights[index] <= capacity){
      capacity -= weights[index];
      value += values[index];
    }else{
      value += capacity*price_per_unit[i].first;
      break;
    }
  }

  return value;
}

int main() {
  int n;
  int capacity;
  std::cin >> n >> capacity;
  vector<int> values(n);
  vector<int> weights(n);
  for (int i = 0; i < n; i++) {
    std::cin >> values[i] >> weights[i];
  }

  double optimal_value = get_optimal_value(capacity, weights, values);

  std::cout.precision(10);
  std::cout << optimal_value << std::endl;
  return 0;
}
