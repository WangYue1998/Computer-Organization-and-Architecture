#include "/user/cse320/Projects/project06.support.h"

double add( double a, double b ){

  union double_precision numa;
  numa.drep = a;
  unsigned long long int biased_expa = (numa.irep >>52) & 0x7ff; 
  unsigned long long int a_sign = (numa.irep >> 63);
  unsigned long long int a_fracfield = ((numa.irep << 12) >> 12);
  
  union double_precision numb, Sum;
  numb.drep = b;
  unsigned long long int biased_expb = (numb.irep >> 52)& 0x7ff;
  unsigned long long int b_sign = (numb.irep >>63 );
  unsigned long long int b_fracfield = ( (numb.irep <<12) >>12);
 
 
  long long int siga = (0x10000000000000 |a_fracfield); //Place leading bit in both significands.
  long long int sigb = (b_fracfield | 0x10000000000000);
  
  if (a_sign != b_sign){
	  if( b_sign == 0x0){
		siga = 0- siga;
		}
	  else{
		sigb = 0-sigb;
		}
  }
  
  
  if (biased_expa == 0x7ff ){
    return numa.drep ;
  }
  if (biased_expb == 0x7ff ){
    return numb.drep;
  }
 
  
  if (biased_expa == 0x000){
    return numb.drep;
  }
  if( biased_expb == 0x000){
    return numa.drep;
  }

  unsigned long long int fraction;
  unsigned long long int  exp_c;
  unsigned int temp_exp;
  unsigned long long int sign;
  
  
  if( biased_expa >= biased_expb){
    exp_c = biased_expa;
    temp_exp = biased_expa - biased_expb;
    sigb = ((unsigned long long int)sigb >> temp_exp); 
	}
  
  else {
    exp_c = biased_expb;
    temp_exp = biased_expb - biased_expa;
    siga = ((unsigned long long int)siga >> temp_exp); 
	}
  
	long long int sigc = ( siga + sigb );
	
	if (sigc == 0 && exp_c != 0x7ff)
		return 0;
		
	if (a_sign != b_sign) {
		if (sigc >=0){
			sign=0;
		}
		else{
			sign =1; 
			sigc = 0-sigc;
		}
	}
	else
		sign = a_sign;
	
	
	if( (sigc & 0x20000000000000) == 0x20000000000000){
	 exp_c +=1;
	 sigc = sigc >> 1;
	}
	else{
		while( (sigc & 0x10000000000000) == 0x0){
			sigc = sigc << 1;
			exp_c--;
		}
	
	}
	fraction = ((unsigned long long int)sigc <<12)>>12; 
	
	//Normalize significand of C.
    Sum.irep =  (sign <<63) | (exp_c <<52)  | fraction;//Insert sign, exponent, and fraction fields of C.

  return Sum.drep;
}






