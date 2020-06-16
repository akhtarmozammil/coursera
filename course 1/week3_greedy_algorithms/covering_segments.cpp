#include <algorithm>
#include <iostream>
#include <climits>
#include <vector>

using std::vector;

struct Segment {
  int start, end;
};

bool segSort(Segment &a, Segment &b){
  return a.start < b.start;
}

vector<int> optimal_points(vector<Segment> &segments) {
  vector<int> points;
  //write your code here
  sort(segments.begin(), segments.end(), segSort);

  for(int i =0; i<segments.size(); i++){
    Segment point_of_cut = segments[i];
    i++;
    while(i<segments.size() && point_of_cut.start <= segments[i].start && point_of_cut.end >=segments[i].start){
      if(segments[i].start > point_of_cut.start){
        point_of_cut.start = segments[i].start;
      }
      if(segments[i].end < point_of_cut.end)
        point_of_cut.end = segments[i].end;
      i++;
    }

    i--;
    points.push_back(point_of_cut.end);
    
  }
  
  return points;
}

int main() {
  int n;
  std::cin >> n;
  vector<Segment> segments(n);
  for (size_t i = 0; i < segments.size(); ++i) {
    std::cin >> segments[i].start >> segments[i].end;
  }
  vector<int> points = optimal_points(segments);
  std::cout << points.size() << "\n";
  for (size_t i = 0; i < points.size(); ++i) {
    std::cout << points[i] << " ";
  }
}
