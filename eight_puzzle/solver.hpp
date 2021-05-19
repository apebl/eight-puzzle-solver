#ifndef EIGHTPUZZLE_SOLVER_HPP
#define EIGHTPUZZLE_SOLVER_HPP

#include "matrix.hpp"
#include "node.hpp"
#include <vector>
#include <queue>
#include <memory>

namespace eight_puzzle {

struct Comparator {
	bool operator() (const Node *a, const Node *b) {
        return a->get_cost() > b->get_cost();
	}
};

class Solver {
public:
    Solver (const Matrix &initial, const Matrix &goal);

    /**
     * Gets the initial matrix,
     */
    const Matrix &get_initial ();
    /**
     * Gets the goal matrix,
     */
    const Matrix &get_goal ();
    /**
     * Returns whether the puzzle is solvable.
     */
    bool is_solvable () const;
    /**
     * Solves the puzzle.
     */
    void solve ();

private:
    bool is_visited (const Node *node) const;

    Matrix _initial;
    Matrix _goal;
    std::vector<Node*> _visited {};
    std::priority_queue<Node*, std::vector<Node*>, Comparator> _queue {};
    std::vector<std::unique_ptr<Node>> _nodes {};
};

} /* namespace eight_puzzle */

#endif /* EIGHTPUZZLE_SOLVER_HPP */
