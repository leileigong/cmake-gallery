#include <stdio.h>
#include <string.h>
#include <openssl/sha.h>

int main(void){
    SHA_CTX stx;
    unsigned char hash[20];
    char buffer[10];
    int len=0;
    int i;

    memset(hash,0,sizeof(hash));
    memset(buffer,0,sizeof(buffer));

    SHA1_Init(&stx);

    printf("hash input data:");
    for(i=0;i<sizeof(buffer);i++)
    {
        buffer[i] = i;
        printf("%02X",buffer[i]);
    }
    printf("\n");
    SHA1_Update(&stx,buffer,len);
    memset(buffer,0,sizeof(buffer));

    SHA1_Final(hash,&stx);

    printf("SHA1 output:");
    for(i=0;i<20;i++)
    {
        printf("%02X",hash[i]);
    }
    printf("\n");
    return 0;
}
