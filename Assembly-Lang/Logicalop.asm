%include"io.mac"
.DATA
  input_line  db "Enter numbers A and B",0
  and_line    db "AND is: ",0
  or_line     db "Or is: ",0
  xor_line    db "Xor is: ",0
  nota_line    db "Not of A is is: ",0
  notb_line    db "Not of B is is: ",0

.CODE
  .STARTUP
  PutStr input_line
  GetLInt eax
  GetLInt ebx

Andop:
  mov      edx, eax
  and      edx, ebx
  mov      ecx, edx       ;ecx := eax and ebx;

  PutStr and_line
  PutLInt ecx
  nwln

Orop:
  mov      edx, eax
  or       edx, ebx
  mov      ecx, edx       ;ecx := eax or ebx;

  PutStr or_line
  PutLInt ecx
  nwln
Xorop:
  mov      edx, eax
  xor      edx, ebx
  mov      ecx, edx       ;ecx := eax xor ebx;

  PutStr xor_line
  PutLInt ecx
  nwln
Notop:
  mov      edx, eax      
  xor      edx, 1
  mov      ecx, edx
  PutStr nota_line
  PutLInt ecx
  nwln

  mov      edx, ebx       
  xor      edx, 1
  mov      ecx, edx
  PutStr notb_line
  PutLInt ecx
  nwln
.EXIT
