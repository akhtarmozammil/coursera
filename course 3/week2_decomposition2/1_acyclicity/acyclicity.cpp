#include <iostream>
#include <vector>

using std::vector;
using std::pair;

bool Ac(vector<vector<int> > &adj , vector<bool> &vis, vector<bool> &recursiveStack, int node){

    recursiveStack[node] = true;
    vis[node] = true;

    for(int i =0; i<adj[node].size(); i++){
        if(!vis[adj[node][i]] && Ac(adj,vis,recursiveStack,adj[node][i]))
            return true;
        else if(recursiveStack[adj[node][i]])
            return true;
    }

    recursiveStack[node] = false;
    return false;
}

int acyclic(vector<vector<int> > &adj) {

  vector < bool > vis(adj.size(), false);
  vector < bool > recursiveStack(adj.size(),false);
  for(int i =0; i<adj.size(); i++){
    if(!vis[i] && Ac(adj,vis,recursiveStack, i)){
        return 1;
    }
  }

  return 0;
}

int main() {


  size_t n, m;
  std::cin >> n >> m;
  vector<vector<int> > adj(n, vector<int>());
  for (size_t i = 0; i < m; i++) {
    int x, y;
    std::cin >> x >> y;
    adj[x - 1].push_back(y - 1);
  }
  std::cout << acyclic(adj);
}
