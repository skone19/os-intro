#include "common.h"
int main()
{
 int readfd;
 int n;
 /*clock_t tst,tfin;
   tst=time(0); tfin=time(0);*/
 char buff[MAX_BUFF];
 printf("FIFO Server...\n");

if(mknod(FIFO_NAME, S_IFIFO | 0666, 0) < 0)
{
fprintf(stderr, "%s: Невозможно создать FIFO (%s)\n",__FILE__, strerror(errno));
exit(-1);
}
if((readfd = open(FIFO_NAME, O_RDONLY)) < 0)
{
fprintf(stderr, "%s: Невозможно открыть FIFO (%s)\n",__FILE__, strerror(errno));
exit(-2);
}
 clock_t now=time(NULL), start=time(NULL);
 while (now-start<30)
  {
   while((n =read(readfd, buff, MAX_BUFF)) > 0)
  {
    if(write(1, buff, n)!=n)
     {
     fprintf(stderr, "%s: Ошибка вывода (%s)\n",__FILE__, strerror(errno));
    exit(-3);
    }
 }
 now=time(NULL );
 }
 /*int t=tfin-tst;
while(t<30)
{
tfin=time(0);
 t=tfin-tst;
while((n =fread(readfd, buff, MAX_BUFF)) > 0)
{

if(t>=30)
{
  fprintf("Ошибка,время ожидания сервера истекло\n",__FILE__, strerror(errno));exit(0);
}
if(fwrite(1, buff, n)!=n)
{
fprintf(stderr, "%s: Ошибка вывода (%s)\n",__FILE__, strerror(errno));
exit(-3);
}
 }
 now=time(NULL );
 sleep(6);
tfin=time(0); t=tfin-tst;
}
pclose(readfd);*/
printf("\n----\nserver timeout\n%u секунда прошла  время истекло!!!\n-----\n", now-start);
if(unlink(FIFO_NAME) < 0)
{
fprintf(stderr, "%s: Невозможно удалить FIFO (%s)\n",__FILE__, strerror(errno));
exit(-4);
}
 exit(0);
}
