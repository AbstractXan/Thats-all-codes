%include"io.mac"
section .text
	global _start 
	_start:

	mov edx,7
	push edx      ;Push edx i.e 7 into stack
	
	xor edx,edx   ;Clear value to perform division
	mov ebx,6     
	mov eax,18
	div ebx
	

	PutLInt EAX   ;Prints Quotient i.e 3
	nwln
	PutLInt EDX   ;Prints Remainder i.e 0
	nwln
	pop edx       ;Prints 7
	PutLInt EDX

.EXIT
