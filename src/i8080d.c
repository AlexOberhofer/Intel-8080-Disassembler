
#include "i8080d.h"

int disassemble(unsigned char *buffer, int pc){

    int op_size = 1;

    /**
     * Notes:
     * low bit opcode[1]
     * high bit opcode[2]
     */
    unsigned char *opcode = &buffer[pc];
    printf("%04x ", pc);

    switch(*opcode){
        case 0x00: printf("NOP"); break;
        case 0x01: printf("LXI        B, #%02x #%02x", opcode[2], opcode[1]);
        op_size = 3; break;
        case 0x02: printf("STAX       B"); break;
        case 0x03: printf("INX        B"); break;
        case 0x04: printf("INR        B"); break;
        case 0x05: printf("DCR        B"); break;
        case 0x06: printf("MVI        B, #%02x", opcode[1]); op_size = 2; break;
        case 0x07: printf("RLC"); break;
        case 0x09: printf("DAD        B"); break;
        case 0x0a: printf("LDAX       B"); break;
        case 0x0b: printf("DCX        B"); break;
        case 0x0c: printf("INR        C"); break;
        case 0x0d: printf("DCR        C"); break;
        case 0x0e: printf("MVI        C, #%02x", opcode[1]); op_size = 2; break;
        case 0x0f: printf("RRC"); break;
        case 0x10: printf("NOP");
        case 0x11: printf("LXI        D, #%02x #%02x", opcode[2], opcode[1]);
                    op_size = 3; break;
        case 0x12: printf("STAX       D"); break;
        case 0x13: printf("INX        D"); break;
        case 0x14: printf("INR        D"); break;
        case 0x15: printf("DCR        D"); break;
        case 0x16: printf("MVI        D, #%02x", opcode[1]); op_size = 2; break;
        case 0x17: printf("RAL"); break;
        case 0x19: printf("DAD"); break;
        default: printf("NOP"); break;
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
