#include <stdio.h>
int main ()

{  
    char number; char prices;
printf("please input the number or input the prices to gain all information");//提示用户扫码或查询
scanf("%s",& number);//s扫描条码
if(number == 001)
    {
        printf ("Cola     3.50 ");
    }
else if(number == 002)
    {
        printf ("Lollipop 0.50");
    }
 else if(number == 003)
    {
        printf ("noodles  6.00");
    }
else if (number == prices)
    {
    printf("Item      No.    Pri.\n");
    printf("-----------------\n");
    printf("Cola      001    3.50\n");
    printf("Lollipop  002    0.50\n");
    printf("Noodles   003    6.00\n"); //做判断，输出商品价格
    }
else {


    printf("ERROR: could not found");
}    //报错
}

  
