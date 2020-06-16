#include <algorithm>
#include <bits/stdc++.h>
#include <vector>

using namespace std;

vector<vector<int> > transpose(vector<vector<int> > &adj){
    vector<vector<int> > t(adj.size(), vector <int>());

    for(int i =0; i<adj.size(); i++){
        for(int j = 0; j<adj[i].size(); j++){
            t[adj[i][j]].push_back(i);
        }
    }
    return t;
}

void doStack(vector<vector<int> > &adj, vector<bool> &vis, int x, stack <int> &s){
    vis[x] = true;

    for(int i =0; i < adj[x].size(); i++){
        if(!vis[adj[x][i]])
            doStack(adj, vis, adj[x][i],s);
    }

    s.push(x);
}

void strongly_conncted(vector<vector<int> > &t, vector<bool> &vis, int node){
    vis[node] = true;

    for(int i =0; i<t[node].size(); i++){
        if(!vis[ t[node][i] ])
            strongly_conncted(t,vis,t[node][i]);
    }
}

int number_of_strongly_connected_components(vector<vector<int> > adj) {
  int result = 0;

  stack <int> s;
  vector <bool> vis(adj.size(),false);

  for(int i = 0; i<adj.size(); i++){
    if(!vis[i])
        doStack(adj,vis,i,s);
  }

  vector<vector<int> > t = transpose(adj);

  for(int i = 0; i<vis.size(); i++)
    vis[i] = false;

  while(!s.empty()){
    int node = s.top();
    s.pop();
    if(!vis[node]){
        result++;
        strongly_conncted(t,vis,node);
    }
  }

  return result;
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
  std::cout << number_of_strongly_connected_components(adj);
}
