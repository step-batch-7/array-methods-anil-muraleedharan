#include <stdio.h>
#include <stdlib.h>
#include "array.h"
#include "array_void.h"

void display_Array(Array_ptr array)
{
  for (int index = 0; index < array->length; index++)
  {
    printf("%d  ", array->array[index]);
  }
  printf("\n");
}

int square(int num)
{
  return num * num;
}

Bool is_even(int num)
{
  return num % 2 == 0 ? True : False;
}

int add(int num1, int num2)
{
  return num1 + num2;
}

Object square_void(Object num)
{
  long int number = (long int )num;
  Object result = (Object)(number * number);
  return result;
}

Bool is_even_void(Object num)
{
  int number = (int)num;
  return number % 2 == 0 ? True : False;
}

Object add_void(Object num1, Object num2)
{
  long int sum = (long int)num1 + (long int)num2;
  return (Object)(sum);
}

void display_number_array(ArrayVoid_ptr array)
{
  for (int index = 0; index < array->length; index++)
  {
    printf("%d  ", (int)array->array[index]);
  }
  printf("\n");
}

int main(void)
{
  int numbers[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
  Array_ptr array = create_intialized_Array(numbers, 10);

  printf("Integer array methodes trials\n```````````````````````````````````````````\n");

  printf("List of numbers : \n");
  display_Array(array);

  printf("\nSquare of all numbers : \n");
  display_Array(map(array, square));

  printf("\nEven numbers in the list : \n");
  display_Array(filter(array, is_even));

  printf("\nSum of all numbers : \n");
  printf("%d\n", reduce(array, 0, add));

  printf("\n\nGeneric array methodes trials\n```````````````````````````````````````````\n");

  ArrayVoid_ptr array_void = create_ArrayVoid(6);
  array_void->array[0] = (Object)(1);
  array_void->array[1] = (Object)(2);
  array_void->array[2] = (Object)(3);
  array_void->array[3] = (Object)(4);
  array_void->array[4] = (Object)(5);
  array_void->array[5] = (Object)(6);
  
  printf("Square of all numbers : \n");
  display_number_array(map_void(array_void, square_void));

  printf("\nEven numbers in the list : \n");
  display_number_array(filter_void(array_void, is_even_void));

  printf("\nSum of all numbers : \n");
  printf("%d\n", (int)reduce_void(array_void, 0, add_void));

  return 0;
}