#include "common.h"
#define MESSAGE "Hello Server!!!\n"
int main()
{
int writefd;
int msglen;
printf("FIFO Client...\n");
if((writefd = open(FIFO_NAME, O_WRONLY)) < 0)
{
fprintf(stderr, "%s: Невозможно открыть FIFO (%s)\n",__FILE__,strerror(errno));
exit(-1);
}
msglen = strlen(MESSAGE);

if(write(writefd, MESSAGE, msglen) != msglen)
{
fprintf(stderr, "%s: Ошибка записи в FIFO (%s)\n",__FILE__, strerror(errno));
exit(-2);
}
close(writefd);
/*FILE *writfd; writfd=fopen(FIFO_NAME, "a");
int k=0;
while(k!=2)
{
k++; sleep(5);int m=time(0); int h=m/3600; int min=m%3600; int s=m%3600%60;
fprint(writfd, "Current time:%d:%d:%d\n", h, min, s);
}*/
exit(0);
}
