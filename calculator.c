/* простой калькулятор */
#include "calculator.h"

int main(int argc, char *argv[])
{
    int i;
    int n;
    int a,b;
    int choice;
    int answer;
    char path[STRLEN];
    char name[STRLEN];
    DIR *d;
    struct dirent *dir;
    operations_t *operations = NULL ;
    /* смотрим наличие либ*/
    d = opendir(LPATH);
    if (d){
        while ((dir = readdir(d)) != NULL){
            /* скипаем .. и . */
            if((dir->d_name[0] == '.'))
                continue;
            strcpy(path, LPATH);
            strcpy(name, dir->d_name);
            rmsbstr(name, "lib");
            rmsbstr(name, ".so");
            strncat(path, dir->d_name, strlen(dir->d_name));
            n = openf(path, name, &operations);
        }
        closedir(d);
    } else {
        fprintf(stderr, "Не могу открыть директорию\n");
        return 1;
    }

    /* функции загружены, можно начинать работать */
    printf("Офигенный калькулятор умеет следующее:\n");
    for(i = 0; i < n; i++){
        printf("\t%d. %s\n",i,operations[i].name);
    }

    printf("\t%d. выходить\n", n);
    while(1){
        printf("Что делаем?\n");
        printf("---> ");
        choice = getNumber();
        if(choice == n){
            for(i = 0; i < n; i++)
                dlclose(operations[i].handle);
            free(operations);
            printf("koniec\n");
            return 0;
        } else if(choice < 0 || choice > n){
            printf("Нет такой функции\n");
        } else if(strcmp(operations[choice].name, "factorial")){
            printf("--> ");
            a = getNumber();
            printf("--> ");
            b = getNumber();
            answer = ((twoi_t) operations[choice].f)(a,b);
            printf("===> %d\n", answer);
        } else if(!strcmp(operations[choice].name, "factorial")){
            printf("--> ");
            a = getNumber();
            answer = ((onei_t) operations[choice].f)(a);
            printf("===> %d\n", answer);
        }
    }
   /*
    *(void **) (&sum) = dlsym(...);
    */
    for(i = 0; i < n; i++)
        dlclose(operations[i].handle);
    free(operations);
    return 0;
}
/* Мы хотим получить только число */
int getNumber()
{
    int num;
    while(1){
        if(scanf("%d", &num) == 1)
            return num;
        getchar();
    }
}

/* функция вытаскивания функции из динамической библиотеки */
int openf (char *path, char *name, operations_t **op)
{
    void *f;
    void *handle;
    char *error;
    static int n = 0;

    handle = dlopen (path, RTLD_NOW);
    if (!handle) {
        fprintf(stderr, "%s\n", dlerror());
        return n;
    }
    f = dlsym(handle, name);
    if ((error = dlerror()) != NULL){
        fprintf (stderr, "%s\n", error);
        return n;
    }
    if(*op == NULL){
        *op =  malloc(sizeof(operations_t));
        if(*op == NULL){
            fprintf(stderr, "Не хватает памяти...\n");
            exit(1);
        }
    }else{
        *op = realloc(*op, ((n+1) * sizeof(operations_t)));
        if(*op == NULL){
            fprintf(stderr, "Не хватает памяти...\n");
            exit(1);
        }
    }
    /* научился правильно присваивать, ага */
    strncpy((*op)[n].name, name, STRLEN);
    strncpy((*op)[n].path, path, STRLEN);
    (*op)[n].handle = handle;
    (*op)[n].f = f;
    n++;
    return n;
}

/* удаляет подстроку из строки*/
void rmsbstr(char *s,const char *toremove)
{
      while((s=strstr(s,toremove)))
          memmove(s,s+strlen(toremove),1+strlen(s+strlen(toremove)));
}
