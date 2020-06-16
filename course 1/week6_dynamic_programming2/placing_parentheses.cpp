#include <iostream>
#include <cassert>
#include <string>
#include <vector>

using std::vector;
using std::string;
using std::max;
using std::min;
using std::cin;
using std::cout;
using std::endl;

long long eval(long long a, long long b, char op) {
  if (op == '*') {
    return a * b;
  } else if (op == '+') {
    return a + b;
  } else if (op == '-') {
    return a - b;
  } else {
    return 0;
  }
}

long long get_maximum_value(const string &exp) {

  int n = (exp.size()+1)/2;

  long long dpMin[n][n]= {0}, dpMax[n][n]= {0};
  for(int i =0; i<n; i++)
    dpMax[i][i] = dpMin[i][i] = int(exp[i*2] - int('0'));

  for(int i = 1; i<n; i++){
    for(int j =0; j<n-i; j++){
        long long minimum = 100000000000000000;
        long long maximum = -10000000000000000;
        for(int k = j; k<j+i; k++){
            vector<long long> e(4);
            e[0] = eval(dpMax[j][k],dpMax[k+1][i+j],exp[(k*2)+1]);
            e[1] = eval(dpMin[j][k],dpMin[k+1][i+j],exp[(k*2)+1]);
            e[2] = eval(dpMax[j][k],dpMin[k+1][i+j],exp[(k*2)+1]);
            e[3] = eval(dpMin[j][k],dpMax[k+1][i+j],exp[(k*2)+1]);

            for(long long val: e)
                maximum = max(maximum, val);
            for(long long val: e)
                minimum = min(minimum,val);
        }
        dpMax[j][i+j] = maximum;
        dpMin[j][i+j] = minimum;
    }
  }

  /*for(int i =0; i<n; i++){
    for(int j =0; j<n; j++){
      cout<<dpMax[i][j]<<" ";
    }cout<<endl;
  }cout<<endl<<endl;

  for(int i =0; i<n; i++){
    for(int j =0; j<n; j++){
      cout<<dpMin[i][j]<<" ";
    }cout<<endl;
  }*/

  return (dpMax[0][n-1] > dpMin[0][n-1])?dpMax[0][n-1]:dpMin[0][n-1];
}

int main() {
  string s;
  std::cin >> s;
  std::cout << get_maximum_value(s) << '\n';
}
