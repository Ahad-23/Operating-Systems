#include<stdio.h>

int leastrecentlyused(int queue[], int n)
{
int i, minimum = queue[0], pos = 0;
for(i = 1; i < n; ++i)
{
if(queue[i] < minimum)
{
minimum = queue[i];
pos = i;
}
}
return pos;//reutrns the postions of the least recently used
}
int main()
{
int frameno, pageno, frames[10], pages[30], counter = 0, queue[10],
flag1, flag2, i, j, pos, faults = 0;
printf("Enter number of frames: ");
scanf("%d", &frameno);
printf("Enter number of pages: ");
scanf("%d", &pageno);
printf("Enter reference string: ");
for(i = 0; i < pageno; ++i)
scanf("%d", &pages[i]);
for(i = 0; i < frameno; ++i)
frames[i] = -1;
for(i = 0; i < pageno; ++i)
{
flag1 = flag2 = 0;
for(j = 0; j < frameno; ++j)
{
if(frames[j] == pages[i])
{
counter++;
queue[j] = counter;
flag1 = flag2 = 1;
break;
}
}

if(flag1 == 0)
{
for(j = 0; j < frameno; ++j)
{
if(frames[j] == -1)
{

counter++;
faults++;
frames[j] = pages[i];
queue[j] = counter;
flag2 = 1;
break;
}
}
}
if(flag2 == 0)
{
pos = leastrecentlyused(queue, frameno);
counter++;
faults++;
frames[pos] = pages[i];
queue[pos] = counter;
}
}
printf("Total Page Faults = %d", faults);
return 0;
}