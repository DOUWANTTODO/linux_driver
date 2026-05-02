#include <stdio.h>
#include <stdlib.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <sys/types.h>
#include <time.h>
#include <unistd.h>

#define SHMSZ 27

int main() {
  char c;
  int shmid;
  key_t key;
  char *shm, *s;
  // 設置隨機數種子
  srand(time(NULL));

  // 產生 0 到 RAND_MAX 之間的隨機數
  int random_num = rand();

  key = 1234;

  /*
   * Create the segment.
   */
  if ((shmid = shmget(key, SHMSZ, IPC_CREAT | 0666)) < 0) {
    perror("shmget");
    return 0;
  }

  /*
   * Now we attach the segment to our data space.
   */
  if ((shm = shmat(shmid, NULL, 0)) == (char *)-1) {
    perror("shmat");
    return 0;
  }

  /*
   * Now put some things into the memory for the
   * other process to read.
   */
  s = shm;

  for (c = 'a'; c <= 'z'; c++) {
    *s++ = c;
    printf("%c", *s);
  }

  /*
   * Finally, we wait until the other process
   * changes the first character of our memory
   * to '*', indicating that it has read what
   * we put there.
   */
  while (*shm != '*') {
    sleep(1);
  }

  shmctl(shmid, IPC_RMID, 0);

  return 0;
}