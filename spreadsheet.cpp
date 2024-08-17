#include <iostream>
#include <exception>
#include "spreadsheet.h"

Spreadsheet::Spreadsheet(const int rows, const int cols){
    m_rows = rows;
    m_cols = cols;
    m_cells = new Cell*[m_rows];
    for (int i = 0; i < m_rows; ++i){
        m_cells[i] = new Cell[m_cols];
    }
}

Spreadsheet::Spreadsheet(const Spreadsheet &src) {
    m_rows = src.m_rows;
    m_cols = src.m_cols;
    for (int i = 0; i < m_rows; ++i) {
        for (int j = 0; j < m_cols; ++j) {
            m_cells[i][j] = src.m_cells[i][j];
        }
    }
}

Spreadsheet::~Spreadsheet() {
    for (int i = 0; i < m_rows; ++i){
        delete [] m_cells[i];
    }
    delete [] m_cells;
    m_cells = nullptr;
}

Spreadsheet& Spreadsheet::operator=(const Spreadsheet &rhs) {
    if (this == &rhs) {
        return *this;
    }
    for (int i = 0; i < m_rows; ++i) {
        delete [] m_cells[i];
    }
    delete [] m_cells;
    m_cells = nullptr;
    m_rows = rhs.m_rows;
    m_cols = rhs.m_cols;
    m_cells = new Cell*[m_rows];
    for (int i = 0; i < m_rows; ++i) {
        m_cells[i] = new Cell[m_cols];
    }
    return *this;
}

int Spreadsheet::get_cols() const {
    return this->m_cols;
}

int Spreadsheet::get_rows() const {
    return this->m_rows;
}

void Spreadsheet::verifyCoordinate(const int &rows, const int &cols) {
    if (rows < 0 || rows >= this->m_rows || cols < 0 && cols >= this->m_cols) {
        throw std::out_of_range("invalid index!");
    }
    else {
        m_rows = rows;
        m_cols = cols;
    }
}

void Spreadsheet::set_value(const int &rows, const int &cols, const std::string &value) {
    verifyCoordinate(rows, cols);
}

Cell Spreadsheet::get_value(const int &rows, const int &cols) {
    verifyCoordinate(rows, cols);
    return m_cells[m_rows][m_cols];
}