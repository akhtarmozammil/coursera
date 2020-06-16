#include <iostream>
#include <vector>
#include <queue>

using std::vector;
using std::queue;

int distance(vector<vector<int> > &adj, int s, int t) {
  if(s == t)
    return 0;

  vector <bool> vis(adj.size(), false);

  queue <int> q;
  q.push(s);
  vis[s] = true;
  int pathLength = 0;

  while(!q.empty()){
    int qSize = q.size();
    pathLength++;
    for(int i = 0; i<qSize; i++){
        s = q.front();
        q.pop();

        for(int j = 0; j< adj[s].size(); j++){
            if(adj[s][j] == t)
                return pathLength;

            if(!vis[adj[s][j]]){
                vis[adj[s][j]] = true;
                q.push(adj[s][j]);
            }
        }
    }
  }

  return -1;
}

int main() {
  int n, m;
  std::cin >> n >> m;
  vector<vector<int> > adj(n, vector<int>());
  for (int i = 0; i < m; i++) {
    int x, y;
    std::cin >> x >> y;
    adj[x - 1].push_back(y - 1);
    adj[y - 1].push_back(x - 1);
  }
  int s, t;
  std::cin >> s >> t;
  s--, t--;
  std::cout << distance(adj, s, t);
}
