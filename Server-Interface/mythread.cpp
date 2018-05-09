#include "mythread.h"



MyThread::MyThread()
{

}


void MyThread::run()
{
    qDebug() << "hello from worker thread " << thread()->currentThreadId();
    struct sockaddr_in serv_addr, cli_addr;
    int sockfd , portno,clilen , clifd;
    portno = 13300;
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    char testingBuffer[100];
    char isim[5] = "akif";
    int senditem = 10;
    bzero((char *) &serv_addr, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_addr.s_addr = INADDR_ANY;
    serv_addr.sin_port = htons(portno);


    if (bind(sockfd, (struct sockaddr *) &serv_addr,sizeof(serv_addr)) < 0)
        perror("ERROR on binding");

    listen(sockfd,MAXTHREAD);

    clifd = accept(sockfd, (struct sockaddr *) &cli_addr, (socklen_t *) &clilen);





    send(clifd, &isim, sizeof(isim), 0);
    recv(clifd, &testingBuffer, sizeof(testingBuffer) , 0);

    qDebug() << "gelen mesaj" << testingBuffer;



    close(sockfd);
    close(clifd);
}
