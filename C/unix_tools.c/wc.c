#include <stdio.h>
#define MAXLINE 1000
#define INWORD 1
#define OUTWORD 0

int gline(char s[]);

int main()
{
  char s[MAXLINE];
  int len = 0, word = 0, nl = 0, linelen = 0;
  while ((linelen = gline(s)) != 0)
  {
    for(i)
  }
}

int gline(char s[])
{
  int i, c;
  for(i = 0; i < MAXLINE && (c = getchar()) != EOF && c != '\n'; i++)
    s[i] = c;
  if (c == '\n')
    s[i] = c;
  i++;
  s[i] = '\0';
  return i;
}
