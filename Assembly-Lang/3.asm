%include "io.mac"

section .data
	input_message db "Input length of string followed by the string",0
	neg_error db	"Negative number error",0

section .bss
	string resb 1000

section .text
	global _start
	_start:

	PutStr input_message	
	
	xor esi,esi	
	xor edi,edi

input:
	GetLInt ecx
	input_loop:
		cmp esi,ecx	;Check if max input reached as counting starts from 0.
		jge input_done
		GetCh [string + (ESI*4)]
		inc esi
	jmp input_loop

input_done:

output:

	xor esi,esi
	
	output_loop:
		cmp eax,ecx	;Check if max input reached as counting starts from 0.
		jge output_done
	
		mov eax,string
		PutCh [eax]
		
		inc eax
		PutLInt eax
	jmp output_loop

output_done:





;reset counters
xor esi,esi
xor edi,edi
mov edi,ecx ;edi is at the end

palin:
cmp esi,edi			;If left counter greater than right counter : done
jge found

mov eax,string			;FIRST poisition
mov edx,string			;LAST POSITION
add edx,ecx

cmp [eax],[edx] 		;COMPARE IF CHARACHTERS FROM FROM START AND END ARE EQUAL
inc ESI				;increment front counter
dec edx				;Decrement back counter
je palin

found:
	;PRINT PALINDROME
not_found
	;PRINT NOT PALINDROME
	
.EXIT


