#include <iostream>

int get_change(int m) {

  int arr[m+1];
  arr[0] = 0; arr[1] = 1; arr[2] = 2; arr[3] = 1; arr[4] = 1;
  for(int i =5; i<=m; i++){
    arr[i] = std::min(arr[i-1] , std::min(arr[i-3], arr[i-4])) + 1;
  }

  return arr[m];
}

int main() {
  int m;
  std::cin >> m;
  std::cout << get_change(m) << '\n';
}
