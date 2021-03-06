/*
  Write a C program for a DFA that accepts only even number of 1s
*/
#include <stdio.h>
int main()
{
  int current_state = 0, i;
  char input[10];
  printf("Input:");
  scanf("%s", input);
  for (i = 0; input[i] != '\0'; i++) 
  {
    /* reject if inout contains values other then 0 or 1 */
    if (input[i] != '0' && input[i] != '1') // reject if input has value other than 0 or 1
    {
      printf("Input should contain only 0 or 1\n");
      return -1; // error
    }
    /* for current state 0
    goto to state 1 for next value as 1
    remain at state 0 for next value as 0*/
    if (current_state == 0)
    {
      if (input[i] == '0')
        current_state = 0;
      else
        current_state = 1;
    }
    /* for current state 1
    go to state 0 for next value as 1
    remain at state 1 for next value as 0*/
    else
    {
      if (input[i] == '0')
        current_state = 1;
      else
        current_state = 0;
    }
  }
  if (current_state == 0) //if current state is ending where it should end
    printf("Accepted\n");
  else // else reject
    printf("Not Accepted\n");
  return 1; //no error
}