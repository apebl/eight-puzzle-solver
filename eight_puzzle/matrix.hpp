#ifndef EIGHTPUZZLE_MATRIX_HPP
#define EIGHTPUZZLE_MATRIX_HPP

#include <initializer_list>

#define MAT_SIZE 3
#define BLANK 0

namespace eight_puzzle {

class Matrix {
public:
    Matrix ();
    Matrix (const int array[MAT_SIZE * MAT_SIZE]);
    Matrix (const Matrix &other);

    bool operator== (const Matrix &other) const;
    /**
     * Gets the value to the specified array element.
     */
    int operator[] (int idx) const;

    /**
     * Gets the value to the specified element.
     */
    int get (int row, int col) const;
    /**
     * Sets the value to (row, col)
     */
    void set (int row, int col, int val);

    /**
     * Gets the row position of the blank tile.
     */
    int get_blank_row () const;
    /**
     * Gets the col position of the blank tile.
     */
    int get_blank_col () const;
    /**
     * Returns whether the blank tile can be moved upwards.
     */
    bool can_move_blank_up () const;
    /**
     * Returns whether the blank tile can be moved downwards.
     */
    bool can_move_blank_down () const;
    /**
     * Returns whether the blank tile can be moved to the left.
     */
    bool can_move_blank_left () const;
    /**
     * Returns whether the blank tile can be moved to the right.
     */
    bool can_move_blank_right () const;
    /**
     * Moves the blank tile upwards.
     */
    void move_blank_up ();
    /**
     * Moves the blank tile downwards.
     */
    void move_blank_down ();
    /**
     * Moves the blank tile to the left.
     */
    void move_blank_left ();
    /**
     * Moves the blank tile to the right.
     */
    void move_blank_right ();

    /**
     * Prints this matrix.
     */
    void print () const;

private:
    int _array[MAT_SIZE * MAT_SIZE];
    int _blank_row = -1;
    int _blank_col = -1;
};

} /* namespace eight_puzzle */

#endif /* EIGHTPUZZLE_MATRIX_HPP */
