#include "stack.h"

int main(){
    string x, token[MAXSTACK], rToken[MAXSTACK];
    int jToken;

    while (x != "exit"){
        cout<< "inputkan 'exit' untuk keluar"<< endl;
        cout<< "Masukan Ekspresi Infix: ";
        getline(cin, x);

        if (x != "exit"){
            jToken = tokenize(x, token);

            cout<< "Ekspresi postfix: "<< infixToPostfix(token, jToken, 1)<< endl;
            cout<< "Ekspresi prefix: "<< infixToPrefix(token, jToken)<< endl;

        }
        cout<< endl;
    }
    return 0;
}
