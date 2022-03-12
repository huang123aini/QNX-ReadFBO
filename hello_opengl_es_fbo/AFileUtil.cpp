#include "AFileUtil.h"
#include <fstream>
#include <iostream>

AFileUtil::AFileUtil() {
}

AFileUtil::~AFileUtil() {
}

void AFileUtil::save(const char *filePath, void *buffer, unsigned int len) {
    printf("avm_engine output file = %s  \n", filePath);
    FILE *fp = nullptr;
    fp = fopen(filePath, "wb+");
    if(fp == nullptr) {
        printf("avm_engine fopen nullptr   \n");
    }
    if (fp) {
        unsigned char *ptr = (unsigned char*) buffer;
        printf("avm_engine ptr[0] = %d  ptr[1] = %d  ptr[2] = %d  ptr[3] = %d   \n", (int)ptr[0], (int)ptr[1], (int)ptr[2], (int)ptr[3]);
        fwrite(ptr, 1, len, fp);
        fflush(fp);
        fclose(fp);
    }
}