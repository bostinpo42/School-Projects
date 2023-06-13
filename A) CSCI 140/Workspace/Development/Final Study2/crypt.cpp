#include <iostream>
#include <fstream>
#include <string>

#define BUFFER_SZ 2048

class File {

private:
    char buffer[BUFFER_SZ]{};
	char otpBuffer[BUFFER_SZ]{};
    std::string phrase{};
    std::string srcFile{};
    std::string dstFile{};
    std::string otpFile{};
    int qty{};

public:
    File();
    ~File();

    std::ifstream source;
    std::ifstream otp;
    std::ofstream dest;

    void openSource(std::string&);
    void openOTP(std::string&);
    void openDest(std::string&);

    void sourceRead();
    void otpRead();

    void decrypt(int, char[], char[], std::string);

    void closeFiles();

};

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
    for(int i{0}; i < qty; i++) {
        buffer[i] = buffer[i] ^ otpBuffer[i] ^ phrase[i];
    }
}

void File::closeFiles() {
    if (source.is_open()) source.close();
    if (otp.is_open()) otp.close();
    if (dest.is_open()) dest.close();
}

File::~File() {}


int main(int argc, char const *argv[]) {
	
    File a;

    std::cout << "Welcome to the OTP Encryption/Decryption Program\n";

    std::cout << "\nEnter the source filepath (\"filename.txt\"): ";
    getline(std::cin, a.srcFile);
    a.openSource(a.srcFile);

    std::cout << "\nEnter the destination filepath (\"filename.txt\"): ";
    getline(std::cin, a.dstFile);
    a.openDest(a.dstFile);

    std::cout << "\nEnter the one-time pad filepath (\"filename.txt\"): ";
    getline(std::cin, a.otpFile);
    a.openOTP(a.otpFile);

    std::cout << "\nEnter your passphrase: ";
    getline(std::cin, a.phrase);

    a.sourceRead();
    a.otpRead();
    
    a.decrypt(a.qty, a.buffer, a.otpBuffer, a.phrase);

    a.dest.write(a.buffer, a.qty);

    a.closeFiles();

    std::cout << "\nYour destination file was created successfully.\n";

	return 0;
}


