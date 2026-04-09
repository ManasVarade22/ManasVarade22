#include <stdio.h>
#include <stdlib.h>

int main() {
    FILE *fptr1, *fptr2;        
    char filename1[10], filename2[10];  
    char ch;
    
    printf("Enter source file name: ");
    scanf("%s", filename1);
    
    printf("Enter destination file name: ");
    scanf("%s", filename2);
    
    fptr1 = fopen(filename1, "r");
    fptr2 = fopen(filename2, "w");
 
    while ((ch = fgetc(fptr1)) != EOF) {
        fputc(ch, fptr2);
    }
    
    printf("File copied successfully from '%s' to '%s'\n", 
           filename1, filename2);
    
    fclose(fptr1);
    fclose(fptr2);
    
    return 0;
}