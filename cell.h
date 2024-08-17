#ifndef CELL_H
#define CELL_H

class Cell {
public:
    Cell() = default;
    Cell(const std::string&);
public:
    void set_value(std::string);
    std::string get_value() const;
public:
    void print_cell(const Cell &);
public:
    int toInt();
    double toDouble();
private:
    std::string m_value;
};

#endif //CELL_H
