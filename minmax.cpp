#include <iostream>

using namespace std;

int* minmax(int *arr, int low, int high){
    if (low == high){
        return nullptr;
    }
    if (low == high - 1){
        if (arr[low] > arr[high]){
            return new int[2]{arr[high], arr[low]};
        }
        return new int[2]{arr[low], arr[high]};
    }
    int mid = (low + high) / 2;
    int *left = minmax(arr, low, mid);
    int *right = minmax(arr, mid, high);
    if (left == nullptr){
        return right;
    }
    if (right == nullptr){
        return left;
    }
    int *result = new int[2];
    result[0] = left[0] < right[0] ? left[0] : right[0];
    result[1] = left[1] > right[1] ? left[1] : right[1];
    return result;
}

//main take input with prompts and print output
int main(){
    int n;
    cout << "Enter the number of elements: ";
    cin >> n;
    int *arr = new int[n];
    cout << "Enter the elements: ";
    for (int i = 0; i < n; i++){
        cin >> arr[i];
    }
    int *result = minmax(arr, 0, n - 1);
    cout << "The minimum element is " << result[0] << " and the maximum element is " << result[1] << endl;
    return 0;
}