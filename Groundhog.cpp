/*
** EPITECH PROJECT, 2019
** Groundog
** File description:
** Groundhog
*/

#include "Groundhog.hpp"

Groundhog::Groundhog(int period): _period(period)
{}

Groundhog::~Groundhog()
{}

void Groundhog::makeG()
{
    size_t i;
    double period_av;
    
    if (_iterator <= _period) {
        return;
    } else {
        _g = 0;
        for (i = _tab.size() - _period; i != _tab.size(); i++) {
            period_av = _tab[i] - _tab[i-1];
            if (period_av > 0) {
                _g += period_av;
            }
        }
        _g /= _period;
    }
}

void Groundhog::makeR()
{
    if (_iterator <= _period) {
        return;
    }
    _oldr = _r;
    double val1 = _tab[_tab.size() - _period - 1]; 
    double val2 = _tab.back();
    _r = (int)(round((val2 - val1) / val1 * 100));
}

void Groundhog::makeS()
{
    if (_iterator < _period) {
        return;
    }
    double val1 = 0;
    double val2 = 0;
    for (auto iterator = _tab.end() - _period; iterator != _tab.end(); iterator++) {
        val1 += *iterator;
        val2 += (*iterator * *iterator);
    }
    _s = sqrt(val2 / _period - (val1 / _period) * (val1 / _period));
}

void Groundhog::add(double val)
{
    _tab.push_back(val);
    _iterator++;
    this->UpdateInfo();
}

void Groundhog::UpdateInfo()
{
    this->makeG();
    this->makeR();
    this->makeS();
}

void Groundhog::DisplayInfo()
{
    if (_iterator > _period) {
        std::cout << std::setprecision(2) << std::fixed << "g=";
        if (_g < 0) 
            std::cout << "0.00"; 
        else 
            std::cout << _g;
        std::cout << "\tr=" << _r << "%\ts=" << _s;
    }
    else if (_iterator == _period) {
        std::cout << std::setprecision(2) << std::fixed << "g=nan\tr=nan%\ts=" << _s;
    }
    else {
        std::cout << "g=nan\tr=nan%\ts=nan";
    }
    if (((_oldr < 0 && _r >= 0) || (_oldr >= 0 && _r < 0)) && _oldr) {
        _switch_occur++;
        std::cout << "\ta switch occurs";
    }
    std::cout << std::endl;
}

void Groundhog::DisplayLastInfo()
{
    getWeird();
    std::cout << "Global tendency switched " << _switch_occur << " times" << std::endl;
    std::cout << "5 weirdest values are [" << _weird_elem.at(0) << ", " << _weird_elem.at(1) << ", " << 
    _weird_elem.at(2) << ", " << _weird_elem.at(3) << ", " << _weird_elem.at(4) << "]" << std::endl;
}

int Groundhog::getR()
{
    int r = 0;
    return (r);
}

float Groundhog::getS()
{
    float s = 0;
    return (s);
}

void Groundhog::getWeird()
{
    size_t i;
    double dif = 0;

    for (i = 1; i != _tab.size(); i++) {
        dif = _tab[i] - _tab[i-1];
        check_dif(dif, _tab[i]);
    }
}

void Groundhog::check_dif(double dif, double val)
{
    if (dif < 0)
        dif *= -1;
    if (_weird_dif.size() != 5) {
        _weird_dif.push_back(dif);
        _weird_elem.push_back(val);
        return;
    }
    size_t min_i = 0;
    double min = _weird_dif[0];
    for (size_t i = 1; i != _weird_dif.size() - 1; i++) {
        if (min > _weird_dif[i]) {
            min_i = i;
            min = _weird_dif[i];
        }
    }
    if (_weird_dif[min_i] < dif) {
            _weird_dif[min_i] = dif;
            _weird_elem[min_i] = val;
            return;
    }
}