#include<stdio.h>

int main()
{
  int i, j, k, frames, pfault = 0, refstr[25], count = 0, miss[10], n;
  
  printf("Enter the length of reference string:\n");
  scanf("%d", &n);
  printf("Enter the Reference string:\n");
  for(i=0; i< n; i++)
    scanf("%d", &refstr[i]);
  printf("Enter the number of frames:\n");
  scanf("%d", &frames);
  
  for(i=0; i<frames;i++)
    miss[i] = -1;
  printf("Page Replacement process is:\n");
  
  for(i=0; i<n;i++)
  {
    for(k=0; k<frames;k++)
    {
      if(miss[k]==refstr[i])
        break;
    }
    if(k == frames)
      {
        miss[count++] = refstr[i];
        pfault++;
      }
    
    for(j=0; j< frames; j++)
      printf("\t%d",miss[j]);

    if(k == frames)
    {
      printf("\tPageF No %d\n", pfault);
    }
    else
      printf("\n");
      
    if(count==frames)
      count = 0;
  }
  
  printf("The Number of Page Faults using FIFO are: %d", pfault );
  
  return 0;
}
