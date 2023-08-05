#pragma once

struct TaxInfo {
    TaxInfo() : zipCode(-1), state("N/A"), incomes({ -1, -1, -1, -1, -1, -1 }) {};
    TaxInfo(int zipCode, std::string state, std::array<int, 6> incomes) : zipCode(zipCode), state(state), incomes(incomes) {};

    const int zipCode;
    const std::string state;
    const std::array<int, 6> incomes;
};