#pragma once

#include <array>
#include <iostream>
#include <string>

// Data struct to store tax info
struct TaxInfo
{
    TaxInfo() : zipCode(-1), state("N/A"), incomes({ -1, -1, -1, -1, -1, -1 }) {};
    TaxInfo(int zipCode, std::string state, std::array<int, 6> incomes) : zipCode(zipCode), state(state), incomes(incomes) {};

    void print()
    {
        std::cout << "State: " << state << " | ";
        std::cout << "Zip Code: " << zipCode << " | ";
        std::cout << "Income Distribution: ";
        for (int i : incomes) {
            std::cout << i << " ";
        }
        std::cout << std::endl;
    }

    const int zipCode;
    const std::string state;
    const std::array<int, 6> incomes;
};
