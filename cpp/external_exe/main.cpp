#include <iostream>
#include <stdio.h>
#include <unistd.h>

using std::cout;
using std::endl;

char buff[1024];

int main(){
    FILE* stream = popen("./external 1 1", "r");
    fread(buff, sizeof(buff), 1, stream);
    pclose(stream);
    cout << buff << endl;
    return 0;
}
