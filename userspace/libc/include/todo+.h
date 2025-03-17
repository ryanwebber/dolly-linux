#ifndef _TODO_H
#define _TODO_H

#define TODO(function) todo(function, __FILE__, __LINE__)

__attribute__((noreturn)) void todo(const char *function, const char *file, int line);

#endif
