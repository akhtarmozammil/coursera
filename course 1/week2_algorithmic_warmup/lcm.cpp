#include <iostream>

using namespace std;

int gcd_fast(int a, int b) {

  while(b != 0){
    int temp = b;
    b = a%b;
    a = temp;
  }

  return a;
}

long long lcm_fast(int a, int b) {
  
  int gcd = gcd_fast(a,b);
  long long lcm = ((long long)(a) * b)/gcd;

  return lcm;
}

int main() {
  int a, b;
  cin >> a >> b;
  cout << lcm_fast(a, b) << endl;
  return 0;
}
