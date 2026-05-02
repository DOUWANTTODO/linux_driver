#include <stdio.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#include <sys/types.h>
#include <unistd.h>

#define MSG_KEY 7676
#define MSG_SIZE 26

typedef struct tMsgBuf {
  long mtype;
  char mtext[MSG_SIZE];
} tMessageBuffer;

// typedef struct tMsgBuf tMessageBuffer;

void main() {
  tMessageBuffer sndmsg = {0};
  tMessageBuffer recvmsg = {0};
  int msqid;
  int k = 0;

  sndmsg.mtype = 7878;

  for (char i = 'a'; k < MSG_SIZE; i++) {
    sndmsg.mtext[k++] = i;
  }

  msqid = msgget(MSG_KEY, 0666 | IPC_CREAT);
  msgsnd(msqid, &sndmsg, MSG_SIZE, 0);
  msgrcv(msqid, &recvmsg, MSG_SIZE, 0, 0);
  printf("mtype %ld\n", recvmsg.mtype);
  for (int i = 0; i < MSG_SIZE; i++) {
    printf("%c", recvmsg.mtext[i]);
  }
  msgctl(msqid, IPC_RMID, NULL);
}