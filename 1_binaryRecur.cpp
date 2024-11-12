#include<iostream>
using namespace std;

int BinaryRecur(int arr[],int i, int j, int search){
    int mid=(i+j)/2;
    while(i<=j){
        if(search<arr[mid])
        {
            return BinaryRecur(arr,i,mid-1,search);
            
        }
        if(search>arr[mid]){
            return BinaryRecur(arr,mid+1,j,search);

        }
        if(search==arr[mid]){
            return mid;
        }
    }
    return -1;
}
int main(){
    int n;
    cout<<"Enter the no of elements in arr:";
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++)
    {
        cout<<"Enter element->"<<i+1<<":";
        cin>>arr[i];
    }
    int search;
    cout<<"Enter element to be searched:";
    cin>>search;
    bool found=false;
    int i=0;
    int j=n-1;
    int mid=(i+j)/2;
    int index=BinaryRecur(arr,i,j,search);
    if(index>0)
    {
        cout<<"element found at index:"<<index<<endl;
    }
    else{
        cout<<"element not found"<<endl;
    }
    return 0;
}