#include "framework.h"
const char* menu= "1.Create VHD \n2.Write to VHD \n3.ReadVHD \n4.Exit";

typedef   int   (__cdecl *unkfunc)(int);





int __cdecl main(){
    puts(menu);
    int opt=getchar()-48;
    switch (opt)
    {
    case 1:

        break;
    case 2:
        break;
    case 3:
        break;
    case 4:
        exit(0);
        break;    
    default:
        printf("%c %s",(char)(opt+48),"is not a Valid option choose again please.");
        break;
    }
    return 0;
} 