#include <iostream>
#include <string>
#include <cmath>
#include <sstream>
using namespace std;

class CharStack{
    char a[100];
    int top;
public:
    CharStack() { top = -1; }
    void push(char x) { a[++top] = x; }
    char pop() { return a[top--]; }
    char peek() { return a[top]; }
    bool empty() { return top == -1; }
};

class NumStack{
    double a[100];
    int top;
public:
    NumStack(){ top = -1; }
    void push(double x){ a[++top] = x; }
    double pop(){ return a[top--]; }
    bool empty(){ return top == -1; }
};

bool isOperator(char c){
    return c == '+' || c == '-' || c == '*' || c == '/' || c == '%' || c == '^';
}

int priority(char c){
    if (c == '+' || c == '-') return 1;
    if (c == '*' || c == '/' || c == '%') return 2;
    if (c == '^') return 3;
    return 0;
}

bool balanced(string s){
    CharStack st;

    for (char c : s){
        if (c == '(')
            st.push(c);
        else if (c == ')'){
            if (st.empty()) return false;
            st.pop();
        }
    }
    return st.empty();
}

string infixToPostfix(string s){
    CharStack st;
    string p = "";

    for (int i = 0; i < s.length(); i++){
        char c = s[i];

        if (c == ' ')
            continue;

        if (isdigit(c) || c == '.'){
            while (i < s.length() && (isdigit(s[i]) || s[i] == '.')) {
                p += s[i];
                i++;
            }
            p += ' ';
            i--;
        }
        else if (c == '('){
            st.push(c);
        }
        else if (c == ')'){
            while (!st.empty() && st.peek() != '('){
                p += st.pop();
                p += ' ';
            }
            st.pop();
        }
        else if (isOperator(c)){
            while (!st.empty() && st.peek() != '(' &&
              
                   priority(st.peek()) >= priority(c)){
                p += st.pop();
                p += ' ';
            }
            st.push(c);
        }
    }

    while (!st.empty()){
        p += st.pop();
        p += ' ';
    }

    return p;
}

double calculate(double a, double b, char op){
    switch (op){
        case '+': return a + b;
        case '-': return a - b;
        case '*': return a * b;
        case '/': return a / b;
        case '%': return fmod(a, b);
        case '^': return pow(a, b);
    }
    return 0;
}

double evaluate(string p){
    NumStack st;
    stringstream ss(p);
    string x;

    while (ss >> x) {
        if(isdigit(x[0]) || x[0] == '.'){
            st.push(stod(x));
        }
        else{
            double b = st.pop();
            double a = st.pop();
            st.push(calculate(a, b, x[0]));
        }
    }

    return st.pop();
}

int main(){
    string expression;

    cout <<"Enter expression: "<<endl;
    getline(cin, expression);
    
    if(!balanced(expression)){
        cout <<"Parentheses are not balanced." << endl;
        return 0;
    }

    cout << "Parentheses are balanced." << endl;

    string postfix = infixToPostfix(expression);

    cout << "Postfix: " << postfix << endl;
    cout << "Result: " << evaluate(postfix) << endl;

    return 0;
}

/*
se5@adminpc-HP-280-G3-MT:~/Desktop/7222$ g++ stack.cpp -o stack
se5@adminpc-HP-280-G3-MT:~/Desktop/7222$ ./stack
Enter expression: (2+3*4)
Parentheses are balanced.
Postfix: 2 3 4 * + 
Result: 14
se5@adminpc-HP-280-G3-MT:~/Desktop/7222$ g++ stack.cpp -o stack
se5@adminpc-HP-280-G3-MT:~/Desktop/7222$ ./stack
Enter expression: (1+3*9-10/2)
Parentheses are balanced.
Postfix: 1 3 9 * + 10 2 / - 
Result: 23
*/

#include <iostream>
#include <string>
#include <cmath>
#include <sstream>
using namespace std;

class CharStack{
    char a[100];
    int top;
public:
    CharStack() { top = -1; }

    void push(char x) { a[++top] = x; }

    char pop() { return a[top--]; }

    char peek() { return a[top]; }

    bool empty() { return top == -1; }
};

class NumStack{
    double a[100];
    int top;
public:
    NumStack(){ top = -1; }

    void push(double x){ a[++top] = x; }

    double pop(){ return a[top--]; }

    bool empty(){ return top == -1; }
};

bool isOperator(char c){
    return c == '+' || c == '-' || c == '*' ||
           c == '/' || c == '%' || c == '^';
}

int priority(char c){
    if (c == '+' || c == '-') return 1;
    if (c == '*' || c == '/' || c == '%') return 2;
    if (c == '^') return 3;
    return 0;
}

// Check whether brackets match correctly
bool balanced(string s){
    CharStack st;

    for (char c : s){

        // Opening brackets
        if (c == '(' || c == '{' || c == '['){
            st.push(c);
        }

        // Closing brackets
        else if (c == ')' || c == '}' || c == ']'){

            // No opening bracket available
            if (st.empty())
                return false;

            char open = st.pop();

            // Check matching pair
            if ((c == ')' && open != '(') ||
                (c == '}' && open != '{') ||
                (c == ']' && open != '[')){
                return false;
            }
        }
    }

    return st.empty();
}

string infixToPostfix(string s){
    CharStack st;
    string p = "";

    for (int i = 0; i < s.length(); i++){
        char c = s[i];

        if (c == ' ')
            continue;

        if (isdigit(c) || c == '.'){
            while (i < s.length() &&
                   (isdigit(s[i]) || s[i] == '.')){
                p += s[i];
                i++;
            }

            p += ' ';
            i--;
        }

        else if (c == '('){
            st.push(c);
        }

        else if (c == ')'){
            while (!st.empty() && st.peek() != '('){
                p += st.pop();
                p += ' ';
            }

            if (!st.empty())
                st.pop();
        }

        else if (isOperator(c)){
            while (!st.empty() &&
                   st.peek() != '(' &&
                   priority(st.peek()) >= priority(c)){

                p += st.pop();
                p += ' ';
            }

            st.push(c);
        }
    }

    while (!st.empty()){
        p += st.pop();
        p += ' ';
    }

    return p;
}

double calculate(double a, double b, char op){
    switch (op){
        case '+': return a + b;
        case '-': return a - b;
        case '*': return a * b;
        case '/': return a / b;
        case '%': return fmod(a, b);
        case '^': return pow(a, b);
    }

    return 0;
}

double evaluate(string p){
    NumStack st;
    stringstream ss(p);
    string x;

    while (ss >> x){

        if (isdigit(x[0]) || x[0] == '.'){
            st.push(stod(x));
        }

        else{
            double b = st.pop();
            double a = st.pop();

            st.push(calculate(a, b, x[0]));
        }
    }

    return st.pop();
}

int main(){

    int choice;

    cout << "1. Check brackets only" << endl;
    cout << "2. Evaluate expression" << endl;
    cout << "Enter your choice: ";
    cin >> choice;

    cin.ignore();

    string expression;

    cout << "Enter expression: ";
    getline(cin, expression);

    // Option 1: Only bracket checking
    if (choice == 1){

        if (balanced(expression))
            cout << "All brackets are balanced." << endl;
        else
            cout << "Brackets are not balanced." << endl;

        return 0;
    }

    // Option 2: Evaluate expression
    if (choice == 2){

        if (!balanced(expression)){
            cout << "Brackets are not balanced." << endl;
            return 0;
        }

        cout << "Brackets are balanced." << endl;

        string postfix = infixToPostfix(expression);

        cout << "Postfix: " << postfix << endl;
        cout << "Result: " << evaluate(postfix) << endl;

        return 0;
    }

    cout << "Invalid choice." << endl;

    return 0;
}

