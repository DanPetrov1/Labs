#include "../Headers/User.h"
#include "../Headers/InputError.h"

User::User(char *username, char *password, bool admin) : admin(admin) {
    strcpy_s(this->username, username);
    strcpy_s(this->password, password);
}

const char *User::getUsername() const {
    return username;
}

void User::setUsername(const char *username) {
    strcpy_s(this->username, username);
}

const char *User::getPassword() const {
    return password;
}

void User::setPassword(const char *password) {
    strcpy_s(this->password, password);
}

bool User::isAdmin() const {
    return admin;
}

void User::setAdmin(bool admin) {
    User::admin = admin;
}

std::ostream &operator<<(std::ostream &os, const User &user) {
    os << "Имя пользователя: " << user.username << std::endl << "Пароль: " << user.password << std::endl;
    return os;
}

std::istream &operator>>(std::istream &is, User &user) {
    rewind(stdin);
    std::cout << "Введите имя пользователя: ";
    is >> user.username;
    std::cout << "Введите пароль: ";
    is >> user.password;
    std::cout << "Является ли данный пользователь администратором? (1. Да. 2. Нет.)" << std::endl;
    user.admin = bool(InputError::Input(0, 1));
    return is;
}
