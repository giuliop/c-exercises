# include <stdlib.h>
# include <string.h>
# include <assert.h>
# include <stdio.h>

// An opaque type for a circular buffer for double values
// It allows to add double values in rear and to take them out in front.
// Each such structure has a maximal amount of elements that can be stored in it.
typedef struct circular circular;
struct circular {
  size_t start;       /** position of element 0 */
  size_t len;         /** number of elements stored */
  size_t max_len;     /** maximum capacity */
  double* tab;        /** array holding the data */
};

// Returns the actual position of the pos'element
static size_t circular_getpos(circular* c, size_t pos) {
  pos += c->start;
  pos %= c->max_len;
  return pos;
}

// Return a pointer to position pos in buffer c.
// Returns: a pointer to the pos’element of the buffer, 0 otherwise.
double* circular_element(circular* c, size_t pos) {
  double* ret = 0;
  if (c) {
    if (pos < c->max_len) {
      pos = circular_getpos(c, pos);
      ret = &c->tab[pos];
    }
  }
  return ret;
}

// Print out a representation of the circular struct
void circular_print(circular* c) {
  size_t maxlen = c->max_len;
  printf ("%12s", "table index");
  for (size_t i = 0; i < maxlen; ++i) {
    printf ("%12zu", i);
  }
  printf ("\n");
  printf ("%12s", "buffer pos");
  for (size_t i = 0; i < maxlen; ++i) {
    size_t pos = (i + maxlen - c->start) % maxlen;
    if (pos < c->len) {
      printf ("%12lu", pos);
    } else {
      printf ("%12s", "*");
    }
  }
  printf ("\n");
  printf ("%12s", "buffer val");
  for (size_t i = 0; i < maxlen; ++i) {
    size_t pos = (i + maxlen - c->start) % maxlen;
    if (pos < c->len) {
      printf ("%12.2f", *circular_element(c, pos));
    } else {
      printf ("%12s", "*");
    }
  }
  printf ("\n");
  printf ("%12s", "memory val");
  for (size_t i = 0; i < maxlen; ++i) {
    printf ("%12.2f", c->tab[i]);
  }
  printf ("\n");
  printf ("\n");
}

// Resize to capacity max_len.
circular* circular_resize(circular* c, size_t nlen) {
  if (c) {
    size_t len = c->len;
    if (len > nlen) return 0;
    size_t olen = c->max_len;
    if (nlen != olen) {
      size_t ostart = circular_getpos(c, 0);
      size_t nstart = ostart;
      double* otab = c->tab;
      double* ntab;
      if (nlen > olen) {
        ntab = realloc(c->tab, sizeof(double[nlen]));
        if (!ntab) return 0;
        // two separate chunks
        if (ostart+len > olen) {
          size_t ulen = olen - ostart;
          size_t llen = len - ulen;
          if (llen <= (nlen - olen)) {
            /* cpy the lower one up after the old end */
            memcpy(ntab + olen, ntab, llen*sizeof(double));
          } else {
            /* mv the upper one up to the new end */
            nstart = nlen - ulen;
            memmove(ntab + nstart , ntab + ostart , ulen*sizeof(double));
          }
        }
      } else {
        ntab = c->tab;
        // if we need to move elements around...
        if (ostart + len > nlen) {
          // if there are wrapped elements 
          if (ostart + len > olen) {
            size_t wrapped = ostart + len - olen;
            memmove(ntab + wrapped, ntab + ostart, (len - wrapped) * sizeof(double));
            if (len == nlen) nstart = 0; // we had to wrap the first element
            // otherwise just wrap the elements that don't fit anymore
          } else {
            size_t from = (nlen > ostart) ? nlen : ostart;
            size_t items = ostart + len - from;
            memcpy(ntab, ntab + from, items * sizeof(double));
          }
        }
        ntab = realloc(c->tab, sizeof(double[nlen]));
        if (!ntab) return 0;
      }
      *c = (circular){
        .max_len = nlen,
        .start = nstart,
        .len = len,
        .tab = ntab,
      };
    }
  }
  return c;
}

// Append a new element with value value to the buffer c.
// Returns: c if the new element could be appended, 0 otherwise.
circular* circular_append(circular* c, double value) {
  if (c) {
    if (c->len == c->max_len) {
      c = circular_resize(c, c->max_len + 10); 
      if (!c) return 0;
    }
    size_t next = circular_getpos(c, c->len);
    c->tab[next] = value;
    c->len += 1;
  }
  return c;
}

// Remove the oldest element from c and return its value.
// Returns: the removed element if it exists, 0.0 otherwise.
double circular_pop(circular* c) {
  if (c->len == 0) return 0.0;
  double* v = circular_element(c, 0);
  if (v) {
    if (c->len == 1) {
      c->start = 0;
    } else {
      c->start += 1;
    }
    c->len -= 1;
    return *v;
  }
  return 0.0;
}

// Return the number of elements stored.
size_t circular_getlength(circular* c) {
  return c->len;
}

// Initialize a circular buffer c with maximally max_len elements.
// Only use this function on an uninitialized buffer.
// Each buffer that is initialized with this function must be destroyed
// with a call to circular_destroy.
circular* circular_init(circular* c, size_t max_len) {
  if (c) {
    if (max_len) {
      *c = (circular) {
        .max_len = max_len ,
        .tab = malloc(sizeof(double[max_len])),
      };
      // allocation failed
      if (!c->tab) c->max_len = 0;
    } else {
      *c = (circular){ 0 };
    }
  }
  return c;
}

// Destroy circular buffer c.
// c must have been initialized with a call to circular_init
void circular_destroy(circular* c) {
  if (c) {
    free(c->tab);
    circular_init(c, 0);
  }
}

// Allocate and initialize a circular buffer with maximally len elements.
// Each buffer that is allocated with this function must be deleted
// with a call to circular_delete.
circular* circular_new(size_t len) {
  circular *c = malloc(sizeof(circular));
  return circular_init(c, len);
}

// Delete circular buffer c.
// c must have been allocated with a call to circular_new
void circular_delete(circular* c) {
  if (c) {
    circular_destroy(c);
    free(c);
  }
}

int main() {
  circular * c = circular_new(3);
  for (size_t i = 0; i < 3; ++i) {
    c = circular_append(c, 1.0 + i);
  }
  circular_print(c);
  assert(circular_getlength(c) == 3);
  assert(*circular_element(c, 0) == 1.0);
  assert(*circular_element(c, 1) == 2.0);
  assert(*circular_element(c, 2) == 3.0);
  assert(circular_pop(c) == 1.0);
  circular_print(c);
  assert(circular_pop(c) == 2.0);
  circular_print(c);
  assert(circular_getlength(c) == 1);
  c = circular_resize(c, 1);
  circular_print(c);
  assert(circular_pop(c) == 3.0);
  circular_print(c);
  assert(circular_getlength(c) == 0);

  circular_delete(c);
}
  
