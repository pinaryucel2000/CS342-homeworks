#include <stdlib.h>
#include <mqueue.h>
#include <stdio.h>
#include <unistd.h>
#include <errno.h>
#include <string.h>
#include "shareddefs.h"
int main()
{
mqd_t mq;
struct item item;
int n;
mq = mq_open(MQNAME, O_RDWR | O_CREAT, 0666, NULL);
if (mq == -1)
{
perror("mq_open failed\n");
exit(1);
}
strcpy(item.astr, "I hear and I forget. I see and I remember. I do and I understand.");
n = mq_send(mq, (char *) &item, sizeof(struct item), 0);
if (n == -1)
{
perror("mq_send failed\n");
exit(1);
}
mq_close(mq);
return 0;
}

