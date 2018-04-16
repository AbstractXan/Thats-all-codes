; AbstractXan

%include"io.mac"
section .data
	
section .bss
	string resb 100
	strlen resd 1
	array resd 100
	

section .text
	global _start 
	_start:
	GetStr string,100
	mov eax,string    ;String pointer EAX  

	xor ecx,ecx	      ;ecx holds string length
count:
	mov bl,[eax]      ;bl is a charachter of string
	cmp bl,0          ;if bl is empty
	je done
	PutCh bl          ;Print Charachter
	inc eax           ;Increment string pointer
	inc ecx           ;Increment String length
	jmp count

done:
	nwln

	mov [strlen],ecx  ;Assign String length to strlen
	PutLInt [strlen]  ;Output Strlen

.EXIT
