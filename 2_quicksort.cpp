#include<iostream>
using namespace std;

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

int partition(int arr[], int l, int h) {
    int i = l;
    int j = h;
    int pivot = arr[l];
    
    while (i < j) {
        do {
            i++;
        } while (i <= h && arr[i] < pivot);
        
        do {
            j--;
        } while (j >= l && arr[j] > pivot);
        
        if (i < j) {
            swap(&arr[i], &arr[j]);
        }
    }
    
    swap(&arr[l], &arr[j]);
    return j;
}

void Quicksort(int arr[], int l, int h) {
    if (l < h) {
        int j = partition(arr, l, h);
        Quicksort(arr, l, j - 1);
        Quicksort(arr, j + 1, h);
    }
}

int main() {
    int n;
    cout << "Enter the number of elements in array: ";
    cin >> n;
    int arr[n];
    
    for (int i = 0; i < n; i++) {
        cout << "Enter element " << i + 1 << ": ";
        cin >> arr[i];
    }

    Quicksort(arr, 0, n);  // Pass n instead of n - 1

    cout << "Sorted array: ";
    cout<<"[";
    for (int i = 0; i < n; i++) {
        cout << arr[i] <<",";
    }
    cout << "]"<<endl;

    return 0;
}
