#include <iostream>
#include <fstream>
#include <string>

#define BUFFER_SZ 2048

void decrypt(int, char[], char[], std::string);

int main(int argc, char const *argv[]) {
	char buffer[BUFFER_SZ]{};
	char otpBuffer[BUFFER_SZ]{};
    std::string phrase{};
    std::string src{};
    std::string dst{};
    std::string otp{};
    int qty{};

    std::cout << "Welcome to the OTP Encryption/Decryption Program\n";

    std::cout << "\nEnter the source filepath (\"filename.txt\"): ";
    getline(std::cin, src);
    std::ifstream source(src, std::ios::in | std::ios::binary);
    if (!source) {
        std::cout << "\nERROR: Could not open the source file.\n" << "---TERMINATING---";
        exit(EXIT_FAILURE);
    }

    std::cout << "\nEnter the destination filepath (\"filename.txt\"): ";
    getline(std::cin, dst);
    std::ofstream destination(dst, std::ios::out | std::ios::binary);
    if (!destination) {
        std::cout << "\nERROR: Could not open the destination file.\n" << "---TERMINATING---";
        exit(EXIT_FAILURE);
    }

    std::cout << "\nEnter the one-time pad filepath (\"filename.txt\"): ";
    getline(std::cin, otp);
    std::ifstream oneTimePad(otp, std::ios::in | std::ios::binary);
    if (!oneTimePad) {
        std::cout << "\nERROR: Could not open the one-time pad file.\n" << "---TERMINATING---";
        exit(EXIT_FAILURE);
    }

    std::cout << "\nEnter your passphrase: ";
    getline(std::cin, phrase);

    while(source) {
        source.read(buffer, BUFFER_SZ);
        qty = source.gcount();
    }
    while(oneTimePad) {
        oneTimePad.read(otpBuffer, BUFFER_SZ);
    }

    decrypt(qty, buffer, otpBuffer, phrase);

    destination.write(buffer, qty);

    source.close();
    destination.close();
    oneTimePad.close();

    std::cout << "\nYour destination file was created successfully.\n";

	return 0;
}

void decrypt(int qty, char buffer[], char otpBuffer[], std::string phrase) {
    for(int i{0}; i < qty; i++) {
        buffer[i] = buffer[i] ^ otpBuffer[i] ^ phrase[i];
    }
}
