#include <iostream>

char *mystrcpy(char *dest,char *src){
    if(src==NULL||dest==NULL){
        return NULL;
    }
    char *p = dest;
    while((*dest=*src)!='\0'){
        dest++;
        src++;
    }
    return p;
}

int mystrcmp(char *str1,char *str2){
    if(str1==NULL||str2==NULL){
        return 100;
    }
    while(*str1!='\0'&& *str2!='\0'&&*str1==*str2){
        str1++;
        str2++;
    }
    if(*str1==*str2){
        return 1;
    }else{
        return 0;
    }
}

int main(void){
    char h[12]={0};
    char hh[] = "hello";
    std::cout << mystrcpy(h,hh) << std::endl;
    return 0;
}