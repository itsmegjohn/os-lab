#include<stdio.h>

int main()
{
  int i, j, n, time, remain, flag = 0;
  int at[10], bt[10], rt[10], ts, twt=0, ttat = 0;
  printf("Enter the No. of Processes: ");
  scanf("%d", &n);
  remain = n;
  for(i=0; i<n; i++)
  {
    printf("Enter the arrival time and Burst time of process P%d:\n", i+1);
    scanf("%d", &at[i]);
    scanf("%d", &bt[i]);
    rt[i] = bt[i];
  }
  printf("Enter the Time Slice:\n");
  scanf("%d", &ts);
  
  for(time=0, i=0; remain != 0;)
  {
  if (rt[i] <= ts && rt[i] >0 )
  {
    time += rt[i];
    rt[i] = 0;
    flag =1;
  }
  else if(rt[i] > 0)
  {
    rt[i] -= ts;
    time += ts;
  }
  if(rt[i] == 0 && flag == 1)
  {
    remain--;
    twt += time - at[i] - bt[i];
    ttat += time - at[i];
    flag = 0;
  }
  if( i == n-1)
    i = 0;
  else if(at[i+1]<=time)
    i++;
  else
    i = 0;
      
  }
  printf("Total waiting Time: %d\n", twt);
  printf("Total Turn Around Time: %d\n", ttat);
  printf("Average waiting Time: %d\n", twt/n);
  printf("Average Turn Around Time: %d\n", ttat/n);
  
}
