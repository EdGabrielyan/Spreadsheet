#ifndef SPREADSHEET_H
#define SPREADSHEET_H
#include "cell.h"

class Spreadsheet {
public:
    Spreadsheet(const int, const int);
    Spreadsheet(const Spreadsheet&);
    ~Spreadsheet();
public:
    int get_cols() const;
    int get_rows() const;
public:
    Spreadsheet& operator=(const Spreadsheet&);

    void set_value(const int&, const int&, const std::string&);
    Cell get_value(const int&, const int&);
    void verifyCoordinate(const int&, const int&);
private:
    int m_cols;
    int m_rows;
    Cell** m_cells;
};

#endif // SPREADSHEET_H
