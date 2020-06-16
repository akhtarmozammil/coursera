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

int index(char c){
    switch(c){
        case '$':
            return 0;
        case 'A':
            return 1;
        case 'C':
            return 2;
        case 'G':
            return 3;
        case 'T':
            return 4;
    }
    return -1;
}

vector<int> sortCharacters(string s){
    // for only 5 different char
    vector<int>countSort(5,0);
    vector<int>order(s.length());

    for(int i =0; i<s.length(); i++)
        countSort[index(s[i])]++;

    for(int i = 1; i<5; i++)
        countSort[i] +=countSort[i-1];

    for(int i = s.length()-1; i>=0; i--){
        int indexVal = index(s[i]);
        countSort[indexVal]--;
        order[countSort[indexVal]] = i;
    }
    return order;
}

vector<int> computeCharecterClasses(string s, vector<int> &order){
    vector<int> Class(s.length());
    Class[order[0]] = 0;

    for(int i= 1; i<s.length(); i++){
        if(s[order[i]] != s[order[i-1]])
            Class[order[i]] = Class[order[i-1]] + 1;
        else
            Class[order[i]] = Class[order[i-1]];
    }

    return Class;
}

vector<int> sortDoubled(string s, int l, vector<int> &order, vector<int> &Class){
    vector<int>countSort(s.length(),0);
    vector<int>newOrder(s.length());

    int n = s.length();

    for(int i =0; i<n; i++)
        countSort[Class[i]]++;
    for(int i = 1; i<n; i++)
        countSort[i] += countSort[i-1];

    for(int i = n-1; i>=0; i--){
        int start = (order[i]-l+n)%n;
        int cl = Class[start];
        countSort[cl]--;
        newOrder[countSort[cl]] = start;
    }

    return newOrder;
}

vector<int> updateClasses(vector<int> & order, vector<int> &Class, int l){
    int n = order.size();
    vector<int> newClass(n);

    newClass[order[0]] = 0;

    for(int i = 1; i<n; i++){
        int cur= order[i]; int pre = order[i-1]; int mid = cur + l; int midPre = (pre+l)%n;
        if(Class[cur] != Class[pre] || Class[mid] != Class[midPre])
            newClass[cur] = newClass[pre]+1;
        else
        newClass[cur] = newClass[pre];

    }
    return newClass;
}

//build suffix array
void BuildSuffixArray(string s){
    vector<int>order = sortCharacters(s);
    vector<int>Class = computeCharecterClasses(s,order);

    int l = 1;
    while(l<s.length()){
        order = sortDoubled(s,l,order,Class);
        Class = updateClasses(order,Class,l);
        l *= 2;
    }

    for(int i =0; i<order.size(); i++)
        cout<<order[i]<<" ";
}

void BruteForceBuildSuffixArray(const string& text) {
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
