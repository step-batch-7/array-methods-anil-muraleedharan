#include<stdlib.h>
#include"array.h"

Array_ptr create_Array(int count)
{
  Array_ptr Array = malloc(sizeof(Array));
  Array->length = count;
  Array->array = malloc(sizeof(int) * count);
  return Array;
}

Array_ptr create_intialized_Array(Int_ptr elements, int count)
{
  Array_ptr initialized_Array = create_Array(count);
  for (int index = 0; index < count; index++)
  {
    initialized_Array->array[index] = elements[index];
  }
  return initialized_Array;
}

Array_ptr map(Array_ptr src, Mapper mapper)
{
  Array_ptr mapped_array = create_Array(src->length);
  for (int index = 0; index < src->length; index++)
  {
    mapped_array->array[index] = mapper(src->array[index]);
  }
  return mapped_array;
}

Array_ptr filter(Array_ptr src, Predicate predigate)
{
  int temp[src->length];
  int count = 0;
  for (int index = 0; index < src->length; index++)
  {
    int current_element = src->array[index];
    if (predigate(current_element))
    {
      temp[count] = current_element;
      count++;
    }
  }
  return create_intialized_Array(temp, count);
}

int reduce(Array_ptr src,int init , Reducer reducer)
{
  for (int index = 0; index < src->length; index++)
  {
    init = reducer(init, src->array[index]);
  }
  return init;
}