#include <bits/stdc++.h>
#include <vector>

using namespace std;

bool rec(vector<int> &arr, vector<int> &subsetSum, vector<bool> taken,
                   int subset, int K, int N, int curIdx, int limitIdx)
{
    if (subsetSum[curIdx] == subset)
    {
        if (curIdx == K - 2)
            return true;
        return rec(arr, subsetSum, taken, subset,
                                            K, N, curIdx + 1, N - 1);
    }

    for (int i = limitIdx; i >= 0; i--)
    {
        if (taken[i])
            continue;
        int tmp = subsetSum[curIdx] + arr[i];

        if (tmp <= subset)
        {
            taken[i] = true;
            subsetSum[curIdx] += arr[i];
            bool nxt = rec(arr, subsetSum, taken,
                                            subset, K, N, curIdx, i - 1);
            taken[i] = false;
            subsetSum[curIdx] -= arr[i];
            if (nxt)
                return true;
        }
    }
    return false;
}

bool part3(vector<int> &arr, int N)
{
    if (N < 3)
        return false;

    int sum = 0;
    for (int i = 0; i < N; i++)
        sum += arr[i];
    if (sum % 3 != 0)
        return false;

    int subset = sum / 3;
    vector<int> subsetSum(3);
    vector<bool> taken(N);

    for (int i = 0; i < 3; i++)
        subsetSum[i] = 0;

    for (int i = 0; i < N; i++)
        taken[i] = false;

    subsetSum[0] = arr[N - 1];
    taken[N - 1] = true;

    return rec(arr, subsetSum, taken, subset, 3, N, 0, N - 1);
}

int main() {

  int n;
  std::cin >> n;
  vector<int> A(n);
  for (size_t i = 0; i < A.size(); ++i) {
    cin >> A[i];
  }
  cout<< part3(A,n)<<'\n';
}
