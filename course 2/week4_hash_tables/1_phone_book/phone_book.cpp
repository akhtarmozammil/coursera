#include <bits/stdc++.h>
#include <vector>
#include <string>

using std::string;
using std::vector;
using std::cin;

struct Query {
    string type, name;
    int number;
};

vector<Query> read_queries() {
    int n;
    cin >> n;
    vector<Query> queries(n);
    for (int i = 0; i < n; ++i) {
        cin >> queries[i].type;
        if (queries[i].type == "add")
            cin >> queries[i].number >> queries[i].name;
        else
            cin >> queries[i].number;
    }
    return queries;
}

void write_responses(const vector<string>& result) {
    for (size_t i = 0; i < result.size(); ++i)
        std::cout << result[i] << "\n";
}

vector<string> process_queries(const vector<Query>& queries) {
    vector<string> result;
    // Keep list of all existing (i.e. not deleted yet) contacts.
    std::unordered_map <long long, string> contacts;
    for (size_t i = 0; i < queries.size(); ++i)
        if (queries[i].type == "add") {
            // case1: if we already have contact with such number,
            // case2: we should rewrite contact's name
            //in both the cases, add contact and update the name
            contacts[queries[i].number] = queries[i].name;

        } else if (queries[i].type == "del") {
            if(contacts.find(queries[i].number) != contacts.end())
                contacts.erase(queries[i].number);
        } else {
            string response = "not found";
            if(contacts.find(queries[i].number) != contacts.end())
                response = contacts[queries[i].number];
            result.push_back(response);
        }
    return result;
}

int main() {
    write_responses(process_queries(read_queries()));
    return 0;
}
