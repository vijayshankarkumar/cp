#include <iostream>
#include <string>
#include <stack>

std::string parseTernaryII(std::string& ternary, int idx) {
    if (ternary[idx] >= '0' && ternary[idx] <= '9') {
        return std::string(1, ternary[idx]);
    }
    else if (ternary[idx] == 'T') {
        return parseTernaryII(ternary, idx + 2);
    }
    else {
        return parseTernaryII(ternary, idx + 4);
    }
}

std::string parseTernary(std::string expression) {
    std::stack<char> stk;
    for(int i= expression.length()-1; i>= 0; i--){
        char c= expression[i]; //current condition
        if(!stk.empty() && stk.top() == '?'){
            stk.pop(); //pop out the '?'
            char first= stk.top();
            stk.pop(); //pop out first digit
            stk.pop(); //pop out ':'
            char second= stk.top();
            stk.top()= (c== 'T')? first: second;
        }
        else
            stk.push(c);
    }
    
    return std::string(1, stk.top());
}

std::string parseTernary(std::string ternary) {
    return parseTernaryII(ternary, 0);
}

int main() {
    std::cout << parseTernary("T?T?1:5:3") << std::endl;
    return 0;
}
