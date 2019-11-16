#define KEY 5
#include "../Headers/User.h"
#include "../Headers/InputError.h"

User::User(std::string username, std::string password, bool admin) : username(username), password(password) , admin(admin) {
}

const std::string &User::getUsername() const {
    return username;
}

void User::setUsername(const std::string &username) {
    this->username = username;
}

const std::string &User::getPassword() const {
    return password;
}

void User::setPassword(const std::string &password) {
    this->password = password;
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
    char BUFFER[20];
    std::cin >> BUFFER;
    for (int j = 0; BUFFER[j] != '\0'; ++j) {
        BUFFER[j] = BUFFER[j] + j * KEY;
    }
    user.password = std::string(BUFFER);
    std::cout << "Является ли данный пользователь администратором? (1. Да. 0. Нет.)" << std::endl;
    user.admin = bool(InputError::Input(0, 1));
    return is;
}

User &User::operator=(const User &user) {
    this->username = user.username;
    this->password = user.password;
    this->admin = user.admin;
    return *this;
}
