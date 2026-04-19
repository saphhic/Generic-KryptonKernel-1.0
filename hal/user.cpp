// written by saphhic.
#include "user.h"

struct User users[MAX_USERS];
int user_count = 0;
int current_uid = -1;

void simple_hash(const char* password, uint8_t* out_hash) {
    for (int i = 0; i < HASH_SIZE; i++) {
        out_hash[i] = 0;
    }

    for (int i = 0; password[i] != '\0'; i++) {
        uint8_t c = password[i];
        for (int j = 0; j < HASH_SIZE; j++) {
            c = (c << 3) | (c >> 5);
            out_hash[j] ^= c + i;
        }
    }
}

bool check_login() {
    return current_uid >= 0;
}

bool check_priv() {
    if (current_uid < 0) return false;
    return users[current_uid].priv;
}

bool login_user(const char* username, const char* password) {
    if (username == nullptr || password == nullptr) return false;

    uint8_t hash[HASH_SIZE];
    simple_hash(password, hash);

    for (int i = 0; i < user_count; i++) {
       int j = 0;
       while (j < MAX_USERNAME &&  username[j] == users[i].username[j]) {
           if (username[j] == '\0') break;
           j++;
       }
       if (username[j] == '\0' && users[i].username[j] == '\0') {

             bool match = true;
            for (int k = 0; k < HASH_SIZE; k++) {
                 if (users[i].password_hash[k] != hash[k]) {
                     match = false;
                     break;
                 }
            }
        

            if (match) {
                current_uid = users[i].uid;
                return true;
            }
       }
       
    }
    return false;
}

bool create_privuser(const char* username, const char* password) {
    if (user_count >= MAX_USERS || username == nullptr || password == nullptr) 
        return false;

    for (int i = 0; i < user_count; i++) {
        int j = 0;
        while (j < MAX_USERNAME && username[j] == users[i].username[j]) {
            if (username[j] == '\0') break;
            j++;
        }
        if (username[j] == '\0' && users[i].username[j] == '\0') {
            return false; // User already exists
        }
    }

    int i = 0;
    while (i < MAX_USERNAME - 1 && username[i] != '\0') {
        users[user_count].username[i] = username[i];
        i++;
    }
    users[user_count].username[i] = '\0';

    simple_hash(password, users[user_count].password_hash);

    users[user_count].uid = user_count;
    users[user_count].priv = true;

    user_count++;
    return true;
}

void init_default_user() {
    create_privuser("root", "toor");
}