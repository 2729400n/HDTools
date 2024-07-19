# MBR

## General stuff
MBR is old and should not be used often instead o pt for gpt

## CHS
Cylinder Head Sector to real value
There are 512 Bytes in a sector
63 sectors in a head 
255 heads in a cylinder and
there are 1024 cylinders allowing for 

 $1024 \times 255 \times 63 \times 256 $ bytes addressable The reason that we say there are only 63 sectors is because the sector 0 is not counted or addressed usually although it may be it represents the bootable part of the mbr 


## LBS


## The real issue 
There is no way to directly specify a signal bit which meant that there was a minimum access size that would be the sectors in CHS and in LBS that would be the Logical block size 