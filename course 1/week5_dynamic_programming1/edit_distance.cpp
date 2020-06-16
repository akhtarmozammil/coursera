#include <iostream>
#include <string>

using std::string;

int edit_distance(const string &str1, const string &str2) {

  int n = str1.length()+1;
  int m = str2.length()+1;
  int arr[n][m];

  for(int i =0; i<n; i++){
    arr[i][0] = i;
  }

  for(int i =0; i<m; i++){
    arr[0][i] = i;
  }

  for(int i = 1; i<n; i++){
    for(int j = 1; j<m; j++){
        if(str1[i-1] != str2[j-1])
          arr[i][j] = std::min(arr[i][j-1], std::min(arr[i-1][j], arr[i-1][j-1])) + 1;
        else
          arr[i][j] = arr[i-1][j-1];
    }
  }

  return arr[n-1][m-1];
}

int main() {
  string str1;
  string str2;
  std::cin >> str1 >> str2;
  std::cout << edit_distance(str1, str2) << std::endl;
  return 0;
}
