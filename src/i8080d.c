
#include "i8080d.h"

int disassemble(unsigned char *buffer, int pc){

    int op_size = 1;
    unsigned char *opcode = &buffer[pc];
    printf("%04x ", pc);

    switch(*opcode){
        case 0x00: printf("NOP"); break;
        case 0x01: printf("LXI      B, #$%02x%02x", opcode[2], opcode[1]);
        op_size = 3; break;
    }

    return op_size;
}

int main(int argc, char* argv[]){

    FILE *f = fopen(argv[1], "rb");
    if(f == NULL){
        printf("Error Could not open %s\n", argv[1]);
    }

    fseek (f, 0L, SEEK_END);
    int fsize = ftell(f);
    fseek(f, 0l, SEEK_SET);

    int pc = 0x0;
    unsigned char *buffer = malloc(fsize);
    fread (buffer, fsize, 1, f);
    fclose (f);



    while(pc < fsize){
        pc += disassemble(buffer, pc);
        printf("\n");
    }

   return 0;
}
