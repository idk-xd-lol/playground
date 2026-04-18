#include <stdio.h>

int guess(int num, int max);
int main()
{
  int unum;
  scanf("%d", &unum);
  if (!(unum >= 0 && unum <= 100))
  {
    printf("Err: num is larger than 100");
    return 0;
  }
  printf("Your num is: %d\n", guess(unum, 100));
}

int guess(int num, int max)
{
  int unum = num;
  int step = 1;
  int gnum = 50;
  int bigger = max + 1;
  int smaller = 0;
  while(gnum != unum)
  {
    gnum = (bigger + smaller) / 2;
    if (gnum > num)
      bigger = gnum;
    else if (gnum < num)
      smaller = gnum;
    printf("Step %d: %d\n", step, gnum);
    step++;
  }
  return gnum;
}
