#include<stdio.h>
#include<string.h>
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
        
    }
    else if(strcmp(number, "002") == 0)
    {
        b++;
        
    }
    else if(strcmp(number, "003") == 0)
    {
        c++;
        
    }
    else if(strcmp(number, "-001") == 0)
    {
        a--;
        
    }
    else if(strcmp(number, "-002") == 0)
    {
        b--;
        
    }
    else if(strcmp(number, "-003") == 0)
    {
        c--;
        
    }
    
    
  printf("Item     Count.  Pri. \n");
  printf  (    "----------------- \n");
  printf( " Cola     %d   %.2f\n",a,3.5*a );
  printf( " Cola     %d   %.2f\n",b,0.5*b );
  printf( " Cola     %d   %.2f\n",c,6.0*c );
  if(strcmp(number,"print")==0)
  {
  printf("Item     Count.  Pri. \n");
  printf  (    "----------------- \n");
  printf( " Cola     %d   %.2f\n",a,3.5*a );
  printf( " Lollipop     %d   %.2f\n",b,0.5*b );
  printf( " noodles     %d   %.2f\n",c,6.0*c );
  
  

  }
  else if(strcmp(number,"drop")==0)
    {
        a=0;b=0;c=0;
        break;
     }
   else if(strcmp(number,"checkout")==0)
   { 
  printf("Item     Count.  Pri. \n");
  printf  (    "----------------- \n");
  printf( " Cola     %d   %.2f\n",a,3.5*a );
  printf( " Lollipop     %d   %.2f\n",b,0.5*b );
  printf( " noodles     %d   %.2f\n",c,6.0*c );
  a=0;b=0;c=0;
  break;
  

   }
}
}
    






























