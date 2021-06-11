/*
** EPITECH PROJECT, 2019
** Groundhog
** File description:
** main cpp
*/

#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "Groundhog.hpp"

void usage()
{
    std::cout << "SYNOPSIS" << std::endl;
    std::cout << "\t./groundhog period" << std::endl;
    std::cout << "DESCRIPTION" << std::endl;
    std::cout << "\tperiod\tthe number of days defining a period" << std::endl;
}

void check_arg(int ac, char *argv[])
{
    if (ac != 2)
        exit(84);
    if (strcmp(argv[1], "-h") == 0) {
        usage();
        exit(EXIT_SUCCESS);
    }
}

int getDays(int ac, char *av[])
{
    int days;

    check_arg(ac, av);
    try {
        days = atoi(av[1]);
    }
    catch (...) {
        exit(84);
    }
    if (days < 1)
        exit(84);
    return (days);
}

double getTemp(std::string user_temp)
{
    double temp;

    try {
        temp = std::stod(user_temp);
    }
    catch (...) {
        std::cerr << "wrong type" << std::endl;
        exit(84);
    }
    return (temp);   
}

int main(int ac, char *av[])
{
    std::string user_command;
    int days;
    double temp;

    days = getDays(ac, av);
    Groundhog tab(days);
    
    while (std::cin) {
        std::cin >> user_command; 
        if (user_command == "STOP") {
            if (days > 0) {
                std::cerr << "not enough value" << std::endl;
                exit(84);
            }
            tab.DisplayLastInfo();
            exit(EXIT_SUCCESS);
        }
        else {
            temp = getTemp(user_command);
            tab.add(temp);
            tab.DisplayInfo();
            days--;
        }
    }
    std::cerr << "no stop" << std::endl;
    exit (84);
}