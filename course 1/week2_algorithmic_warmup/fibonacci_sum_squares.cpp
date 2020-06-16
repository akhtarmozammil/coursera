#include <iostream>

int fibo_sq[30];

void fibo_assign_lst_digit_sq(){

    fibo_sq[0] = 0; fibo_sq[1] = 1;

    for(int i = 2; i<30; i++){
        fibo_sq[i] = (fibo_sq[i-1] + fibo_sq[i-2])%10;
    }

    for(int i= 2; i<30; i++){
        fibo_sq[i] = (fibo_sq[i]*fibo_sq[i]);
        if(fibo_sq[i > 9])
            fibo_sq[i] %= 10;
    }

    for(int i = 2; i<30; i++){
        fibo_sq[i] += fibo_sq[i-1];
        if(fibo_sq[i] > 9)
            fibo_sq[i] %= 10;
    }

}

// int repeatition_found(){

//     int start1 = 0;
//     int mid = 1;
//     int start2 = mid;

//     while(mid < 1000){
//         bool match_found = true;

//         while(start1 != mid){
//             if (fibo_sq[start2] != fibo_sq[start1]){
//                 match_found = false;
//                 break;
//             }
//             start1++; start2++;
//         }

//         if(match_found){
//             return mid;
//         }
//         start1 = 0;
//         mid++;
//         start2 = mid;

//     }
//     return -1;
// }



// int fibonacci_sum_squares_naive(long long n) {
//     if (n <= 1)
//         return n;

//     long long previous = 0;
//     long long current  = 1;
//     long long sum      = 1;

//     for (long long i = 0; i < n - 1; ++i) {
//         long long tmp_previous = previous;
//         previous = current;
//         current = tmp_previous + current;
//         sum += current * current;
//     }

//     return sum % 10;
// }

int main() {
    long long n = 0;
    std::cin >> n;
    fibo_assign_lst_digit_sq();
    std::cout<<fibo_sq[n%30]<<'\n';
}
