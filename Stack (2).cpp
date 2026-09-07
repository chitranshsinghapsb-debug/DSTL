#include <bits/stdc++.h>
using namespace std;

class Stack {
    int a[100];
    int top;
public:
    Stack(){top=-1;}
    bool empty(){return top==-1;}
    void push(int x){a[++top]=x;}
    int pop(){return a[top--];}
    int peek(){return a[top];}
};
bool balanced(string s){
    Stack st;
    for(char c:s){
        if(c=='('||c=='['||c=='{')
            st.push(c);
        else if(c==')'||c==']'||c=='}'){
            if(st.empty()) return false;
            char top=st.peek();
            if((c==')'&&top!='(')||(c==']'&&top!='[')||(c=='}'&&top!='{'))
                return false;
            st.pop();
        }
    }
    return st.empty();
}
int precedence(char c){
    if(c=='^') return 3;
    if(c=='*'||c=='/') return 2;
    if(c=='+'||c=='-') return 1;
    return 0;
}
string infixToPostfix(string s){
    Stack st;
    string p;
    for(int i=0;i<s.length();i++){
        char c=s[i];
        if(c==' ') continue;

        if(c!='+'&&c!='-'&&c!='*'&&c!='/'&& c!='^'&& c!='('&& c!=')'){
            p+=c;
            p+=' ';
        }
        else if(c=='(') st.push(c);
        else if(c==')'){
            while(!st.empty() && st.peek()!='('){
                p+=st.pop();
                p+=' ';
            }
            st.pop();
        }
        else {
            while(!st.empty() && st.peek() != '(' &&
                  (precedence(st.peek()) > precedence(c) ||
                  (precedence(st.peek()) == precedence(c) && c != '^'))) {
                p+=st.pop();
                p+=' ';
            }
            st.push(c);
        }
    }
    while(!st.empty()){
        p+=st.pop();
        p+=' ';
    }
    return p;
}
int evaluatePostfix(string p){
    Stack st;
    for(int i=0;i<p.length();i++){
        if(p[i]==' ') continue;
        if(isdigit(p[i])){
            st.push(p[i]-'0');
        }else{
            int b=st.pop();
            int a=st.pop();
            switch(p[i]){
                case '+':st.push(a+b); break;
                case '-':st.push(a-b); break;
                case '*':st.push(a*b); break;
                case '/':st.push(a/b); break;
                case '^':st.push(pow(a,b)); break;
            }
        }
    }
    return st.pop();
}
int main(){
    string infix;
    cout<<"Enter expression: ";
    getline(cin, infix);
    
    int choice;
    do{
        cout<<"1. Check paranthesis balance.\n";
        cout<<"2. Convert infix to postfix.\n";
        cout<<"3. Evaluate the postfix expression.\n";
        cout<<"4. Exit\n";
        cout<<"Enter your choice: ";
        cin>>choice;
        switch(choice){
        case 1:{
        	if(!balanced(infix)){
        		cout<<"Parentheses are not balanced"<<endl;
        	}else{
        		cout<<"Parentheses are balanced"<<endl;
        	}
        	break;
        }
        case 2:{
        	string postfix=infixToPostfix(infix);
    		cout<<"Postfix: "<<postfix<<endl;
    		break;
        }
        case 3:{
        	string postfix=infixToPostfix(infix);
        	cout<<"Result: "<<evaluatePostfix(postfix)<<endl;
        	break;
        }
        case 4:{
            cout << "Exiting program...\n";
            break;
	}
        default:
            cout << "Invalid choice. Please try again.\n";
        }
    }while(choice!=4);
    return 0;
}
/*
Enter expression: (1+(8*3)/2-2+(2*5))
1. Check paranthesis balance.
2. Convert infix to postfix.
3. Evaluate the postfix expression.
4. Exit
Enter your choice: 1
Parentheses are balanced
Enter your choice: 2
Postfix: 1 8 3 * 2 / + 2 - 2 5 * + 
Enter your choice: 3
Result: 21
Enter your choice: 4
Exiting program...
*/
