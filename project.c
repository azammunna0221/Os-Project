#include<stdio.h>
int main()
{
    int n,i,j,min,temp;
    int pr[10]={1,2,3,4,5,6,7,8,9,0};
    int b_t[10],ar_t[10],wa_t[10],ta_t[10],ta=0,sum=0,k=1,btime=0;
    float w_avg=0, t_avg=0,t_sum=0,w_sum=0;
    printf("______PROJECT 3________ \n\n");
    printf("\n Enter No of Process:- ");
    scanf("%d", &n);

    for(i=0;i<n;i++)
    {
        printf("\t Enter burst time p%d:- ",i+1);
        scanf("%d",&b_t[i]);
        printf("\t Enter arrival time p%d:- ",i+1);
        scanf("%d",&ar_t[i]);
    }



    for(i=0; i<n; i++)
    {
        for (j=0; j<n; j++)
        {
            if(ar_t[i]<ar_t[j])
            {
                temp=pr[j];
                pr[j]=pr[i];
                pr[i]=temp;
                temp=ar_t[j];
                ar_t[j]=ar_t[i];
                ar_t[i]=temp;
                temp=b_t[j];
                b_t[j]=b_t[i];
                b_t[i]=temp;
            }
        }
    }

   for(j=0;j<n;j++)
   {
       btime=btime+b_t[j];
       min=b_t[k];
       for(i=k ; i<n; i++)
       {
           if(btime>=ar_t[i] && b_t[i]<min)
           {
               temp=pr[k];
               pr[k]=pr[i];
               pr[i]=temp;
               temp=ar_t[k];
               ar_t[k]=ar_t[i];
               ar_t[i]=temp;
               temp=b_t[k];
               b_t[k]=b_t[i];
               b_t[i]=temp;
           }
       }
       k++;
   }
   wa_t[0]=0;
   for(i=1; i<n; i++)
   {
       sum=sum+b_t[i-1];
       wa_t[i]=sum-ar_t[i];
       w_sum=w_sum+wa_t[i];
   }

   w_avg=(w_sum/n);
   for(i=0;i<n;i++)
   {
       ta=ta+b_t[i];
       ta_t[i]=ta-ar_t[i];
       t_sum=t_sum+ta_t[i];
   }
   t_avg=(t_sum/n);
   printf("\n RESULT:- ");
   printf("\nprocess\t Arrival_t\t Burst\t Turn-around\t Waiting-time" );
   for(i=0; i<n; i++)
   {
       printf("\n p%d\t %d\t\t %d\t %d\t\t%d",pr[i],ar_t[i],b_t[i],ta_t[i],wa_t[i]);
   }
   printf("\n\nAverage watting time: %f",w_avg);
   printf("\nAverage turn_around time: %f",t_avg);
}
