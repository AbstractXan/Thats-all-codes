%include"io.mac"
section .data
	input_message db "Enter the number: ",0
	output_message db "The Hex Number is: ",0

	hex db "0123456789ABCDEF",0

section .text
	global _start
		_start:
		
	PutStr input_message
	GetLInt EAX				;Get Number
	mov EBX,16				;16 because hex
	xor esi,esi				;Counter for number of digits
	
hex_loop:					;Calculating Quotient and Remainders
	cmp EAX,0
	jle done_hex_loop
	
	div EBX 		;Divide by ebx
	push EDX		;Store edx(Remainder) in stack
	xor edx,edx		;Reset EDX for next division
	inc esi			;Increment counter
	jmp hex_loop

done_hex_loop:

PutStr output_message
put_loop:	
	cmp esi,0		;Check if count hits 0
	jle done_put

	mov ecx,hex		;ECX is pointer to array 'hex'
	pop	EDX			;GetBack Value of EDX (Remainder)
	add ecx,edx		;Increment pointer by remainder
	mov al,[ecx]	;Mov Charachter value to al
	PutCh al		;Print Charachter
	dec esi			;Decrement Count
	jmp put_loop
	
done_put:
nwln
.EXIT

