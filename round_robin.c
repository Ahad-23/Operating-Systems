#include<stdio.h>
#include<string.h>
#include<stdbool.h>

int main()
{
int no[10]={0,1,2,3,4,5,6,7,8,9};
int at[10];
int bt[10];
int wt[10];
int ct[10];
int tt[10];
int at1[10];
int bt1[10];
int btsum = 0;
double avgt = 0.0;
double avgw = 0.0;
int i,j;
int n;
//input;
printf("Enter the number of processes (Max 10) : \n");
scanf("%d",&n);
for(i = 0 ; i < n ; i++)
{
printf("Enter Arrival Time of process P%d :\n" , (i));
scanf("%d" , &at[i]);
at1[i] = at[i];
printf("Enter Burst Time of process P%d :\n" , (i));
scanf("%d" , &bt[i]);
bt1[i] = bt[i];
}
printf("\nEnter the time quantum :\n");
int tq;
scanf("%d",&tq);
//display
printf("The data entered is: \n");
printf("Ps = Process , AT = Arrival Time , BT = Burst Time: \n\n");
printf("Ps\tAT\tBT\t\n");
for(i = 0 ; i < n ; i++)
{

printf("P%d\t%d\t",i,at[i]);
printf("%d\t\n",bt[i]);
btsum = btsum + bt[i];
}
int sum = 0;
//gantt chart
printf("Gantt Chart is :\n");
printf("\n");
printf(" 0");
i = 0;
bool done;
while(1)
{
done = true;
for(i = 0; i<n ;i++)
{
if(bt1[i]>0)
{
done = false;

printf("| P%d ",no[i]);
if(bt1[i] > tq)
{
sum = sum+tq;
bt1[i] = bt1[i] - tq;
}
else
{
sum = sum+bt1[i];
ct[i]= sum;
tt[i] = ct[i] - at1[i];
wt[i] = tt[i] - bt[i];
bt1[i] = 0;
}
printf("|%d",sum);
}
}
if(done==true)
{
break;

}}

printf("\n\nThe final result is : \n");
printf("Ps = Process , AT = Arrival Time , BT = Burst Time, CT = Completion Time, TT =TurnAround Time, WT = Waiting Time\n\n");
printf("Ps\tAT\tBT\tCT\tTT\tWT\t\n");
for(i = 0 ; i < n ; i++)
{
printf("P%d\t%d\t",i,at[i]);
printf("%d\t",bt[i]);
printf("%d\t",ct[i]);
printf("%d\t",tt[i]);
printf("%d\t\n",wt[i]);
avgw = avgw+(wt[i]);
avgt = avgt+(tt[i]);
}
avgw = avgw/n;
avgt = avgt/n;
printf("Average Waiting Time = %f\n", avgw);
printf("Average TurnAround Time = %f\n", avgt);
}