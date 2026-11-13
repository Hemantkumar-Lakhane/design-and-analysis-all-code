// Q6. Implement Quick Sort and analyze best and worst cases for different arrangements.

#include<iostream>
#include<vector>
using namespace std;

int partition(vector<int>&arr,int start,int end){
    int pivot = arr[end]; //last element as pivot
    
    int i=start-1;    //smaller elements swap
    for(int j=start; j<end; j++){   //compar each element
        if(arr[j]<pivot){
            i++;
            swap(arr[i],arr[j]);
        }
    }
    swap(arr[i+1],arr[end]);
    return i+1;
}

void quicksort(vector<int>&arr,int start,int end){
    if(start<end){
        int p = partition(arr,start,end);
        quicksort(arr,start,p-1);
        quicksort(arr,p+1,end);
    }  
}

int main(){
    vector<int>arr= {5,1,3,9,2};
    quicksort(arr,0,arr.size()-1);

    cout << "Sorted array: ";
    for (int i = 0; i < arr.size(); i++) {
        cout << arr[i] << " ";
    }

    return 0;
}