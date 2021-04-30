#include <iostream>

int main(void){

    union Test{
        unsigned int a;
        unsigned char buf[4]={0};
    };
    Test tt;
    tt.a = 0x12345678;
    int s_len = sizeof(tt);
    printf("s_len = %d\n",s_len);
    for(int i=0;i<4;i++){
        printf("0x%2X  ",tt.buf[i]);
    }
    printf("\n");
    return 0;
}
