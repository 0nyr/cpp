#include "../inc/model/User.hpp"

// static const string : https://stackoverflow.com/questions/1563897/static-constant-string-class-member 
const std::string User::DEFAULT_USERNAME = "default username";

User::User()
{
    this->username = User::DEFAULT_USERNAME;
    this->id = User::DEFAULT_ID;
}

User::User(std::string username): 
    username(username)
{
    this->id = User::DEFAULT_ID;
}

User::User(std::string username, int id):
    username(username), id(id) {}

User::~User()
{}

std::string User::toString()
{
    std::string str = "[User] id: " + std::to_string(this->id) +
        " username: " + this->username;
    return str;
}