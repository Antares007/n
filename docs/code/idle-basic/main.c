#include <stdio.h>
#include <uv.h>
void wait_for_a_while(uv_idle_t *handle) {
  (*(uint64_t *)handle->data)++;
  if (*(uint64_t *)handle->data % 1000000 == 0)
    fprintf(stdout, "%ld\n", *(uint64_t *)handle->data);
  if (*(uint64_t *)handle->data >= 10000000)
    uv_idle_stop(handle);
}
void uvloop(){
  uv_loop_t loop;
  uv_loop_init(&loop);
  uv_idle_t idler;
  uint64_t counter = 0;
  idler.data = &counter;
  uv_idle_init(&loop, &idler);
  uv_idle_start(&idler, wait_for_a_while);

  printf("Idling...\n");
  uv_run(&loop, UV_RUN_DEFAULT);

  uv_loop_close(&loop);
}
int main() {
  uvloop();
  return 0;
}
