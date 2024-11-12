#include <iostream>
using namespace std;
#define max 100

void merge(int arr[], int low, int mid, int high)
{
    int b[max];
    int i = low;
    int j= mid+1;
    int k=low;

    while(i<=mid && j<=high)
    {
        if(arr[i]<arr[j])
        {
            b[k]=arr[i];
            i++;
            k++;
        }

        if(arr[j]<arr[i])
        {
            b[k]=arr[j];
            j++;
            k++;
        }
    }

    while(i<=mid)
    {
        b[k]=arr[i];
        i++;
        k++;
    }

    while (j <= high)
    {
        b[k] = arr[j];
        j++;
        k++;
    }

    for(int a=low;a<=high;a++)
    {
        arr[a]=b[a];
    }
}

void mergesort(int arr[], int low, int high)
{
    if(low<high)
    {
        int mid=(low+high)/2;
        mergesort(arr,low,mid);
        mergesort(arr,mid+1,high);
        merge(arr,low,mid,high);
    }
}

int main()
{
    int n;
    cout << "enter the number of elements: ";
    cin >> n;
    int arr[n];
    cout << "enter array elements:\n";
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    mergesort(arr, 0, n - 1);

    cout << "sorted array: \n";
    for (int i = 0; i < n; i++)
    {
        cout << " "<<arr[i];
    }

    return 0;
}