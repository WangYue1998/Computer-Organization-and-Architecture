
/******************************************************************************
  Project #4 skeleton
******************************************************************************/

#include <Sim.h>

void circuits( SD, Signal, Signal, Signal, Signal, Signal, Signal );


/******************************************************************************
  Function "simnet"   -- test bed for student circuits
******************************************************************************/

void simnet()
{
  Signal Init, Clock, w, x, y, z;

  // Replace with code for your Pulsers
  Pulser ((SD("1a"), "i - Init"), Init, 'i', 1000);
  Pulser ((SD("2a"), "c - Clock" ), Clock,  'c', 1000);

  circuits( SD("2b-5b"), Init, Clock, w, x, y, z );

  // Replace with code for your Probes
  Probe ( (SD("3d"), "w"), w );        // Probe
  Probe ( (SD("4d"), "x"), x );        // Probe
  Probe ( (SD("5d"), "y"), y );        // Probe
  Probe ( (SD("6d"), "z"), z );        // Probe
}


/******************************************************************************
  Function "circuits" -- implementation of student circuits
******************************************************************************/

void circuits( SD sd, Signal Init, Signal Clock, 
  Signal w, Signal x, Signal y, Signal z )
{
  Module( (sd, "circuits"), (Init, Clock), (w, x, y, z) );

  // Replace with declarations for any auxiliary Signals
  Signal notw, notx, noty, notz;
  Signal and1, and2, and3, and4, and5, and6, and7, and8;  
  // Intermediate objects 
  Signal W, X, Y,Z;

  // Replace with code for your DFFs
  Dff ((SD(sd,"3b"), "Dff0"), (Init, W, Clock, Zero), w);
  Dff ((SD(sd,"4b"), "Dff1"), (Zero, X, Clock, Init), x);
  Dff ((SD(sd,"5b"), "Dff2"), (Init, Y, Clock, Zero), y);
  Dff ((SD(sd,"6b"), "Dff3"), (Zero, Z, Clock, Init), z);

  // Replace with circuit implementation (Not, And, Or gates)
  Not ( SD(sd,"1e"), w, notw );           // NOT gates
  Not ( SD(sd,"2e"), x, notx );
  Not ( SD(sd,"3e"), y, noty );
  Not ( SD(sd,"4e"), z, notz );

  And ( SD(sd,"1c"), (y, z), and1 );   // AND gates                                     
  And ( SD(sd,"2c"), (z, noty), and2 );   // AND gates                                     
  And ( SD(sd,"3c"), (y, notz), and3 );   // AND gates                                     
  And ( SD(sd,"4c"), (x, y, notz), and4 );
  And ( SD(sd,"5c"), (x, notz), and5 );
  And ( SD(sd,"6c"), (w, y), and6 );   // AND gates                                     
  And ( SD(sd,"7c"), (notw, notx), and7 );
  And ( SD(sd,"8d"), (w, noty), and8 );   // AND gates

  Or ( SD(sd,"1d"), (and1, and8), W );    // OR gate
  Or ( SD(sd,"2d"), (and3, and2), X );    // OR gate
  Or ( SD(sd,"3d"), (and7, and5, and8), Y);    // OR gate
  Or ( SD(sd,"4d"), (and4, and6), Z );    // OR gate

   
}

