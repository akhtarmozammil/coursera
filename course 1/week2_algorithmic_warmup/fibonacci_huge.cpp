#include <iostream>

using namespace std;

int fibo[1000000];

int pattern_match(int m){

    int count = 2;
    fibo[0] = 0;
    fibo[1] = 1;

    while(true){
        fibo[count] = (fibo[count-1] + fibo[count-2])%m;
        count++;
        if(count%2 == 0){
            int start = 0;
            int mid = count/2;

            bool match = true;
            while(mid < count){
                if(fibo[start] != fibo[mid]){
                    match = false;
                    break;
                }

                start++; mid++;
            }

            if(match){
                return count/2;
            }
        }
    }
}

long long get_fibonacci_huge_naive(long long n, long long m) {
    if (n <= 1)
        return n;

    long long previous = 0;
    long long current  = 1;

    for (long long i = 0; i < n - 1; ++i) {
        long long tmp_previous = previous;
        previous = current;
        current = tmp_previous + current;
    }

    return current % m;
}

int main() {
    long long n, m;
    cin >> n >> m;
    
    //cout << get_fibonacci_huge_naive(n, m) << '\n';
    n %= pattern_match(m);
    cout<<fibo[n]<<endl;
}
