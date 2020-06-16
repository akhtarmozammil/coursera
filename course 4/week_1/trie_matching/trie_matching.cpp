#include <algorithm>
#include <cassert>
#include <cstdio>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

int const Letters =    4;
int const NA      =   -1;

/*struct Node
{
	int next [Letters];

	Node ()
	{
		fill (next, next + Letters, NA);
	}

	bool isLeaf () const
	{
	    return (next[0] == NA && next[1] == NA && next[2] == NA && next[3] == NA);
	}
};*/

int letterToIndex (char letter)
{
	switch (letter)
	{
		case 'A': return 0; break;
		case 'C': return 1; break;
		case 'G': return 2; break;
		case 'T': return 3; break;
		default: assert (false); return -1;
	}
}

struct trie{
    int position;
    struct trie *child[4];
    bool endOfPattern;

    trie(int pos){
        position = pos;
        endOfPattern = false;
        for(int i =0; i<4; i++)
            child[i] = NULL;
    }
};

trie* build_trie(const vector<string> & patterns) {
  trie* t = new trie(0);
  int count = 1;

  for(int k =0; k<patterns.size(); k++){
    trie *temp = t;
    int i = 0;

    while(i < patterns[k].length()){
        int index = letterToIndex(patterns[k][i]);
        if(temp->child[index] == NULL){
            temp->child[index] = new trie(count);
            count++;
        }

        temp = temp->child[index];
        i++;
    }
    temp->endOfPattern = true;
  }

  return t;
}

vector <int> solve (const string& text, int n, const vector <string>& patterns)
{
	vector <int> result;

	// write your code here
	trie *t = build_trie(patterns);

	for(int i = 0; i<text.size(); i++){
        trie * temp = t;
        int index = letterToIndex(text[i]);

        if(temp->child[index] != NULL){

            if(temp->child[index]->endOfPattern)
                result.push_back(i);
            temp = temp->child[index];

            for(int j = i+1; j<text.size(); j++){
                index = letterToIndex(text[j]);

                if(temp->child[index] == NULL){
                     break;
                }

                if(temp->child[index]->endOfPattern)
                    result.push_back(i);

                temp = temp->child[index];
            }
        }
	}


	return result;
}

int main (void)
{
	string text;
	cin >> text;

	int n;
	cin >> n;

	vector <string> patterns (n);
	for (int i = 0; i < n; i++)
	{
		cin >> patterns[i];
	}

	vector <int> ans;
	ans = solve (text, n, patterns);

	for (int i = 0; i < (int) ans.size (); i++)
	{
		cout << ans[i];
		if (i + 1 < (int) ans.size ())
		{
			cout << " ";
		}
		else
		{
			cout << endl;
		}
	}

	return 0;
}
