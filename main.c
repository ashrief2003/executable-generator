#include <stdio.h>
#include "sec/core.h"


//2070kb or more size to met the requirements of functional exe file
unsigned char data[2070];


void MakeFile(){


    static int st = 0;
    int count = 0;

    size_t theSize = WinHSize;

    int i = 0;
    while(i < theSize){
        data[i] = winH[st];
        ++st;
        ++i;
    }

    theSize = dataSize;

    count = i;
    st = 0;

    while(i < count + theSize){
        data[i] = _data[st];
        ++st;
        ++i;
    }

    //skip section
    i += 496;

    theSize = codeSize;

    count = i;
    st = 0;

    while(i < count + theSize){
        data[i] = _code[st];
        ++st;
        ++i;
    }

    //skip section
    i += 480;

    theSize = idataSize;

    count = i;
    st = 0;

    while(i < count + theSize){
        data[i] = _idata[st];
        ++st;
        ++i;
    }

}


void assign_var(char text[]){
    for(int i = 0; i < 8; ++i){
        _data[i] = 0x00 + text[i];
    }
}

int main(){


    char your_text[10];

    //enter the desired message that you want the application to print when running
    if(scanf("%s", your_text) < 9) assign_var(your_text);


    //preparing all necessary sections for the program to be written
    MakeFile();


    
    //
    //
    //
    //
    //
    //
    //
    //
    //
    //
    //
    //
    //
    //
    //
    //
    ////////////////////////////////////////////////////////////
    //                                                       //
    //                                                       //
    //                                                       //
    //                                                       //
    /////////////////writing the exe file//////////////////////
    size_t dataSize = sizeof(data) / sizeof(unsigned char);

    FILE *file = fopen("app.exe", "wb");
    if (file == NULL) {
        perror("Error opening file");
        return 1;
    }

    size_t elementsWritten = fwrite(data, sizeof(unsigned char), dataSize, file);
    if (elementsWritten != dataSize) {
        perror("Error writing to file");
        fclose(file);
        return 1;
    }

    fclose(file);

    printf("Data written to app.exe successfully.\n");
    return 0;
}
