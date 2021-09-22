#pragma once
typedef struct {
  unsigned long pages_free;
  unsigned long pages_total;
  unsigned long *freemap;
  unsigned long freemap_cells;
  unsigned long length;
  unsigned long page_size;
  unsigned long page_bits;
} page_t;
void page_init(page_t *o, void *begin, unsigned long length,
               unsigned long page_bits);
void page_free(page_t *o, void *pageaddr);
void *page_alloc(page_t *o, int);
