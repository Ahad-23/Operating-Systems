#include <stdio.h>
#include <stdlib.h>
void main()
{
printf("Enter the number of pages \n");
int pagenum;
scanf("%d", &pagenum);
int pages[pagenum];
printf("Enter the pages \n");
for (int i = 0; i < pagenum; i++)
{
scanf("%d", &pages[i]);
}
printf("Enter the frame size \n");
int fsize;
scanf("%d", &fsize);
int frame[fsize];
int pagefault = 0, pagehit = 0;
int count = 0; // to keep track of the current position in the frame
for (int i = 0; i < fsize; i++)
{
frame[i] = -1;
}
for (int i = 0; i < pagenum; i++)
{
int pageFound = 0;
for (int j = 0; j < fsize; j++)
{

if (frame[j] == pages[i])
{
pageFound = 1;
break;
}
}
if (pageFound == 0)
{
frame[count] = pages[i];
count = (count + 1) % fsize;
pagefault++;
}
else
{
pagehit++;
}
}
printf("Pagehit: %d\n", pagehit);
printf("Pagefault: %d\n", pagefault);
}