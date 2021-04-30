/*
 * 查找算法演示
 * */
#include <stdio.h>
//折半查找函数
int *half_search(const int *p_val, int size, int val) {
    const int *p_start = p_val, *p_end = p_val + size - 1, *p_mid = NULL;
    while (p_start <= p_end) {
        p_mid = p_start + (p_end - p_start + 1) / 2;
        if (*p_mid == val) {
            return (int *)p_mid;
        }
        else if (*p_mid > val) {
            p_end = p_mid - 1;
        }
        else {
            p_start = p_mid + 1;
        }
    }
    return NULL;
}
int main() {
    int arr[] = {10, 20, 30, 40, 50, 60, 70, 80, 90, 100};
    int *p_val = half_search(arr, 10, 80);
    if (p_val) {
        printf("找到的数字是%d\n", *p_val);
    }
    return 0;
}






