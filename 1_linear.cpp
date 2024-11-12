#include<iostream>
using namespace std;

int main(){
    int n;
    cout<<"Enter the no of elements in arr";
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
    for(int i=0; i<n; i++)
    {
        if(search==arr[i])
        {
            cout<<"Found at index:"<<i<<endl;
            found=true;
            break;
        }
        
    }
    if(!found){
        cout<<"Element does not exist"<<endl;
    }

    return 0;
}