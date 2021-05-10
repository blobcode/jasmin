#include "mongoose.h"
#include <string.h>

char *s_web_root_dir = "./";
char s_listening_address[17] = "http://localhost:";

static void cb(struct mg_connection *c, int ev, void *ev_data, void *fn_data) {
  struct mg_http_serve_opts opts = {.root_dir = s_web_root_dir};
  if (ev == MG_EV_HTTP_MSG) mg_http_serve_dir(c, ev_data, &opts);
}

int main(int argc, char *argv[]) {
  struct mg_mgr mgr;
  s_web_root_dir = argv[1];
  strcat(s_listening_address, argv[2]);
  mg_mgr_init(&mgr);
  mg_http_listen(&mgr, s_listening_address, cb, &mgr);
  for (;;) mg_mgr_poll(&mgr, 1000);
  mg_mgr_free(&mgr);
  return 0;
}