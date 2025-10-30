#include "stack.h"

void createStack(stack &S){
    S.top = 0;
}

bool isEmpty(stack S){
    return S.top == 0;
}

bool isFull(stack S){
    return S.top == MAXSTACK;
}

void push(stack &S, infotype x){
    if (not(isFull(S))){
        S.info[S.top] = x;
        S.top++;
    }
}

void pop(stack &S, infotype &x){
    if (not(isEmpty(S))){
        x = S.info[S.top-1];
        S.top--;
    }
}

int tokenize(string X, string tokens[]) {
    int count = 0;
    string number = "";

    for (int i = 0; i < X.length(); i++) {
        char c = X[i];

        if (c == ' ') continue;

        if (c >= '0' && c <= '9') {
            number += c; // gabungkan angka multi-digit
        } else {
            if (number != "") {
                tokens[count++] = number;
                number = "";
            }

            if (c == '+' || c == '-' || c == '*' || c == '/' || c == '(' || c == ')' || c == '^') {
                string op = "";
                op += c;
                tokens[count++] = op;
            }
        }
    }

    if (number != "") {
        tokens[count++] = number;
    }

    return count;
}

int tingkatOperator(string op){
    if (op=="^"){
        return 3;
    } else if (op=="*" || op=="/"){
        return 2;
    } else{
        return 1;
    }
}

bool isOperator(string op){
    return (op=="^" || op=="*" || op=="/" || op=="+" || op=="-");
}

void infixToPostfix(stack& S, string tokens[], int jToken) {
    string x;

    for (int i = 0; i < jToken; i++) {

        if (!isOperator(tokens[i]) && tokens[i] != "(" && tokens[i] != ")") {
            cout << tokens[i];

        } else if (tokens[i] == "(") {
            push(S, tokens[i]);

        } else if (tokens[i] == ")") {
            while (!isEmpty(S) && S.info[S.top-1] != "(") {
                pop(S, x);
                cout << x;
            }
            if (!isEmpty(S) && S.info[S.top-1] == "(") {
                pop(S, x);
            }

        } else if (isOperator(tokens[i])) {
            int tingkatSekarang = tingkatOperator(tokens[i]);

            while (!isEmpty(S) && S.info[S.top-1] != "(" && tingkatOperator(S.info[S.top-1]) >= tingkatSekarang){
                pop(S, x);
                cout << x;
            }
            push(S, tokens[i]);
        }
    }

    while (!isEmpty(S)) {
        pop(S, x);
        cout << x;
    }

    cout << endl;
}
