#include <iostream>
#include <vector>

using std::vector;
using std::pair;

bool isPath(vector <bool> &vis, vector<vector<int> > &adj, int x, int y){
    if(x == y)
        return true;

    vis[x] = true;

    bool path = false;
    for(int i =0; i<adj[x].size(); i++){
        if(!vis[adj[x][i]])
            path |= isPath(vis,adj,adj[x][i],y);
    }

    return path;
}

int reach(vector<vector<int> > &adj, int x, int y) {
  vector<bool> vis(adj.size(), false);
  if(isPath(vis,adj,x,y))
    return 1;

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
    adj[y - 1].push_back(x - 1);
  }
  int x, y;
  std::cin >> x >> y;
  std::cout << reach(adj, x - 1, y - 1);
}
