#include <stdlib.h>
#include <stdio.h>
#include "array_void.h"

ArrayVoid_ptr create_ArrayVoid(int length)
{
  ArrayVoid_ptr array_void = malloc(sizeof(ArrayVoid));
  array_void->length = length;
  array_void->array = malloc(sizeof(Object) * length);
  return array_void;
}

ArrayVoid_ptr map_void(ArrayVoid_ptr src, MapperVoid mapper)
{
  ArrayVoid_ptr mapped_array = create_ArrayVoid(src->length);
  for (int index = 0; index < src->length; index++)
  {
    mapped_array->array[index] = mapper(src->array[index]);
  }
  return mapped_array;
}