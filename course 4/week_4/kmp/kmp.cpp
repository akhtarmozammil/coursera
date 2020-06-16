#include<bits/stdc++.h>

using namespace std;

// Find all occurrences of the pattern in the text and return a
// vector with all positions in the text (starting from 0) where
// the pattern starts in the text.
int pf[1000000];

void find_pattern() {
  string pattern ;
  string text ;
  cin >> pattern;
  cin >> text;
  //design prefix array of pattern;
  pf[0] = 0;
  int i = 1;
  int j = 0;

  while(i <= pattern.length()){
    if(pattern[i] == pattern[j]){
        j++;
        pf[i] = j;
        i++;
    }else if(j > 0){
        j = pf[j-1];
    }else{
        pf[i] = 0;
        i++;
    }
  }
  //match text
    i = 0;
    j = 0;
    while (i < text.length()) {
        if (pattern[j] == text[i]) {
            j++;
            i++;
        }

        if (j == pattern.length()) {
            cout<<i-j<<" ";
            j = pf[j - 1];
        }

        else if (i < text.length() && pattern[j] != text[i]) {
            if (j != 0)
                j = pf[j - 1];
            else
                i++;
        }
    }
}

int main() {
  find_pattern();
  cout<<endl;
  return 0;
}
