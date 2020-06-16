#include <iostream>
#include <vector>

int dp[301][10001];

using std::vector;

int optimal_weight(int W, const vector<int> &w) {
  int n = w.size()+1;
  int m = W+1;

  for(int i = 0; i<n; i++)
    dp[i][0] = 0;
  for(int i =0; i<m; i++)
    dp[0][i] = 0;

  for(int i = 1; i<n; i++){
    for(int j = 1; j<m; j++){
      if(w[i-1] <= j)
        dp[i][j] = std::max(dp[i-1][j], w[i-1] + dp[i-1][j- w[i-1] ]);
      else
        dp[i][j] = dp[i-1][j];
    }
  }

  /*for(int i = 0;  i<n; i++){
    for(int j =0; j<m; j++){
      std::cout<<dp[i][j]<<" ";
    }std::cout<<"\n";
  }*/

  return dp[n-1][m-1];
}

int main() {
  int n, W;
  std::cin >> W >> n;
  vector<int> w(n);
  for (int i = 0; i < n; i++) {
    std::cin >> w[i];
  }
  std::cout << optimal_weight(W, w) << '\n';
}
