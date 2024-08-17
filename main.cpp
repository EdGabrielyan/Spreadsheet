#include <iostream>
#include "cell.h"
#include "spreadsheet.h"

int main() {
    Cell obj;
    obj.set_value("hello");
    //obj.get_value(obj);
    Spreadsheet sheet(4, 5);
    sheet.set_value(1, 3, "16");
    sheet.set_value(2, 2, "25");
    std::cout << sheet.get_value(1, 2).toInt() << std::endl;
}
