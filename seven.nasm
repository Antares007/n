one:                                   .LC0:
 mov	QWORD PTR [rdi+rsi*8], 1        .string	"ara"
 mov	rax, QWORD PTR 8[rdi+rdx*8]    aralog:
 mov	QWORD PTR 8[rdi+rsi*8], rax     lea	rdi, .LC0[rip]
 add	rsi, 1                          xor	eax, eax
 jmp	rax                             jmp	printf@PLT
add:                                   .LC1:
 sub	rsi, 1                          .string	"da %p"
 lea	rax, 0[0+rsi*8]                dalog:
 lea	r8, [rdi+rax]                   mov	rsi, QWORD PTR -8[rdi+rsi*8]
 mov	r9, QWORD PTR [r8]              xor	eax, eax
 add	QWORD PTR -8[rdi+rax], r9       lea	rdi, .LC1[rip]
 mov	rax, QWORD PTR 8[rdi+rdx*8]     jmp	printf@PLT
 mov	QWORD PTR [r8], rax            .LC2:
 jmp	rax                             .string	"an"
two:                                   anlog:
 lea	rax, 0[0+rsi*8]                 lea	rdi, .LC2[rip]
 lea	r8, one[rip]                    xor	eax, eax
 mov	QWORD PTR [rdi+rsi*8], r8       jmp	printf@PLT
 lea	r9, add[rip]                   main:
 add	rsi, 4                          push	rbp
 mov	QWORD PTR 8[rdi+rax], r8        mov	edi, 4096
 mov	r8, QWORD PTR da@GOTPCREL[rip]  call	malloc@PLT
 mov	QWORD PTR 24[rdi+rax], r9       mov	ecx, 512
 mov	QWORD PTR 16[rdi+rax], r8       mov	edx, 509
 mov	QWORD PTR 32[rdi+rax], r8       xor	esi, esi
 jmp	da@PLT                          mov	rbp, rax
seven:                                  lea	rax, aralog[rip]
 mov	r8, QWORD PTR da@GOTPCREL[rip]  mov	QWORD PTR 4088[rbp], rax
 lea	rax, 0[0+rsi*8]                 lea	rax, dalog[rip]
 lea	r10, two[rip]                   mov	rdi, rbp
 lea	r9, add[rip]                    mov	QWORD PTR 4080[rbp], rax
 lea	r11, one[rip]                   lea	rax, anlog[rip]
 mov	QWORD PTR [rdi+rsi*8], r11      mov	QWORD PTR 4072[rbp], rax
 add	rsi, 12                         lea	rax, seven[rip]
 mov	QWORD PTR 8[rdi+rax], r10       mov	QWORD PTR 0[rbp], rax
 mov	QWORD PTR 16[rdi+rax], r8       call	seven
 mov	QWORD PTR 24[rdi+rax], r9       mov	rdi, rbp
 mov	QWORD PTR 32[rdi+rax], r8       call	free@PLT
 mov	QWORD PTR 40[rdi+rax], r10      xor	eax, eax
 mov	QWORD PTR 48[rdi+rax], r8       pop	rbp
 mov	QWORD PTR 56[rdi+rax], r9       ret
 mov	QWORD PTR 64[rdi+rax], r8       .ident	"GCC: (GNU) 11.1.0"
 mov	QWORD PTR 72[rdi+rax], r10     
 mov	QWORD PTR 80[rdi+rax], r8      
 mov	QWORD PTR 88[rdi+rax], r9      
 mov	QWORD PTR 96[rdi+rax], r8      
 jmp	da@PLT                         
