#include <stdio.h>
#include "/user/cse320/Projects/project07.support.h"
#include <string.h>

int main()
{

	
	//testcase 1
	char test1[80];
	decode( 0xe086a017, test1 );
	printf( "%s\n",test1 );
	
	
	//testcase 2
	char test2[80];
	decode( 0xe096a007, test2 );
	printf( "%s\n",test2 );
	
	//testcase 3
	char test3[80];
	decode( 0xe286a007, test3 );
	printf( "%s\n",test3 );
	
	//testcase 4
	char test4[80];
	decode( 0xe1520003, test4 );
	printf( "%s\n",test4 );
	
	//testcase 5
	char test5[80];
	decode( 0xe1a01003, test5 );
	printf( "%s\n",test5 );
	
	//testcase 6
	char test6[80];
	decode( 0xe39870ff, test6 );
	printf( "%s\n",test6 );
	
	//testcase 7
	char test7[80];
	decode( 0xf39870ff, test7 );
	printf( "%s\n",test7 );
	
	//testcase 8
	char test8[80];
	decode( 0xe1a03103, test8 );
	printf( "%s\n",test8 );
	
	
	//testcase 9
	char test9[80];
	decode( 0xe24b2070, test9 );
	printf( "%s\n",test9 );
	
	//testcase 10
	char test10[80];
	decode( 0xe0822003, test10 );
	printf( "%s\n",test10 );
	

	//testcase 11
	char test11[80];
	decode( 0xf0822003, test11 );
	printf( "%s\n",test11 );
	
	//testcase 12 mov
	char test12[80];
	decode(  0xe1b01003, test12 );
	printf( "%s\n", test12 );
	
	//testcase 14 mov
	char test14[80];
	decode(  0xe1a01013, test14 );
	printf( "%s\n", test14 );
	
	
	//testcase 13
	char test13[80];
	decode(  0xe1528003, test13 );
	printf( "%s\n",test13 );
	
}

