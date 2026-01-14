#include <iostream>
using namespace std;

int binarySearch(int arr[], int low, int high, int target) {
    if (low>high)
        return -1;
    int mid = low+(high-low)/2;
    if (arr[mid]==target)
        return mid;
    else if (arr[mid]>target)
        return binarySearch(arr,low,mid-1,target);
    else
        return binarySearch(arr,mid+1,high,target);
}

int main() {
    int arr[] = {2, 5, 8, 12, 16, 23, 38, 56, 72, 91};
    int n = sizeof(arr)/ sizeof(arr[0]);
    int target = 23;
    int index = binarySearch(arr,0,n-1,target);
    if (index != -1)
        cout << "23 found at index " << index;
    else
        cout << "23 not found";

    return 0;
}
