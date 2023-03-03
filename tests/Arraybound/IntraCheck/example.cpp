#include <stdio.h>
#include <stdlib.h>
#define UINT32 unsigned int
/*
int main(int argc, char** argv) {
    UINT32 j, k;
    char p[12], q[15], t[14];
    if(argc+2<16){
        p[argc-1]=0;
    }
    t[argc] = 2;
    if (argc<12) {
        j = argc;
        q[j]=1;
    }
    if (argc>12) {
        return 0;
    }
    q[argc]=3;
    return 0;
}*/

static void
initialize_regex (void)
{
  int character;		/* character value */
  char folded_chars[10];
  /* Initialize the case folding table.  */

  if (true)
    for (character = 0; character < 10; character++)
      folded_chars[character] = 'a';
}