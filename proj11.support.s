		.global search
		.text
		.balign 4 
search:
		push		{r4-r11,lr}
		mov 		r4, r0 			@ 1st argument: pointer to table of players
		mov 		r5, r1 			@ 2nd argument: jersey number of player to be located
		mov			r6, r2			@ 3rd argument: pointer to pointer to player  
		
		ldrh		r8, [r4, #2]	@ contens of count field (number of player)
		add			r4, r4, #4  	@ address of memory in the table  
		ldr 		r4, [r4]		@ r4 become address of the player    same with ldr  r4, [r4,#4]
		mov			r7, #0          @ initialize index to zero (index of player)
		
loop:
		cmp 		r7, r8			@ compare index of player and number of player
		bge 		endloop
		ldrh 		r9, [r4]		@ contents of number field 
		cmp			r9, r5			@ compare the key
		beq			find
		bgt			endloop			@ search false , if key exists, the address the key should be
		add 		r7, r7, #1 		@ increment index by one
		add			r4, r4, #40		@ increment r4 by the size of player
		b 			loop
 
find:
		mov			r0, #1			@ return 1			
		str         r4, [r6]		@ store the address of player in to r6 
		b			end	
endloop:
		mov			r0, #0			@ return 0
		str         r4, [r6]		@ store the address of player in to r6
		b			end
end:
		pop 		{r4-r11,lr}
		bx 			lr				@ return from search





		
		.global delete
		.data
memory:	.skip		4				@ third argument of search

		.text
		.balign 4
delete:
		push		{r4-r11,lr}
		mov			r4, r0			@ 1st argument: pointer to table of players
		mov 		r5, r1 			@ 2nd argument: jersey number of player to be deleted
		ldr			r2, =memory		@ getting the address of memory
		bl			search			@ call search function
		mov			r6,	r0			@ the return of search 1/0
		cmp 		r6, #1			@ the player is present in the table
		beq			del
		mov			r0, #0			@ cannot find player false to delete return 0	
		b			end1

del:	
		ldr         r10,=memory
		ldr			r0, [r10]		@ Destination address of player to be deleted  move records up one slots each 
		add			r1, r0, #40		@ Source address of player
		
		mov			r7, #40			@ the size of player
		ldr			r9,	[r4, #4]	@ the start address of array of player
		sub			r9, r1, r9		@ the address from the begining to the searched player
		sdiv		r9, r9, r7		@ how many player to teh searched player	
		ldrh		r8, [r4, #2]	@ the count field of table
		sub			r8, r8, r9		@ how many player to copy
		mul			r8, r8, r7		@ number of bytes of player to copy
		mov			r2, r8			@ Number of bytes to copy
		bl			memmove			@ Call function memmove  Use memmove to copy source player over destination player
		
		ldrh		r11, [r4,#2]	@ the count field of table
		sub			r11, #1			@ count -1
		strh		r11, [r4,#2]	@ save the updated count
		mov			r0, #1			@ return 1
		b           end1
end1:
		pop 		{r4-r11,lr}
		bx 			lr				@ return from delete
		
	
		
		
		.global	insert
		.data
memory1:.skip		4				@ third argument of search

		.text
		.balign 4
insert:
		push		{r4-r11,lr}
		mov			r4, r0			@ 1st argument: pointer to table of players
		mov 		r5, r1 			@ 2nd argument: jersey number of player to be inserted
		mov			r6, r2			@ 3rd argument: name of player   r2 is a pointer 
		mov         r7, r3          @ 4th argument: number of games played
		ldrh		r8, [sp, #36]	@ 5th argument: number of goals scored   
		ldrh		r9, [sp, #40]	@ 6th argumemt: number of assists scored
		
		ldr			r2, =memory1	@ getting the address of memory  
		bl			search			@ call search function
		cmp 		r0, #0			@ the player is present in the table
		bgt			false			@ the player already in there
		
		ldrh		r10, [r4]		@ the capacity field of table
		ldrh		r11, [r4,#2]	@ the count field of table
		cmp			r11, r10		@ check there is room in the table and the player is not already present
		blt			ins				@ has the room to insert
		b			false		

ins:	
		ldr			r10,=memory1
		ldr			r1, [r10]		@ Source address of player  
		add			r0, r1, #40		@ Destination address of player to be moved  move records up one slots each
cp3:	
		mov			r10, #40		@ the size of player  moving records down one slot each
		ldr			r11, [r4, #4]	@ the start address of array of player
		sub			r11, r1, r11	@ the address from the begining to the searched player
		ldrh		r8, [r4, #2]	@ the count field of table	
		mul			r8, r8, r10		@ number of bytes of player to copy
		sub			r8, r8, r11		@ how many player to copy
		mov			r2, r8			@ Number of bytes to copy
		bl			memmove			@ Call function memmove  Use memmove to copy source player over destination player
		
cp:									
		ldr			r10, =memory1	@ getting the address of memory
		ldr			r10, [r10]
		strh		r5, [r10]	    @ store the number to the player filed
		
		mov			r1, r6			@ source register
		add			r0, r10, #2		@ destination register (pointer which is a ADDRESS)
		bl			strcpy			@ store the name to the name filed 
cp2:		
		strh		r7, [r10, #28]	@ store the number to the game filed
		ldrh		r8, [sp, #36]	@ 5th argument: number of goals scored   
		strh		r8, [r10, #30]	@ store the number to the goals filed
		strh		r9, [r10, #32]	@ store the number to the assist filed
		
		add			r11, r8, r9		@ A player’s points is defined as the sum of that player’s goals and assists.
		strh		r11, [r10, #34]	@ store the number to the points filed
		
		cmp			r7, #0			@ compare the games between 0 
		bgt			div				@ float division
		fmsr		s0, r7			@ Copy value of games to FPU register
		fsitos		s1, s0			@ Covert from int to float
		fsts		s1, [r10, #36]	@ store the number to the points per game filed   
		b           ins2

ins2:		
		ldrh		r11, [r4,#2]	@ the count field of table
		add			r11, #1			@ count +1
		strh		r11, [r4,#2]	@ save the updated count
		mov			r0, #1			@ return 1 insert successfully
		b           end2

		
div:		
		fmsr		s0, r7				@ Copy value of games to FPU register
		fsitos		s1, s0				@ Covert from int to float
		fmsr		s2, r11				@ Copy value of points to FPU register
		fsitos		s3, s2				@ Covert from int to float
		fdivs		s4, s3, s1			@ Perform single precision floating point division
		fsts		s4, [r10, #36]		@ store the number to the points per game filed
		b			ins2
				
				
false:
		mov			r0, #0			@ insert false, return 0
		b			end2  
			
end2:
		pop 		{r4-r11,lr}
		bx 			lr				@ return from insert
	
		

		





