#include <string>
#include <iostream>
#include <vector>
#include <map>


using namespace std;

//typedef map<char, int> edges;
//typedef vector<edges> trie;

struct trie{
    int position;
    struct trie *child[26];

    trie(int pos){
        position = pos;
        for(int i =0; i<26; i++)
            child[i] = NULL;
    }
};

trie* build_trie(vector<string> & patterns) {
  trie* t = new trie(0);
  int count = 1;

  for(int k =0; k<patterns.size(); k++){
    trie *temp = t;
    int i = 0;

    while(i < patterns[k].length()){
        if(temp->child[patterns[k][i] - 'A'] == NULL){
            temp->child[patterns[k][i] - 'A'] = new trie(count);
            count++;
        }

        temp = temp->child[patterns[k][i]-'A'];
        i++;
    }
  }

  return t;
}

void printTrie(trie *t){

    for(int i =0; i<26; i++){
        if(t->child[i]){
            cout<<t->position<<"->"<<t->child[i]->position<<":"<<char('A' + i)<<endl;
            printTrie(t->child[i]);
        }
    }

}

int main() {
  size_t n;
  std::cin >> n;
  vector<string> patterns;
  for (size_t i = 0; i < n; i++) {
    string s;
    std::cin >> s;
    patterns.push_back(s);
  }

  trie *t = build_trie(patterns);
  /*for (size_t i = 0; i < t.size(); ++i) {
    for (const auto & j : t[i]) {
      std::cout << i << "->" << j.second << ":" << j.first << "\n";
    }
  }*/

  printTrie(t);

  return 0;
}
