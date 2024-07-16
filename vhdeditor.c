#include  <types/types.h>
#include "framework.h"
#include "vhdeditor.h" 

#define VHDMAGIC 'c','o','n','e','c','t','i','x' 
#define SIZEMASK (u32)((-1)^0x000fffff)
#define VARBIT 1<<0

struct GUID{
u32 interclass;
u32 innerIDs;
u32 Outerclass;
u32 OuterID;
};

union Checksum{
    u32 CRC32;
};

struct header{
    u8 magic[8];
    u32 flag1,flag2;
    u64 unk;
    u32 check;
    u32 Signature;
    u32 flag3;
    u32 W2KSig;
    u64 size;
    u64 nextsize;
    u32 unk2;
    u32 unk3;
    struct GUID id;
    u32 crc32Checksum; 
};

int createVHD(const char*,u32 , char );



int populateFile(FILE* fp,int size){
    u8 buffer[0x200]={0};
    u16 blocks= size>>9;
    if(blocks==0){
        blocks=1;
    }
    for (u16 i =0; i <blocks ; i++)
    {
        if(fwrite(buffer,512,1,fp)!=1)
        return blocks;
    }
    return blocks;
}

int createVHD(const char* name ,u32 size , char resizable ){


    srand(time(NULL));
    struct header VHDhead;
    memcpy_s(&(VHDhead.magic),8,"conectix",8);
    memcpy_s(&(VHDhead.flag1),8,"\0\0\0\x02\0\0\x01\0\0",8);
    memcpy_s(&(VHDhead.flag3),8,"\0\0\0\0Wi2k",8);
    ((u32)size)&=SIZEMASK;
    size= __builtin_bswap32(size);
    u64 realsize = size;
    memcpy_s(&(VHDhead.size),8,&realsize,8);
    memcpy_s(&(VHDhead.nextsize),8,&realsize,8);
    memcpy_s(&(VHDhead.unk2),8,"\0\x78\x04\x11\0\0\0\x02",8);
    memcpy_s(,16,,16)
    


    FILE* diskFile= fopen(name,"xb");
    populateFile(diskFile,size);
    fflush(diskFile);
    fseek(diskFile,-511,SEEK_CUR);

    return 0;
}


int readVHD(const u8* name ,u32 size , u8 resizable ){


    return 0;
}