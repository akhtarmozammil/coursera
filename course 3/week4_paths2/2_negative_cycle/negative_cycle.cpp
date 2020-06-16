#include <iostream>
#include <vector>

using std::vector;

int negative_cycle(vector<vector<int> > &adj, vector<vector<int> > &cost) {

    vector<int> dist(adj.size(), 1000000001);
    dist[0] = 0;
    bool anyChange = false;

    for(int i =1; i<adj.size(); i++){
        for(int j = 0; j<adj.size(); j++){
            for(int k = 0; k<adj[j].size(); k++){
                if(dist[ adj[j][k] ] > dist[j] + cost[j][k]){
                    anyChange = true;
                    dist[adj[j][k]] = dist[j] + cost[j][k];
                }
            }
        }
        if(anyChange)
            anyChange = false;
        else
            return 0;
    }

    for(int j = 0; j<adj.size(); j++){
        for(int k = 0; k<adj[j].size(); k++){
            if(dist[ adj[j][k] ] > dist[j] + cost[j][k]){
                anyChange = true;
                dist[adj[j][k]] = dist[j] + cost[j][k];
            }
        }
    }

    if(anyChange)
        return 1;

    return 0;
}

int main() {
  int n, m;
  std::cin >> n >> m;
  vector<vector<int> > adj(n, vector<int>());
  vector<vector<int> > cost(n, vector<int>());
  for (int i = 0; i < m; i++) {
    int x, y, w;
    std::cin >> x >> y >> w;
    adj[x - 1].push_back(y - 1);
    cost[x - 1].push_back(w);
  }
  std::cout << negative_cycle(adj, cost);
}
