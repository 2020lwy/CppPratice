#include <iostream>
#include <string>
#include <cstring>

void change(char *str){
    if(str==NULL)
        return;
    char tmp;
    int len = strlen(str);
    for(int i = 0;i<len/2;i++){
        tmp = str[i];
        str[i]=str[len-1-i];
        str[len-1-i]=tmp;
    }
}


int mystrcmp(char *str1,char *str2){
    if(str1==NULL||str2==NULL)
        return 100;
    while(*str1!='\0'&&*str2!='\0'&&*str1==*str2){
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
    char str1[]="hello guangzhou";
    char str2[]="hello shenzhen";
    if(mystrcmp(str1,str2)==1){
        std::cout << "相同" << std::endl;
    }
    if(mystrcmp(str1,str2)==0){
        std::cout << "不相同" << std::endl;
    }
    change(str1);
    std::cout << str1 << std::endl;
    return 0;
}