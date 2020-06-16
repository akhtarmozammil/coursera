#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main() {

    string s, t;
    cin>>s>>t;

    //prefix of s
    int pre[s.length()];
    pre[0] = 0;
    int i = 1;
    int j = 0;

    while(i < s.length()){
        if(s[i] == s[j]){
            j++;
            pre[i] = j;
            i++;

        }else if(j > 0){
            j = pre[j-1];
        }else{
            pre[i] = 0;
            i++;
        }
    }

    i =0,j =0;
    while(i<t.length()){
        if(s[j] == t[i]){
            if(j == s.length()-1){
                cout<<i-j<<" ";
                j = pre[j];
                i++;
            }else{
                i++;
                j++;
            }
        }else if(j > 0){
            j = pre[j-1];
        }else
            i++;
    }
    cout<<endl;

    return 0;
}
