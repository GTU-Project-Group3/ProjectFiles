#ifndef MYTHREAD_H
#define MYTHREAD_H

#include <iostream>
#include <cstdio>

#include <sys/types.h>
#include <winsock2.h>
//#include <sys/socket.h>
//#include <netinet/in.h>
#include <stdlib.h>
#include <strings.h>
#include <errno.h>
#include <unistd.h>
#include <pthread.h>
#include <signal.h>
#include <string.h>
#include <fcntl.h>
#include <fstream>
#include <strings.h>
#include <string>
//#include <sys/wait.h>
#include <QDebug>
#include <QThread>
#include <QObject>

#define MAXTHREAD 100

using namespace std;

class MyThread : public QThread
{
    Q_OBJECT
public:
    MyThread();

private:
    void run();
};

#endif // MYTHREAD_H
