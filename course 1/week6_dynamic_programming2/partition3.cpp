#include <bits/stdc++.h>
#include <vector>

using namespace std;

bool partition3(int index, const vector<int> &A,vector<bool> &is_used, int sum, int current_sum, int remaining_bucket){
  if(remaining_bucket == 1)
    return true;
  if(current_sum == sum)
    return partition3(0,A,is_used,sum,0,remaining_bucket-1);

  for(int i =0; i<A.size(); i++){
    if(!is_used[i]){
      is_used[i] = true;
      if(partition3(i+1,A,is_used,sum,current_sum+A[i],remaining_bucket))
        return true;
      is_used[i] = false;
    }
  }

  return false;
}

int main() {

  int n;
  std::cin >> n;
  vector<int> A(n);
  int sum = 0;
  for (size_t i = 0; i < A.size(); ++i) {
    cin >> A[i];
    sum += A[i];
  }
  if(sum%3 == 0){
    vector<bool> is_used(A.size(), false);
    sort(A.begin(),A.end(),greater<int>());
    std::cout << partition3(0,A,is_used,sum/3,0,3) << '\n';
  }
  else
    std::cout << 0 <<'\n';
}
