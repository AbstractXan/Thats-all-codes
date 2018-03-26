
%include "io.mac"

section .data
in_msg  db  "Please enter integers. ",0
        db  "Entering zero terminates the input.",0
output_msg  db  "The sorted array is: ",0

section .bss
array1      resw  200

section .text
global _start
_start:

      PutStr  in_msg     ; request number
      nwln
      mov     EBX,array1
      xor     ESI,ESI        ; ESI keeps a count of input numbers

read_more:
      GetInt  AX             ; read a number
      mov     [EBX+ESI*2],AX ; store it in array
      cmp     AX,0           ; test if zero
      je      done_read
      inc     ESI
      jmp     read_more

done_read:
      xor     EDI,EDI        ; EDI = lo index
      dec     ESI            ; ESI = hi index
      call    qsort
      PutStr  output_msg     ; output sorted array

write_more:
      mov     AX,[EBX+EDI*2]
      cmp     AX,0
      je      done
      PutInt  AX
      nwln
      inc     EDI
      jmp     write_more

done:
      .EXIT

.CODE
qsort:
pusha
      cmp     ESI,EDI
      jle     qsort_done        ; end recursion if hi <= lo
  
      ; save hi and lo for later use
      mov     ECX,EDI
      mov     EDX,ESI

      mov     AX,[EBX+ESI*2] ; AX = xsep

lo_loop:                        ;
      cmp     [EBX+EDI*2],AX    ;
      jge     lo_loop_done      ; LO while loop
      inc     EDI               ;
      jmp     lo_loop           ;
lo_loop_done:

      dec     ESI            ; hi = hi-1
hi_loop:
      cmp     ESI,EDI           ;
      jle     sep_done          ;
      cmp     [EBX+ESI*2],AX    ;
      jle     hi_loop_done      ;
      dec     ESI               ;
      jmp     hi_loop           ;
hi_loop_done:

      xchg    AX,[EBX+EDI*2]    ;
      xchg    AX,[EBX+ESI*2]    ;
      xchg    AX,[EBX+EDI*2]    ;
      jmp     lo_loop

sep_done:
      xchg    AX,[EBX+EDI*2]    ;
      xchg    AX,[EBX+EDX*2]    ; x[i] <=> x[hi]
      xchg    AX,[EBX+EDI*2]    ;

      dec     EDI
      mov     ESI,EDI           ; hi = i-1

      mov     EDI,ECX
      call    qsort

      ; ESI has the i value
      inc     ESI
      inc     ESI
      mov     EDI,ESI           ; lo = i+1
      mov     ESI,EDX
      call    qsort

qsort_done:
popa
      ret
