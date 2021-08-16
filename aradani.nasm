dddu:                                 
 mov	rax, QWORD PTR 24[rdi+rdx*8]  
 add	rdx, 4                        
 mov	QWORD PTR [rdi+rsi*8], rax    
 jmp	rax                           
dddd0:                                dddd1:                                
 add	rdx, 4                         mov	rax, QWORD PTR 40[rdi+rdx*8]
 mov	rax, QWORD PTR [rdi+rdx*8]     add	rdx, 4                      
 mov	QWORD PTR [rdi+rsi*8], rax     mov	QWORD PTR [rdi+rsi*8], rax  
 jmp	rax                            jmp	rax                         
da:                                   an:                                   
 lea	r8, 2[rdx]                     lea	r8, 2[rdx]                    
 lea	r11, dddu[rip]                 lea	r11, dddd1[rip]               
 sub	rdx, 4                         sub	rdx, 4                        
 mov	r9, QWORD PTR [rdi+r8*8]       mov	r9, QWORD PTR [rdi+r8*8]      
 lea	rax, 0[0+r8*8]                 lea	rax, 0[0+r8*8]                
 lea	r8, -1[rsi]                    lea	r8, -1[rsi]                   
 sub	rsi, 2                         sub	rsi, 2                        
 mov	r10, QWORD PTR [rdi+r8*8]      mov	r10, QWORD PTR [rdi+r8*8]     
 mov	QWORD PTR -40[rdi+rax], r11    mov	QWORD PTR -40[rdi+rax], r11   
 mov	QWORD PTR -32[rdi+rax], r9     mov	QWORD PTR -32[rdi+rax], r9    
 lea	r9, dddd0[rip]                 lea	r9, dddu[rip]                 
 mov	QWORD PTR -24[rdi+rax], r10    mov	QWORD PTR -24[rdi+rax], r10   
 mov	QWORD PTR -48[rdi+rax], r9     mov	QWORD PTR -48[rdi+rax], r9    
 jmp	[QWORD PTR -8[rdi+r8*8]]       jmp	[QWORD PTR -8[rdi+r8*8]]      
                                       .ident	"GCC: (GNU) 11.1.0"           
















