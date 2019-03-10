#include <stdio.h>
#include "/user/cse320/Projects/project06.support.h"

int main () {
  union double_precision a1 ;
  a1.irep=0x7ff0000000000000;
  double b1 = 5;  
  union double_precision T1;
 T1.drep = add( a1.drep, b1 );
  printf( "Values: %f + %f\n", a1.drep, b1 );
  printf( "Equal = : %f\n" ,  T1.drep ); 
  printf("\n");
  
  union double_precision B1 ;
  B1.irep=0xfff0000000000001;
  double b0 = 5;  
  double B2 = add( B1.drep, b0 );
  printf( "Values: %f + %f\n", B1.drep, b0 );
  printf( "Equal =: %f\n" ,  B2 ); 
   printf("\n");
            
  double d1 = +17.75; 
  b1 = -5.555;  
  T1.drep = add( d1, b1 );
  union double_precision trueT1 ;
  trueT1.drep = 17.75-5.555;
  printf( "Values: %f + %f\n", d1, b1 );
  printf( "Equal = Double: %f    Hexadecimal: %016llx True: %016llx\n", T1.drep, T1.irep , trueT1.irep);
  printf("\n");
  
  d1 = +0; 
  b1 = -5.825;  
  T1.drep = add( d1, b1 );
  trueT1.drep = 0-5.825;
  printf( "Values: %f + %f\n", d1, b1 );
  printf( "Equal = Double: %f    Hexadecimal: %016llx True: %016llx\n", T1.drep, T1.irep , trueT1.irep);
  printf("\n");
  
  d1 = -7.58642; 
  b1 = +2.588;  
  T1.drep = add( d1, b1 );
  trueT1.drep = d1+b1;
  printf( "Values: %f + %f\n", d1, b1 );
  printf( "Equal = Double: %f    Hexadecimal: %016llx True: %016llx\n", T1.drep, T1.irep , trueT1.irep);
  printf("\n");
  
  d1 = +89.58785; 
  b1 = -19.525;  
  T1.drep = add( d1, b1 );
  trueT1.drep = d1+b1;
  printf( "Values: %f + %f\n", d1, b1 );
  printf( "Equal = Double: %f    Hexadecimal: %016llx True: %016llx\n", T1.drep, T1.irep , trueT1.irep);
  printf("\n");
  
  d1 = 1088.47683; 
  b1 = 104.47683;  
  T1.drep = add( d1, b1 );
  trueT1.drep = d1+b1;
  printf( "Values: %f + %f\n", d1, b1 );
  printf( "Equal = Double: %f    Hexadecimal: %016llx True: %016llx\n", T1.drep, T1.irep , trueT1.irep);
  printf("\n");
  
  d1 = -14.2341; 
  b1 = -2059.123;  
  T1.drep = add( d1, b1 );
  trueT1.drep = d1+b1;
  printf( "Values: %f + %f\n", d1, b1 );
  printf( "Equal = Double: %f    Hexadecimal: %016llx True: %016llx\n", T1.drep, T1.irep , trueT1.irep);
  printf("\n");
  
  d1 = -108.885; 
  b1 = -2043.25;  
  T1.drep = add( d1, b1 );
  trueT1.drep = d1+b1;
  printf( "Values: %f + %f\n", d1, b1 );
  printf( "Equal = Double: %f    Hexadecimal: %016llx True: %016llx\n", T1.drep, T1.irep , trueT1.irep);
  printf("\n");
  
  
  d1 = +856.5; 
  b1 = +2.0;  
  T1.drep = add( d1, b1 );
  trueT1.drep = d1+b1;
  printf( "Values: %f + %f\n", d1, b1 );
  printf( "Equal = Double: %f    Hexadecimal: %016llx True: %016llx\n", T1.drep, T1.irep , trueT1.irep);
  printf("\n");
  
  d1 = 108.35675; 
  b1 = -108.3745;  
  T1.drep = add( d1, b1 );
  trueT1.drep = d1+b1;
  printf( "Values: %f + %f\n", d1, b1 );
  printf( "Equal = Double: %f    Hexadecimal: %016llx True: %016llx\n", T1.drep, T1.irep , trueT1.irep);
  printf("\n");
  
  double a0 = -17856.75;  
  b0 = +17856.75;
  double T0 = add( a0, b0 );
  printf( "Values: %f + %f\n", a0, b0 );
  printf( "Equal = Double: %f \n ", T0 );
  printf("\n");
 
}


