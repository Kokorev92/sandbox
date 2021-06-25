#include <unistd.h>
#include <iostream>
#include <sys/types.h>

using std::cout;
using std::endl;

int pipe_desc[2];
pid_t parent_pid;
pid_t child_pid;

int main(int argc, char** argv) {
    parent_pid = getpid();
    child_pid = getppid();
    cout << parent_pid << endl;
    cout << child_pid << endl;
    return 0;
}
