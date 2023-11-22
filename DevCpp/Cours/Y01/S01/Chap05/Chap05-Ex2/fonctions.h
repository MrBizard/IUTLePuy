#pragma once
#include <vector>
#include <string>

double plus(double a, double b);
double moins(double a, double b);
double fois(double a, double b);
double divise(double a, double b);

using OperatorFunc = double(*)(double, double);

void decodeCalcul(const std::string& calcul, std::vector<double>& operandes, std::vector<OperatorFunc>& operateurs);
double calcule(const std::vector<double>& operandes, const std::vector<OperatorFunc>& operateurs);
