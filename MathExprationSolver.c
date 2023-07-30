/*Before going to this culculator you will be required the knowledge of what is 
1.Postfix    2.infix    3.stack     4.stackoperations     5.Shunting Yard Algo

6.Functions


Now remeber this calculator can handle exprations like 1+2-14+15*10/40 etc etc bla bla

also it will only consider oparators(like +-"*"/) and operands(1,2,3,) as its parts other thingks will be garbage for it

*/

#include <iostream>                                                                   
#include <stack>
#include <cmath>
using namespace std;

bool isOperator(char c) {
    return c == '+' || c == '-' || c == '*' || c == '/' || c == '^';
}

int getPrecedence(char c) {
    if (c == '^') return 3;
    if (c == '*' || c == '/') return 2;
    if (c == '+' || c == '-') return 1;
    return 0;
}

double applyOperator(char op, double a, double b) {
    switch (op) {
        case '+': return a + b;
        case '-': return a - b;
        case '*': return a * b;
        case '/': return a / b;
        case '^': return pow(a, b);
        default: return 0;
    }
}

double evaluateExpression(const string& expression) {
    stack<double> values;
    stack<char> operators;

    for (size_t i = 0; i < expression.length(); ++i) {
        char c = expression[i];

        if (c == ' ')
            continue;

        if (isdigit(c)) {                                                                                        //isdigit() cheacking that is it a digit or not
            string numStr;
            while (i < expression.length() && (isdigit(expression[i]) || expression[i] == '.')) {
                numStr += expression[i];
                i++;
            }
            i--;
            values.push(stod(numStr));                                                                          //stod()  converts number string to its double type eg. "11"=11
                                                                                                                 // to convert in int we can use stoi()
        } else if (c == '(') {
            operators.push(c);
        } else if (c == ')') {
            while (!operators.empty() && operators.top() != '(') {
                char op = operators.top();
                operators.pop();

                double b = values.top();
                values.pop();

                double a = values.top();
                values.pop();

                values.push(applyOperator(op, a, b));
            }

            if (!operators.empty())
                operators.pop(); // Pop '('
        } else if (isOperator(c)) {
            while (!operators.empty() && getPrecedence(operators.top()) >= getPrecedence(c)) {
                char op = operators.top();
                operators.pop();

                double b = values.top();
                values.pop();

                double a = values.top();
                values.pop();

                values.push(applyOperator(op, a, b));
            }
            operators.push(c);
        }
    }

    while (!operators.empty()) {
        char op = operators.top();
        operators.pop();

        double b = values.top();
        values.pop();

        double a = values.top();
        values.pop();

        values.push(applyOperator(op, a, b));
    }

    return values.top();
}

int main() {
    string expression;
    cout << "Enter a mathematical expression: ";
    getline(cin, expression);

    try {
        double result = evaluateExpression(expression);
        cout << "Result: " << result << endl;
    } catch (exception& e) {
        cout << "Error: " << e.what() << endl;                                                           // error handling
    }

    return 0;
}
