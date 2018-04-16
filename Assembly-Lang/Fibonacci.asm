%include "io.mac"

section .data
	input_message db "Input a number",0
	neg_error db	"Negative number error",0
section .text
	global _start
	_start:

input:
	
	PutStr input_message
	nwln
	GetLInt eax		;Get Input number

	
	mov ebx,1	;1st fibonacci number
	mov ecx,1	;2nd fibonnaci number
	
	cmp eax,0
	jle disp_error
	
	cmp eax,1
	je first

	cmp eax,2
	call second

	sub eax,2
	;PutLInt eax

	call fib
	
done:	
	nwln	
.EXIT

disp_error:
	PutStr neg_error
	nwln
	jmp input

first:
	nwln
	PutLInt ebx	;Print first number
	jmp done

second:
	nwln
	PutLInt ebx	;Print first number
	nwln
	PutLInt ecx	;Print second number
	ret

fib:
	cmp eax,0
	jle fib_ret	
	
	mov edx,ecx	;Edx is the next fib. Copy ECX to EDX
	add edx,ebx	;Edx = ecx+ebx
	mov ebx,ecx	;Ebx = Ecx
	mov ecx,edx	;Ecx=EDX
	
	nwln
	PutLInt ecx 	;Print new number
	
	dec eax
	call fib
fib_ret:	
ret

