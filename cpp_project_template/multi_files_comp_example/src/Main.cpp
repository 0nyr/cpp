#include <list>
#include <iostream>
#include <random>

#include "../inc/model/User.hpp"

void printUsers(std::list<User>& users)
{
    for(User user : users)
    {
        std::cout << user.toString() << std::endl;
    }
}

int main()
{
    std::list<User> users;

    users.push_back(User());
    users.push_back(User("Lolilol Gallé"));
    users.push_back(User("Caius Maxus", 11));

    // random number generation: https://stackoverflow.com/questions/5008804/generating-random-integer-from-a-range 
    std::random_device rd;     // only used once to initialise (seed) engine
    std::mt19937 rng(rd());    // random-number engine used (Mersenne-Twister in this case)
    std::uniform_int_distribution<int> uni(11, 99); // uni(min,max), guaranteed unbiased
    
    for(int i = 0; i < 10; i++)
    {
        int random_integer = uni(rng);
        std::string name = "bot number " + std::to_string(i);
        users.push_back(User(name, random_integer));
    }

    std::cout << "Number of users: " << users.size() << std::endl;
    printUsers(users);
}