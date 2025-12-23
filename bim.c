#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[])
{
  char *filename = argv[2];
  
  if(argc < 3) {
    printf("usage: bim example.txt typpe bim --help for commands");
  }

  if(strcmp(argv[1], "create") == 0) {
    printf("creating %s", argv[2]);
    FILE *file = fopen(filename, "w");
    fclose(file);

  } else if(strcmp(argv[1], "read") == 0) {
    FILE *file = fopen(filename, "r");
    int ch;
    while((ch = fgetc(file)) != EOF) {
      putchar(ch);
    }
    fclose(file);

  } else if(strcmp(argv[1], "delete") == 0) {
    if(remove(filename) == 0) {
      printf("file deleted");
    } else {
      printf("error deleting");
    }

  } else if(strcmp(argv[1], "write") == 0 || strcmp(argv[1], "edit") == 0) {
    system("clear");
    printf("Enter text to write to %s (Ctrl+D to finish):\n", filename);
    FILE *file = fopen(filename, "w");
    if(file == NULL) {
      printf("Error: Could not open file for writing\n");
      return 1;
    }
    char buffer[1024];
    while(fgets(buffer, sizeof(buffer), stdin) != NULL) {
      fputs(buffer, file);
    }
    fclose(file);
    printf("Content written to %s\n", filename);
  
  }
}
