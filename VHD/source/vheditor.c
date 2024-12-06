#include "framework.h"
#include "vhdeditor.h" 

#define VHDMAGIC 'c','o','n','e','c','t','i','x' 
#define SIZEMASK (u32)((-1)^0x000fffff)
#define VARBIT 1<<0


int check=0;
void resetchecksum(){
    check=0x11040100;
}
void checksum(int adder){
    char* checkcontrol=&check;
    u16 result=0;
    u8 adderg= (adder>>24)&0xff;
    u8  holder=(check>>24)&0xff;
    
    if((result>>8)&1){
        (*checkcontrol+1);
        result+1;
    }
    u8 highbight = adder>>24;
    check+=adder;
    return;
    
}

int getchecksum(int adder){
    
    return check;
    
}

 
struct GUID{
union {
    struct 
    {
        u32 interclass;
        u16 innerIDs;
        u16 Outerclass;
        u8 b1,b2,b3,b4;

    };
    int segs[4];

    

};};

union Checksum{
    u32 CRC32;
};

struct VHDTypeFlags{
    u32 unk:30,something:1,Resizable:1; 
};

struct header{
    u8 magic[8];
    u32 flag1,flag2;
    u64 cxsparsestructure;
    u32 check;
    u32 Signature;
    u32 flag3;
    u32 W2KSig;
    u64 size;
    u64 nextsize;
    u32 sizesum;
    struct VHDTypeFlags typeflag;
    u32 crc32Checksum;
    struct GUID id;
     
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

int __cdecl createVHD(const char* name ,u32 size , char resizable ){
    printf("name=%s size=%d resize=%d\n",name,size,resizable);
    if(name){
        return 0;
    }

    srand(time(NULL));
    
    
      
    rand();
    struct header VHDhead;

    memcpy_s(&(VHDhead.magic),8,"conectix",8);
    memcpy_s(&(VHDhead.flag1),8,"\0\0\0\x02\0\0\x01\0\0",8);
    memcpy_s(&(VHDhead.flag3),8,"\0\0\0\0Wi2k",8);
    ((u32)size)&=SIZEMASK;
    size= __builtin_bswap32(size);
    u64 realsize = size;
    memcpy_s(&(VHDhead.size),8,&realsize,8);
    memcpy_s(&(VHDhead.nextsize),8,&realsize,8);
    memcpy_s(&(VHDhead.sizesum),8,"\0\x78\x04\x11\0\0\0\x02",8);
    int i = 0;
    for (; i <4; i++)
    {
        VHDhead.id.segs[i]=rand();
    }
    VHDhead.W2KSig=0x6b326957;

    


    FILE* diskFile= fopen(name,"xb");
    populateFile(diskFile,size);
    fflush(diskFile);
    fseek(diskFile,-511,SEEK_CUR);

    return 0;
}

int __cdecl writeVHD(const u8* name ,u32 size , u8 resizable ){


    return 0;
}


int __cdecl readVHD(const u8* name ,u32 size , u8 resizable ){


    return 0;
}