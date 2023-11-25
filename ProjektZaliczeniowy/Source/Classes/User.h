//
// Created by Janek on 25/11/2023.
//

#ifndef ALGORITHMSANDDATASTRUCTS_USER_H
#define ALGORITHMSANDDATASTRUCTS_USER_H

#include <string>

class User {
public:
    std::string username;
    User() { //constructr with no parameter.
        this->username = "Unknown player";
    }
    User(std::string p_username) { //constructor with given username;
        this->username = p_username;
    }
    void greetPlayer() {};
};


#endif //ALGORITHMSANDDATASTRUCTS_USER_H
