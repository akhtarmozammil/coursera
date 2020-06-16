#include <bits/stdc++.h>
#include <vector>

using namespace std;

long long mergeSort(vector<int> &a, vector<int> &b, int left ,int mid, int right){

    long long inversion = 0;
    int l = left;
    int r = mid+1;
    int i = left;

    while((l <= mid) && (r <= right)){
        if(a[l] <= a[r]){
            b[i] = a[l];
            l++;
            i++;
        }else{
            b[i] = a[r];
            i++;
            r++;
            inversion += (mid - l + 1);
        }
    }

    while(l<=mid){
        b[i] = a[l];
        l++;
        i++;
    }

    while(r <= right){
        b[i] = a[r];
        r++;
        i++;
    }


    for(int j = left; j<= right; j++){
        a[j] = b[j];
    }

    return inversion;
}

long long  get_number_of_inversions(vector<int> &a, vector<int> & b, int left , int right){
    long long  inversion = 0;

    if(left + 1 > right)
        return inversion;

    int mid = (left + right)/2;

    inversion += get_number_of_inversions(a,b, left, mid);
    inversion += get_number_of_inversions(a,b,mid+1,right);

    inversion += mergeSort(a,b,left,mid,right);

    return inversion;
}

int main() {
  int n;
  cin >> n;
  vector<int> a(n);
  for (size_t i = 0; i < a.size(); i++) {
    std::cin >> a[i];
  }
  vector<int> b(a.size());
  std::cout << get_number_of_inversions(a, b, 0, a.size()-1) << '\n';
}
