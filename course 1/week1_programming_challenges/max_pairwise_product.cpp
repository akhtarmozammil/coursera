#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

long long MaxPairwiseProduct(vector<int>& numbers) {

    int index_1 = 0;
    int index_2 = -1;

    for(int i =1; i<numbers.size(); i++){
        if(numbers[index_1] < numbers[i])
            index_1 = i;
    }

    for(int i = 0; i<numbers.size(); i++){
        if(i == index_1)
            continue;
        if(index_2 == -1)
            index_2 = i;
        if(numbers[index_2] < numbers[i])
            index_2 = i;
    }

    long long max_product = (long long)(numbers[index_1]) * numbers[index_2];

    return max_product;
}

int main() {
    int n;
    cin >> n;
    vector<int> numbers(n);
    for (int i = 0; i < n; ++i) {
        cin >> numbers[i];
    }

    cout << MaxPairwiseProduct(numbers)<< "\n";
    return 0;
}
