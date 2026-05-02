#include <stdio.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <sys/types.h>
#include <unistd.h>

#define SHMSZ 27

int main() {
  char c;
  int shmid;
  key_t key;
  char *shm, *s;

  /*
   * We'll name our shared memory segment
   * "5678".
   */
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
   * Now read what the server put in the memory.
   */
  for (s = shm; *s != 0; s++) {
    putchar(*s);
  }

  putchar('\n');

  /*
   * Finally, change the first character of the
   * segment to '*', indicating we have read
   * the segment.
   */
  *shm = '*';

  return 0;
}