#include "core.h"


//windows header that contain DOS and windows signeture
const unsigned char winH[] = {
    0x4d ,0x5a ,0x80 ,0x00 ,0x01 ,0x00 ,0x00 ,0x00 ,0x04 ,0x00 ,0x10 ,0x00 ,0xff ,0xff ,0x00 ,0x00 ,
    0x40 ,0x01 ,0x00 ,0x00 ,0x00 ,0x00 ,0x00 ,0x00 ,0x40 ,0x00 ,0x00 ,0x00 ,0x00 ,0x00 ,0x00 ,0x00 ,
    0x00 ,0x00 ,0x00 ,0x00 ,0x00 ,0x00 ,0x00 ,0x00 ,0x00 ,0x00 ,0x00 ,0x00 ,0x00 ,0x00 ,0x00 ,0x00 ,
    0x00 ,0x00 ,0x00 ,0x00 ,0x00 ,0x00 ,0x00 ,0x00 ,0x00 ,0x00 ,0x00 ,0x00 ,0x80 ,0x00 ,0x00 ,0x00 ,
    0x0e ,0x1f ,0xba ,0x0e ,0x00 ,0xb4 ,0x09 ,0xcd ,0x21 ,0xb8 ,0x01 ,0x4c ,0xcd ,0x21 ,0x54 ,0x68 ,
    0x69 ,0x73 ,0x20 ,0x70 ,0x72 ,0x6f ,0x67 ,0x72 ,0x61 ,0x6d ,0x20 ,0x63 ,0x61 ,0x6e ,0x6e ,0x6f ,
    0x74 ,0x20 ,0x62 ,0x65 ,0x20 ,0x72 ,0x75 ,0x6e ,0x20 ,0x69 ,0x6e ,0x20 ,0x44 ,0x4f ,0x53 ,0x20 ,
    0x6d ,0x6f ,0x64 ,0x65 ,0x2e ,0x0d ,0x0a ,0x24 ,0x00 ,0x00 ,0x00 ,0x00 ,0x00 ,0x00 ,0x00 ,0x00 ,
    0x50 ,0x45 ,0x00 ,0x00 ,0x64 ,0x86 ,0x03 ,0x00 ,0x08 ,0x51 ,0xbf ,0x66 ,0x00 ,0x00 ,0x00 ,0x00 ,
    0x00 ,0x00 ,0x00 ,0x00 ,0xf0 ,0x00 ,0x2f ,0x00 ,0x0b ,0x02 ,0x01 ,0x49 ,0x00 ,0x02 ,0x00 ,0x00 ,
    0x00 ,0x04 ,0x00 ,0x00 ,0x00 ,0x00 ,0x00 ,0x00 ,0x00 ,0x20 ,0x00 ,0x00 ,0x00 ,0x20 ,0x00 ,0x00 ,
    0x00 ,0x00 ,0x40 ,0x00 ,0x00 ,0x00 ,0x00 ,0x00 ,0x00 ,0x10 ,0x00 ,0x00 ,0x00 ,0x02 ,0x00 ,0x00 ,
    0x01 ,0x00 ,0x00 ,0x00 ,0x00 ,0x00 ,0x00 ,0x00 ,0x05 ,0x00 ,0x00 ,0x00 ,0x00 ,0x00 ,0x00 ,0x00 ,
    0x00 ,0x40 ,0x00 ,0x00 ,0x00 ,0x02 ,0x00 ,0x00 ,0x4f ,0x49 ,0x00 ,0x00 ,0x03 ,0x00 ,0x00 ,0x00 ,
    0x00 ,0x10 ,0x00 ,0x00 ,0x00 ,0x00 ,0x00 ,0x00 ,0x00 ,0x10 ,0x00 ,0x00 ,0x00 ,0x00 ,0x00 ,0x00 ,
    0x00 ,0x00 ,0x01 ,0x00 ,0x00 ,0x00 ,0x00 ,0x00 ,0x00 ,0x00 ,0x00 ,0x00 ,0x00 ,0x00 ,0x00 ,0x00 ,
    0x00 ,0x00 ,0x00 ,0x00 ,0x10 ,0x00 ,0x00 ,0x00 ,0x00 ,0x00 ,0x00 ,0x00 ,0x00 ,0x00 ,0x00 ,0x00 ,
    0x00 ,0x30 ,0x00 ,0x00 ,0x62 ,0x00 ,0x00 ,0x00 ,0x00 ,0x00 ,0x00 ,0x00 ,0x00 ,0x00 ,0x00 ,0x00 ,
    0x00 ,0x00 ,0x00 ,0x00 ,0x00 ,0x00 ,0x00 ,0x00 ,0x00 ,0x00 ,0x00 ,0x00 ,0x00 ,0x00 ,0x00 ,0x00 ,
    0x00 ,0x00 ,0x00 ,0x00 ,0x00 ,0x00 ,0x00 ,0x00 ,0x00 ,0x00 ,0x00 ,0x00 ,0x00 ,0x00 ,0x00 ,0x00 ,
    0x00 ,0x00 ,0x00 ,0x00 ,0x00 ,0x00 ,0x00 ,0x00 ,0x00 ,0x00 ,0x00 ,0x00 ,0x00 ,0x00 ,0x00 ,0x00 ,
    0x00 ,0x00 ,0x00 ,0x00 ,0x00 ,0x00 ,0x00 ,0x00 ,0x00 ,0x00 ,0x00 ,0x00 ,0x00 ,0x00 ,0x00 ,0x00 ,
    0x00 ,0x00 ,0x00 ,0x00 ,0x00 ,0x00 ,0x00 ,0x00 ,0x00 ,0x00 ,0x00 ,0x00 ,0x00 ,0x00 ,0x00 ,0x00 ,
    0x00 ,0x00 ,0x00 ,0x00 ,0x00 ,0x00 ,0x00 ,0x00 ,0x00 ,0x00 ,0x00 ,0x00 ,0x00 ,0x00 ,0x00 ,0x00 ,
    0x00 ,0x00 ,0x00 ,0x00 ,0x00 ,0x00 ,0x00 ,0x00 ,0x2e ,0x64 ,0x61 ,0x74 ,0x61 ,0x00 ,0x00 ,0x00 ,
    0x11 ,0x00 ,0x00 ,0x00 ,0x00 ,0x10 ,0x00 ,0x00 ,0x00 ,0x02 ,0x00 ,0x00 ,0x00 ,0x02 ,0x00 ,0x00 ,
    0x00 ,0x00 ,0x00 ,0x00 ,0x00 ,0x00 ,0x00 ,0x00 ,0x00 ,0x00 ,0x00 ,0x00 ,0x40 ,0x00 ,0x00 ,0xc0 ,
    0x2e ,0x63 ,0x6f ,0x64 ,0x65 ,0x00 ,0x00 ,0x00 ,0x1d ,0x00 ,0x00 ,0x00 ,0x00 ,0x20 ,0x00 ,0x00 ,
    0x00 ,0x02 ,0x00 ,0x00 ,0x00 ,0x04 ,0x00 ,0x00 ,0x00 ,0x00 ,0x00 ,0x00 ,0x00 ,0x00 ,0x00 ,0x00 ,
    0x00 ,0x00 ,0x00 ,0x00 ,0x20 ,0x00 ,0x00 ,0x60 ,0x2e ,0x69 ,0x64 ,0x61 ,0x74 ,0x61 ,0x00 ,0x00 ,
    0x62 ,0x00 ,0x00 ,0x00 ,0x00 ,0x30 ,0x00 ,0x00 ,0x00 ,0x02 ,0x00 ,0x00 ,0x00 ,0x06 ,0x00 ,0x00 ,
    0x00 ,0x00 ,0x00 ,0x00 ,0x00 ,0x00 ,0x00 ,0x00 ,0x00 ,0x00 ,0x00 ,0x00 ,0x40 ,0x00 ,0x00 ,0x40
};

//data section
unsigned char _data[] = {
    0x48 ,0x65 ,0x6c ,0x6c ,0x6f ,0x2c ,0x57 ,0x6f ,0x72 ,0x6c ,0x64 ,0x21 ,0x0a ,0x00 ,0x25 ,0x73
}; //also add 496 of 0x00

unsigned char _code[] = {
    0x48 ,0x83 ,0xec ,0x28 ,0x48 ,0xc7 ,0xc1 ,0x0e ,0x10 ,0x40 ,0x00 ,0x48 ,0xc7 ,0xc2 ,0x00 ,0x10 ,
    0x40 ,0x00 ,0xff ,0x15 ,0x30 ,0x10 ,0x00 ,0x00 ,0x48 ,0x83 ,0xc4 ,0x28 ,0xc3 ,0x00 ,0x00 ,0x00
}; // also add 480 of 0x00

const unsigned char _idata[] = {
    0x38 ,0x30 ,0x00 ,0x00 ,0x00 ,0x00 ,0x00 ,0x00 ,0x00 ,0x00 ,0x00 ,0x00 ,0x28 ,0x30 ,0x00 ,0x00 ,
    0x48 ,0x30 ,0x00 ,0x00 ,0x00 ,0x00 ,0x00 ,0x00 ,0x00 ,0x00 ,0x00 ,0x00 ,0x00 ,0x00 ,0x00 ,0x00 ,
    0x00 ,0x00 ,0x00 ,0x00 ,0x00 ,0x00 ,0x00 ,0x00 ,0x6d ,0x73 ,0x76 ,0x63 ,0x72 ,0x74 ,0x2e ,0x64 ,
    0x6c ,0x6c ,0x00 ,0x00 ,0x00 ,0x00 ,0x00 ,0x00 ,0x58 ,0x30 ,0x00 ,0x00 ,0x00 ,0x00 ,0x00 ,0x00 ,
    0x00 ,0x00 ,0x00 ,0x00 ,0x00 ,0x00 ,0x00 ,0x00 ,0x58 ,0x30 ,0x00 ,0x00 ,0x00 ,0x00 ,0x00 ,0x00 ,
    0x00 ,0x00 ,0x00 ,0x00 ,0x00 ,0x00 ,0x00 ,0x00 ,0x00 ,0x00 ,0x70 ,0x72 ,0x69 ,0x6e ,0x74 ,0x66
};// add to it 416 of 0x00

int WinHSize = sizeof(winH) / sizeof(winH[0]);
int dataSize = sizeof(_data) / sizeof(_data[0]);
int codeSize = sizeof(_code) / sizeof(_code[0]);
int idataSize = sizeof(_idata) / sizeof(_idata[0]);