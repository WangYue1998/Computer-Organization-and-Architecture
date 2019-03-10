		.global main

		.text
main:	push	{lr}
	    
	    mov 	r4, #0 		@ Initialize Total number of characters
	    mov 	r5, #0 		@ Initialize Number of newline characters
	    mov 	r6, #0 		@ Initialize Number of whitespace characters (blanks, tabs and newlines)
	    mov 	r7, #0 		@ Initialize Number of octal digits (in the set {0-7})
	    mov 	r8, #0 		@ Initialize Number of decimal digits (in the set {0-9})
	    mov 	r9, #0 		@ Initialize Number of hexadecimal digits (in the set {0-9, A-F, a-f})
	    mov 	r10, #0 	@ Initialize Number of letters (in the set {A-Z, a-z})


loop: 	bl 		getchar 	@ Read one character (returned in r0)
		cmp 	r0, #-1 	@ Compare return value to EOF
		beq 	end 		@ When EOF found, exit loop
		bl 		putchar 	@ Write one character (returned in r0)
		add 	r4, r4, #1 	@ Increment character count

ifNew:	cmp		r0, #0x0a	@ Compare return value to newline
		beq 	thenNew 	@ If newline found
		b       ifwhite

thenNew:add 	r5, r5, #1 	@ Increment Newline count
		add 	r6, r6, #1 	@ Increment whitespace count
		b 		loop 		@ Branch to top of loop

ifwhite:cmp	    r0, #0x20	@ Compare return value to blank
		beq	    thenwhite   @ If whitespace found
		
		cmp	    r0, #0x09	@ Compare return value to tab
		beq	    thenwhite   @ If whitespace found		
		b       ifd

thenwhite:
		add 	r6, r6, #1 	@ Increment whitespace count
		b 		loop 		@ Branch to top of loop
		
ifd:	cmp     r0, #'0'    @compare with decimal 0
		blt     endifd		@ if less than 0
		cmp     r0, #'9'    @compare with decimal 9
		bgt     endifd      @ greater than 9
		
		add 	r8, r8, #1 	@ Increment decimal count
		add 	r9, r9, #1 	@ Increment hexadecimal count
		
		cmp     r0, #'8'    @ compare with decimal 8
		blt     theno       @ if less than 8, satisfy the condition of octal digits
		b       loop


theno:  add 	r7, r7, #1 	@ Increment octal digits count
		b 		loop 		@ Branch to top of loop			

endifd: b       iflowl

		
iflowl:	cmp     r0, #'a'    @compare with a
		blt     endifl		@ if less than a
		cmp     r0, #'z'    @compare with z
		bgt     endifl     	@ greater than z
		
		add		r10, r10, #1 @ Increment lower case letter count
	    cmp     r0, #'g'	@ compare with g
	    blt     thenh1      @ if less than 'g', then satisfy the condition of hex digits 'a'-'f'
	    b       loop

thenh1: add 	r9, r9, #1 	@ Increment hex digits count
		b 		loop 		@ Branch to top of loop    

endifl: b       ifuppl


ifuppl:	cmp     r0, #'A'    @compare with A
		blt     endifu		@ if less than A
		cmp     r0, #'Z'    @compare with Z
		bgt     endifu    	@ greater than Z
		
		add		r10, r10, #1 @ Increment upper case letter count
	    cmp     r0, #'G'	@ compare with G
	    blt     thenh2      @ if less than 'G', then satisfy the condition of hex digits 'A'-'F'
		b       loop

thenh2: add 	r9, r9, #1 	@ Increment hex digits count
		b 		loop 		@ Branch to top of loop    

endifu: b       loop
		
		


end: 	ldr 	r0, =fmt 	@ First arg -- address of format string
		mov 	r1, r4 		@ Second arg -- character count
		bl 		printf 		@ Print the number of characters
		
		ldr 	r0, =fmt1 	@ First arg -- address of format string
		mov 	r1, r5 		@ Second arg -- character count
		bl 		printf 		@ Print the number of characters
		
		ldr 	r0, =fmt2 	@ First arg -- address of format string
		mov 	r1, r6 		@ Second arg -- character count
		bl 		printf 		@ Print the number of characters
		
		ldr 	r0, =fmt3 	@ First arg -- address of format string
		mov 	r1, r7		@ Second arg -- character count
		bl 		printf 		@ Print the number of characters
		
		ldr 	r0, =fmt4 	@ First arg -- address of format string
		mov 	r1, r8		@ Second arg -- character count
		bl 		printf 		@ Print the number of characters
		
		ldr 	r0, =fmt5 	@ First arg -- address of format string
		mov 	r1, r9 		@ Second arg -- character count
		bl 		printf 		@ Print the number of characters
		
		ldr 	r0, =fmt6 	@ First arg -- address of format string
		mov 	r1, r10 		@ Second arg -- character count
		bl 		printf 		@ Print the number of characters
 
 
		pop 	{lr}
		bx 		lr

fmt:	.asciz	"\nTotal Number of Characters = %d\n"
fmt1:	.asciz	"Number of newline characters = %d\n"
fmt2:	.asciz	"Number of whitespace characters (blanks, tabs and newlines) = %d\n"
fmt3:	.asciz	"Number of octal digits (in the set {0-7}) = %d\n"
fmt4:	.asciz	"Number of decimal digits (in the set {0-9}) = %d\n"
fmt5:	.asciz	"Number of hexadecimal digits (in the set {0-9, A-F, a-f}) = %d\n"
fmt6:	.asciz	"Number of letters (in the set {A-Z, a-z}) = %d\n"










