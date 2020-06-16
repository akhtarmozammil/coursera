#include <algorithm>
#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

int get_majority_element(vector<int> &a) {

  unordered_map <int , int> m;

  for(int val : a){
    m[val]++;
  }

  int half = a.size()%2==0?(a.size()/2)+1:(a.size()+1)/2;

  for(auto key : m){
    if(key.second >= half){
      return 1;
    }
  }
  return -1;
}

int main() {
  int n;
  std::cin >> n;
  vector<int> a(n);
  for (size_t i = 0; i < a.size(); ++i) {
    std::cin >> a[i];
  }
  std::cout << (get_majority_element(a) != -1) << '\n';
}
