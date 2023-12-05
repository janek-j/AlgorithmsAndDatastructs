#include <iostream>
#include <stack>
#include <string>
#include <cmath>
#include <sstream>

bool isOperator(const std::string &token) {
    return token == "+" || token == "-" || token == "*" || token == "/";
}

double applyOperator(const std::string &op, double operand1, double operand2) {
    if (op == "+") return operand1 + operand2;
    if (op == "-") return operand1 - operand2;
    if (op == "*") return operand1 * operand2;
    if (op == "/") return operand1 / operand2;
    throw std::invalid_argument("Invalid operator");
}

double evaluateRPN(const std::string &expr) {
    std::stack<double> operandStack;
    std::istringstream iss(expr);
    std::string token;
    while(iss >> token) {
        if(!isOperator(token)) {
            double operand;
            std::istringstream(token)>>operand;
            operandStack.push(operand);
        }
        else {
            double operand2 = operandStack.top();
            operandStack.pop();
            double operand1 = operandStack.top();
            operandStack.pop();
            double result = applyOperator(token, operand1, operand2);
            operandStack.push(result);
        }

    }
    return operandStack.top();
}

int main() {
    std::string rpnExpression = "3 4 *";
    double result = evaluateRPN(rpnExpression);
    std::cout << "Result: " << result << std::endl;
    return 0;
}