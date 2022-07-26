#include <stdint.h> // for uint8_t
#include <stdio.h> // for printf
#include <netinet/in.h>

int main(int argc, char* argv[]) {
        uint32_t a;
        uint32_t b;

        FILE *fp1 = fopen(argv[1], "rb");    
        fread(&a, sizeof(uint32_t), 1, fp1);

        FILE *fp2 = fopen(argv[2], "rb");
        fread(&b, sizeof(uint32_t), 1, fp2);

        a = ntohl(a);
        b = ntohl(b);

        printf("%d(0x%x) + %d(0x%x) = %d(0x%x)\n", a, a, b, b, a+b, a+b);   
 
        fclose(fp1);   
        fclose(fp2);  
        return 0;
}
