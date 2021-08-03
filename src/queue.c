#include "queue.h"
#include "mbo.h"
#include <stdio.h>
struct item_s {
  int x;
  QUEUE queue;
};
typedef struct item_s item_t;
void vs(void *);
void q_insert_tail(QUEUE *q, QUEUE *i) { QUEUE_INSERT_TAIL(q, i); }
int main() {
  QUEUE queue;
  QUEUE_INIT(&queue);
  printf("queue*:%p\n", &queue);
  item_t a = {.x = 1};
  q_insert_tail(&queue, &a.queue);
  printf("a*:%p\n", &a.queue);
  item_t b = {.x = 2};
  q_insert_tail(&queue, &b.queue);
  printf("b*:%p\n", &b.queue);
  item_t c = {.x = 3};
  q_insert_tail(&queue, &c.queue);
  printf("c*:%p\n", &c.queue);
  item_t d = {.x = 4};
  q_insert_tail(&queue, &d.queue);
  printf("d*:%p\n", &d.queue);

  QUEUE *q;
  QUEUE_FOREACH(q, &queue) {
    struct item_s *user = QUEUE_DATA(q, struct item_s, queue);
    printf("%p %d\n", q, user->x);
  }
  printf("done\n");
}
