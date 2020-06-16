#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

struct Query {
    string type, s;
    int ind;
};

int hash_func(const string& s, int bucket_count){
    static const int multiplier = 263;
    static const int prime = 1000000007;
    unsigned long long hash = 0;
    for (int i = static_cast<int> (s.size()) - 1; i >= 0; --i)
        hash = (hash * multiplier + s[i]) % prime;
    return hash % bucket_count;
}

Query readQuery(){
    Query query;
    cin >> query.type;
    if (query.type != "check")
        cin >> query.s;
    else
        cin >> query.ind;
    return query;
}

void processQuery(Query &query, vector<vector<string> > &elems, int bucket_count) {
    if (query.type == "check") {
        // use reverse order, because we append strings to the end
        for (int i = elems[query.ind].size()-1; i >= 0; --i)
            std::cout << elems[query.ind][i] << " ";
        std::cout << "\n";
    } else {
        int index = hash_func(query.s, bucket_count);
        //std::cout<<index<<"\n";
        //std::cout<<elems[index].size()<<"\n";
        if (query.type == "find"){
            if(elems[index].size() > 0){
                bool found = false;
                for (int i = elems[index].size()-1; i >= 0; --i){
                    if(elems[index][i] == query.s){
                        found = true;
                        break;
                    }
                }
                if(found)
                    std::cout<<"yes\n";
                else
                    std::cout<<"no\n";
            }else{
                std::cout<<"no\n";
            }
        }
        else if (query.type == "add") {
            if(elems[index].size() > 0){
                bool found = false;
                for (int i = elems[index].size()-1; i >= 0; --i){
                    if(elems[index][i] == query.s){
                        found = true;
                        break;
                    }
                }
                if(!found)
                    elems[index].push_back(query.s);
            }else{
                elems[index].push_back(query.s);
            }
        } else if (query.type == "del") {
            if(elems[index].size() > 0){
                bool found = false;
                int i =0;
                for(; i<elems[index].size();){
                    if(elems[index][i] == query.s){
                        found = true;
                        break;
                    }
                    i++;
                }

                if(found){
                    for(; i<elems[index].size()-1; i++){
                        elems[index][i] = elems[index][i+1];
                    }
                    elems[index].pop_back();
                }
            }
        }
    }
}

int main() {
    std::ios_base::sync_with_stdio(false);
    int bucket_count;
    cin >> bucket_count;
    vector<vector<string> >elems(bucket_count);
    for(int i =0; i<bucket_count; i++){
        elems.push_back(vector<string>());
    }
    int n;
    cin>>n;
    for(int i =0; i<n; i++){
        Query q = readQuery();
        processQuery(q,elems,bucket_count);
    }
    return 0;
}
