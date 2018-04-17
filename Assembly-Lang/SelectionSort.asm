;AbstractXan
;Sorting

%include"io.mac"
section .data
	input_message db "Enter the array [Enter 0 to terminate]",0
	output_message db "The current array is: ",0
	sorting db "Sorting...",0
	space db " ",0
	key db "key: ",0
	index db "index: ",0
	swapping db "swapping...",0
section .bss
	array resd 1000
	size resd 1
section .text
	global _start
		_start:

call input
call output

call sort

call output
.EXIT




;======================SWAP====================================;
;Swap esi and edi index values where edi < esi
swap:
	xor edx,edx
	xor ebx,ebx
	
	xchg edx,[array+esi*4]
	xchg ebx,[array+edi*4]
	xchg edx,ebx
	xchg edx,[array+esi*4]
	xchg ebx,[array+edi*4]
	
	;ebx has the smaller number
	
	xor edx,edx
	xor ebx,ebx
ret

;======================OUTPUT=======================================;	
output: 
	PutStr output_message

xor esi,esi				;ESI is temporary array index

output_loop:
	cmp esi,[size]
	jge output_done
	
	PutLInt [array+esi*4]
	PutStr space
	inc esi
	jmp output_loop

output_done:
nwln
ret
;====================================================================;


;======================INPUT=====================================;
input:
	PutStr input_message
	nwln

mov ecx,-1				;ECX is the number count
xor esi,esi				;ESI is temporary array index

input_loop:
	inc ecx
	cmp ecx,5
	jg input_done
	
	GetLInt eax				;Eax is temporary variable
	
	cmp eax,0				;If input = 0
	je input_done			;Exit input
	
	mov [array+esi*4],eax	;Mov new value to array
	inc esi
	jmp input_loop

input_done:
	mov [size],ecx		;Move size to [size]
	xor ecx,ecx			;Clear ecx
nwln
ret
;==================================================================;


;========================SORT========================================;
sort:
	PutStr sorting
	nwln
xor esi,esi		;Counter for current key index
xor edi,edi		;Counter for current index
mov ecx,[size]	;ecx stores size of array

sort_loop:
	cmp esi,ecx				;If key counter is greater or equal to size
	jge done_sort			;Sorting complete
	
	mov eax,[array+esi*4]	;Get current key as eax
	
	;PutStr key
	;PutLInt eax
	;nwln
	
	mov edi,esi
	inc edi					;Get next index to key

	inner_loop:
	
		cmp edi,ecx				;If index counter is greater or equal to size
		jge done_inner			;Inner loop complete
		
		
		;PutStr index
		;PutLInt [array+edi*4]
		;nwln
		
		cmp eax,[array+edi*4]	;Compare other elements with key
		jl continue_inner		;If key is smaller , continue with loop

			;PutStr swapping
			;nwln
			call swap			;Swap with smaller number
			mov eax,[array+esi*4] 	;Update key value
			
		continue_inner:
		inc edi
		jmp inner_loop
	done_inner:
	
	
	inc esi						;Increment key counter
	jmp sort_loop
done_sort:
ret
;====================================================================;	


