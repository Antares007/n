#include "queue.h"
#include "mbo.h"
#include <stdio.h>
typedef struct {
  int x;
  QUEUE queue;
} item_t;
#define PRINTF(a,b) printf(a, ((unsigned long)(b))&0xfff)
int main() {
  item_t a = {.x = 1};
  QUEUE_INIT(&a.queue);
  PRINTF("a.queue*:%03lx\n", &a.queue);
  item_t b = {.x = 2};
  QUEUE_INSERT_TAIL(&a.queue, &b.queue);
  PRINTF("b.queue*:%03lx\n", &b.queue);
  item_t c = {.x = 3};
  QUEUE_INSERT_TAIL(&a.queue, &c.queue);
  PRINTF("c.queue*:%03lx\n", &c.queue);
  item_t d = {.x = 4};
  QUEUE_INSERT_TAIL(&a.queue, &d.queue);
  PRINTF("d.queue*:%03lx\n", &d.queue);
  QUEUE *q;
  QUEUE_FOREACH(q, &a.queue) {
    item_t *user = QUEUE_DATA(q, item_t, queue);
    printf("%p %d\n", q, user->x);
  }
  printf("done\n");
}
