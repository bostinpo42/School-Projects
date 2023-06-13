#include <fstream>
#include <string>

#ifndef FILE_H
#define FILE_H

#define BUFFER_SZ 2048

class File {

private:

public:
    File();
    ~File();

    char buffer[BUFFER_SZ]{};
	char otpBuffer[BUFFER_SZ]{};
    std::string phrase{};
    std::string srcFile{};
    std::string dstFile{};
    std::string otpFile{};
    int qty{};

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

#endif