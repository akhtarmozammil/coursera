#include <iostream>
#include<stdlib.h>

using namespace std;

int get_fibonacci_last_digit_fast(int n){

    if(n <= 1)
        return n;

    int lastDigitNow = 1;
    int lastDigitPre = 0;

    for(int i = 2; i<=n; i++){
        int temp = lastDigitNow;
        lastDigitNow += lastDigitPre;
        if(lastDigitNow > 9)
            lastDigitNow %= 10;
        
        lastDigitPre = temp;
    }

    return lastDigitNow;
}

// int get_fibonacci_last_digit_naive(int n) {
//     if (n <= 1)
//         return n;

//     int previous = 0;
//     int current  = 1;

//     for (int i = 0; i < n - 1; ++i) {
//         int tmp_previous = previous;
//         previous = current;
//         current = tmp_previous + current;
//     }

//     return current % 10;
// }

int main() {

    //stree test
    // while(true){

    //     int n = rand()%100 + 2;
    //     if(get_fibonacci_last_digit_fast(n) != get_fibonacci_last_digit_naive(n)){
    //         cout<<"N "<<n<<endl;
    //         break;
    //     }else{
    //         cout<<n<<" OK"<<endl;
    //     }
    // }

    int n;
    cin >> n;
    int c = get_fibonacci_last_digit_fast(n);
    cout << c << '\n';
    }
