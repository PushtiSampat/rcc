#include"Stack.h"
#include<string>
#include<iostream>


int main()
{
    StackClass<char> *s = new StackClass <char>;
    string str;
    int count=0;

    char openingBraces[] = {'[', '{', '('};
    char closingBraces[] = {']', '}', ')'};

    std :: cin >> str;

    for(uint i = 0; i < str.length(); i++){

        for(int j = 0; j < 3; j++){
            if(str[i] == openingBraces[j]){
                s->push(str[i]);
                count++;
            }
        }
        for(int j = 0; j < 3; j++){
            if(str[i] == closingBraces[j]){
                if (openingBraces[j] == s->topOfStack()){
                    s->pop();
                    count--;
                }
            }
        }
    }

    if(count == 0) cout << "yo";
    else cout <<"no";

    return 0;
}
