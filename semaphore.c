#include<stdio.h>
#include<stdlib.h>

int mutex = 1;
int full = 0;
int size;

int empty = 5;
int x=0;

void producer()
{
  -- mutex;
  ++ full;
  -- empty;
  x ++;
  printf("Producer produces item %d", x);
  ++mutex;
  
}

void consumer()
{
  --mutex;
  --  full;
  ++ empty;
  printf("Consumer consumes item %d", x);
  x --;
  ++mutex;
  
  
}

int main()
{
  
  int n, i;
  printf("\n1.Press 1 for Producer \n2.Press 2 for Consumer \n3.Press 3 for Exit");
  for(i=1; i>0; i++)
  {
    printf("\nEnter your choice: ");
    scanf("%d", &n);
    
    switch(n)
    {
      case 1: if((mutex == 1) && (empty != 0))
      {
        producer();
      }
      else
      {
        printf("Buffer is full!\n");
        
      }
      break;
      case 2: if((mutex == 1) && (full !=0 ))
      {
        consumer();
      }
      else
      {
        printf("Buffer is Empty!\n");
        
      }
      break;
      case 3:exit(0);
      break;
    }
  }
  return 0;
}
