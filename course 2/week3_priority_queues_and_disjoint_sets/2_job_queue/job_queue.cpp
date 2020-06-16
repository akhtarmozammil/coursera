#include <iostream>
#include <vector>
#include <algorithm>

using std::vector;
using std::cin;
using std::cout;
using std::swap;

class JobQueue {
 private:
  int n;
  vector<int> jobs_;

  // work as a heap
  vector<int> assigned_workers_;
  vector<long long> start_times_;

  /*void WriteResponse() const {
    for (int i = 0; i < jobs_.size(); ++i) {
      cout << assigned_workers_[i] << " " << start_times_[i] << "\n";
    }
  }*/

  void ReadData() {
    int m;
    cin >> n >> m;
    jobs_.resize(m);
    assigned_workers_.resize(n);
    for(int i =0; i<n; i++)
        assigned_workers_[i] = i;
    start_times_.resize(n,0);
    for(int i = 0; i < m; ++i)
      cin >> jobs_[i];
  }

  void AssignJobs() {

    for(int time : jobs_){
        cout<<assigned_workers_[0]<<" "<<start_times_[0]<<"\n";
        start_times_[0] += time;
        int index = 0;
        while(index < n){
            if(n > index*2 + 2){
                if(start_times_[index*2 + 1] > start_times_[index] && start_times_[index] < start_times_[index*2 + 2])
                    break;
                else if(start_times_[index*2 + 1] == start_times_[index*2 + 2] && start_times_[index] == start_times_[index*2 + 1]){
                    if(assigned_workers_[index*2+1] < assigned_workers_[index*2 + 2] && assigned_workers_[index] > assigned_workers_[index*2 + 1]){
                        swap(assigned_workers_[index],assigned_workers_[index*2 +1]);
                        index = index*2 + 1;
                    }else if(assigned_workers_[index*2+2] < assigned_workers_[index*2 + 1] && assigned_workers_[index] > assigned_workers_[index*2 + 2]){
                        swap(assigned_workers_[index],assigned_workers_[index*2 +2]);
                        index = index*2 + 2;
                    }else{
                        break;
                    }
                }else if(start_times_[index*2 + 1] == start_times_[index*2 + 2]){
                    if(assigned_workers_[index*2+1] < assigned_workers_[index*2 + 2]){
                        swap(start_times_[index],start_times_[index*2 +1]);
                        swap(assigned_workers_[index],assigned_workers_[index*2 +1]);
                        index = index*2 + 1;
                    }else if(assigned_workers_[index*2+1] > assigned_workers_[index*2 + 2]){
                        swap(start_times_[index],start_times_[index*2 +2]);
                        swap(assigned_workers_[index],assigned_workers_[index*2 +2]);
                        index = index*2 + 2;
                    }else{
                        break;
                    }
                }
                else if(start_times_[index*2 + 1] < start_times_[index*2 + 2]){
                    swap(start_times_[index],start_times_[index*2 +1]);
                    swap(assigned_workers_[index],assigned_workers_[index*2 +1]);
                    index = index*2 + 1;
                }
                else if(start_times_[index*2 + 2] < start_times_[index]){
                    swap(start_times_[index],start_times_[index*2 + 2]);
                    swap(assigned_workers_[index],assigned_workers_[index*2 +2]);
                    index = index*2 + 2;
                }
                else if(start_times_[index*2 + 2] == start_times_[index]){
                    if(assigned_workers_[index] > assigned_workers_[index*2 + 2]){
                        swap(assigned_workers_[index],assigned_workers_[index*2 +2]);
                        index = index*2 + 2;
                    }else
                        break;
                }else if(start_times_[index*2 + 1] == start_times_[index]){
                    if(assigned_workers_[index] > assigned_workers_[index*2 + 1]){
                        swap(assigned_workers_[index],assigned_workers_[index*2 +1]);
                        index = index*2 + 1;
                    }else
                        break;
                }
                else
                    break;
            }else if(n > (index*2 +1) && start_times_[index*2 + 1] == start_times_[index]){
                if(assigned_workers_[index] > assigned_workers_[index*2 + 1]){
                    swap(assigned_workers_[index],assigned_workers_[index*2 + 1]);
                    index = index*2 + 1;
                }else
                    break;
            }else if(n > (index*2 +1) && start_times_[index*2 + 1] < start_times_[index]){
                swap(start_times_[index],start_times_[index*2 +1]);
                swap(assigned_workers_[index],assigned_workers_[index*2 +1]);
                index = index*2 + 1;
            }
            else{
                break;
            }
        }
    }
  }

 public:
  void Solve() {
    ReadData();
    AssignJobs();
    //WriteResponse();
  }
};

int main() {
  std::ios_base::sync_with_stdio(false);
  JobQueue job_queue;
  job_queue.Solve();
  return 0;
}
