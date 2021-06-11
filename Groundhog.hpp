/*
** EPITECH PROJECT, 2019
** Groundhog
** File description:
** tableau element
*/

#ifndef _GROUNDHOG_HPP_
#define _GROUNDHOG_HPP_

#include <iostream>
#include <vector>
#include <iomanip>
#include <cmath>

class Groundhog
{
    public:
        Groundhog(int);
        ~Groundhog();

        void add(double);

        void UpdateInfo();
        void DisplayInfo();
        void DisplayLastInfo();

        void getG();
        int getR();
        float getS();
        void makeG();
        void makeR();
        void makeS();

        void getWeird();
        void check_dif(double, double);

        int _iterator = 0;

    private:
        std::vector<double> _tab;
        std::vector<double> _weird_dif;
        std::vector<double> _weird_elem;

        int _period;

        int _switch_occur = 0;

        double _g = 0;
        int _r = 0;
        int _oldr = 0;
        double _s = 0;
};

#endif