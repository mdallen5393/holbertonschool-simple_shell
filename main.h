#ifndef MAIN_H
#define MAIN_H


/* Standard Libraries */
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <string.h>
#include <stddef.h>
#include <sys/wait.h>
#include <limits.h>
#include <signal.h>


/* Structs & Typedefs */
/**
 * struct list_s - singly linked list
 * @str: string - (malloc'ed string)
 * @next: points to the next node
 *
 * Description: singly linked list node structure
 */
typedef struct list_s
{
	char *str;
	struct list_s *next;
} list_t;


/* Function Prototypes */
/* --- strops.c --- */
char *strcpycat(char *str1, char *str2);
int _strlen(const char *str);
int _strcmp(const char *s1, const char *s2);
int _strncmp(const char *s1, const char *s2, size_t n);
char *_strdup(const char *str);

/* --- helpers.c --- */
void _puts(char *str);
int _putchar(char c);
int _putint(int n);
char *dipr(int n);
void print_array(char **array);

/* --- env.c --- */
void printenv(void);
char *_getenv(const char *name);
int _setenv(const char *name, const char *value, int overwrite);
int _unsetenv(const char *name);
int envloc(const char *name);

/* --- which.c --- */
list_t *make_env(char *str);
char *_which(char *exec);

/* --- linked list operations --- */
size_t print_list(const list_t *h);
size_t list_len(const list_t *h);
list_t *add_node(list_t **head, const char *str);
list_t *add_node_end(list_t **head, const char *str);
void free_list(list_t *head);
list_t *insert_node_at_index(list_t **head, unsigned int idx, char *str);

/* --- shell.c --- */
char **make_av(char *);
int run(int isInteractive);
int execute(char **command);
void free_array(char **array);
void signal_handler(int sig);

/* Global Variables */
extern char **environ;
char **av;

#endif
