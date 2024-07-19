# The VHDEditor

This was made to handle VHD files that exist for virtualization software 
The library was built using a zero knowledge forensic approach 
Only using a file produced the file format was reverse engineered to 
give finer control over the  use of VHD files and VHDdisks



## The Timestamp
The timestamp is located at offset 0x18 I found this while diffing files created around the same time with the same size and the same filename
It incremented by a certain value for each time stamp.
The epoch seems to be 1970 but it can be faked by manipulating the final checksum 

## The checksum

The check sum seems to be a simple checksum at first it add 01eh  to the 2nd byte of the  checksum for each MiB and whenever a carry is done
the 1st byte is incremented and then adde to the starting checksum.
E.G. 20MiB would not give 0x258 = 20\*01eh but instead 0x25a= 20\*01eh+ (20*01eh)>>8
However the 1st bytes seems to be capped at a value of 3.


## The GUID
The GUID is the standard Microsoft GUID Format hence being 16bytes of UUID with the format. 
```C
typedef struct GUID {
union{
    struct {
        uint32_t id1,id2;
        uint16_t id3,id4;
        uint8_t id5,id6,id7,id8
    }
    uint32_t id[4];
}
}
```
## The final checksum
The final checksum comes before the GUID it is initailly set to 0xffffffff (effectively -1). The rest of the information block is then subtracted from the checksum such that the checksum  equals the $-(\texttt{sum}( \texttt{INFO\_TABLE\_BYTES} +1 ) )$ .  Therefore this time  adding the bytes to the attained  checksum and then adding 1 should equal 0 and set teh overflow flag which can be used to speed up checking     . This allows for a check to whether the overflow flag is set during a checksum loop if it is then an error must have occured and if its not set after the loop then an error must have occured  

## Extention Variable Length Disk 
The extended veriosn of this file format has a need for those 8 bytes at offset 10h They point to a cxsparse block that seems to be the next adventure after cracking the size chexksum