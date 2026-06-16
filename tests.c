
//bcc -x -i -L -3 -Md intro.c -o intro.c32
void sputs(s);

long unsigned cursor=0xb8000;
int main()

{
        char *r=" ";
        char a[512];
        char *rrr;
        int nnn=0;
	int nn=0;
	int n=0;
	char sss[128];
	
	char *argv0=0x82;
        cursor=getx();
        n=0;
        a[0]='o';
        a[1]='p';
        a[2]='e';
        a[3]='r';
        a[4]='a';
        a[5]='t';
        a[6]='i';
        a[7]='o';
        a[8]='n';
        a[9]=' ';
        a[10]='s';
        a[11]='y';
        a[12]='s';
        a[13]='t';
        a[14]='e';
        a[15]='m';
        a[16]='\0';
        sputs(a);
        cursor++;
        return 0;
}
void sputs(s1)
char s1[];
{
	char cc=0;
	int counter=0;
	do{
                cc=s1[counter];
		cputc(cursor,cc);
                counter++;
                
                
                
                cursor++;
                cursor++;
	}while(cc!=0);
	
}
#asm
.globl _cls3
.globl _cputc
.globl _cursors
.global _getx
_cursors: .word 0xb8000
_cls3:
     push ds
     mov eax,*0
     push ax
     pop ds 
     mov ebx,*0xb8000
     mov ecx,*2000
     mov al,*0x20
     mov ah,*0x0f
_clss:
     mov [ebx],al
     inc ebx
     mov [ebx],ah
     inc ebx
     dec ecx
     cmp ecx,*0
     jnz _clss
     pop ds
     ret

_getx:
    mov eax,*0xb8000
    ret

_cputc:
    mov esi, esp
    add esi, *4        ; parâmetro
    seg ss
    mov eax,[esi]
    add esi, *4        ; parâmetro
    seg ss
    mov dl,[esi]
    mov esi,eax
        
    push ds
    xor eax, eax
    push ax
    pop ds             ; DS = 0
    cmp dl,*10
     
    jz _cputc2
    seg ds
    mov [esi], dl      ; escreve carácter
    inc esi
    seg ds
    mov byte [esi], *0xf0  ; atributo branco sobre preto
    inc esi

    pop ds

    mov eax, esi     ; atualiza cursor
    ret
_cputc2:
    pop ds
    mov eax,esi
    add eax,*160
    ret
#endasm

