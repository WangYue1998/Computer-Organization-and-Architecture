#include <stdio.h>
#include "/user/cse320/Projects/project12.support.h"

int main(){
	unsigned test;

	test = update(0x00012000, 0xE00B0005, 0xA0000000);
	printf("new nPC = %x\n", test);//5
	
	test = update(0x00012000, 0x638610CC, 0xA0000000);
	printf("new nPC = %x\n", test);//5
	
	test = update(0x00012000, 0x40292005, 0xA0000000);
	printf("new nPC = %x\n", test);//5
	
	test = update(0x00012000, 0xE5983004, 0xA0000000);
	printf("new nPC = %x\n", test);//5
	
	test = update(0x00012000, 0xE5864002, 0xA0000000);
	printf("new nPC = %x\n", test);//5
	
	test = update(0x00012000, 0x0A000005, 0xA0000000);
	printf("new nPC = %x\n", test);//5
	
	test = update(0x00012000, 0xEAFFFFF6, 0xA0000000);
	printf("new nPC = %x\n", test);//5
	
	test = update(0x00012000, 0xEB000009, 0xA0000000);
	printf("new nPC = %x\n", test);//5
	
	// 00 data processingn pass
	test = update(0x00000001, 0x40000001, 0x00e00000);
	printf("PC = %x\n", 0x00000001);//1
	printf("new nPC = %x\n", test);//5
	
	// 01 data movement pass
	test = update(0x00000002, 0x46000001, 0x00e00000);
	printf("PC = %x\n", 0x00000002);//2
	printf("new nPC = %x\n", test);//6
	
	
	
	// 10 branch pass    sign_extend
	
	// invalid cond
	test = update(0x00000001, 0xfa123456, 0x40000000);
	printf("PC = %x\n", 0x00000001);//1
	printf("new nPC = %x\n", test); // 0
	
	// invalid I
	test = update(0x00000001, 0x08123456, 0x40000000);
	printf("PC = %x\n", 0x00000001);//1
	printf("new nPC = %x\n", test); // 0
	
	// EQ
	test = update(0x00000001, 0x0a123456, 0x40000000);
	printf("PC = %x\n", 0x00000001);//1
	printf("new nPC = %x\n", test); // sign_extend
	
	test = update(0x00000001, 0x0aabcdef, 0x40000000);
	printf("PC = %x\n", 0x00000001);//1
	printf("new nPC = %x\n", test); // sign_extend
	
	test = update(0x00000001, 0x0a123456, 0x00000000);
	printf("PC = %x\n", 0x00000001);//1
	printf("new nPC = %x\n", test); // 5
	
	// NE
	test = update(0x00000001, 0x1b123456, 0x00000000);
	printf("PC = %x\n", 0x00000001);//1
	printf("new nPC = %x\n", test); // sign_extend
	
	test = update(0x00000001, 0x1b123456, 0x40000000);
	printf("PC = %x\n", 0x00000001);//1
	printf("new nPC = %x\n", test); // 5
	
	// CS
	test = update(0x00000001, 0x2a123456, 0x20000000);
	printf("PC = %x\n", 0x00000001);//1
	printf("new nPC = %x\n", test); // sign_extend
	
	test = update(0x00000001, 0x2a123456, 0x40000000);
	printf("PC = %x\n", 0x00000001);//1
	printf("new nPC = %x\n", test); // 5
	
	//CC
	test = update(0x00000001, 0x3a123456, 0x40000000);
	printf("PC = %x\n", 0x00000001);//1
	printf("new nPC = %x\n", test); // sign_extend
	
	test = update(0x00000001, 0x3a123456, 0x20000000);
	printf("PC = %x\n", 0x00000001);//1
	printf("new nPC = %x\n", test); // 5
	
	// MI
	test = update(0x00000001, 0x4a123456, 0x90000000);
	printf("PC = %x\n", 0x00000001);//1
	printf("new nPC = %x\n", test); // sign_extend
	
	test = update(0x00000001, 0x4a123456, 0x20000000);
	printf("PC = %x\n", 0x00000001);//1
	printf("new nPC = %x\n", test); // 5
	
	//PL
	test = update(0x00000001, 0x5b123456, 0x20000000);
	printf("PC = %x\n", 0x00000001);//1
	printf("new nPC = %x\n", test); // sign_extend
	
	test = update(0x00000001, 0x5b123456, 0x90000000);
	printf("PC = %x\n", 0x00000001);//1
	printf("new nPC = %x\n", test); // 5
	
	// VS
	test = update(0x00000001, 0x6a123456, 0x10000000);
	printf("PC = %x\n", 0x00000001);//1
	printf("new nPC = %x\n", test); // sign_extend
	
	test = update(0x00000001, 0x6a123456, 0x60000000);
	printf("PC = %x\n", 0x00000001);//1
	printf("new nPC = %x\n", test); // 5
	
	//VC
	test = update(0x00000001, 0x7b123456, 0x60000000);
	printf("PC = %x\n", 0x00000001);//1
	printf("new nPC = %x\n", test); // sign_extend
	
	test = update(0x00000001, 0x7b123456, 0x10000000);
	printf("PC = %x\n", 0x00000001);//1
	printf("new nPC = %x\n", test); // 5
	
	//HI
	test = update(0x00000001, 0x8a123456, 0xb0000000);
	printf("PC = %x\n", 0x00000001);//1
	printf("new nPC = %x\n", test); // sign_extend
	
	test = update(0x00000001, 0x8a123456, 0x40000000);
	printf("PC = %x\n", 0x00000001);//1
	printf("new nPC = %x\n", test); // 5
	
	//LS
	test = update(0x00000001, 0x9b123456, 0x00000000);
	printf("PC = %x\n", 0x00000001);//1
	printf("new nPC = %x\n", test); // sign_extend
	
	test = update(0x00000001, 0x9b123456, 0xb0000000);
	printf("PC = %x\n", 0x00000001);//1
	printf("new nPC = %x\n", test); // 5
	
	// GE
	test = update(0x00000001, 0xaa123456, 0x90000000);
	printf("PC = %x\n", 0x00000001);//1
	printf("new nPC = %x\n", test); // sign_extend
	
	test = update(0x00000001, 0xaa123456, 0x80000000);
	printf("PC = %x\n", 0x00000001);//1
	printf("new nPC = %x\n", test); // 5
	
	// LT
	test = update(0x00000001, 0xba123456, 0x80000000);
	printf("PC = %x\n", 0x00000001);//1
	printf("new nPC = %x\n", test); // sign_extend
	
	test = update(0x00000001, 0xba123456, 0x90000000);
	printf("PC = %x\n", 0x00000001);//1
	printf("new nPC = %x\n", test); // 5
	
	// GT
	test = update(0x00000001, 0xcb123456, 0x90000000);
	printf("PC = %x\n", 0x00000001);//1
	printf("new nPC = %x\n", test); // sign_extend
	
	test = update(0x00000001, 0xcb123456, 0x80000000);
	printf("PC = %x\n", 0x00000001);//1
	printf("new nPC = %x\n", test); // 5
	
	//LE
	test = update(0x00000001, 0xda123456, 0x40000000);
	printf("PC = %x\n", 0x00000001);//1
	printf("new nPC = %x\n", test); // sign_extend
	
	test = update(0x00000001, 0xda123456, 0x90000000);
	printf("PC = %x\n", 0x00000001);//1
	printf("new nPC = %x\n", test); // 5
	
	test = update(0x00000001, 0xda123456, 0x00000000);
	printf("PC = %x\n", 0x00000001);//1
	printf("new nPC = %x\n", test); // 5
	
	// AL
	test = update(0x00000001, 0xea123456, 0x00000000);
	printf("PC = %x\n", 0x00000001);//1
	printf("new nPC = %x\n", test); // sign_extend
	
	test = update(0x00000001, 0xea123456, 0x90000000);
	printf("PC = %x\n", 0x00000001);//1
	printf("new nPC = %x\n", test); // sign_extend
	


}
