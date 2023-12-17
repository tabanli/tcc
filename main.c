#include "defs.h"
#define extern_
#include "data.h"
#undef extern_
#include "decl.h"
#include <errno.h>

// Compiler setup and top-level execution
// Copyright (c) 2019 Warren Toomey, GPL3

// Initialise global variables
static void init() {
  
  Line = 1;
  Putback = '\n';
}

// Print out a usage if started incorrectly
static void usage(char *prog) {
  
  fprintf(stderr, "Usage: %s infile\n", prog);
  
  exit(1);
}

// Printable token list
char *tokstr[] = { "+", "-", "*", "/", "intlit" };

// Scan all the tokens of input file and
// print out details of each token found
static void scanfile() {
  
  struct token T;

  while (scan(&T)) {
    printf("Token %s", tokstr[T.token]);
    
    if (T.token == T_INTLIT)
      printf(", value %d", T.intvalue);
    
    printf("\n");
  }
}

// Check the arguments and print out correct usage
// if we don't have an argument. Open up the input
// file and call scanfile() to scan the tokens in it
void main(int argc, char *argv[]) {
  
  if (argc != 2)
    usage(argv[0]);

  init();

  if ((Infile = fopen(argv[1], "r")) == NULL) {
    fprintf(stderr, "Unable to open %s: %s\n", argv[1], strerror(errno));
    
    exit(1);
  }

  scanfile();
  exit(0);
}
