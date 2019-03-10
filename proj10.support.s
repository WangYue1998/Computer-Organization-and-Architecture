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
	
