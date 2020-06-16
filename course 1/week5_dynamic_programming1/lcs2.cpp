#include <iostream>
#include <vector>

using std::vector;

int lcs2(vector<int> &a, vector<int> &b) {

  int dp[a.size()+1][b.size()+1];

  for(int i =0; i<=a.size(); i++)
    dp[i][0] = 0;

  for(int i =0; i<=b.size(); i++)
    dp[0][i] = 0;

  for(int i =1; i<=a.size(); i++){
    for(int j =1; j<=b.size(); j++){
      if(a[i-1] != b[j-1])
        dp[i][j] = std::max(dp[i-1][j],dp[i][j-1]);
      else
        dp[i][j] = dp[i-1][j-1] + 1;
    }
  }

  return dp[a.size()][b.size()];
}

int main() {
  size_t n;
  std::cin >> n;
  vector<int> a(n);
  for (size_t i = 0; i < n; i++) {
    std::cin >> a[i];
  }

  size_t m;
  std::cin >> m;
  vector<int> b(m);
  for (size_t i = 0; i < m; i++) {
    std::cin >> b[i];
  }

  std::cout << lcs2(a, b) << std::endl;
}
