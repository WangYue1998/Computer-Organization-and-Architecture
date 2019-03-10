#include <stdio.h>
#include "/user/cse320/Projects/project09.support.h"

int main(){
    printf("\nNegate:\n");
    printf("-(%d) = %d\n", 1, negate(1));
    printf("-(%d) = %d\n", 2, negate(2));
    printf("-(%d) = %d\n", 0, negate(0));
    printf("-(%d) = %d\n", 89, negate(89));
 

    printf("Absolute:\n");
    printf("abs(%d) = %d\n", 1, absolute(1));
    printf("abs(%d) = %d\n", -1, absolute(-1));
    printf("abs(%d) = %d\n", 69, absolute(69));
    printf("abs(%d) = %d\n", -100, absolute(-100));


	printf("Add:\n");
    printf(" %d + %d = %d\n", 1, 1, add(1,1));
    printf("%d + %d = %d\n", -1, 1, add(-1,1));
    printf(" %d + %d = %d\n", 2, -2, add(2,-2));
    printf("%d + %d = %d\n", 25, 12, add(25,12));
    printf("%d + %d = %0x\n", 0x7FFFFFFF, 0x7FFFFFFF, add(0x7FFFFFFF,0x7FFFFFFF)); //overflow

    printf("Sub:\n");
    printf(" %d - %d = %d\n", 1, 1, sub(1,1));
    printf("%d - %d = %d\n", -1, 1, sub(-1,1));
    printf(" %d - %d = %d\n", 2, -2, sub(2,-2));
    printf("%d - %d = %d\n", 25, 12, sub(25,12));
    printf("%d + %d = %0x\n", 0x7FFFFFFF, -0x7FFFFFFF, sub(0x7FFFFFFF,-0x7FFFFFFF)); //overflow

    printf("Mul:\n");
	printf("%08x * %d = %08x\n", 2147483647, 2, mul(2147483647,2));	//high overflow case
	printf("%08x * %d = %08x\n", 0x80000000, 2, mul(0x80000000,2));	//lower overflowcase
    printf(" %d * %d = %d\n", 1, 1, mul(1,1));
    printf("%d * %d = %d\n", -1, 1, mul(-1,1));
    printf(" %d * %d = %d\n", 2, -2, mul(2,-2));
    printf("%d * %d = %d\n", 25, 12, mul(25,12)); 

    printf("Divide:\n");
	printf(" %d / %d = %d\n", 0, 1, divide(0,1));
	printf(" %d / %d = %08x\n", 1, 0, divide(1,0));		//Can't divide by zero case
    printf(" %d / %d = %d\n", 1, 1, divide(1,1));
    printf("%d / %d = %d\n", -1, 1, divide(-1,1));
    printf(" %d / %d = %d\n", 2, -2, divide(2,-2));
    printf("%d / %d = %d\n", 25, 5, divide(25,5));
    printf("%d / %d = %d\n", 1, 3, divide(1,3));


    printf("Power:\n");
	printf("%d ^ %d = %d\n", 0, 2, power(0,2));
    printf("%d ^ %d = %d\n", 1, 1, power(1,1));
	printf("%d ^ %d = %08x\n", -1, -1, power(-1,-1));	//no negative powers allowed
    printf("%d ^ %d = %d\n", 2, 3, power(2,3));
    printf("%d ^ %d = %d\n", 3, 3, power(3,3));
    printf("%d ^ %d = %d\n", -1, 1, power(-1,1));
    printf("%d ^ %d = %d\n", -2, 2, power(-2,2));
    printf("%d ^ %d = %d\n", -4, 0, power(-4,0));
	printf("%d ^ %d = %08x\n", -4, -2, power(-4,-2));	//no negative powers allowed

    printf("Factorial:\n");
    printf("%d! = %d\n", 1, factorial(1));
	printf("%d! = %08x\n", -1, factorial(-1));
    printf("%d! = %d\n", 3, factorial(3));
    printf("%d! = %d\n", 5, factorial(5));
    printf("%d! = %d\n\n", 10, factorial(10));

}
