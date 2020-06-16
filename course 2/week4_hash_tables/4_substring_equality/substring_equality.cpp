#include <bits/stdc++.h>

using namespace std;

void hashVal(vector<int> &hashLeft, string s){
    unsigned long long hash = 0;
    long long prime = 1000000007;
    int multiplyer = 263;
    hashLeft[0] = 0;
    for(int i = 1; i<hashLeft.size(); i++){
        hash = ((hash*multiplyer) + s[i]) % prime;
        hashLeft[i] = hash;
    }
}

bool ask(int a, int b, int l, vector<int> &hashLeft,string s){
    int hashA = 0;
    int hashB = 0;
    if(a == 0){
        hashA = hashLeft[a+l];
    }else{
        long long x = 263;
        for(int i =1; i<l; i++){
            x = (x*x)%1000000007;
        }
        hashA = hashLeft[a+l] - x*hashLeft[a];
    }

    if(b == 0){
        hashB = hashLeft[b+l];
    }else{
        long long x = 263;
        for(int i =1; i<l; i++){
            x = (x*x)%1000000007;
        }
        hashB = hashLeft[b+l] - x*hashLeft[b];
    }
    cout<<hashA<<" "<<hashB<<endl;
    if(hashA%1000000007 == hashB%1000000007){
        while(l--){
            if(s[a] != s[b])
                return false;
            a++;
            b++;
        }
        return true;
    }

    return false;
}

int main() {
	ios_base::sync_with_stdio(0), cin.tie(0);

	string s;
	int q;
	cin >> s >> q;
	vector<int> hashLeft(s.length()+1);
	hashVal(hashLeft,s);
	for (int i = 0; i < q; i++) {
		int a, b, l;
		cin >> a >> b >> l;
		cout << (ask(a, b, l,hashLeft,s) ? "Yes\n" : "No\n");
	}
}
