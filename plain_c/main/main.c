#include <stdio.h>

void prn_string(char *s)
{
  while(*s!='\0')
  {
    fputc(*s, stdout);
    s++;
  }
}
int main()
{
  char str[80]="Hello World!\n";
  printf("Hello World!\n");
  fflush(stdout);
  prn_string(str);
    return 0;
}
