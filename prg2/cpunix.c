#include <stdio.h>
#include <stdlib.h>
 
int main(int argc, char *argv[]) {
    FILE *sourceFile, *destFile;
    char ch;
 
    if (argc != 3) {
        printf("Usage: %s <source_file> <destination_file>\n", argv[0]);
        return 1;
    }
 
    sourceFile = fopen(argv[1], "rb");
    if (sourceFile == NULL) {
        printf("Unable to open the source file: %s\n", argv[1]);
        return 1;
    }
 
    destFile = fopen(argv[2], "wb");
    if (destFile == NULL) {
        printf("Unable to create the destination file: %s\n", argv[2]);
        fclose(sourceFile);
        return 1;
    }

    while ((ch = fgetc(sourceFile)) != EOF) {
        fputc(ch, destFile);
    }
    printf("File copied successfully from %s to %s\n", argv[1], argv[2]);
    fclose(sourceFile);
    fclose(destFile);
 
    return 0;
}
