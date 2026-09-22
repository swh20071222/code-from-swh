#include<stdio.h>
#include<string.h>
#include <time.h>
int main(void)
{  
    int a=0,b=0,c=0;
    char number[20];
    printf("please input the number to gain the ticket\n");
    
    while(1){
        scanf("%19s",number);
    if (strcmp(number, "001") == 0)
    {
        a++;
        printf("Item     Count.  Pri. \n");
        printf  (    "----------------- \n");
        printf( " Cola     %d   %.2f\n",a,3.5*a );
        
    }
    else if(strcmp(number, "002") == 0)
    {
        b++;
        printf("Item     Count.  Pri. \n");
        printf  (    "----------------- \n");
       printf( " Lollipop     %d   %.2f\n",b,0.5*b );
        
    }
    else if(strcmp(number, "003") == 0)
    {
        c++;
        printf("Item     Count.  Pri. \n");
  printf  (    "----------------- \n");
  printf( " Noodles     %d   %.2f\n",c,6.0*c );
        
    }
    else if(strcmp(number, "-001") == 0)
    {
        a--;
        printf("Item     Count.  Pri. \n");
  printf  (    "----------------- \n");
  printf( " Cola     %d   %.2f\n",a,3.5*a );
        
    }
    else if(strcmp(number, "-002") == 0)
    {
        b--;
        printf("Item     Count.  Pri. \n");
        printf  (    "----------------- \n");
       printf( " Lollipop     %d   %.2f\n",b,0.5*b );
        
    }
    else if(strcmp(number, "-003") == 0)
    {
        c--;
        printf("Item     Count.  Pri. \n");
  printf  (    "----------------- \n");
  printf( " Noodles     %d   %.2f\n",c,6.0*c );
       
        
    }   //完成扫描条码输出价格
    
    
  
  if(strcmp(number,"print")==0)
  {
  printf("Item     Count.  Pri. \n");
  printf  (    "----------------- \n");
  printf( " Cola     %d   %.2f\n",a,3.5*a );
  printf( " Lollipop     %d   %.2f\n",b,0.5*b );
  printf( " Noodles     %d   %.2f\n",c,6.0*c ); //打印账单
  
  

  }
  else if(strcmp(number,"drop")==0)
    {
        a=0;b=0;c=0;
        break; //清零
     }
   else if(strcmp(number,"checkout")==0)
   { 
  printf("Item     Count.  Pri. \n");
  printf  (    "----------------- \n");
  printf( " Cola     %d   %.2f\n",a,3.5*a );
  printf( " Lollipop     %d   %.2f\n",b,0.5*b );
  printf( " Noodles     %d   %.2f\n",c,6.0*c );
  time_t now = time(NULL);//调用时间

  struct bill 
     {
        char time[100];
        float Ament;
        int cola;
        int Lollipop;
        int Noodles;
     }first;
     strftime(first.time, sizeof(first.time),
             "%Y-%m-%d_%H-%M-%S", localtime(&now));//把具体到分钟的时间存到结构中
     first .  cola =a;
     first. Lollipop =b;
     first . Noodles =c;
     first. Ament =3.5*a+0.5*b+6.0*c;
     char filename [100];
     char filetime [100];
     strftime(filetime, sizeof(filename),
             "%Y-%m-%d", localtime(&now));//把具体到天的时间存到filetime中，便于写文件名
     snprintf(filename, sizeof(filename),
             "C:/Users/15388/Desktop/data_%s.txt", first.time);//将文件名“浓缩”到filename中
    
  FILE *fp = fopen(filename, "at");
            
            if (fp == NULL) // 打开失败
                {
                    
                printf("please check the content\n");
            } 
            else
            
      {
        fprintf(fp,"No.   Time      Items              Ament\n ");
        fprintf(fp,"-------------------------------------------\n");
        fprintf(fp,"1,    %s,      colla,%d\n",first . time,first.cola);
        fprintf(fp,"                 Lollipop,%d\n",first.Lollipop);
        fprintf(fp,"                 Noodles,%d,       %.2f\n",first.Noodles,first. Ament);
        fclose(fp);
      }
  a=0;b=0;c=0;
 
  
  

   }

}
}



























