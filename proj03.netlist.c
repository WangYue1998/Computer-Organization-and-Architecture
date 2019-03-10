
/******************************************************************************
  Project #3 skeleton
******************************************************************************/

#include <Sim.h>

void circuits( SD, Signal, Signal, Signal, Signal, 
  Signal, Signal, Signal, Signal, Signal, Signal, Signal, Signal );


/******************************************************************************
  Function "simnet"   -- test bed for student circuits
******************************************************************************/

void simnet()
{
  Signal w, x, y, z, Present, a, b, c, d, e, f, g;

  // Replace with code to generate four input signals
  Signal Strobe (1);   // Counter strobe input
  Signal ResetA (1);   // Counter reset signal (before complemented)
  Signal ResetB (1);   // Counter reset signal (after complemented)

  // A pulser is used to generate a temporary value of "One" on a specified
  //  signal line (signal value:  Zero ==> One ==> Zero)
  
  Pulser ((SD("1a"), "r -- Reset counter"),  ResetA, 'r', 10000);
  Pulser ((SD("2a"), "s -- Strobe counter"), Strobe, 's', 10000);
  
  // Complement the reset signal (counter reset is active low)
    
  Not (SD("1b"), ResetA, ResetB);
  Counter ((SD("1c-2c"), "4-bit counter"), (ResetB, Strobe), (w,x,y,z));

  circuits( SD("1d-4d"), w,x,y,z, Present, a, b, c, d, e, f, g);

  // Replace with code to display eight output signals
  Probe ( (SD("1f"), "P"), Present );     // Probe
  Probe ( (SD("2f"), "a"), a );           // Probe
  Probe ( (SD("3g"), "b"), b );           // Probe
  Probe ( (SD("5g"), "c"), c );           // Probe
  Probe ( (SD("6f"), "d"), d );           // Probe
  Probe ( (SD("5e"), "e"), e );           // Probe
  Probe ( (SD("3e"), "f"), f );           // Probe
  Probe ( (SD("4f"), "g"), g );           // Probe
}


/******************************************************************************
  Function "circuits" -- implementation of student circuits

  Do not alter the interface -- function "circuits" must receive four
  signals as inputs and return eight signals as outputs.
*****************************************************************************/

void circuits( SD sd, Signal w, Signal x, Signal y, Signal z, 
  Signal Present, Signal a, Signal b, Signal c, Signal d, Signal e,
  Signal f, Signal g )    
{
  Module( (sd, "circuits"), (w, x, y, z), (Present, a, b, c, d, e, f, g) );

  // Replace with declarations for any auxiliary Signals
  Signal notw, notx, noty, notz;
  Signal and1, and2, and3, and4, and5, and6, and7, and8, and9, and10; // Intermediate objects 
  
  // Replace with circuit implementation (Not, And, Or gates)
  Not ( SD(sd,"1a"), w, notw );           // NOT gates
  Not ( SD(sd,"2a"), x, notx );
  Not ( SD(sd,"3a"), y, noty );
  Not ( SD(sd,"4a"), z, notz );
 
  And ( SD(sd,"1b"), (x, notw), and1 );   // AND gates                                     
  And ( SD(sd,"2b"), (y, notx, notz), and2 );
  And ( SD(sd,"3b"), (w, notx, notz), and3 );
  And ( SD(sd,"4b"), (noty, notz), and4 );    
  And ( SD(sd,"5b"), (y,z), and5 );    
  And ( SD(sd,"6b"), (w, noty), and6 );    
  And ( SD(sd,"7b"), (z, noty), and7 );    
  And ( SD(sd,"8b"), (y, notw, notz), and8 );    
  And ( SD(sd,"9b"), (y, notz), and9 );    
  And ( SD(sd,"1d"), (x, notz), and10 );    
               
  Or ( SD(sd,"1c"), (and1, and2, and3), Present );    // OR gate
  Or ( SD(sd,"2c"), (w, z, y), a );
  Or ( SD(sd,"3c"), (notx, and4, and5), b );
  Or ( SD(sd,"4c"), (w, x), c );
  Or ( SD(sd,"5c"), (and6, and7, and8), d );
  Or ( SD(sd,"6c"), (notx, and9), e );
  Or ( SD(sd,"7c"), (and10, w, noty), f );
  Or ( SD(sd,"8c"), (notz, noty), g );


}

