#include<bits/stdc++.h>
#include<string>

using namespace std;

string BWT(string& text) {
  string result = "";

  vector<string> bwt(text.size());
  int n = text.length();

  for(int i =0; i<n; i++){
    bwt[i] = text;
    text = text.substr(1,n-1) + text[0];
  }

  sort(bwt.begin(),bwt.end());

  for(int i = 0; i<n; i++){
    //cout<<bwt[i]<<endl;
    result += bwt[i][n-1];
  }

  return result;
}

int main() {
  string text;
  cin >> text;
  cout << BWT(text) << endl;
  return 0;
}
