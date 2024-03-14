#include <stdio.h>
#include <string.h>
#include "AES.h"

#define MESSAGE_LENGTH 32

void printHex(const unsigned char* data, int length) {
    for (int i = 0; i < length; ++i) {
        printf("%02x", data[i]);
    }
    printf("\n");
}

int main() {

    // ECB-Mode
    unsigned char message[MESSAGE_LENGTH + 1] = "This is secret!";
    unsigned char key[AES_SIZE + 1] = "ThisIsAKey";

    printf("ECB-Mode: \n");
    printf("The plaintext: %s\n", message);
    printf("The key: %s\n", key);
    AES_ECB_encr(message, key, MESSAGE_LENGTH);

    printf("The ciphertext: ");
    printHex(message, MESSAGE_LENGTH);

    AES_ECB_decr(message, key, MESSAGE_LENGTH);
    printf("The decred message: %s\n\n", message);

    // CBC-Mode
    memcpy(message, "This is secret!", MESSAGE_LENGTH);
    memcpy(key, "ThisIsAKey", AES_SIZE);
    unsigned char iv[AES_SIZE + 1] = "ThisIsAnIV";

    printf("CBC-Mode: \n");
    printf("The plaintext: %s\n", message);
    printf("The key: %s\n", key);
    printf("The IV: %s\n", iv);
    AES_cbc_encr(message, key, MESSAGE_LENGTH, iv);

    printf("The ciphertext: ");
    printHex(message, MESSAGE_LENGTH);

    AES_cbc_decr(message, key, MESSAGE_LENGTH, iv);
    printf("The decred message: %s\n\n", message);

    return 0;
}
