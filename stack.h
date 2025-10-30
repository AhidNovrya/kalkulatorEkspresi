#ifndef STACK_H_INCLUDED
#define STACK_H_INCLUDED
#include <iostream>
using namespace std;

const int MAXSTACK = 100;

typedef string infotype;

struct stack{
    infotype info[MAXSTACK];
    int top;
};

void createStack(stack &S);
bool isEmpty(stack S);
bool isFull(stack S);
void push(stack &S, infotype x);
void pop(stack &S, infotype &x);
int tokenize(string expr, string tokens[]);
int tingkatOperator(string op);
bool isOperator(string op);
void infixToPostfix(stack &S, string tokens[], int jToken);

#endif // STACK_H_INCLUDED
