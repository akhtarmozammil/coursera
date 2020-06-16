#include <iostream>
#include <vector>
#include <algorithm>

using std::vector;
using std::cin;
using std::cout;
using std::swap;
using std::pair;
using std::make_pair;

class HeapBuilder {
 private:
  vector<int> data_;
  vector< pair<int, int> > swaps_;

  void ReadData() {
    int n;
    cin >> n;
    data_.resize(n);
    for(int i = 0; i < n; ++i)
      cin >> data_[i];
  }

  void GenerateSwaps(int index) {
    //if leaf node
    if(data_.size() <= index*2 +1 && data_.size() <= index*2 + 2)
        return;

    if(data_.size() > index*2 +1)
        GenerateSwaps(index*2 +1);
    if(data_.size() > index*2 + 2)
        GenerateSwaps(index*2 + 2);

    //check heap
    if(data_.size() > index*2 + 2){
        if(data_[index*2 + 1] < data_[index*2 + 2]){
            if(data_[index*2 + 1] < data_[index]){
                swaps_.push_back({index,index*2 + 1});
                swap(data_[index],data_[index*2 +1]);
                GenerateSwaps(index*2 + 1);
            }
            return;
        }else if(data_[index*2 + 2] < data_[index]){
            swaps_.push_back({index,index*2 + 2});
            swap(data_[index],data_[index*2 + 2]);
            GenerateSwaps(index*2 + 2);
        }
        return;
    }else if(data_[index*2 + 1] < data_[index]){
        swaps_.push_back({index,index*2 + 1});
        swap(data_[index],data_[index*2 +1]);
        GenerateSwaps(index*2 + 1);
    }
    return;
  }

  void WriteResponse() const {
    cout << swaps_.size() << "\n";
    for (int i = 0; i < swaps_.size(); ++i) {
      cout << swaps_[i].first << " " << swaps_[i].second << "\n";
    }
  }

 public:
  void Solve() {
    ReadData();
    GenerateSwaps(0);
    WriteResponse();
  }
};

int main() {
  std::ios_base::sync_with_stdio(false);
  HeapBuilder heap_builder;
  heap_builder.Solve();
  return 0;
}
