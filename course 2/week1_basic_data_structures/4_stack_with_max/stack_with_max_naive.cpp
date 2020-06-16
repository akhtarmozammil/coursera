#include <iostream>
#include <vector>
#include <string>
#include <cassert>
#include <algorithm>

using std::cin;
using std::string;
using std::vector;
using std::cout;
using std::max_element;

class StackWithMax {
    vector<int> stack;
    int maximum = 0;

  public:

    void Push(int value) {
        if(stack.size() == 0){
          stack.push_back(value);
          maximum = value;
        }else{
          if(value > maximum){
            stack.push_back((value*2) - maximum);
            maximum = value;
          }else{
            stack.push_back(value);
          }
        }
    }

    void Pop() {
        assert(stack.size());
        if(stack.back() > maximum){
          maximum = maximum*2 - stack.back();
        }

        stack.pop_back();
    }

    int Max() const {
        assert(stack.size());
        return maximum;
    }
};

int main() {
    int num_queries = 0;
    cin >> num_queries;

    string query;
    string value;

    StackWithMax stack;

    for (int i = 0; i < num_queries; ++i) {
        cin >> query;
        if (query == "push") {
            cin >> value;
            stack.Push(std::stoi(value));
        }
        else if (query == "pop") {
            stack.Pop();
        }
        else if (query == "max") {
            cout << stack.Max() << "\n";
        }
        else {
            assert(0);
        }
    }
    return 0;
}
