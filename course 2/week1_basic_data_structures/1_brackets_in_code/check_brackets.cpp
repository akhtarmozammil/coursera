#include <iostream>
#include <stack>
#include <string>

using namespace std;

int main() {
    std::string text;
    getline(std::cin, text);

    std::stack <pair <char,int> > stk;
    int i = 1;
    for (char c : text) {
        if (c == '(' || c == '[' || c == '{') {
            stk.push({c,i});
        }

        if(c == ')' || c == ']' || c == '}'){
            if(stk.empty()){
              break;
            }

            if(c == ')')
              if(stk.top().first == '(')
                 stk.pop();
              else
                break;

            if(c == ']')
              if(stk.top().first == '[')
                 stk.pop();
              else
                break;

            if(c == '}')
              if(stk.top().first == '{')
                 stk.pop();
              else
                break;
        }
        i++;
    }

    if(text.length() >= i)
      cout<<i<<endl;
    else if(stk.size() > 0)
      cout<<stk.top().second<<endl;
    else
      cout<<"Success\n";

    return 0;
}
