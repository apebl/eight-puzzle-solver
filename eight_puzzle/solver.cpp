#include "solver.hpp"
#include <iostream>

namespace {
    int calc_inv_count (const eight_puzzle::Matrix &mat) {
        int inv_count = 0;
        int len = MAT_SIZE*MAT_SIZE;
        for (int i = 0; i < len - 1; i++) {
            for (int j = i + 1; j < len; j++) {
                if (mat[i] != BLANK && mat[j] != BLANK && mat[i] > mat[j]) {
                    inv_count++;
                }
            }
        }
        return (inv_count % 2) == 0;
    }
}

namespace eight_puzzle {

Solver::Solver (const Matrix &initial, const Matrix &goal)
: _initial { initial }, _goal { goal } {
}

const Matrix &Solver::get_initial () {
    return _initial;
}

const Matrix &Solver::get_goal () {
    return _goal;
}

bool Solver::is_solvable () const {
    int initial_inv_count = calc_inv_count(_initial);
    int goal_inv_count = calc_inv_count(_goal);
    return (initial_inv_count%2) == (goal_inv_count%2);
}

void Solver::solve () {
    if (!is_solvable()) {
        _initial.print();
        std::cout << ":: Unsolvable puzzle" << std::endl << std::endl;
        return;
    }

    std::unique_ptr<Node> root = std::make_unique<Node>(nullptr, _initial, 0);
    root->estimate(_goal);
    _queue.push(root.get());
    _nodes.push_back( std::move(root) );

    while (!_queue.empty()) {
        Node *node = _queue.top();
        _queue.pop();
        _visited.push_back(node);

        if (node->get_puzzle() == _goal) {
            node->print_path();
            break;
        }

        std::unique_ptr<Node> up = node->move_up();
        std::unique_ptr<Node> down = node->move_down();
        std::unique_ptr<Node> left = node->move_left();
        std::unique_ptr<Node> right = node->move_right();
        std::unique_ptr<Node> next_nodes[] = {
            std::move(up), std::move(down), std::move(left), std::move(right)
        };

        for (int i = 0; i < 4; i++) {
            std::unique_ptr<Node> &next = next_nodes[i];
            if (!next) continue;
            if (is_visited(next.get())) continue;
            next->estimate(_goal);
            _queue.push(next.get());
            _nodes.push_back( std::move(next) );
        }
    }
    _nodes.clear();
}

bool Solver::is_visited (const Node *node) const {
    for (const Node *el : _visited) {
        if (*node == *el) {
            return true;
        }
    }
    return false;
}

} /* namespace eight_puzzle */
