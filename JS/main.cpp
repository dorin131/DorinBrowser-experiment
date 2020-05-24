#include "tokenizer.h"
#include <iostream>

using namespace std;
using namespace js;

int main()
{
    cout << "Hello World!" << endl;
    Tokenizer* tokenizer = new Tokenizer("test");
    tokenizer->next_token();
    return 0;
}
