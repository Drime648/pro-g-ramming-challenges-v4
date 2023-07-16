; compile and run with: 
;nasm -gdwarf -f elf64 -o fizzbuzz.o  fizzbuzz.s; gcc -no-pie -o fizzbuzz.out fizzbuzz.o; ./fizzbuzz.out
default rel            ; make [rel format] the default, you always want this.
extern printf, puts, putchar, exit    ; NASM requires declarations of external symbols, unlike GAS
section .rodata
    format db "%#d", 0   ; C 0-terminated string: "%#x\n" 
   
section	.data
   buzz db 'buzz', 0
   fizz db 'fizz', 0  ;string to be printed
   
section .text
global main
main:
   sub   rsp, 8             ; re-align the stack to 16 before calling another function

   mov esi, 1 ; initialize counter
loop:
   cmp esi, 20
   ja exit
   xor rcx, rcx ; this will check if fizz was used. if it is zero, then print the number normally. If it is 1, then skip printing the number.
check_fizz:
   mov eax, esi
   mov ebx, 3
   call modulo

   cmp eax, 0
   je print_fizz
check_buzz:
   mov eax, esi
   mov ebx, 5
   call modulo

   cmp eax, 0
   je print_buzz
   cmp ecx, 1
   je increment
print_number_normally:

   ; if neither fizz nor buzz
   lea   rdi, [rel format]
   xor   eax, eax           ; AL=0  no FP args in XMM regs
   push rsi ; save what rsi was before
   call  printf
   pop rsi ; restore rsi
increment:
   mov rdi, 10
   push rsi
   call putchar
   pop rsi
   inc esi
   jmp loop


print_fizz:
   mov edi, fizz
   mov rcx, 1
   mov eax, 0
   push rsi
   push rcx
   call printf
   pop rcx
   pop rsi
   jmp check_buzz

print_buzz:
   mov edi, buzz
   mov eax, 0
   push rsi
   call printf
   pop rsi
   jmp increment


exit:
   ; Return from main.
   xor   eax, eax
   add   rsp, 8
   ret




modulo:         ; calcs eax mod ebx, returns eax
    mov edx, 0  ; clear higher 32-bits as edx:eax / ebx is calced
    div ebx     
    mov eax, edx ; the remainder was stored in edx     
    ret



   ;registers needed: 
      ; counter: esi. This is what is printed by printf also.
      ; eax: set to zero
      ; rdi string
      ; have ecx store if fizz or buzz was used
   ; example for modulo:
         ; mov eax, 9
         ; mov ebx, 5
         ; call modulo
   ; how to do newline:
         ; mov rdi, 10
         ; call putchar
   ; how to print a number:
         ;  mov   esi, 100   ; "%x" takes a 32-bit unsigned int
         ;  lea   rdi, [rel format]
         ;  xor   eax, eax           ; AL=0  no FP args in XMM regs
         ;  call  printf
   ; how to print fizz:
         ;  mov edi, fizz
         ;  mov eax, 0
         ;  call printf