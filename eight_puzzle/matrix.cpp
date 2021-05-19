#include "matrix.hpp"
#include <iostream>

namespace eight_puzzle {

Matrix::Matrix () : _array {{0}} {
}

Matrix::Matrix (const int array[MAT_SIZE * MAT_SIZE]) : _array {{0}} {
    for (int r = 0; r < MAT_SIZE; r++) {
        for (int c = 0; c < MAT_SIZE; c++) {
            set(r, c, array[r*MAT_SIZE + c]);
        }
    }
}

Matrix::Matrix (const Matrix &other) : _array {{0}} {
    for (int r = 0; r < MAT_SIZE; r++) {
        for (int c = 0; c < MAT_SIZE; c++) {
            set(r, c, other.get(r, c));
        }
    }
}

bool Matrix::operator== (const Matrix &other) const {
    if (this == &other) return true;
    for (int r = 0; r < MAT_SIZE; r++) {
        for (int c = 0; c < MAT_SIZE; c++) {
            if (get(r, c) != other.get(r, c)) {
                return false;
            }
        }
    }
    return true;
}

int Matrix::operator[] (int idx) const {
    return _array[idx];
}

int Matrix::get (int row, int col) const {
    return _array[row*MAT_SIZE + col];
}

void Matrix::set (int row, int col, int val) {
    _array[row*MAT_SIZE + col] = val;
    if (val == BLANK) {
        _blank_row = row;
        _blank_col = col;
    }
}

int Matrix::get_blank_row () const {
    return _blank_row;
}

int Matrix::get_blank_col () const {
    return _blank_col;
}

bool Matrix::can_move_blank_up () const {
    return _blank_row > 0;
}

bool Matrix::can_move_blank_down () const {
    return _blank_row < MAT_SIZE-1;
}

bool Matrix::can_move_blank_left () const {
    return _blank_col > 0;
}

bool Matrix::can_move_blank_right () const {
    return _blank_col < MAT_SIZE-1;
}

void Matrix::move_blank_up () {
    set(_blank_row, _blank_col, get(_blank_row-1, _blank_col));
    set(_blank_row - 1, _blank_col, BLANK);
}

void Matrix::move_blank_down () {
    set(_blank_row, _blank_col, get(_blank_row+1, _blank_col));
    set(_blank_row + 1, _blank_col, BLANK);
}

void Matrix::move_blank_left () {
    set(_blank_row, _blank_col, get(_blank_row, _blank_col-1));
    set(_blank_row, _blank_col - 1, BLANK);
}

void Matrix::move_blank_right () {
    set(_blank_row, _blank_col, get(_blank_row, _blank_col+1));
    set(_blank_row, _blank_col + 1, BLANK);
}

void Matrix::print () const {
    for (int r = 0; r < MAT_SIZE; r++) {
        std::cout << "| ";
        for (int c = 0; c < MAT_SIZE; c++) {
            int val = get(r, c);
            std::string tilestr = val == BLANK ? " " : std::to_string(val);
            std::cout << tilestr << " | ";
        }
        std::cout << std::endl;
        if (r != MAT_SIZE - 1) {
            std::cout << " ";
            for (int i = 0; i < MAT_SIZE; i++) {
                std::cout << "--- ";
            }
            std::cout << std::endl;
        }
    }
}

} /* namespace eight_puzzle */
