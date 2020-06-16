#include <bits/stdc++.h>
#include <vector>

using std::deque;
using std::cin;
using std::cout;
using std::vector;
using std::max;

void max_sliding_window_naive(vector<int> const & A, int w) {
    for (size_t i = 0; i < A.size() - w + 1; ++i) {
        int window_max = A.at(i);
        for (size_t j = i + 1; j < i + w; ++j)
            window_max = max(window_max, A.at(j));

        cout << window_max << " ";
    }

    return;
}

void max_sliding_window(vector<int> const & A, int w){
  deque <int> q;
  for(int i =0; i<w; i++){
    while(!q.empty() && q.back() < A[i])
      q.pop_back();

    q.push_back(A[i]);
  }

  cout<<q.front()<<" ";

  for(int i = 0; i<A.size()-w; i++){
    if(q.front() == A[i])
      q.pop_front();
    while(!q.empty() && q.back() < A[i+w])
      q.pop_back();
    q.push_back(A[i+w]);

    cout<<q.front()<<" ";
  }
  return;
}

int main() {
    int n = 0;
    cin >> n;

    vector<int> A(n);
    for (size_t i = 0; i < n; ++i)
        cin >> A.at(i);

    int w = 0;
    cin >> w;

    max_sliding_window(A, w);

    return 0;
}
