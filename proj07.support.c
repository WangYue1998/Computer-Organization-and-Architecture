#include <stdio.h>
#include <string.h>
#include "/user/cse320/Projects/project07.support.h"

void decode( unsigned int bit_pattern, char outary[] )	//(bit_pattern,address of array)
{	
	char w[16]={"warning"};
	if (  ((bit_pattern >>26)== 0x38)  && (((bit_pattern << 20)>>28) == 0x0) ) {
		unsigned int Ibit = (bit_pattern << 6) >> 31;
		unsigned int opcode = (bit_pattern << 7) >> 28;
		unsigned int Sbit = (bit_pattern << 11) >> 31;
		unsigned int Rn = (bit_pattern << 12) >> 28;
		unsigned int Rd = (bit_pattern << 16) >> 28;
		unsigned int imvalue = (bit_pattern << 24) >> 24;
		unsigned int Rm = (bit_pattern << 28) >> 28;
		unsigned int partRm = (bit_pattern << 24) >> 28;
		char op[16][4] = {"and","eor","sub","rsb","add","adc","sbc","rsc","tst","teq","cmp","cmn","orr","mov","bic","mvn"};
		

		if (opcode == 0xf || opcode == 0xd ){
			if (Rn == 0x0 && Sbit == 0x0){
				if (Ibit ==1){
					sprintf(outary, "%s, r%d, #0x%x", op[opcode], Rd, imvalue);
				}
				else{
					if (partRm == 0x0){
						sprintf(outary, "%s, r%d, r%d" , op[opcode], Rd, Rm);
					}
					else{
						sprintf(outary, "%s bits 7:4 not 0000 " , w);
					}	
				}
			}
			else{
				sprintf(outary, "%s, Rn not 0000 or signbit not 0" , w);
			}
		}
		
		else if (opcode == 0x8 || opcode == 0x9 || opcode == 0xa || opcode == 0xb ){
			if (Rd == 0x0 && Sbit==0x1){
				if (Ibit ==1){
					sprintf(outary, "%s, r%d, #0x%x", op[opcode], Rn, imvalue);			
				}
				else{
					if (partRm == 0x0){
						sprintf(outary, "%s, r%d, r%d" , op[opcode], Rn, Rm);
					}
					else{
						sprintf(outary, "%s bits 7:4 not 0000 " , w);
					}	
				}
			}
			else{
				sprintf(outary, "%s, Rd not 0000 or signbit not 1" , w);
			}
		}
		
		else{
			if (Ibit ==1){
				if (Sbit ==0x1){
					sprintf(outary, "%ss, r%d, r%d, #0x%x" , op[opcode], Rd, Rn, imvalue);
				}
				else{
					sprintf(outary, "%s, r%d, r%d, #0x%x", op[opcode], Rd, Rn, imvalue);
				}
			}
			else{
				if (partRm == 0x0){
					if (Sbit ==0x1){
						sprintf(outary, "%ss, r%d, r%d, r%d" , op[opcode], Rd, Rn, Rm);
					}
					else{
						sprintf(outary, "%s, r%d, r%d, r%d" , op[opcode], Rd, Rn, Rm);
					}	
				}
				else{
					sprintf(outary, "%s, bits 7:4 not 0000" , w);
				}
			}
		}
	}
	else{
		sprintf(outary, "%s, bits 31:26 not 111000 or bits 12:8 not 0000" , w);
	}
	
}  
