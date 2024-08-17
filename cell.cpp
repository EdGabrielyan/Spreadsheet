#include <iostream>
#include "cell.h"

Cell::Cell(const std::string &value) {
    this->m_value = value;
}

void Cell::set_value(std::string value) {
    this->m_value = value;
    print_cell(*this);
}

std::string Cell::get_value() const {
    return this->m_value;
}

int Cell::toInt() {
    int tmp = std::stoi(this->m_value);
    return tmp;
}

double Cell::toDouble() {
    double tmp = std::stod(this->m_value);
    return tmp;
}

void Cell::print_cell(const Cell &cell) {
    std::cout << cell.get_value() << std::endl;
}