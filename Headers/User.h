#ifndef KURSACHKARPEICHIK_USER_H
#define KURSACHKARPEICHIK_USER_H

#include <iostream>
#include <string>

class User {
private:
    char username[20];
    char password[20];
    bool admin;
public:
    explicit User(char *username = "", char *password = "", bool admin = false);

    const char *getUsername() const;
    void setUsername(const char *username);
    const char *getPassword() const;
    void setPassword(const char *password);
    bool isAdmin() const;
    void setAdmin(bool admin);

    friend std::ostream &operator<<(std::ostream &os, const User &user);
    friend std::istream &operator>>(std::istream &is, User &user);
};


#endif //KURSACHKARPEICHIK_USER_H
