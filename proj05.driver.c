#include "/user/cse320/Projects/project05.support.h"
#include "/user/cse320/lib/bitlib.h"
#include <stdio.h>
int main () {
  char array0[]= " ";    //Testing leading whitespace and positive-sign
  int base0 = 16;
  int num0 = 0;
  int T0 = convert(array0, base0, &num0);
  if(T0 == 1){
    printf( "Value: %s base %d\n", array0, base0 );
    printf( "Decimal: %d  Hexadecimal: %08x\n\n", num0, num0);
  }

  char array[]= " 44A??A";     //Testing capitatlization and negative values
  int base = 9;
  int num = 0;
  int T = convert(array, base, &num);
  if(T == 1){
    printf( "Value: %s base %d\n", array, base );
    printf( "Decimal: %d  Hexadecimal: %08x\n\n", num, num);
  }

  /*char test19[]= "1111";     
  int base_test19 = 37;
  int num_test19 = 0;
  int Test19 = convert(test19, base_test19, &num_test19);
  if(Test19 == 1){
    printf( "Value: %s base %d\n", test19, base_test19 );
    printf( "Decimal: %d  Hexadecimal: %08x\n\n", num_test19, num_test19);
           }
  else{
    printf("invalid base\n\n");
  }

  char array1[]= "          100!";    //Testing 100! which should be 4 in base 2 (binary)
  int base1 = 2;      
  int num1 = 0;       
  int T1 = convert(array1, base1, &num1);       
  if(T1 == 1){            
    printf( "Value: %s base %d\n", array1, base1 );            
    printf( "Decimal: %d  Hexadecimal: %08x\n\n", num1, num1);              
  } 
            
            
  char array2[]= "12";            
  int base2 = 10;              
  int num2 = 0;              
  int T2 = convert(array2, base2, &num2);                 
  if(T2 == 1){                     
    printf( "Value: %s base %d\n", array2, base2 );                      
    printf( "Decimal: %d  Hexadecimal: %08x\n\n", num2, num2);                      
  }
                      
                      
  char array3[]= " -17";             
  int base3 = 10;
  int num3 = 0;
  int T3 = convert(array3, base3, &num3);
  if(T3 == 1){
    printf( "Value: %s base %d\n", array3, base3 );
    printf( "Decimal: %d  Hexadecimal: %08x\n", num3, num3);
    printf("base8: %o   twos complement %32s\n\n",num3,bit32(num3)); 
    }

  char array4[]= "  -325";     //Testing negative values
  int base4 = 10;
  int num4 = 0;
  int T4 = convert(array4, base4, &num4);
  if(T4 == 1){
    printf( "Value: %s base %d\n", array4, base4 );
    printf( "Decimal: %d  Hexadecimal: %08x\n", num4, num4);
    printf("base8: %o twos complement %32s\n", num4, bit32(num4));
  }*/
}
