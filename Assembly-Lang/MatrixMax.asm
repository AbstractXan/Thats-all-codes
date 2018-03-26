;===============================================;
;AbstractXan					;
;===============================================;
;Input: 					;
;	m and n for a Matrix mxn		;
;	elements of the matrix			;
;===============================================;
;Output:					;
;	Matrix					;
;	Maximum Element and it's oordinates	;
;===============================================;

%include "io.mac"
section .data
	input_message db "Input m and n for m x n",0
	error_size db	"Negative number error",0
	maxx db	"The max element and position is: ",0
	neww db "Updated new max",0

	line db	"------------------",0
	leftbrace db "(",0
	comma db ", ",0
	rightbrace db ")",0

section .bss
	array resd 1000

section .text
	global _start
	_start:

	PutStr input_message

	;Clear position counters
	xor esi,esi
	xor edi,edi

input:
	; m x n input
	GetLInt ecx 	;Holds m value
	GetLInt edx		;Holds n value

	; Checking if size too big
	mov eax,ecx
	mul edx

	;PutLInt eax
	cmp eax,1000
	jge size_error

	xor esi,esi
	xor edi,edi ;max pointer
	;temp max
	mov edx,-100

input_loop:
	cmp esi,eax	;Check if max input reached as counting starts from 0.
	jge input_done

	nwln
	GetLInt ebx	;Input each of the values
	mov [array + (ESI*4)],ebx
	;PutLInt ebx
	call newmax
	nwln
	;PutLInt esi
	inc esi
jmp input_loop

input_done:

output:
	xor esi,esi

PutStr line
nwln

output_loop:
	cmp esi,eax	;Check if max input reached as counting starts from 0.
	jge output_done

	mov ebx,[array+(ESI*4)]
	PutLInt ebx


	;PutLInt esi
	inc esi
jmp output_loop

output_done:

get_max:
	nwln
	PutStr maxx
	PutLInt [array+(EDI*4)]

	;Getting position
	nwln

	mov eax,edi ;EAX=max element position
	xor edx,edx ;Clear edx for divison's remainder

	;Getting coordinates
	div ecx	; Divide EAX(position) by ECX(no. of columns)
	inc eax	;	(Increment quotient by 1 as matrix starts from 1,1 and not 0,0)
	inc edx

	;Formatting Output
	nwln
	PutStr leftbrace
	PutLInt eax
	PutStr comma
	PutLInt edx
	PutStr rightbrace

	nwln
done:
.EXIT

size_error:
	PutStr error_size
jmp done

newmax:
	PutStr neww

	;Compare if max
	cmp edx, ebx
	jg not_max

	;Putting new max in edx
	mov edx,ebx ;update newmax

	;Putting new position in edi
	mov edi,esi ;

	;PutLInt edx
	;PutLInt edi
	;PutStr line
not_max:
ret
