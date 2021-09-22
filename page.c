#include "page.h"
#include <string.h>

#define CELL_BITS (8 * sizeof(*o->freemap))

void page_init(page_t *o, void *begin, unsigned long length,
               unsigned long page_bits) {
  int i;
  o->page_bits = page_bits;
  o->page_size = 1 << page_bits;
  o->pages_total = o->pages_free = length / o->page_size;
  o->freemap = (unsigned long *)begin;
  unsigned long freemap_bytes = 1 + o->pages_total / 8;
  o->freemap_cells = 1 + o->pages_total / CELL_BITS;
  unsigned long freemap_pages = 1 + freemap_bytes / o->page_size;

  memset(o->freemap, 0xff, freemap_bytes);
  for (i = 0; i < freemap_pages; i++)
    page_alloc(o, 0);
  o->freemap[o->freemap_cells - 1] = o->freemap[o->freemap_cells - 1] &
                                     ((1 << (o->pages_total % CELL_BITS)) - 1);
}

void *page_alloc(page_t *o, int zeroit) {
  for (unsigned long i = 0; i < o->freemap_cells; i++) {
    if (o->freemap[i] != 0) {
      for (unsigned long j = 0; j < CELL_BITS; j++) {
        unsigned long cellmask = (1 << j);
        if (o->freemap[i] & cellmask) {
          o->freemap[i] &= ~cellmask;
          unsigned long pagenumber = i * CELL_BITS + j;
          void *pageaddr = (pagenumber << o->page_bits) + o->freemap;
          if (zeroit)
            memset(pageaddr, 0, o->page_size);
          o->pages_free--;
          return pageaddr;
        }
      }
    }
  }
  return 0;
}

void page_free(page_t *o, void *pageaddr) {
  unsigned long pagenumber =
      ((char *)pageaddr - (char *)o->freemap) >> o->page_bits;
  unsigned long cellnumber = pagenumber / CELL_BITS;
  unsigned long celloffset = pagenumber % CELL_BITS;
  unsigned long cellmask = (1 << celloffset);
  o->freemap[cellnumber] |= cellmask;
  o->pages_free++;
}
