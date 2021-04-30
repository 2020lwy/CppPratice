#include <iostream>

//冒泡法
void maopao(int *arr,int num){
    for(int i =num-1;i>=1;i--){
        for(int j=0;j<i;j++){
            if(arr[j]<arr[j+1]){
                int tmp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = tmp;
            }
        }
    }
}

//选择排序法
void xuanze(int *arr,int num){
    for(int i=num-1;i>=1;i--){
        for(int j=0;j<i;j++){
            if(arr[j]<arr[i]){
                int tmp = arr[j];
                arr[j]  = arr[i];
                arr[i]  = tmp;
            }
        }
    }
}

//插入排序法

//快速排序法
void quick(int *arr,int start,int end){
    if(start > end)
        return ;
    int base = arr[start];
    int i = start;
    int j = end;
    while(i!=j){
        while(arr[j]>=base&&j>i)
            j--;
        while(arr[i]<=base&&j>i)
            i++;
        if(j>i){
            int tmp = arr[j];
            arr[j] = arr[i];
            arr[i] = tmp;
        }
    }
    arr[start]=arr[i];
    arr[i] = base;
    quick(arr,start,i-1);
    quick(arr,i+1,end);
}

int main(void){

    int arr[10]={1,4,900,30,0,190,80,70,50,100};
    // maopao(arr,10);
    // xuanze(arr,10);
    quick(arr,0,9);
    for(int i = 0;i<10;i++){
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;
    return 0;
}