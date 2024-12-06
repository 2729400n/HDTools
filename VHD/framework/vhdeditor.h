#include <time.h>
#include "../../arch/x86/types/types.h"

int createVHD(const char*,u32 , char );
int __cdecl writeVHD(const u8* name ,u32 size , u8 resizable );
int __cdecl readVHD(const u8* name ,u32 size , u8 resizable );