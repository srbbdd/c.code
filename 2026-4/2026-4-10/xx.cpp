#include <iostream>
using namespace std;

int main() {

    int arr[6] = { 0 };

    int len = sizeof(arr) / sizeof(int);

    for (int i = 0; i < len; i++) {
        cin >> arr[i];
    }

    cout << "[";
    for (int i = 0; i < len; i++) {
        if (i == len - 1) {
            cout << arr[i] << "]" << endl;
            break;
        }
        cout << arr[i] << ", ";
    }
    int left = 0;
    int right = len - 1;
    while (left < right)
    {
        int ret = arr[left];
        arr[left] = arr[right];
        arr[right] = ret;
        left++;
        right--;
    }
    cout << "[";
    for (int i = 0; i < len; i++) {
        if (i == len - 1) {
            cout << arr[i] << "]" << endl;
            break;
        }
        cout << arr[i] << ", ";
    }

    return 0;
}
#include <iostream>
using namespace std;

void exchange(int& m, int& n)
{
    int ret = m;
    m = n;
    n = ret;
}
int main() {

    int m, n;
    cin >> m;
    cin >> n;

    exchange(m, n);


    cout << m << " " << n << endl;

    return 0;
}