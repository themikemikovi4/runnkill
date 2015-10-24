#ifndef UTIL_LOG_H
#define UTIL_LOG_H

#include <stdio.h>
#include <time.h>

#define LOG_D 0
#define LOG_I 1
#define LOG_W 2
#define LOG_E 3

#ifdef __cplusplus
extern "C" {
#endif

extern unsigned int min_log_level;
extern time_t begin_t;

FILE* lopen(const char* path);
int lclose();
void printl_header(char *buf, int time, int level);
int printl(unsigned int log_level, const char* format, ...);

#ifdef __cplusplus
}
#endif

#endif // UTIL_LOG_H
