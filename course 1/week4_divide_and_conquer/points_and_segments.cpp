#include <bits/stdc++.h>
#include <vector>

using namespace std;

bool cmp(pair<int, int> &a, pair<int,int> &b){
    return a.first < b.first;
}

bool cmp2(pair<int,int> &a, pair<int,int> &b){
    return a.second < b.second;
}

pair<int, int> binarySearch(int a, int b, vector<int> points){
    int start = 0;
    int end = points.size()-1;
    int mid;

    int l = -1, r = -1;
    pair<int,int> segment;


    //for upper bond
    while(start <= end){
        mid = (start+ end)/2;

        if(points[mid] == a){
            l = mid;
            break;
        }else if(points[mid] < a){
            start = mid +1;
        }else{
            end = mid -1;
        }
    }

    while(mid-1 > -1 && points[mid] == points[mid-1] && points[mid] >= a){
        mid--;
    }

    if(l == -1){
        if(points[mid] > a){
            if(points[mid] <= b){
                segment.first = mid;
            }else{
                segment = {0,0};
                return segment;
            }
        }else if(points[mid+1] <= b){
            segment.first = mid+1;
        }else{
            segment = {0,0};
            return segment;
        }
    }else{
        segment.first = mid;
    }


    //for lower bond
    start = 0;
    end = points.size()-1;
    mid;

    while(start <= end){
        mid = (start+ end)/2;

        if(points[mid] == b){
            r = mid;
            break;
        }else if(points[mid] < b){
            start = mid +1;
        }else{
            end = mid -1;
        }
    }

    while(mid+1 < points.size() && points[mid] == points[mid+1] && points[mid] <= b){
        mid++;
    }

    if(r == -1){
        if(points[mid] > b){
            segment.second = mid;
        }else{
            segment.second = mid +1;
        }
    }else{
        segment.second = mid + 1;
    }

    return segment;
}

vector<int> fast_count_segments(vector<int> starts, vector<int> ends, vector<int> points) {
  vector<int> cnt(points.size()+1,0);

  int n= starts.size();

  vector< pair<int,int> > sortedPoints(points.size());
  for(int i =0; i<points.size(); i++){
    sortedPoints[i].second = i;
    sortedPoints[i].first = points[i];
  }

  sort(sortedPoints.begin(), sortedPoints.end(),cmp);
  sort(points.begin(), points.end());

  for(int i =0; i<n; i++){

    pair <int, int> p = binarySearch(starts[i],ends[i], points);

    //debug
    //cout<<"Start: "<<starts[i] <<" END: "<<ends[i]<<endl;
    //cout<<"p.first: "<<p.first<<" p.second: "<<p.second<<endl;

    cnt[p.first] ++;
    cnt[p.second] --;

  }

  int count = 0;
  for(int i =0; i<cnt.size()-1; i++){
    count += cnt[i];
    sortedPoints[i].first = count;
  }

  sort(sortedPoints.begin(), sortedPoints.end(), cmp2);

  for(int i=0; i<cnt.size()-1; i++){
    cnt[i] = sortedPoints[i].first;
  }
  //write your code here
  return cnt;
}



vector<int> naive_count_segments(vector<int> starts, vector<int> ends, vector<int> points) {
  vector<int> cnt(points.size());
  for (size_t i = 0; i < points.size(); i++) {
    for (size_t j = 0; j < starts.size(); j++) {
      cnt[i] += starts[j] <= points[i] && points[i] <= ends[j];
    }
  }
  return cnt;
}



int main() {

  //code for stress test
  /*while(true){
    int n, m;
    n = rand()%20 + 2;
    m = rand()%30 + 3;


    vector<int> starts(n), ends(n);
    for (size_t i = 0; i < starts.size(); i++) {
        starts[i] = rand()%100000000;
        ends[i] = starts[i] + rand()%10 + 2;
    }
    vector<int> points(m);
    for (size_t i = 0; i < points.size(); i++) {
        int temp = rand()%100000000 - 30;
        bool found = false;
        for(int j = 0; j<i; j++){
            if(points[j] == temp)
            {
                found = true;
                break;
            }
        }
        if(found){
            i--;
        }else{
            points[i] = temp;
        }
    }

    vector<int> naiveCNT = naive_count_segments(starts,ends,points);
    vector<int> fastCNT = fast_count_segments(starts,ends,points);

    bool match = true;
    for(int i =0; i<naiveCNT.size(); i++){
        if(naiveCNT[i] != fastCNT[i]){
            match = false;
            for(int j =0; j<starts.size(); j++){
                cout<<starts[j]<<" "<<ends[j]<<endl;
            }

            for(int j =0; j<points.size(); j++){
                cout<<points[j]<<" ";
            }

            for(int j =0; j<naiveCNT.size(); j++){
                cout<<"correct: "<<naiveCNT[j]<<"False: "<<fastCNT[j]<<endl;
            }
            cout<<endl<<endl<<endl;
        }
    }

    if(match == false)
        break;
    else{
        cout<<"MATCH\n";
        for(int j =0; j<starts.size(); j++){
                cout<<starts[j]<<" "<<ends[j]<<endl;
            }

            for(int j =0; j<points.size(); j++){
                cout<<points[j]<<" ";
            }

            for(int j =0; j<naiveCNT.size(); j++){
                cout<<"correct: "<<naiveCNT[j]<<"False: "<<fastCNT[j]<<endl;
            }
            cout<<endl<<endl<<endl;
    }
  }*/

  int n, m;
  cin >> n >> m;
  vector<int> starts(n), ends(n);
  for (size_t i = 0; i < starts.size(); i++) {
    cin >> starts[i] >> ends[i];
  }
  vector<int> points(m);
  for (size_t i = 0; i < points.size(); i++) {
    cin >> points[i];
  }


  //use fast_count_segments
  vector<int> cnt = fast_count_segments(starts, ends, points);

  for (size_t i = 0; i < cnt.size()-1; i++) {
    cout << cnt[i] << ' ';
  }
}
