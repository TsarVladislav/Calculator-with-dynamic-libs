#include <stdio.h>
#include <dlfcn.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h> 
#include "operations.h"
#define LPATH "lib/"
#define STRLEN 256
typedef struct{
    char name[STRLEN];
    char path[STRLEN];
    void *handle;
    void *f;
} operations_t;

int getNumber();
int openf (char *path, char *name, operations_t **op);
void rmsbstr(char *s,const char *toremove);
