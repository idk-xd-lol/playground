#include <unistd.h>
#include <stdio.h>
#include <signal.h>
#include <stdlib.h>

int getoption();
void timer(int start_time);
int s = 0;

int main()
{
  printf("Select an option:\n1 - Start New Timer\n2 - Continue Timer\n");
  int opt = getoption();
  int time = 0;
  if (opt == 0){
    printf("wrong option, existing");
    return 0;
  }
  printf("\033[H\033[J");
  if (opt == 1)
    timer(time);
  else if(opt == 2)
  {
    FILE *fptr = fopen("time.txt", "r");
    if (fptr == NULL)
    {
      fptr = fopen("time.txt", "w");
      fprintf(fptr, "0");
      fclose(fptr);
      fptr = fopen("time.txt", "r");
    }
    fscanf(fptr, "%d", &time);
    fclose(fptr);
    timer(time);
  }
}

int getoption()
{
  int c = 0;
  c = getchar();
  if (c == '1')
    return 1;
  else if (c == '2')
    return 2;
  else
   return 0;
}

void save(int sig)
{
  FILE *fptr;
  fptr = fopen("time.txt", "w");
  fprintf(fptr, "%d", s);
  fclose(fptr);
  exit(0);
}

void timer(int start_time)
{
  s = start_time;
  int m = 0; 
  int h = 0;
  signal(SIGINT, save);
  while (1)
  {
    m = s / 60;
    h = m / 60;
    printf("\rTime: %02d:%02d:%02d", h, (m % 60), (s++ % 60));
    fflush(stdout);
    sleep(1);
  }
}
