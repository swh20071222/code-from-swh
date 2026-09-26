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
     strftime(filetime, sizeof(filetime),
             "%Y-%m-%d", localtime(&now));//把具体到天的时间存到filetime中，便于写文件名
     snprintf(filename, sizeof(filename),
             "C:/Users/15388/Desktop/data_%s.txt", filetime);//将文件名“浓缩”到filename中
    
  FILE *fp = fopen(filename, "at");
            
            if (fp == NULL) // 打开失败
                {
                    
                printf("please check the content\n");
            } 
            else
            
      {
        fprintf(fp,"No.   Time                                               Items               Ament\n ");
        fprintf(fp,"-------------------------------------------\n");
        fprintf(fp,"1,    %s,                   colla,%d\n",first . time,first.cola);
        fprintf(fp,"                                                               Lollipop,%d\n",first.Lollipop);
        fprintf(fp,"                                                               Noodles,%d,       %.2f\n",first.Noodles,first. Ament);
        fclose(fp);
      }
  a=0;b=0;c=0;
 
  }
else if(strcmp(number,"sales")==0)  //先读取sales得到指令
 {  char day[100];//再建立字符串数组用于储存sales后面的日期
    int duqu=getchar();//再向后读取一个字符并赋给duqu
    if(duqu==' ')//读到空格说明用户输入了日期
       {
        scanf("%99s",day);
       }//把日期存储到day数组
    else{
        day[0] = '\0';//没有日期不存储
    }
    if (strlen(day) == 0) //如果没有输入日期
         {
                time_t now = time(NULL);//调取现在时间
                
                strftime(day, sizeof(day), "%Y-%m-%d", localtime(&now));//存储到day中
         }
            char chazhao[100];
            sprintf(chazhao, "C:/Users/15388/Desktop/data_%s.txt", day);//把要查的文件名存储到chazhao中
            FILE *fp = fopen(chazhao, "r");//打开需要的文件
            float jine = 0.0 ;
            float daily = 0.0;
            int hangshu = 0 ;
           if (fp != NULL)
           {
            char hang[200];
        while (fgets(hang, sizeof(hang), fp))//逐行读取文件并存入hang，直到读完结束循环
           {               hangshu++;//每读一行hangshu+1
           printf("%s", hang);//原样打印一天的销售记录
          if (hangshu == 5)//第五行存在总金额
          {
            sscanf(hang, "%*[^,],%*d,%f", &jine);//跳过非逗号字符，逗号，整数，逗号，然后读浮点数
            daily += jine;
            hangshu = 0;
             
           }
           }
        fclose(fp);
        }
        printf("--------------------------------\n");
        printf("Daily: %.2f\n", daily);
}
else if(strcmp(number,"newday")==0)
{
    printf("New day started. Today's sales records cleared.\n");
}//由于已经通过文件名实现了要求3，所以只需要得到命令后给用户一个反馈就可以了

}
}



























