;AbstractXan
;This Code Finds Product and Quotient of two numbers without using Mult or Div operations
;---------------------------------------------------------------------------------------

%include"io.mac"
.DATA
  options db " 0 to exit | 1 for Division | 2 for Multiplication ",0
  Input_div db "Input dividend and divisor",0
  Input_mult db " Input the two numbers: ",0
  Out_div db "Quotient is: ",0
  Out_mult db "Product is: ",0

.CODE
.STARTUP
main:
  nwln
  PutStr options
  GetLInt edx
    nwln

  cmp edx,0
  je done
  cmp edx,1
  je Division

  cmp edx,2
  je Multiplication


  done:
.EXIT

Division:
  PutStr Input_div
    nwln
  GetLInt eax
  GetLInt ebx
    nwln

  xor edx,edx
  xor ecx,ecx ;ecx is temp variable
  jmp div_loop

  done_div:
  PutStr Out_div
  dec edx;Quotient
  PutLInt edx
    nwln
  ;Clear

  mov edx,1
  xor eax,eax
  xor ebx,ebx

jmp main

div_loop:
  add ecx,ebx
  inc edx     ;Tracks 1+ quotient
  cmp ecx,eax
  jg done_div ;if less
call div_loop

Multiplication:
  PutStr Input_mult
    nwln
  GetLInt eax
  GetLInt ebx
    nwln


  xor ecx,ecx   ;ecx is temp variable
  jmp mult_loop

  done_mult:
  PutStr Out_mult
  PutLInt ecx
    nwln

  ;Clear
  xor eax,eax
  xor ebx,ebx
jmp main

mult_loop:
  add ecx,eax
  dec ebx
  cmp ebx,0
  jle done_mult
  ;PutLInt ebx

call mult_loop
