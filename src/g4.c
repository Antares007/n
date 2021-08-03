#include "m.h"
#include "uv.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct {
  uv_write_t req;
  uv_buf_t buf;
} write_req_t;
void cb_free_write_req(uv_write_t *req) {
  printf("cb_free_write_req %p\n", req);
  write_req_t *wr = (write_req_t *)req;
  free(wr->buf.base);
  free(wr);
}
void cb_alloc_buffer(uv_handle_t *handle, size_t suggested_size,
                     uv_buf_t *buf) {
  printf("cb_alloc_buffer %p %ld %p\n", handle, suggested_size, buf);
  buf->base = (char *)malloc(suggested_size);
  buf->len = suggested_size;
}
void cb_close(uv_handle_t *handle) {
  printf("cb_close %p\n", handle);
  free(handle);
}
void cb_echo_write(uv_write_t *req, int status) {
  printf("cb_echo_write %p %d \n", req, status);
  if (status) {
    fprintf(stderr, "Write error %s\n", uv_strerror(status));
  }
  cb_free_write_req(req);
}
void cb_echo_read(uv_stream_t *client, ssize_t nread, const uv_buf_t *buf) {
  printf("cb_echo_read %p %ld %p\n", client, nread, buf);
  if (nread > 0) {
    write_req_t *req = (write_req_t *)malloc(sizeof(write_req_t));
    req->buf = uv_buf_init(buf->base, nread);
    uv_write((uv_write_t *)req, client, &req->buf, 1, cb_echo_write);
    return;
  }
  if (nread < 0) {
    if (nread != UV_EOF)
      fprintf(stderr, "Read error %s\n", uv_err_name(nread));
    uv_close((uv_handle_t *)client, cb_close);
  }
  free(buf->base);
}
void on_new_connection(uv_stream_t *server, int status) {
  printf("on_new_connection %p %d\n", server, status);
  if (status < 0) {
    fprintf(stderr, "New connection error %s\n", uv_strerror(status));
    return;
  }
  uv_tcp_t *client = (uv_tcp_t *)malloc(sizeof(uv_tcp_t));
  uv_tcp_init(server->loop, client);
  if (uv_accept(server, (uv_stream_t *)client) == 0) {
    uv_read_start((uv_stream_t *)client, cb_alloc_buffer, cb_echo_read);
  } else {
    uv_close((uv_handle_t *)client, cb_close);
  }
}
// loop draw 1000/60 'timer' r1 mba3 run mba.
// loop  'serv' r1 mba3 run mba.
// draw = jkhkhj.
void loop() {
  uv_loop_t loop;
  uv_loop_init(&loop);

  uv_tcp_t server;
  uv_tcp_init(&loop, &server);

  struct sockaddr_in addr;
  const int port = 7000;
  uv_ip4_addr("0.0.0.0", port, &addr);

  uv_tcp_bind(&server, (const struct sockaddr *)&addr, 0);
  int r = uv_listen((uv_stream_t *)&server, 128, on_new_connection);
  if (r) {
    fprintf(stderr, "Listen error %s\n", uv_strerror(r));
    return;
  }
  fprintf(stdout, "Listening on port:%d\n", port);
  uv_run(&loop, UV_RUN_DEFAULT);
  uv_loop_close(&loop);
}
int main() {
  loop();
}
