#include <algorithm>
#include <iostream>
#include <vector>

using std::cin;
using std::cout;
using std::endl;
using std::vector;

struct Node {
  int key;
  int left;
  int right;

  Node() : key(0), left(-1), right(-1) {}
  Node(int key_, int left_, int right_) : key(key_), left(left_), right(right_) {}
};

bool isBST(const vector<Node>& tree, int index, long long min, long long max){

  if(index == -1)
    return true;

  if(tree[index].key < min || tree[index].key > max)
    return false;

  return isBST(tree,tree[index].left,min,tree[index].key) && isBST(tree,tree[index].right,tree[index].key,max);
}

bool dupNodeOnLeftSide(const vector<Node>& tree,int index){

    if(index == -1)
        return true;

    if(tree[index].left != -1 && tree[index].key == tree[tree[index].left].key)
        return false;

    return dupNodeOnLeftSide(tree,tree[index].left) && dupNodeOnLeftSide(tree,tree[index].right);
}

bool IsBinarySearchTree(const vector<Node>& tree) {

  if(tree.empty())
      return true;

  if(isBST(tree,0,-1000000000000,1000000000000))
    return dupNodeOnLeftSide(tree,0);

  return false;
}

int main() {
  int nodes;
  cin >> nodes;
  vector<Node> tree;
  for (int i = 0; i < nodes; ++i) {
    int key, left, right;
    cin >> key >> left >> right;
    tree.push_back(Node(key, left, right));
  }
  if (IsBinarySearchTree(tree)) {
    cout << "CORRECT" << endl;
  } else {
    cout << "INCORRECT" << endl;
  }
  return 0;
}
