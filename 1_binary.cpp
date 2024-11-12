#include<iostream>
using namespace std;
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
    do
    {
        mid=(i+j)/2;
        if(search<arr[mid])
        {
            j=mid-1;
            
        }
        if(search>arr[mid]){
            i=mid+1;
            
        }
        if(search==arr[mid]){
            found=true;
            break;
        }
        /* code */
    } while (i<=j);
    
    if(!found)
    {
        cout<<"Element not Found"<<endl;
    }
    else{
        cout<<"Element found at index:"<<mid<<endl;
    }
    return 0;
}