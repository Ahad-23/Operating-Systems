#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include<fcntl.h>
char buffer[2048];
void copy(int old,int new)
{
int count;
count=read(old,buffer,sizeof(buffer));
//while(count>0)
write(new,buffer,count);
}
void main(int argc,char *argv[])
{
int fdold,fdnew;
if(argc!=3)
{
printf("need 2 arguments for copy program\n");
exit(1);
}
fdold=open(argv[1],O_RDONLY);
if(fdold==-1)
{
printf("cannot open file %s\n",argv[1]);
exit(1);
}

fdnew=creat(argv[2],0666);
if(fdnew==-1)
{
printf("Cannot create file %s\n",argv[2]);
exit(1);
}
copy(fdold,fdnew);
printf("File copied successfully");
close(fdold);
close(fdnew);
exit(0);
}