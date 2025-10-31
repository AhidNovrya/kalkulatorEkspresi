#include "stack.h"

stack createStack(){
    stack S;
    S.top = 0;
    return S;
}

bool isEmpty(stack S){
    return S.top == 0;
}

bool isFull(stack S){
    return S.top == MAXSTACK;
}

void push(stack &S, infotype x){
    if (!isFull(S)){
        S.info[S.top] = x;
        S.top++;
    }
}

int size(stack S){
    return S.top;
}

void pop(stack &S, infotype &x){
    if (!isEmpty(S)){
        x = S.info[S.top-1];
        S.top--;
    }
}

int tokenize(string X, string tokens[]) {
    int count = 0;
    string number = "";

    for (int i = 0; i < X.length(); i++) {
        char c = X[i];

        if (c == ' ') {
            if (number != "") {
                tokens[count++] = number;
                number = "";
            }
            continue;
        }

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

string infixToPostfix(string tokens[], int jToken, int c){
    string x, postfix;
    stack sOp = createStack(), stackPostfix = createStack();

    for (int i = 0; i < jToken; i++){

        if (!isOperator(tokens[i]) && tokens[i] != "(" && tokens[i] != ")"){
            push(stackPostfix, tokens[i]);

        } else if (tokens[i] == "("){
            push(sOp, tokens[i]);

        } else if (tokens[i] == ")"){
            while (!isEmpty(sOp) && sOp.info[sOp.top-1] != "("){
                pop(sOp, x);
                push(stackPostfix, x);
            }
            if (!isEmpty(sOp) && sOp.info[sOp.top-1] == "("){
                pop(sOp, x);
            }

        } else if (isOperator(tokens[i])){
            int tingkatSekarang = tingkatOperator(tokens[i]);

            while (!isEmpty(sOp) && sOp.info[sOp.top-1] != "("){
                if (tingkatOperator(sOp.info[sOp.top-1]) >= tingkatSekarang && c == 1){
                    pop(sOp, x);
                    push(stackPostfix, x);
                } else if (tingkatOperator(sOp.info[sOp.top-1]) <= tingkatSekarang && c == 2){
                    pop(sOp, x);
                    push(stackPostfix, x);
                }
            }
            push(sOp, tokens[i]);
        }
    }

    while (!isEmpty(sOp)){
        pop(sOp, x);
        push(stackPostfix, x);
    }

    int j = size(stackPostfix);
    for (int i=0; i<j; i++){
        postfix += stackPostfix.info[i] + " ";
    }

    return postfix;
}

stack tokenToStack(string tokens[], int jToken){
    stack S = createStack();
    for (int i=0;i<jToken;i++){
        string x = tokens[i];
        push(S, x);
    }
    return S;
}

void reverse(string tokens[], int jToken){
    stack S = createStack();
    string x, t[MAXSTACK];

    S = tokenToStack(tokens, jToken);

    int j = size(S);
    for (int i=0;i<j;i++){
        pop(S, x);
        if (x == "("){
            x = ")";
        }else if (x == ")"){
            x = "(";
        }
        tokens[i] = x;
    }
}

string infixToPrefix(string tokens[], int jToken){
    string prefix, reverseToken[MAXSTACK];

    for (int i=0;i<jToken;i++){
        reverseToken[i] = tokens[i];
    }

    reverse(reverseToken, jToken);
    prefix = infixToPostfix(reverseToken, jToken, 2);

    int j = tokenize(prefix, reverseToken);
    reverse(reverseToken, j);

    prefix = "";
    for (int i=0;i<j;i++){
        prefix += reverseToken[i];
    }
    return prefix;
}
