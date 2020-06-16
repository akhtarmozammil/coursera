#include <algorithm>
#include <iostream>
#include <iomanip>
#include <vector>
#include <cmath>
#include <bits/stdc++.h>

using namespace std;

struct node{

    int source;
    int destination;
    double distance;
};

struct comp{
    bool operator()(const struct node &a, const struct node &b){
        return a.distance > b.distance;
    }
};

double calDistance(int x1, int y1, int x2, int y2){
    return sqrt( (x2-x1)*(x2-x1) + (y2-y1)*(y2-y1) );
}

int findParent(vector<int> &parent, int child){

    int p = child;
    while(parent[p] != p){
        p = parent[p];
    }
    parent[child] = p;
    return p;
}

double minimum_distance(vector<int> x, vector<int> y) {
  double result = 0.;
  priority_queue<struct node, vector<struct node>, comp> q;

  //fill queue
    for(int i =0;i<x.size(); i++){
        for(int j =i+1; j<x.size(); j++){
            node n = {i,j,calDistance(x[i],y[i],x[j],y[j])};
            q.push(n);
            //cout<<"S: "<<n.source<<"  D: "<<n.destination<<"  DIS: "<<n.distance<<endl;
        }
    }


  //make disjoint set
    vector<int> parent(x.size());
    for(int i =0; i<x.size(); i++)
        parent[i] = i;

  //min span tree using kruskal
    while(!q.empty()){
        node n = q.top();
        q.pop();

        //cout<<"S: "<<n.source<<"  D: "<<n.destination<<"  DIS: "<<n.distance<<endl;

        int parentOfA = findParent(parent,n.source);
        int parentOfB = findParent(parent,n.destination);

        //cout<<"PA: "<<parentOfA<<"  PB: "<<parentOfB<<endl;

        if(parentOfA != parentOfB){
            result += n.distance;
            parent[parentOfB] = parentOfA;
        }
    }

  return result;
}

int main() {
  size_t n;
  std::cin >> n;
  vector<int> x(n), y(n);
  for (size_t i = 0; i < n; i++) {
    std::cin >> x[i] >> y[i];
  }
  std::cout << std::setprecision(10) << minimum_distance(x, y) << std::endl;
}
