		.global     negate	
		.text
negate:
		push		{r4-r8,lr}
		mov 		r4, r0						@ Save first argument
		neg 		r4,	r4						@ negative the value  
		bvs    		error 						@ Check for overflow
		mov 		r0, r4						@ get the negation
		pop 		{r4-r8,lr}  				@ end function
		bx 			lr

		.global     absolute
absolute:
		push		{r4-r8,lr}
		cmp         r0, #0						@ see the value is positive or negative
		bllt        negate						@ if it's negative value, convert it to positive   bl and less than
		cmp         r0, #0x80000000
		beq         error
		pop 		{r4-r8,lr}					@ end function
		bx 			lr

	
		.global     add
add:
		push 		{r4-r8,lr}
		mov 		r4, r0 						@ Save first argument
		mov 		r5, r1 						@ Save second argument
		adds 		r7, r4, r5 					@ Add the operands, set NZCV
		bvs    		error 						@ Check for overflow
		mov 		r0, r7						@ get the sum of A and B
		pop 		{r4-r8,lr}					@ end function
		bx 			lr


		.global     sub
sub:
		push 		{r4-r8,lr}
		mov 		r4, r0 						@ Save first argument
		mov 		r5, r1 						@ Save second argument
		subs		r7, r4, r5				
		bvs         error
		mov         r0, r7
		pop 		{r4-r8,lr}
		bx 			lr


		.global     mul	
mul:
		push 		{r4-r8,lr}
		mov 		r4, r0 						@ Save first argument
		mov 		r5, r1 						@ Save second argument
		smull		r8,	r7, r4, r5
		cmp			r7, #0x00000000				@ valid positive
		beq         g1
		cmp			r7, #0xffffffff				@ valid negative
		beq         g2
		b			error
g1:		cmp         r8, #0
		blt			error
		b           good
g2:		cmp         r8, #0
		bge			error
		b           good
good:	
		mov         r0, r8
		b			endmul
endmul:
		pop 		{r4-r8,lr}
		bx 			lr


		.global     divide	
divide:
		push 		{r4-r8,lr}
		mov 		r4, r0 						@ Save first argument
		mov 		r5, r1 						@ Save second argument
		cmp         r5, #0						@ 1/0 error
		beq			error
		sdiv		r7, r4, r5
		mov         r0, r7
		pop 		{r4-r8,lr}
		bx 			lr



		.global     power		
power:   
		push 		{r4-r8,lr}
		mov 		r4, r0 						@ Save first argument value
		mov 		r5, r1 						@ Save second argument power

		cmp         r5,#0
		beq         one							@ result is one

		cmp         r4,#1						@ result is one
		beq         one

		cmp         r5,#1						@ result is r0
		beq         orig

		cmp         r5, #0						@no negative powers allowed 
		bllt        error
		mov         r6, #1
		b			powerloop



powerloop:
		subs		r5, #1				      	@ power continue -1
		cmp         r5, #0						@ if greater than 0
		bge         multi
		mov			r0, r6						@ store result
		b			endpower
		
multi:	
		mov			r1, r4						@ mul base
		mov			r0, r6
		bl			mul
		cmp         r0, #0x80000000
		beq         error
		mov			r6, r0
					
		b           powerloop

one:
		mov 		r0, #1						@ return one
		b			endpower
orig:
		mov         r0, r4						@ return r0
		b			endpower
		
endpower:
		pop 		{r4-r8,lr}
		bx 			lr






		.global     factorial
factorial:
		push 		{r4-r8,lr}                 	
		mov 		r4, r0						@ store the value
		cmp         r4, #0						@ compare to 0
		blt         error
		beq			o
		cmp         r4, #1
		beq			endfactorial
		
		
		mov 		r7, r4
factloop:
		
		subs       	r4, r4,#1					@ keep subtracting
		bvs         error
		
		mov			r1, r4						@ multiply
		mov			r0, r7
		bl			mul
		cmp         r0, #0x80000000
		beq         error
		mov			r7, r0

		
		cmp     	r4,#1						@ compare to 1
		bgt			factloop
		b           endfactorial

o:		
		mov			r0, #1						@ 0!=1
		b			endfactorial
endfactorial:
		pop 		{r4-r8,lr}
		bx 			lr




error:
		mov     r0, #0x80000000					@error message
		pop		{r4-r8,lr}
		bx		lr
