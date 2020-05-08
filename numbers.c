#include<stdio.h>
#include<stdlib.h>
#include"array.h"

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

int main(void)
{
  int numbers[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
  Array_ptr array = create_intialized_Array(numbers, 10);

  printf("List of numbers : \n");
  display_Array(array);

  printf("\nSquare of all numbers : \n");
  display_Array(map(array, square));

  printf("\nEven numbers in the list : \n");
  display_Array(filter(array, is_even));

  printf("\nSum of all numbers : \n");
  printf("%d\n", reduce(array, 0, add));

  return 0;
}