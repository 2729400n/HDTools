#include <stdio.h>
#include <stdlib.h>
#include <memory.h>
#include <string.h>
#include <signal.h>
#include "vhdeditor.h"

inline int __builtin_bswap32(int val){
    int retval=0;
    for (size_t i = 0; i < 4; i++)
    {
        retval = retval+ (val&0xff);
        val>>=8;
        retval<<=8;
    }
    
    return retval;
}
