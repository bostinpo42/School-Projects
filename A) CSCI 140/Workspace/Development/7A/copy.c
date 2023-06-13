#include "stdlib.h"
#include "stdio.h"

#define BUF_SZ 4096

int main(int argc, char const *argv) {
    int qty;
    unsigned char buffer[BUF_SZ];

    FILE* src = NULL;
    FILE* dst = NULL;

    if(src = fopen("ubuntu.iso", "rb") == NULL){
        printf("Could not open source file!\n");
        exit(1);
    }

    if((dst = fopen("ubuntu2.iso", "wb")) == NULL) {
        fclose(src);
        printf("Could not open destination file!\n");
        exit(2);
    }

    while ((qty = fread(buffer, sizeof(char), BUF_SZ, src) > 0)) {
        fwrite(buffer, sizeof(char), qty, dst);
    }
    
    fclose(src);
    fclose(dst);

    return 0;
}