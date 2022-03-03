#include <iostream>

using namespace std;

int arr[10] = {1,2,3,4,5,6,7,8,9,10};

void rotate(int a[], unsigned size, int shift){
    for(int j = 0; j < shift; ++j) {
        for (int i = 0; i < size - 1; ++i) {
            int tmp = a[i];
            a[i] = a[i + 1];
            a[i + 1] = tmp;
        }
    }
}

int main() {
    rotate(arr, 10, 11);
    for(int i = 0; i < 10; ++i){
        cout << arr[i] << " ";
    }
    cout << endl;
    return 0;
}
