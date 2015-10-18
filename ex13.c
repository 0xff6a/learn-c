#include <stdio.h>

int main(int argc, char *argv[])
{
  if(argc !=2) {
    printf("Error: you need one argument\n");

    return 1;
  }

  int i = 0;
  for(i = 0; argv[1][i] != '\0'; i++) {
    char letter = argv[1][i];

    switch(letter) {
      case 'a':
      case 'A':
        printf("%d: 'A'\n", i);
        break;

      case 'z':
      case 'Z':
        printf("%d: 'Z'\n", i);
        break;

      default:
        printf("%d: %c is not considered\n", i, letter);
    }
  }

  return 0;
}