#include "/user/cse320/Projects/project05.support.h"

int convert( const char ch[], int base, int* num){
  
  //Testing if base is in value range of (2,36) inclusive
  if(base >36 || base<2){return 0;}
  
  int negative_value =0; // negative sign
  int value = 0;
  *num = 0; // inilitize internal representation:

  int i =0;
  if (ch[i] == 0){
    return 0;
  }

  while(ch[i] != 0){// terminating null
    //begins after leading white space
    if(ch[i] == ' ' || ch[i] == '\n' || ch[i] == '\t'){     //WHITESPACE
      if(value == 1){ 
        return 1; //Just stop and return the numbers we have before the space
      }
    }

    else if(ch[i] == '-'){  //Negative-sign
      if(value == 1){
        return 1; //Just stop and return the numbers we have before the negative-sign
      }
      else{      
        negative_value = 1;
      }
    }
     
    else if(ch[i] == '+'){  //Positive-sign
       if(value == 1){
          return 1; //Just stop and return the numbers we have before the positive-sign
        }
     }
  
    else if((ch[i] >= '0') && (ch[i] <= '9')){
      int curr = (ch[i] - '0');
      if( curr >= base){
        return 0;
      } //terminates with the first invalid character.
      value = 1;
      *num = (base * (*num)) + curr;
    }

    else if((ch[i] >= 'a') && (ch[i] <= 'z')){
      int curr = ((ch[i]-'a')+10);
      if( curr >= base){
        return 0;
      }
      value = 1;
      *num = (base * (*num)) + curr;
    }

    else if((ch[i] >= 'A') && (ch[i] <= 'Z')){
      int curr = ((ch[i]-'A')+10);
      if( curr >= base){            
          return 0;                    
        }                      
      value = 1;         
      *num = (base * (*num)) + curr;               
    }
        
    else{
      if (value==0){
        return 0;}    
      return 1;
    }
    i++;
  }

  if(negative_value == 1){      
    *num = 0-(*num);//signed value
    }
  
  return 1;//the conversion is successful
 }     
