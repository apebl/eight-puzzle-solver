#ifndef EIGHTPUZZLE_NODE_HPP
#define EIGHTPUZZLE_NODE_HPP

#include "matrix.hpp"
#include <limits>
#include <memory>

namespace eight_puzzle {

class Node {
public:
    Node ();
    Node (const Node *parent, const Matrix &matrix, int distance);
    Node (const Node &other);

    bool operator== (const Node &other) const;

    /**
     * Returns the puzzle.
     */
    Matrix &get_puzzle ();
    /**
     * Returns the distance from start.
     */
    int get_distance () const;
    /**
     * Returns the heuristic which is the number of misplaced tiles.
     */
    int get_heuristic () const;
    /**
     * Returns the cost of this node.
     */
    int get_cost () const;
    /**
     * Estimates the heuristic value.
     */
    void estimate (const Matrix &goal);

    /**
     * Returns a next node whose blank tile has moved upward.
     *
     * @return The next node, or nullptr if unable to move
     */
    std::unique_ptr<Node> move_up () const;
    /**
     * Returns a next node whose blank tile has moved downwards.
     *
     * @return The next node, or nullptr if unable to move
     */
    std::unique_ptr<Node> move_down () const;
    /**
     * Returns a next node whose blank tile has moved to the left.
     *
     * @return The next node, or nullptr if unable to move
     */
    std::unique_ptr<Node> move_left () const;
    /**
     * Returns a next node whose blank tile has moved to the right.
     *
     * @return The next node, or nullptr if unable to move
     */
    std::unique_ptr<Node> move_right () const;

    /**
     * Prints this node.
     */
    void print () const;
    /**
     * Prints the path from start to this node.
     * @return the depth
     */
    int print_path () const;

private:
    const Node *_parent;
    Matrix _matrix;
    int _distance;
    int _heuristic = std::numeric_limits<int>::max();
};

} /* namespace eight_puzzle */

#endif /* EIGHTPUZZLE_NODE_HPP */
