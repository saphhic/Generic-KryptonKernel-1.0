// written by saphhic.
#ifndef USER_H
#define USER_H

#include <stdint.h>

#define MAX_USERS 16
#define MAX_USERNAME 16
#define HASH_SIZE 32

struct User {
    char username[MAX_USERNAME];
    uint8_t password_hash[HASH_SIZE];
    int uid;
    bool priv;
};

extern struct User users[MAX_USERS];
extern int user_count;
extern int current_uid;

bool check_login();
bool check_priv();
bool login_user(const char* username, const char* password);
bool create_privuser(const char* username, const char* password);
void init_default_user();

#endif // USER_H

