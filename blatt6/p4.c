#include <stdio.h>


int main (int argc, char * argv[])
{
int a  = 10;
int b = 0;
int select = 0;
printf("a = %d , b = %d\n",a,b);
printf("(1):= +, (2):= -, (3):= *, (4):= :, (5):= end");
scanf("%d",&select);
while(select != 5){
  scanf("%d",&select);
switch (select) {
  case 1:printf("+ = %d\n",a+b);  break;
  case 2:printf("- = %d\n",a-b);  break;
  case 3:printf("* = %d\n",a*b);  break;
  case 4:  if (b==0){printf("not able to divide by 0!"); break;}else {printf(": = %d\n",a/b);}  break;
  case 5:printf("goodbye\n"); break;
  default : printf("wrong"); break ;
}
}
  return 0;
}
