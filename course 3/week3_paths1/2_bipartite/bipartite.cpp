#include <iostream>
#include <vector>
#include <queue>

using std::vector;
using std::queue;

int bipartite(vector<vector<int> > &adj) {
  if(adj.size() == 0)
    return 1;

  vector<int> color(adj.size(), -1);
  queue<int> q;
  q.push(0);
  color[0] = 1;

  while(!q.empty()){
    int qSize = q.size();

    for(int i = 0; i<qSize; i++){
        int s = q.front();
        q.pop();
        int colorOfS = color[s];

        for(int j = 0; j< adj[s].size(); j++){
            if(color[adj[s][j]] == colorOfS)
                return 0;

            if(color[adj[s][j]] == -1){
                color[adj[s][j]] = colorOfS == 1?2:1;
                q.push(adj[s][j]);
            }
        }
    }
  }

  return 1;
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
  std::cout << bipartite(adj);
}
