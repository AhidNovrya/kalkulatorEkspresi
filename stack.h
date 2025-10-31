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

//fungsi/prosedure utama stack
stack createStack();
bool isEmpty(stack S);
bool isFull(stack S);
void push(stack &S, infotype x);
void pop(stack &S, infotype &x);
int size(stack S);

int tokenize(string expr, string tokens[]);
int tingkatOperator(string op);
bool isOperator(string op);
string infixToPostfix(string tokens[], int jToken, int c);
void reverse(string tokens[], int jToken);
string infixToPrefix(string tokens[], int jToken);

#endif // STACK_H_INCLUDED
