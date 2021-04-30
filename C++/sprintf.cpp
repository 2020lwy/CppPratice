#include <iostream>

int main(void){

    //sprintf
    char str[128]={0};
    int a = 10;
    char *m_str = (char*)"helloguangzhou";
    int s = 900;
    sprintf(str,"%d %s %d",a,m_str,s);  //sprintf函数的使用，将格式化的字符串输入到指定的字符串中
    std::cout << str << std::endl;

    //fprintf
    FILE *fp = fopen("./fprintf.txt","w+");
    if(fp==NULL)
        std::cout << "fopen error" << std::endl;
    fprintf(fp,"%d\n",a);
    fprintf(fp,"%s %d\n",m_str,s);
    fclose(fp);
    system("cat ./fprintf.txt");//fprintf函数的使用，将格式化的字符串输入到指定的文件中

    //sscanf
    int b = 0;
    char *b_str = new char[128];
    int b_s =0;
    sscanf(str,"%d %s %d",&b,b_str,&b_s);
    std::cout << "b = " << b << std::endl;
    std::cout << "b_str " << b_str << std::endl;
    std::cout << "b_s = " << b_s << std::endl; //sscanf函数就是类似于从相应的字符串中读取格式化的数据
    delete [] b_str;
    
    //fscanf     //fscanf函数类似于从相应的文件中读取格式化的数据

    return 0;
}