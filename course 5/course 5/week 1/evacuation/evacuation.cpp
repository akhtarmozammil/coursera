#include <bits/stdc++.h>
using namespace std;

void bfs(const vector<vector<int> > &adjMatrix, vector<int> &parent, int t){

    vector<bool>visited(t+1,false);
    int minFlow = 0;
    queue<int>q;
    q.push(0);
    parent[0] = -1;
    parent[t] = -1;
    while(!q.empty()){
        int u = q.front();
        q.pop();
        visited[0] = true;
        for(int v = 0; v <=t;  v++){
            if(adjMatrix[u][v] > 0 && !visited[v]){
                visited[v] = true;
                parent[v] = u;
                q.push(v);
                if(v == t)
                    return;
            }
        }
    }
}

int main()
{
    int n,m;
    cin>>n>>m;

    vector<vector<int> > adjMatrix(n,vector<int>(n));

    for(int i= 0; i<n; i++){
        for(int j = 0; j<n; j++){
            adjMatrix[i][j] = 0;
        }
    }

    for(int i =0; i<m; i++){
        int u,v,c;
        cin>>u>>v>>c;
        adjMatrix[u-1][v-1] += c;
    }

    int maxFlow = 0;
    while(true){
        vector<int> parent(n);
        bfs(adjMatrix,parent,n-1);
        if(parent[n-1] == -1)
            break;
        else{
            int minflow = 2000000000;
            int node = n-1;
            while(parent[node] != -1){
                minflow = min(minflow,adjMatrix[parent[node]][node]);
                node = parent[node];
            }

            node = n-1;
            while(parent[node] != -1){

                adjMatrix[parent[node]][node] -= minflow;
                adjMatrix[node][parent[node]] += minflow;

                node = parent[node];
            }

            maxFlow += minflow;
        }
    }

    cout<<maxFlow<<endl;
    return 0;
}
