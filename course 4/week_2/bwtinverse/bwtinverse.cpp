#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::vector;
using std::pair;
using std::make_pair;

string InverseBWT(const string& bwt) {
  string text = "";

  vector<pair<char,int> > v;
  int index;

  for(int i = 0; i<bwt.length(); i++){
    v.push_back(make_pair(bwt[i],i));
    if(bwt[i] == '$')
        index = i;
  }

  sort(v.begin(), v.end());
  //for(int i= 0; i<bwt.length(); i++){
    //cout<<v[i].first<<v[i].second<<": "<<bwt[i]<<i<<endl;
  //}

  for(int i = 0; i<bwt.length(); i++){
    text += v[index].first;
    index = v[index].second;
  }

  return text;
}

int main() {
  string bwt;
  cin >> bwt;
  cout << InverseBWT(bwt) << endl;
  return 0;
}
