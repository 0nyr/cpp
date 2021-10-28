#pragma once

#include <iostream>
#include <string>

class User {
    private: 
        std::string username;
        int id;
    
    public:
        // default values
        const static int DEFAULT_ID = 42;
        const static std::string DEFAULT_USERNAME; // definition in implementation file

        User();
        User(std::string username);
        User(std::string username, int id);
        ~User(); // WARN: Need to be defined in implementation file

        std::string toString();

        std::string getUsername() 
        {
            return this->username;
        }
        void setUsername(std::string newUsername) 
        {
            this->username = newUsername;
        }
        int getId() 
        {
            return this->id;
        }
        void setId(int newId)
        {
            this->id = newId;
        }
};