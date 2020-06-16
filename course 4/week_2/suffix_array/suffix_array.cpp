#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
#include <utility>

using std::cin;
using std::cout;
using std::endl;
using std::make_pair;
using std::pair;
using std::string;
using std::vector;

// Build suffix array of the string text and
// return a vector result of the same length as the text
// such that the value result[i] is the index (0-based)
// in text where the i-th lexicographically smallest
// suffix of text starts.
void BuildSuffixArray(const string& text) {
  int n = text.length();
  vector<pair<string,int> >s(n);

  for(int i =0; i<n; i++){
    s[i] = make_pair(text.substr(i),i);
  }

  sort(s.begin(), s.end());
  for(int i =0; i<text.size(); i++)
    cout<<s[i].second<<" ";
}

int main() {
  string text;
  cin >> text;
  BuildSuffixArray(text);
  cout << endl;
  return 0;
}
