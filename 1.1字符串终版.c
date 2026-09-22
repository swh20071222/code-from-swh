

#include <stdio.h>
#include <string.h>
int main(void)
{ 
    char number[20]; //定义变量
while (1)           //死循环
    { 
    
    printf("please input the number or input the prices to gain all information\n");
    printf("please input exit or quit to stop the machine\n");//提示信息
    scanf("%19s", number);   // 输入字符串
    if(strcmp(number,"exit")==0||strcmp(number,"quit")==0)
        {
            break;
        }                                                    //手动退出
    else if (strcmp(number, "001") == 0)
    {
       printf("Cola     3.50\n");
    }
    else if (strcmp(number, "002") == 0)
    {
       printf("Lollipop 0.50\n");
    }
    else if (strcmp(number, "003") == 0)
    {
       printf("Noodles  6.00\n");
    }
    else if (strcmp(number, "prices") == 0)
    {
        printf("Item      No.    Pri.\n");
        printf("-----------------\n");
        printf("Cola      001    3.50\n");
        printf("Lollipop  002    0.50\n");
        printf("Noodles   003    6.00\n");              //计价判断
    }
    else
    {
        printf("ERROR: could not found\n");
    }                                                  //报错语句
     }    

    return 0;
}