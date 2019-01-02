#include <iostream>
#include <vector>
using namespace std;

bool binarySearch(vector<int> avector, int item) {
    int first = 0;
    int last = avector.size() - 1;
    bool found = false;

    while (first <= last && !found) {
        int midpoint = (first + last) / 2;
        if (avector[midpoint] == item) {
            found = true;
        } else {
            if (item < avector[midpoint]) {
                last = midpoint - 1;
            } else {
                first = midpoint + 1;
            }
        }
    }
    return found;
}

int main() {
    // Using static array to initialize a vector
    static const int arr[] = {0, 1, 2, 8, 13, 17, 19, 32, 42};
    vector<int> avector(arr, arr + sizeof(arr) / sizeof(arr[0]));

    cout << binarySearch(avector, 3) << endl;
    cout << binarySearch(avector, 13) << endl;

    return 0;
}
