struct CHSOffset{
    short cylinders; // For the possible invalidation speed
    unsigned char heads;
    char sector; // For the possible invalidation speed
} // space reductions are nice

 offestToCHS(int offset){
    short cylinder= offset&0x3ff;
    unsigned char sector  =(offset>>12)&0x3f,
    head=(offset>>16)&0xff;
     
    return (struct CHSOffset){.cylinders=cylinder,.heads=head,.sector=sector};
} // a nice trick to inlining functions with type or struct definiations

