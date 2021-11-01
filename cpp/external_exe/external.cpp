#include <iostream>

using std::cout;
using std::endl;

int main(int argc, char** argv){
    if(argc == 3){
        auto a = atoi(argv[1]);
        auto b = atoi(argv[2]);

        int c = a + b;
        cout << c << endl;
    }
    
    return 0;
}
