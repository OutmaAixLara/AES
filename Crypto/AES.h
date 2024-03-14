#pragma once
#define AES_SIZE 16 
#define NUM_ROUNDS 10

void AES_decr(unsigned char* plaintext, unsigned char* key);
void AES_encr(unsigned char* plaintext, unsigned char* key);
void AES_ECB_encr(unsigned char* plaintext, unsigned char* key, int text_length);
void AES_ECB_decr(unsigned char* plaintext, unsigned char* key, int text_length);
void AES_cbc_encr(unsigned char* plaintext, unsigned char* key, int text_length, unsigned char* iv);
void AES_cbc_decr(unsigned char* plaintext, unsigned char* key, int text_length, unsigned char* iv);