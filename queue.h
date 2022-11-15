#pragma once
#include <stdlib.h>
#include <stdarg.h>
#include <stdbool.h>
#include <assert.h>

#define define_queue(suffix,type) \
\
    bool print_with_ptr_queue_##suffix = false; \
\
    typedef struct s_queue_##suffix { \
        type m_value; \
        struct s_queue_##suffix *ptr_next; \
    } queue_##suffix;\
\
    queue_##suffix *new_queue_##suffix(const unsigned int amount_of_values,...) { \
        if(amount_of_values < 1) return NULL; \
        va_list argp; \
        va_start(argp,amount_of_values); \
        queue_##suffix *n = NULL, *t = NULL; \
        for(int i = 0; i < amount_of_values; i++) { \
            if(n == NULL) { \
                n = (queue_##suffix*)calloc(1,sizeof(queue_##suffix)); \
                assert(n != NULL); \
                n->m_value = va_arg(argp,type); \
                n->ptr_next = NULL; \
                t = n; \
                continue; \
            } \
            t->ptr_next = (queue_##suffix*)calloc(1,sizeof(queue_##suffix)); \
            assert(t->ptr_next != NULL); \
            t->ptr_next->m_value = va_arg(argp,type); \
            t->ptr_next->ptr_next = NULL; \
            t = t->ptr_next; \
        } \
        return n; \
    } \
    queue_##suffix *last_queue_##suffix(queue_##suffix *start) { \
        queue_##suffix *last = start; \
        while(last->ptr_next != NULL) last = last->ptr_next; \
        return last; \
    } \
    void en_queue_##suffix(queue_##suffix *start, type value) { \
        queue_##suffix *last = last_queue_##suffix(start); \
        last->ptr_next = (queue_##suffix*)calloc(1,sizeof(queue_##suffix)); \
        assert(last->ptr_next != NULL); \
        last->ptr_next->ptr_next = NULL; \
        last->ptr_next->m_value = value; \
    } \
\
    void de_queue_##suffix(queue_##suffix **start) { \
        queue_##suffix *t = *start; \
        *start = (*start)->ptr_next; \
        free(t); \
    } \
\
    void print_queue_##suffix(queue_##suffix *start, char *formatter) { \
        queue_##suffix *t = start; \
        while(t != NULL) { \
            printf(formatter,t->m_value); \
            if(print_with_ptr_queue_##suffix) { \
                printf("self %p\nnext %p\n",t, t->ptr_next); \
            } \
            t = t->ptr_next; \
        } \
    }  \
\
    void destroy_queue_##suffix(queue_##suffix *start) { \
        queue_##suffix *c = start, *t = NULL;  \
        while(c != NULL) { \
            t = c->ptr_next; \
            free(c); \
            c = t; \
        } \
    }