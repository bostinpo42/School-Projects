#include "file.h"
#include <iostream>

File::File() {}

void File::openSource(std::string& srcFile) {
    source.open(srcFile, std::ios::in | std::ios::binary);
    if (!source) {
        std::cout << "\nERROR: Could not open the source file.\n" << "---TERMINATING---";
        exit(EXIT_FAILURE);
    }
}

void File::openOTP(std::string& otpFile) {
    otp.open(otpFile, std::ios::in | std::ios::binary);
    if (!otp) {
        std::cout << "\nERROR: Could not open the one-time pad file.\n" << "---TERMINATING---";
        exit(EXIT_FAILURE);
    }
}

void File::openDest(std::string& destFile) {
    dest.open(destFile, std::ios::out | std::ios::binary);
    if (!dest) {
        std::cout << "\nERROR: Could not open the destination file.\n" << "---TERMINATING---";
        exit(EXIT_FAILURE);
    }
}

void File::sourceRead() {
    while(source) {
        source.read(buffer, BUFFER_SZ);
        qty = source.gcount();
    }
}

void File::otpRead() {
    while(otp) {
        otp.read(otpBuffer, BUFFER_SZ);
    }
}

void File::decrypt(int qty, char buffer[], char otpBuffer[], std::string phrase) {
    for(int i{0}; i < qty; ++i) {
        buffer[i] = buffer[i] ^ otpBuffer[i] ^ phrase[i];
    }
}

void File::closeFiles() {
    if (source.is_open()) source.close();
    if (otp.is_open()) otp.close();
    if (dest.is_open()) dest.close();
}

File::~File() {}
