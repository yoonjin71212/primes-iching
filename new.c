#include <stdio.h>
#include <stdint.h>
#include <string.h>
#include <unistd.h>
#include <time.h>
#include <stdatomic.h>
#include <math.h>

typedef atomic_int aint;
FILE *f;
struct timespec *req,*rem;
void pattern(aint x, aint y)
{
    if (x<y)
    {
	req++;
	rem--;
	
        fprintf(f,"%c%c",x,y);
    } else if (x>y) {
	rem++;
	req--;
        fprintf(f,"%c%c",y,x);
    } else if(x==y) {
	rem--;
	req++;
        fprintf(f,"%c%c",y,x);
        fprintf(f,"%c%c",x,y);
    }
}

void main(aint argc, char **argv)
{
  while(1) {
    f=fopen("./pattern", "r");
    pattern(argc,argc);
    fclose(f);
  }
  return 0;
}
