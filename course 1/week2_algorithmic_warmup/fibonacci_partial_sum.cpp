#include <iostream>
#include <vector>
using std::vector;

int fibo[120];

void fibonac() {
    
    fibo[0] = 0;
    fibo[1] = 1;

    for(int i = 2; i<120; i++){
        fibo[i] = (fibo[i-1] + fibo[i-2])%10;
        
    }
    return;
}


long long get_fibonacci_partial_sum_naive(long long from, long long to) {
    long long sum = 0;

    long long current = 0;
    long long next  = 1;

    for (long long i = 0; i <= to; ++i) {
        if (i >= from) {
            sum += current;
        }

        long long new_current = next;
        next = next + current;
        current = new_current;
    }

    return sum % 10;
}

int main() {
    long long from, to;
    std::cin >> from >> to;
    //std::cout << get_fibonacci_partial_sum_naive(from, to) << '\n';
    fibonac();
    
    int sum = 0;
    from %= 60;
    to %= 60;

    if(from > to){
        to += 60;
    }

    for(int i = from; i<=to; i++){
        sum += fibo[i];
    }

    std::cout<<sum%10<<'\n';
}
