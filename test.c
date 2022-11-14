#include <queue.h>
#include <stdio.h>

define_queue(int,int);

struct point {
    int x, y;
};

define_queue(p,struct point*);

int main(void) {
    queue_int *q = new_queue_int(2,1,2);
    print_with_ptr_queue_int = true;
    print_queue_int(q,"%d\n");
    puts("----");
    en_queue_int(q,3);
    print_queue_int(q,"%d\n");
    puts("---");
    de_queue_int(&q);
    print_queue_int(q,"%d\n");
    destroy_queue_int(q);
    puts("---");


    struct point p1 = {
        .x = 1,
        .y = 1
    }, p2 = {
        .x = 2,
        .y = 2
    }, p3 = {
        .x = 3,
        .y = 3
    };
    queue_p *p = new_queue_p(2,&p1,&p2);
    print_queue_p(p,"%p\n");
    puts("----");
    en_queue_p(p,&p3);
    print_queue_p(p,"%p\n");
    puts("----");
    de_queue_p(&p);
    print_queue_p(p,"%p\n");
    destroy_queue_p(p);
}