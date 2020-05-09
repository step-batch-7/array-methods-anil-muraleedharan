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

ArrayVoid_ptr filter_void(ArrayVoid_ptr src, PredicateVoid predigate)
{
  Object temp[src->length];
  int count = 0;
  for (int index = 0; index < src->length; index++)
  {
    Object current_element = src->array[index];
    if (predigate(current_element))
    {
      temp[count] = current_element;
      count++;
    }
  }
  ArrayVoid_ptr filtered_array = create_ArrayVoid(count);
  for (int index = 0; index < count; index++)
  {
    filtered_array->array[index] = temp[index];
  }
  return filtered_array;
}

Object reduce_void(ArrayVoid_ptr src, Object init, ReducerVoid reducer)
{
  for (int index = 0; index < src->length; index++)
  {
    init = reducer(init, src->array[index]);
  }
  return init;
}