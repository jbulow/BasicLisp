#include "lisp.h"

#include <stdlib.h>

DEFUN("+", lisp_add, VAR_MIN, 2) {
  LISPINT *sum = malloc(sizeof(LISPINT));

  struct lisp_object *current = HEAD(args);

  while (current) {
    (*sum) += TOLINT(current);
    current = current->next;
  }

  return make_lisp_object(INTEGER, sum);
}

DEFUN("-", lisp_subtract, VAR_MIN, 2) {
  LISPINT *sum = malloc(sizeof(LISPINT));

  struct lisp_object *current = HEAD(args);

  (*sum) = TOLINT(current);

  current = current->next;

  while (current) {
    (*sum) -= TOLINT(current);
    current = current->next;
  }

  return make_lisp_object(INTEGER, sum);
}

DEFUN("*", lisp_multiply, VAR_MIN, 2) {
  LISPINT *ret = malloc(sizeof(LISPINT));

  struct lisp_object *current = HEAD(args);

  (*ret) = TOLINT(current);

  current = current->next;

  while (current) {
    (*ret) *= TOLINT(current);
    current = current->next;
  }

  return make_lisp_object(INTEGER, ret);
}

DEFUN("/", lisp_divide, VAR_MIN, 2) {
  LISPINT *ret = malloc(sizeof(LISPINT));

  struct lisp_object *current = HEAD(args);

  (*ret) = TOLINT(current);

  current = current->next;

  while (current) {
    (*ret) /= TOLINT(current);
    current = current->next;
  }

  return make_lisp_object(INTEGER, ret);
}

void math_initialize() {
  lisp_add_init();
  lisp_subtract_init();
  lisp_multiply_init();
  lisp_divide_init();
}