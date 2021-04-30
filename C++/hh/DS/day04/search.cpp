#include <iostream>

int search(int *arr,int length,int target){
    int left = 0;
    int right = length;
    while(left<=right){
        int mid = (left+right)/2;
        if(arr[mid]==target){
            return arr[mid];
        }else if(arr[mid]>target){
            right = mid -1;
        }else if(arr[mid]<target){
            left = mid +1;
        }
    }
    return -1;
}

int main(void){

    int arr[10]={0,1,2,3,4,5,6,7,8,9};
    std::cout << search(arr,9,8)  << std::endl;
    return 0;
}