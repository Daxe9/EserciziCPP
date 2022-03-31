// initialize c++ program
#include <iostream>
using namespace std;

int main() {
    // generate an array with random number
    int arr[10];

    int n = 10;
    // print array
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
    // sort array even and odd
    int even = 0;
    int odd = n - 1;
    int i = 0;
    
    for (int i = 0; i < odd; ++i) {
        if(arr[i] % 2 == 0) {
            int temp = arr[i];
            arr[i] = arr[odd];
            arr[odd] = temp;
            i--;
            --odd;
        }
    }

    // print array
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}