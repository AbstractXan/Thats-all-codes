;AbstractXan
;Transpose of a matrix
%include"io.mac"
section .data
	input_message db "Enter the n for nxn matrix: ]",0
	output_message db "The current matrix is: ",0
	transpose_message db "Transposing... ",0
	swapping db "Swapping...",0
	space db " ",0
	key db "key: ",0
	index db "index: ",0
	here db "here...",0
	
section .bss
	matrix resd 1000
	swapped resd 1000
	order resd 1
	
section .text
	global _start
		_start:

	call input
	call output
	
	call swapped_create
	call output

	call transpose
	call output
done:
.EXIT

;======================SWAPPED MATRIX=====================================;
swapped_create:
pushad
	mov eax,[order]
	xor esi,esi				;ESI is temporary array index
	mul eax					;EAX is= size*size, i.e the number of times the input is to be taken

input_swapped_loop:
	cmp esi,eax
	jge input_swapped_done

	xor ebx,ebx
	xchg [swapped+esi*4],ebx;Input into matrix
	
	inc esi
	jmp input_swapped_loop
	
input_swapped_done:
	xor eax,eax			;Clear ecx
nwln
popad
ret
;==================================================================;

;======================OUTPUT=======================================;	
output: 
pushad	;Save state of program
	PutStr output_message

mov ecx,[order]			;ECX is order of the matrix
mov eax,ecx		
mul ecx					;EAX is= size*size, i.e the number of times the input is to be taken
xor esi,esi				;ESI is temporary row index
xor edi,edi				;EDI is temporary column index
xor ebx,ebx				;EBX is current array size
nwln
outer_loop:

	cmp ebx,[order]		;Compare if number of elements printed is less than total
	jge outer_done
	
	;PutStr key
	;PutLInt ebx
	;nwln
	
	xor edi,edi			;Reset 
	inner_loop:
		cmp edi,[order]	;Check if all columns are traversed
		jge inner_done
		
		push eax
			mov eax,esi
			mul ecx
			add eax,edi
			PutLInt [matrix+eax*4]		;Print number
		pop eax
		
		PutStr space
		inc edi	;Increment
		jmp inner_loop
	inner_done:
	
	nwln
	inc ebx		;Increment matrix number of element index
	inc esi		;Increment row index
	jmp outer_loop
	
outer_done:
nwln
popad	;Return to origianl state
ret
;====================================================================;


;======================INPUT=====================================;
input:
	PutStr input_message
	nwln

GetLInt [order]				;ECX is temporary
mov eax,[order]
xor esi,esi				;ESI is temporary array index
mul eax					;EAX is= size*size, i.e the number of times the input is to be taken

input_loop:
	cmp esi,eax
	jge input_done

	GetLInt [matrix+esi*4]	;Input into matrix
	inc esi
	jmp input_loop
	
input_done:
	xor eax,eax			;Clear ecx
nwln
ret
;==================================================================;

;========================TRANSPOSE========================================;
transpose: 
;pushad	;Save state of program
	PutStr transpose_message

mov ecx,[order]			;ECX is order of the matrix
mov eax,ecx		
mul ecx					;EAX is= size*size, i.e the number of times the input is to be taken
xor esi,esi				;ESI is temporary row index
xor edi,edi				;EDI is temporary column index
xor ebx,ebx				;EBX is current array size
nwln
outer_trans:

	cmp ebx,ecx		;Compare if number of elements printed is less than total
	jge outer_trans_done
	
	xor edi,edi			;Reset 
	inner_trans:
		
		cmp edi,[order]	;Check if all columns are traversed
		jge inner_trans_done

			call swap	;Swap indices

		PutStr space
		inc edi		;Increment
		jmp inner_trans
		
	inner_trans_done:
	
	nwln
	inc ebx		;Increment matrix number of element index
	inc esi		;Increment row index
	jmp outer_trans
	
outer_trans_done:
nwln
;popad	;Return to original state
ret

;======================SWAP====================================; SWAPS THE INDICES OF MATRIX
;Swap esi and edi index values where transposed == 0
swap:
	
	PutStr swapping
	nwln
	
	push eax
	push ebx
	push edx
	push esi 
	push edi
	
	;EAX IS TEMPORARY VARIABLE
	;First index value 
	mov eax,esi
	mul ecx
	add eax,edi
	
	push eax	;Push value of esi computed	ESI = EDI*ORDER+ESI
	
	;Second index value 
	mov eax,edi
	mul ecx
	add eax,esi
	
	mov esi,eax	;ESI = EDI*ORDER+ESI
	
	pop eax
	mov edi,eax	;Assign edi value just computed EDI = ESI*ORDER+EDI
	
	xor eax,eax
	
	cmp esi,edi	;CHECK IF INDICES ARE SAME, IF SAME, MARK SWAPPED
	je done_swap
	
	mov eax,[swapped+esi*4]
	cmp eax,1			;CHECK IF INDEX ALREADY SWAPPED
	je done_swap
	
	;IF NOT SWAPPED , SWAP
	xor edx,edx
	xor ebx,ebx
	
	;swap values
	xchg edx,[matrix+esi*4]
	xchg ebx,[matrix+edi*4]
	xchg edx,ebx
	xchg edx,[matrix+esi*4]
	xchg ebx,[matrix+edi*4]
	
	

done_swap:
	xor edx,edx
	xor ebx,ebx
	
	mov edx,1
	
	xchg [swapped+esi*4],edx	;MARK INDICES AS SWAPPED
	xchg [swapped+edi*4],edx	

	pop edi
	pop esi
	pop edx
	pop ebx
	pop eax
ret

;====================================================================;	



