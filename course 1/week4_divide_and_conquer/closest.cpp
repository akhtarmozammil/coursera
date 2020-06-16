#include <algorithm>
#include <iostream>
#include <sstream>
#include <iomanip>
#include <vector>
#include <string>
#include <cmath>

using namespace std;

bool sortX(pair<int,int> &a , pair<int,int> &b){
    return a.first < b.first;
}

bool sortXY(pair<int,int> &a , pair<int,int> &b){
    if(a.first <= b.first)
        return a.second < b.second;

    return a.first < b.first;
}

bool sortY(pair<int,int> &a , pair<int,int> &b){
    return a.second < b.second;
}

bool sortYX(pair<int,int> &a , pair<int,int> &b){
    if(a.second <= b.second)
        return a.first < b.first;

    return a.second < b.second;
}

double minimal_distance(vector< pair<int,int> > &m) {
  //write your code here
  sort(m.begin(),m.end(),sortX);
  sort(m.begin(),m.end(),sortXY);

  double minDistance = 1900000000;
  //cout<<minDistance;
  for(int i =0; i<m.size()-1; i++){
    int x1 = m[i].first;
    int y1 = m[i].second;
    int x2 = m[i+1].first;
    int y2 = m[i+1].second;

    minDistance = min(minDistance,  sqrt(pow(fabs(x2-x1),2) + pow(fabs(y2-y1),2)) );
  }

  sort(m.begin(),m.end(),sortY);
  sort(m.begin(),m.end(),sortYX);

  for(int i =0; i<m.size()-1; i++){
    int x1 = m[i].first;
    int y1 = m[i].second;
    int x2 = m[i+1].first;
    int y2 = m[i+1].second;

    minDistance = min(minDistance,  sqrt(pow(fabs(x2-x1),2) + pow(fabs(y2-y1),2)) );
  }

  /*for(int i =0; i<m.size(); i++){
    std::cout<<m[i].first<<" "<<m[i].second<<std::endl;
  }*/

  return minDistance;
}

double naive(vector< pair<int,int> > &m){
    double minDistance = 1900000000;

    for(int i =0; i<m.size()-1; i++){
        for(int j = i+1; j<m.size(); j++){
            int x1 = m[i].first;
            int y1 = m[i].second;
            int x2 = m[j].first;
            int y2 = m[j].second;

            minDistance = min(minDistance,  sqrt(pow(fabs(x2-x1),2) + pow(fabs(y2-y1),2)) );
        }
    }

    return minDistance;
}

int main() {

    //stress test
    while(true){
        int n = rand()% 5 + 2;
        vector< pair<int,int> > m(n);

        for(int i = 0; i<n; i++){
            m[i].first = rand()%10 -5;
            m[i].second = rand()%10 + 5;
        }
        double slow = naive(m);
        double fast = minimal_distance(m);
        if(slow == fast){
            cout<<"PASS\n";
        }else{
            for(int i =0; i<m.size(); i++){
                std::cout<<m[i].first<<" "<<m[i].second<<std::endl;
            }
            cout<<"Corr:  "<<slow<<"   wrong:  "<<fast<<endl;
            break;
        }
    }



  size_t n;
  std::cin >> n;
  vector< pair<int,int> > m(n);
  for (size_t i = 0; i < n; i++) {
    std::cin >> m[i].first >> m[i].second;
  }
  std::cout << std::fixed;
  std::cout << std::setprecision(9) << minimal_distance(m) << "\n";
}
