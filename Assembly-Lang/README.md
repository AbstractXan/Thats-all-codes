Get NASM before running any files here.

Note: These codes are for 8086 intel processor.
Note: You must have the io.mac and io.o files in the directory

Use the following commands to run them on terminal  
  
    nasm -f elf <filenamehere>.asm
    ld -o <anynameasyouwish> <filenamehere>.o io.o -melf_i386
    ./<anyfilenameyouwish>

Tutorials:

http://ce.kashanu.ac.ir/sabaghian/assembly/8086%20tutorial/8086%20Assembler%20Tutorial%20for%20Beginners%20(Part%204).htm
