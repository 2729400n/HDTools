#include "framework.h"
const char* menu= "1.Create VHD \n2.Write to VHD \n3.ReadVHD \n4.Exit";
int main(){
    switch (getchar())
    {
    case 1:
        break;
    case 2:
        break;
    case 3:
        break;
    case 4:
        exit(0);    
    default:
        printf("%s","Not a Valid option choose again please");
        break;
    }
    return 0;
} 