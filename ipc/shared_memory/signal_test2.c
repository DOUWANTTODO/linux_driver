#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

void sig_handler(int signo);
int main(void) {
  printf("mian is waiting for a signal\n");

  // print preveous sig

  __sighandler_t pre_sig = 0;
  pre_sig = signal(SIGINT, SIG_DFL);
  printf("the previous value of the signal handler is %d\n", (int)pre_sig);
  if (pre_sig == SIG_ERR) {
    perror("signal errror");
    exit(EXIT_FAILURE);
  }
  for (;;)
    ; //有時間讓我們發送信號

  return 0;
}

void sig_handler(int signo) { printf("catch the signal SIGINT %d\n", signo); }