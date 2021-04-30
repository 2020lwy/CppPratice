/*
 * 排序算法演示
 * */
#include <stdio.h>
//快速排序函数
void quick_sort(int *p_val, int size) {
    int base = *p_val, tmp = 0;
    int *p_start = p_val, *p_end = p_val + size - 1;
    if (size <= 1) {
        return ;
    }
    while (p_start < p_end) {
        //调整选定数字和另外一个数字
        //之间的顺序
        if (*p_start > *p_end) {
            tmp = *p_start;
            *p_start = *p_end;
            *p_end = tmp;
        }
        //把非选定数字排除在外
        if (*p_start == base) {
            p_end--;
        }
        else {
            p_start++;
        }
    }
    //递归调用quick_sort函数对左半边
    //数字进行排序
    quick_sort(p_val, p_start - p_val);
    //递归调用quick_sort函数对右半边
    //数字进行排序
    quick_sort(p_start + 1, size - (p_start - p_val) - 1);
}
//插入排序函数
void insert_sort(int *p_val, int size) {
    int num = 0, num1 = 0, tmp = 0;
    for (num = 1;num <= size - 1;num++) {
        //每次把下标为num存储区里的数字插入到前面合适的位置上
        for (num1 = num - 1;num1 >= 0;num1--) {
            //每次把下标为num1和num1 + 1的存储区内容做顺序调整
            if (*(p_val + num1) > *(p_val + num1 + 1)) {
                tmp = *(p_val + num1);
                *(p_val + num1) = *(p_val + num1 + 1);
                *(p_val + num1 + 1) = tmp;
            }
            else {
                break;
            }
        }
    }
}
//选择排序函数
void choice_sort(int *p_val, int size) {
    int num = 0, num1 = 0, tmp = 0;
    for (num = size - 1;num >= 1;num--) {
        //每次循环把合适的数字放在下标为num的存储区里
        for (num1 = 0;num1 <= num - 1;num1++) {
            //每次循环的时候把下标为num1和num的存储区内容做顺序调整
            if (*(p_val + num1) > *(p_val + num)) {
                tmp = *(p_val + num1);
                *(p_val + num1) = *(p_val + num);
                *(p_val + num) = tmp;
            }
        }
    }
}
//冒泡排序函数
void bubble_sort(int *p_val, int size) {
    int num = 0, num1 = 0, tmp = 0;
    for (num = size - 1;num >= 1;num--) {
        //每次循环把合适的数字放在下标为num的存储区里
        for (num1 = 0;num1 <= num - 1;num1++) {
            //每次循环把下标为num1和num1 + 1这两个存储区里的内容做顺序调整
            if (*(p_val + num1) > *(p_val + num1 + 1)) {
                tmp = *(p_val + num1);
                *(p_val + num1) = *(p_val + num1 + 1);
                *(p_val + num1 + 1) = tmp;
            }
        }
    }
}

int main() {
    int arr[] = {40, 80, 50, 30, 60, 20, 10};
    int num = 0;
    //bubble_sort(arr, 7);
    //choice_sort(arr, 7);
    //insert_sort(arr, 7);
    quick_sort(arr, 7);
    for (num = 0;num <= 6;num++) {
        printf("%d ", arr[num]);
    }
    printf("\n");
    return 0;
}







