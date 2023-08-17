#include<stdio.h>
#include<stdlib.h>

int main()
{
  int  psize[10], bsize[10], pno, bno, flags[10], i, j, allocation[10];
  
    for(i =0; i < 10; i++)
  {
    flags[i] = 0;
    allocation[i] = -1;
  }
  
  printf("\nEnter the number of Blocks: \n");
  scanf("%d", &bno);
  printf("\nEnter the Block size: \n");
  for(i=0; i<bno; i++)
  {
    scanf("%d", &bsize[i]);
  }
  
    printf("\nEnter the number of Processes: \n");
  scanf("%d", &pno);
  printf("\nEnter the Process size: \n");
  for(i=0; i<pno; i++)
  {
    scanf("%d", &psize[i]);
  }
  

  
  for(i=0; i< pno; i++)
  {
    for(j=0; j< bno; j++)
    {
      if(bsize[j] >= psize[i])
      {
        allocation[i] = j;
        bsize [j] -= psize[i];
        break;
      }
    }
  }
  
  printf("\n\tProcess Number\tProcess size\tBlock Number\n");
  for(i=0; i<pno; i++)
  {
    printf("\t\t%d\t\t%d\t", i+1, psize[i]);
    if(allocation[i] != -1)
    {
      printf("%d\n",allocation[i] + 1);
    }
    else
      printf("Not Allocated\n");
  }
  
}
