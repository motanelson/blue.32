


int main()

{
        char *r=" ";
        char *rr="\n";
        char *rrr;
        int nnn=0;
	int nn=0;
	int n=0;
	char sss[128];
	char sss1="!!!!!!";
	char *argv0=0x82;
        n=0;
        cls3();
        /*
        while(1){
            ;
        }*/
        return 0;
}
#asm
.globl _cls3

_cls3:
     push ds
     mov eax,0
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
     cmp ecx,0
     jnz _clss
     pop ds
     ret

#endasm

