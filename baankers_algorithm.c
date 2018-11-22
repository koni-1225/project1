#include<stdio.h>
#include<stdlib.h>
void safety_alg();
int RR_alg();
void input();
void display();
int available[10], max[10][3], need[10][3], allocation[10][3];
int i, j, nop, nor, count=0,k,ch;
void main()
{

    printf("Enter no. of processes\n");
    scanf("%d", &nop);
    printf("Enter no. of resources\n");
    scanf("%d", &nor);
    printf("\nApplying Banker's Algorithm\n");
    while(1)
    {
        printf("\nenter choice:\n1.Safety Algorithm  2.Resource_Request Algorithm 3.Display 4.Input\t 5.exit\n");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1:
                    safety_alg();
                    break;
            case 2:
                    if(!RR_alg())
                        printf("Not satisfied\n");
                    else
                        safety_alg();
                    break;
            case 3:
                    display();
                    break;
            case 4:
                    input();
                    break;
            default:
                    return;
        }
    }
}
    void safety_alg()
    {
        int count=0;
        int safe[10]={0};
        int finish[10]={0};
        for(i=0;i<nop;i++)
        {
            if(finish[i]==0)
            {
                for(j=0;j<nor;j++)
                {
                    if(need[i][j]>available[j])
                        break;
                }
                if(j==nor)
                {
                    safe[count++]=i;
                    finish[i]=1;
                     for(k=0;k<nor;k++)
                    {
                        available[k]=available[k]+max[i][k]-need[i][k];
                    }
                    i=-1;
                }
            }
        }

        if(count==nop)
        {
            printf("\nSafe State order:\t");
            for(k=0;k<count;k++)
            {
                printf("%d ",safe[k]);
            }
        }
        else
        {
            printf("Unsafe state");
             for(k=0;k<count;k++)
            {
                printf("%d ",safe[k]);
            }
        }
        printf("\n");
    }
    int RR_alg()
    {
        int request[5][10],r;
        printf("Enter process no \n");
        scanf("%d",&r);
        printf("enter requested resources\n");
        for(i=0;i<nor;i++)
        {
            scanf("%d",&request[r][i]);
        }
        for(j=0;j<nor;j++)
        {
            if(request[r][j]>available[j])
                return 0;
        }
        if(j==nor)
        {
            for(i=0;i<nor;i++)
            {
                available[i]-=request[r][i];
                allocation[r][i]+=request[r][i];
                need[r][i]-=request[r][i];
            }
            return 1;
        }
}

    void input()
    {
        printf("Enter Max Resources\n");
        for(i=0;i<nop;i++)
        {
            for(j=0;j<nor;j++)
            {
                scanf("%d", &max[i][j]);
            }
        }
        printf("Enter Allocation Resources\n");
        for(i=0;i<nop;i++)
        {
            for(j=0;j<nor;j++)
            {
                scanf("%d", &allocation[i][j]);
            }
        }
        printf("Enter available resources\n");
        for(i=0;i<nor;i++)
        {
                scanf("%d", &available[i]);
        }
        printf("Need Matrix\n");
        for(i=0;i<nop;i++)
        {

            for(j=0;j<nor;j++)
            {
               need[i][j]=max[i][j]-allocation[i][j];
               printf("%d  ",need[i][j]);
            }
            printf("\n");
        }
    }
    void display()
    {
        printf("Max Matrix\n");
        for(i=0;i<nop;i++)
        {
            for(j=0;j<nor;j++)
            {

               printf("%d  ",max[i][j]);
            }
            printf("\n");
        }
          printf("Allocation Matrix\n");
        for(i=0;i<nop;i++)
        {
            for(j=0;j<nor;j++)
            {

               printf("%d  ",allocation[i][j]);
            }
            printf("\n");
        }
         printf("Need Matrix\n");
        for(i=0;i<nop;i++)
        {

            for(j=0;j<nor;j++)
            {
               need[i][j]=max[i][j]-allocation[i][j];
               printf("%d  ",need[i][j]);
            }
            printf("\n");
        }
        printf("Available Matrices\n");
        for(j=0;j<nor;j++)
        {
            printf("%d ",available[j]);
        }
    }
