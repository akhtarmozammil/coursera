#include <iostream>
using namespace std;

int fibo_sum[60],fib[60];

// int repeatition_found(){

//     int start1 = 0;
//     int mid = 1;
//     int start2 = mid;

//     while(mid < 5000){
//         bool match_found = true;

//         while(start1 != mid){
//             if (fibo_sum[start2] != fibo_sum[start1]){
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


void fibo_sumnacci_sum_last_digit() {
    
    fib[0] = fibo_sum[0] = 0;
    fib[1] = fibo_sum[1] = 1;

    int sum = 1;

    for(int i = 2; i<60; i++){
        fib[i] = (fib[i-1] + fib[i-2])%10;
        sum = (sum+fib[i])%10;
        fibo_sum[i] = sum;
    }
    return;
}

int main() {
    long long n = 0;
    cin >> n;
    fibo_sumnacci_sum_last_digit();

    std::cout << fibo_sum[n%60]<<endl;
}
