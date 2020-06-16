#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> optimal_sequence(int n) {
  vector<int> index(n+1);
  vector<int> dp(n+1, 1000001) ;
  dp[0] = dp[1] = index[0] = index[1] = 0;

  for(int i = 1; i<=n; i++){
    if(i+1 <= n && dp[i+1] > dp[i] + 1){
      dp[i+1] = dp[i] + 1;
      index[i+1] = i;
    }
    if(i*2 <= n && dp[i*2] > dp[i] + 1){
      dp[i*2] = dp[i] + 1;
      index[i*2] = i;
    }
    if(i*3 <= n && dp[i*3] > dp[i] + 1){
      dp[i*3] = dp[i] + 1;
      index[i*3] = i;
    }
  }

  vector<int> numbers(dp[n]+1);
  int pos = dp[n];
  int jump = n;
  while(pos >= 0){
    numbers[pos] = jump;
    jump = index[jump];
    pos--;
  }
  return numbers;
}

int main() {
  int n;
  std::cin >> n;
  vector<int> sequence = optimal_sequence(n);
  std::cout << sequence.size() - 1 << std::endl;
  for (size_t i = 0; i < sequence.size(); ++i) {
    std::cout << sequence[i] << " ";
  }
}
