#include "framework.h"
const char* menu= "1.Create VHD \n2.Write to VHD \n3.ReadVHD \n4.Exit";
struct VHDargs{
    stackelem* a,*b,*c;
};
typedef   int   (__cdecl *unkfunc)(int*,int*,int*);

void dtor();
void catchInterrupt(int sigcode){


    switch (sigcode)
    {
    case SIGINT:
        printf("KeyBoard Interrupt Recieved Terminating Program\n");
        dtor();
        exit(0);

        break;
    
    default:
        break;
    }
    return;
}

void ctor(){

    signal(SIGINT,catchInterrupt);
}

void dtor(){
    return;
}

unkfunc dispatchtable[3] = {createVHD,writeVHD,readVHD};

void getargs(){

}



int __cdecl main(){
    ctor();
    puts(menu);
    int opt;
    while (1)
    {
       opt =getchar()-48;
       getchar();
    switch (opt)
    {
    case 1:        
    case 2:
    case 3:

        dispatchtable[opt-1]("Hello.vhd",123,1);
        break;
    case 4:
        return 0;
        break;    
    default:
        printf("%c %s",(char)(opt+48),"is not a Valid option choose again please.\n");
        break;
    }
    }
    
    
    dtor();
    return 0;
} 