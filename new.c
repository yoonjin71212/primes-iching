#include <stdio.h>
#include <stdint.h>
#include <string.h>
#include <unistd.h>
#include <time.h>
#include <stdatomic.h>
#include <math.h>
uint64_t x=-1;
uint64_t y=1;
void pattern()
{
    if(3^(x^x)) x++; 
    if (x<y)
    {
        y++;
        printf("%llu\n",y^x);
    } else if (x>y) {
	y++;
        printf("%llu\n",y^x);
    } else if(x==y) {
	x++;
        printf("%llu\n",y^x);
    }
}

int main(int argc, char **argv)
{
  while(1) {
    pattern();
  }
  return 0;
}
