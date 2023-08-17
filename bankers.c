#include<stdio.h>
int main()
{
int n, m, i, j, k, y, ind=0;

printf("\n Enter the number of processes: \n");
scanf("%d", &n);
printf("\n Enter the number of resources: \n");
scanf("%d", &m);
int alloc[n][m], max[n][m], avail[n], need[n][m];

printf("\n Enter the Allocation Matrix: \n");
for(i=0; i<n; i++)
{
  for(j=0; j<m; j++)
  {
    scanf("%d", &alloc[i][j]);
  }
}

printf("\n Enter the Maximum Matrix:\n ");
for(i=0; i<n; i++)
{
  for(j=0; j<m; j++)
  {
    scanf("%d", &max[i][j]);
  }
}

printf("\n Enter the Available Matrix: \n");
for(i=0; i<m; i++)
{
    scanf("%d", &avail[i]);
}

for(i=0; i<n; i++)
{
  for(j=0; j<m; j++)
  {
    need[i][j] = max[i][j] - alloc[i][j];
  }
}

printf("\n Need Matrix is:\n");
for(i=0; i<n; i++)
{ 
  printf("\n");
  for(j=0; j<m; j++)
  {
    printf("\t%d\t", need[i][j]);
  }
}

int   finish[n], safesequence[n], work[m];

for(i =0;i<m; i++)
{
  work[i] = avail[i];
}
for(i =0;i<n; i++)
{
  finish[i] = 0;
}

for( k =0; k<n; k++)
{
  for(i=0; i<n; i++)
  {
    if( finish[i] == 0)
    {
      int flag = 0;
      for(j =0; j< m; j++)
      { 
        if(need[i][j] > work[j] )
        {
        flag = 1;
          break;
        }
      }
      if(flag == 0)
      {
        safesequence[ind++] = i;
        for(y=0; y<m; y++)
        {
          work[y] += alloc[i][y];
          
        }
        finish[i] = 1; 
        
      }
      
    }
  }
  

}
 
 printf("\n The Safe Sequence is: \n");
  for(i=0; i<=n-1 ; i++)
  {
    printf("P%d\t", safesequence[i]);
  }

return 0;
}
