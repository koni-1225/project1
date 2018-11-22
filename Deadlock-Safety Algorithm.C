#include<stdio.h>
int main()
{
int alloc[10][10],max[20][20],need[20][20],available[20],work[20],i,p,j,np, flag=0,k,process,nr;
char finish[10];

printf("enter the no of processes");
scanf("%d",&np);
printf("enter the no of resourses types");
scanf("%d",&nr);

printf("enter the no of resources allocated to each process");
for(i=0;i<np;i++)
  {
    for(j=0;j<nr;j++)

       scanf("%d",&alloc[i][j]);

   }
printf("enter the maximum demand of each process");
for(i=0;i<np;i++)
  {
   for(j=0;j<nr;j++)

      scanf("%d",&max[i][j]);

  }

printf(" the generated need matrix is:");

for(i=0;i<np;i++)
{
   printf("\n");
  for(j=0;j<nr;j++)
    {
      need[i][j]=max[i][j]-alloc[i][j];
      printf("%d\t",need[i][j]);
    }
printf("\t \t");
}

printf("The available matrix is:");
for(i=0;i<nr;i++)

 scanf("%d",&available[i]);

for(i=0;i<np;i++)
  {
 finish[i]='f';
  }
for(i=0;i<np;i++)

work[i]=available[i];

printf("safe sequence is");
for(i=0;i<np;i++)
    {
for(j=0;j<nr;j++)
      {
if(finish[i]=='f' && need[i][j]<=work[j])
    {
     p=i;
     printf("p%d",p);
     work[j]=work[j]+alloc[i][j];
      finish[i]='t';
      i=-1;
      continue;
    }
    else
     {
       break;
     }
    }
  }
for(i=0;i<np;i++)
{
if(finish[i]=='f')

  flag=1;

else

  flag=0;

}
if(flag==1)

  printf("System is in safe state");

else

printf("system is not in safe state");


}
