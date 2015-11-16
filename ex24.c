#include <stdio.h>
#include "dbg.h"

#define MAX_DATA 100

typedef enum EyeColor {
  BLUE_EYES, GREEN_EYES, BROWN_EYES,
  BLACK_EYES, OTHER_EYES
} EyeColor;

const char *EYE_COLOR_NAMES[] = {
  "Blue", "Green", "Brown", "Black", "Other"
};

typedef struct Person {
  int age;
  char first_name[MAX_DATA];
  char last_name[MAX_DATA];
  EyeColor eyes;
  float income;
} Person;

int main(int argc, char *argv[])
{
  Person you = {.age = 0};
  int i = 0;
  char *in = NULL;

  printf("First name?\n");
  in = fgets(you.first_name, MAX_DATA-1, stdin);
  check(in != NULL, "Failed to read first name");

  printf("Last name?\n");
  in = fgets(you.last_name, MAX_DATA-1, stdin);
  check(in != NULL, "Failed to read last name");

  printf("Age?\n");
  int rc = fscanf(stdin, "%d", &you.age);
  check(rc > 0, "You must enter a number");

  printf("Eye color?\n");
  for(i = 0; i <= OTHER_EYES; i++) {
    printf("%d) %s\n", i+1, EYE_COLOR_NAMES[i]);
  }
  printf(">");

  int eyes = -1;
  rc = fscanf(stdin, "%d", &eyes);
  check(rc > 0, "You must enter a number");

  you.eyes = eyes - 1;
  check(you.eyes <= OTHER_EYES && you.eyes >= 0, "Invalid option");

  printf("Hourly rate?\n");
  rc = fscanf(stdin, "%f", &you.income);
  check(rc > 0, "Enter an FP number");

  printf("----RESULTS----\n");

  printf("First name: %s", you.first_name);
  printf("Last name: %s", you.last_name);
  printf("Age: %d\n", you.age);
  printf("Eyes: %s\n", EYE_COLOR_NAMES[you.eyes]);
  printf("Income: %f\n", you.income);

  return 0;

error:
  return -1;
}
