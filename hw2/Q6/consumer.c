#include <stdlib.h>
#include <mqueue.h>
#include <stdio.h>
#include <unistd.h>
#include <errno.h>
#include <string.h>
#include "shareddefs.h"
int main()
{ mqd_t mq;
struct mq_attr mq_attr;
struct item *itemptr;
int n;
int buflen;
char *bufptr;
mq = mq_open(MQNAME, O_RDWR | O_CREAT, 0666, NULL);
if (mq == -1)
{
perror("can not create msg queue\n");
exit(1);
}
mq_getattr(mq, &mq_attr);
/* allocate large enough space for the buffer */
buflen = mq_attr.mq_msgsize;
bufptr = (char *) malloc(buflen);
n = mq_receive(mq, (char *) bufptr, buflen, NULL);
if (n == -1)
{
perror("mq_receive failed\n");
exit(1);
}
itemptr = (struct item *) bufptr;
printf("%s\n", itemptr->astr);
free(bufptr);
mq_close(mq);
return 0;
}
