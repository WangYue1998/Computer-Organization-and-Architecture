#include "/user/cse320/Projects/project12.support.h"


unsigned update( unsigned PC, unsigned IR, unsigned CPSR ){
	//Bits 27:26 of the IR identify the category to which a machine language instruction belongs
	unsigned op = ((IR>>26)<<30)>>30;
	
	//00 Data Processing 
	if (op == 0){
		//the default computation for all instructions is used: 
		PC = PC + 4;
		return PC;
	}

	// 01 Data Movement 
	if (op == 1){
		//the default computation for all instructions is used: 
		PC = PC + 4;
		return PC;
	}
	
		
	// 10 Branch 
	
	// Bits 23:0 simm24 (signed immediate 24-bit value) 
	unsigned simm24 = (IR << 8)>>8; 
	// When the condition field indicates that the branch should be taken, the following computation is used:
	signed simm2 = simm24<<2;
	unsigned sign_extend = (simm2<<6)>>6; 
	

	// decode CPSR
	// 31:28 of CPSR are NZCV bits
	unsigned NZCV = CPSR >> 28;
	// get N bit
	unsigned N = NZCV >> 3;
	// get Z bit
	unsigned Z = (NZCV<<29)>>31;
	// get C bit
	unsigned C = (NZCV<<30)>>31;
	// get V bit
	unsigned V = (NZCV<<31)>>31;

	
	if (op == 2){
		// decode IR
		
		// bit 25 always 1
		unsigned I = (IR<<6)>>31;
		if (I !=1){
			return 0;
		}
		
		// check condition field
		
		// Bits 31:28 cond (condition field) 
		unsigned cond = IR>> 28;

		// The value zero will be returned for illegal machine language instructions. 
		if ((cond >14) || (cond < 0)){
			return 0;
		}
		
		
		// 0000 equal Z set 
		if (cond == 0){
			if (Z == 1){
				PC = PC + 4;
				PC = PC + sign_extend;
			}
			else{
				PC = PC + 4;
			}
			return PC;
		}
				
	    // 0001 not equal Z clear 
		if (cond == 1){
			if (Z == 0){
				PC = PC + 4;
				PC = PC + sign_extend;
			}
			else{
				PC = PC + 4;
			}
			return PC;
		}
				
		// 0010 carry C set
		if (cond == 2){
			if (C == 1){
				PC = PC + 4;
				PC = PC + sign_extend;
			}
			else{
				PC = PC + 4;
			}
			return PC;
		}
				
		// 0011 not carry C clear
		if (cond == 3){
			if (C == 0){
				PC = PC + 4;
				PC = PC + sign_extend;
			}
			else{
				PC = PC + 4;
			}
			return PC;
		}
				
		// 0100 negative N set
		if (cond == 4){
			if (N == 1){
				PC = PC + 4;
				PC = PC + sign_extend;	
			}
			else{
				PC = PC + 4;
			}
			return PC;
		}
				
		// 0101 not negative N clear
		if (cond == 5){
			if (N == 0){
				PC = PC + 4;
				PC = PC + sign_extend;
			}
			else{
				PC = PC + 4;
			}
			return PC;
		}
				
		// 0110 overflow  V set
		if (cond == 6){
			if (V == 1){
				PC = PC + 4;
				PC = PC + sign_extend;	
			}
			else{
				PC = PC + 4;
			}
			return PC;
		}
			
	   // 0111 not overflow  V clear
		if (cond == 7){
			if (V == 0){
				PC = PC + 4;
				PC = PC + sign_extend;	
			}
			else{
				PC = PC + 4;
			}
			return PC;
		}
			
		// 1000 unsigned greater than  C set and Z clear
		if (cond == 8){
			if (Z == 0 && C ==1){
				PC = PC + 4;
				PC = PC + sign_extend;	
			}
			else{
				PC = PC + 4;
			}
			return PC;
		}
			
		// 1001 unsigned less than or equal to C clear or Z set
		if (cond == 9){
			if (Z == 1 || C ==0){
				PC = PC + 4;
				PC = PC + sign_extend;	
			}
			else{
				PC = PC + 4;
			}
			return PC;
		}
			
		// 1010 signed greater than or equal to N == V
		if (cond == 10){
			if (N == V){
				PC = PC + 4;
				PC = PC + sign_extend;
			}	
			else{
				PC = PC + 4;
			}
			return PC;
		}
			
		// 1011 signed less than N != V
		if (cond == 11){
			if (N != V){
				PC = PC + 4;
				PC = PC + sign_extend;	
			}
			else{
				PC = PC + 4;
			}
			return PC;
		}
			
		// 1100 signed greater than Z clear and N== V
		if (cond == 12){
			if (N == V && Z == 0){
				PC = PC + 4;
				PC = PC + sign_extend;
			}	
			else{
				PC = PC + 4;
			}
			return PC;
		}
			
		// 1101 signed less than or equal to Z set or N!= V
		if (cond == 13){
			if (N != V || Z == 1){
				PC = PC + 4;
				PC = PC + sign_extend;	
			}
			else{
				PC = PC + 4;
			}
			return PC;
		}
		
		// 1110 always irrelevant
		if (cond == 14){
			PC = PC + 4;
			PC = PC + sign_extend;
			return PC;
		}
	}
	
	return 0;
}
