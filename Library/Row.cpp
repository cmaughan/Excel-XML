//
//  Row.cpp
//  ExcelTest
//
//  Created by Daniel Eisterhold on 2/11/15.
//  Copyright (c) 2015 Daniel Eisterhold. All rights reserved.
//

#include "Row.h"

Row::Row() {
    _contentsOfRow = vector<Cell>();
}

Row::Row(Cell data[], int numOfCells) {
    for (int cellNum = 0; cellNum < numOfCells; cellNum++) {
        addCell(data[cellNum]);
    }
}

void Row::addCell(Cell newCell) {
    _contentsOfRow.push_back(newCell);
}

void Row::removeCell(int index) {
    _contentsOfRow.erase(_contentsOfRow.begin() + index);
}

void Row::setCell(Cell newCell, int index) {
    _contentsOfRow[index] = newCell;
}

Cell* Row::getCell(int index) {
    return &_contentsOfRow[index];
}

int Row::getNumberOfCells() {
    return (int) _contentsOfRow.size();
}

string Row::getXML() {
    string temp = "<ss:Row>\n";
    
    for (int cellNum = 0; cellNum < _contentsOfRow.size(); cellNum++) {
        temp += _contentsOfRow[cellNum].getXML();
    }
    
    temp += "</ss:Row>\n";
    return temp;
}