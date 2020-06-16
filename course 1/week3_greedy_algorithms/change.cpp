#include <iostream>

int get_change(int m) {

  int n = 0;
  if(m > 9){
    n += m/10;
    m %= 10;
  }
  if(m > 4){
    n++;
    m -= 5;
  }
  if(m > 0){
    n += m;
  }

  return n;
}

int main() {
  int m;
  std::cin >> m;
  std::cout << get_change(m) << '\n';
}
