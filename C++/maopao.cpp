#include <iostream>
#include <vector>
//冒泡排序法
void maopao(int *arr,int num){
    int tmp =0;
    for(int i = num-1;i>=1;i--){
        for(int j=0;j < i;j++){
            if(arr[j]>arr[j+1]){
                tmp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = tmp;
            }
        }
    }
}

void mao(int *arr,int num){
    int tmp = 0;
    for(int i=num-1;i>=1;i--){
        for(int j=0;j<i;j++){
            if(arr[j]>arr[j+1]){
                tmp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = tmp;
            }
        }
    }
}

void xuan(int *arr,int num){
    int tmp =0;
    for(int i=num-1;i>=1;i--){
        for(int j=0;j<i;j++){
            if(arr[i]<arr[j]){
                tmp = arr[i];
                arr[i] = arr[j];
                arr[j] = tmp;
            }
        }
    }
}

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
            int tmp = arr[i];
            arr[i] = arr[j];
            arr[j] = tmp;
        }
    }
    arr[start] = arr[i];
    arr[i]     = base;
    quick(arr,start,i-1);
    quick(arr,i+1,end);

}

//选择排序
void xuanze(int *arr ,int num){
    int tmp = 0;
    for(int i=num-1;i>=1;i--){
        for(int j = 0;j<i;j++){
            if(arr[i]>arr[j]){
                tmp = arr[i];
                arr[i] = arr[j];
                arr[j] = tmp;
            }
        }
    }
}

//快速排序
void quick_sort(int *arr,int start,int end){
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

void Quick_Sort(int *arr, int begin, int end){
    if(begin > end)
        return;
    int tmp = arr[begin];
    int i = begin;
    int j = end;
    while(i != j){
        while(arr[j] >= tmp && j > i)
            j--;
        while(arr[i] <= tmp && j > i)
            i++;
        if(j > i){
            int t = arr[i];
            arr[i] = arr[j];
            arr[j] = t;
        }
    }
    arr[begin] = arr[i];
    arr[i] = tmp;
    Quick_Sort(arr, begin, i-1);
    Quick_Sort(arr, i+1, end);
}

int main(void){

    std::vector<int> vt;
    vt.push_back(2);
    vt.push_back(12);
    vt.push_back(200);
    vt.push_back(24);
    vt.push_back(32);
    vt.push_back(902);
    vt.push_back(702);
    std::vector<int>::iterator it;
    // for(it=vt.begin();it!=vt.end();++it){
    //     std::cout << *it << std::endl;
    // }
    int arr[10]={100,3,50,900,60,70,30,190,600,340};
    //bubble_sort(arr,sizeof(arr)/sizeof(arr[0]));
    // maopao(arr,sizeof(arr)/sizeof(arr[0]));
    // quick_sort(arr,0,9);
    // Quick_Sort(arr,0,9);
    // xuan(arr,10);
    quick(arr,0,9);
    for(int i = 0;i<10;i++){
        std::cout << arr[i] << std::endl;
    }

    return 0;
}