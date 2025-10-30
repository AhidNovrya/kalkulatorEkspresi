#include "stack.h"

int main(){
    string x, token[100];
    int jToken;
    stack S;

    createStack(S);

    while (x != "exit"){
        cout<< "inputkan 'exit' untuk keluar"<< endl;
        cout<< "Masukan Ekspresi Infix: ";
        getline(cin, x);

        if (x != "exit"){
            jToken = tokenize(x, token);

            cout<< "Ekspresi postfix: ";
            infixToPostfix(S, token, jToken);

        }
        cout<< endl;
    }

    return 0;
}
