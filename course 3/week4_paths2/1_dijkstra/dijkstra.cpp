#include <iostream>
#include <vector>
#include <queue>

using namespace std;

struct comp{
    bool operator()(const pair<int,int> &a, const pair<int,int> &b){
        return a.first > b.first;
    }
};

int distance(vector<vector<int> > &adj, vector<vector<int> > &cost, int s, int t) {
  if(adj[s].size() == 0)
    return -1;

  vector<int> dist(adj.size(),1000000001);
  dist[s] = 0;

  priority_queue<pair<int,int>, vector<pair<int,int> > , comp > q;
  q.push(make_pair(0,s));

  while(!q.empty()){
    int d = q.top().first;
    int u = q.top().second;
    q.pop();

    for(int i =0; i<adj[u].size(); i++){
        if(dist[ adj[u][i] ] > (d + cost[u][i])){
            dist[ adj[u][i] ] = d + cost[u][i];
            q.push(make_pair(dist[ adj[u][i] ],adj[u][i]));
        }
    }
  }

  if(dist[t] == 1000000001)
    return -1;
  return dist[t];
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
  int s, t;
  std::cin >> s >> t;
  s--, t--;
  std::cout << distance(adj, cost, s, t);
}
