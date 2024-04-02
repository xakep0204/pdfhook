#include <stdio.h>
#include <stdlib.h>


int main(){
    FILE *pdf;
    FILE *output = fopen("out.txt", "w");

    if ((pdf = fopen("linalg.pdf", "r")) == NULL){
        printf("Error! opening file\n");
        return 1;
    }

    // Calculate file length
    fseek(pdf, 0, SEEK_END);
    unsigned long filelen = ftell(pdf);
    rewind(pdf);
    
    char *buffer = (char *)malloc(filelen);
    fread(buffer, filelen, 1, pdf);
    fprintf(output, "%s", buffer);
    free(buffer);
    fclose(pdf);
    fclose(output);
    return 0;


}


