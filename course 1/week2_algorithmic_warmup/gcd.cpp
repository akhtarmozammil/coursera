#include <iostream>

int gcd_fast(int a, int b) {

  while(b != 0){
    //std::cout<<"A "<<a<<"  "<<"B "<<b<<std::endl;
    int temp = b;
    b = a%b;
    a = temp;
  }

  return a;
}

int main() {
  int a, b;
  std::cin >> a >> b;
  std::cout << gcd_fast(a, b) << std::endl;
  return 0;
}
