#include <iostream>

//二分查找 前提条件是要查找的数组是一个有序排列的数组

int search(int *arr,int length,int target){
    int left = 0;
    int right = length;
    while(left<=right){
        int mid = (left+right)/2;
        if(arr[mid]==target){
            return arr[mid];
        }else if(arr[mid]>target){
            right = mid -1;
        }else if(arr[mid<target]){
            left = mid +1;
        }
    }
    return -1;
}

//冒泡排序法
void maopao(int *arr,int num){

    for(int i=num-1;i>=1;i--){
        for(int j=0;j<i;j++){
            if(arr[j]>arr[j+1]){
                int tmp = 0;
                tmp = arr[j];
                arr[j]=arr[j+1];
                arr[j+1]= tmp;
            }
        }
    }
}

//选择排序法
void xuanze(int *arr,int num){
    for(int i = num-1;i>=1;i--){
        for(int j=0;j<i;j++){
            if(arr[i]>arr[j]){
                int tmp = 0;
                tmp = arr[i];
                arr[i] = arr[j];
                arr[j] = tmp;
            }
        }
    }
}

//快速排序法

void quick_sort(int *arr,int start,int end){
    if(start>end){
        return;
    }
    int base = arr[start];
    int i = start;
    int j = end;
    while(i!=j){
        while(arr[j]>=base&&i<j)
            j--;
        while(arr[i]<=base&&i<j)
            i++;
        if(j>i){
            int tmp = 0;
            tmp = arr[i];
            arr[i] = arr[j];
            arr[j] = tmp;
        }
        
    }
    
    arr[start]=arr[i];
    arr[i]=base;
    quick_sort(arr,start,i-1);
    quick_sort(arr,i+1,end);
}

void quick_sort2(int *arr,int start,int end){
    if(start > end)
        return;
    int base = arr[start];
    int i = start;
    int j = end;
    while(i!=j){
        while(arr[j]>=base && j>i)
            j--;
        while(arr[i]<=base && j>i)
            i++;
        if(j>i){
            int t = arr[j];
            arr[j] = arr[i];
            arr[i] = t; 
        }
    }
    arr[start] = arr[i];
    arr[i] = base;
    quick_sort(arr,start,i-1);
    quick_sort(arr,i+1,end);

}


int main(void){

    int arr[10]={0,1,2,3,4,5,6,7,8,9};
    int b = search(arr,9,8);
    std::cout << b << std::endl;

    int test[10]={1,2,33,4,5,6666,77,8,0,90};
    // maopao(test,10);
    // xuanze(test,10);
    quick_sort(test,0,9);
    for(int i=0;i<10;i++){
        std::cout << test[i]<< " ";
    }
    std::cout << std::endl;
    return 0;
}