#include "node.hpp"
#include <iostream>

namespace eight_puzzle {

Node::Node ()
: _parent {nullptr}, _matrix {}, _distance {0} {
}

Node::Node (const Node *parent, const Matrix &matrix, int distance)
: _parent {parent}, _matrix {matrix}, _distance {distance} {
}

Node::Node (const Node &other)
: _parent {other._parent}, _matrix {other._matrix},
  _distance {other._distance}, _heuristic {other._heuristic} {
}

bool Node::operator== (const Node &other) const {
    if (this == &other) return true;
    return _matrix == other._matrix;
}

Matrix &Node::get_puzzle () {
    return _matrix;
}

int Node::get_distance () const {
    return _distance;
}

int Node::get_heuristic () const {
    return _heuristic;
}

int Node::get_cost () const {
    return _distance + _heuristic;
}

void Node::estimate (const Matrix &goal) {
    int h = 0;
    for (int r = 0; r < MAT_SIZE; r++) {
        for (int c = 0; c < MAT_SIZE; c++) {
            if (_matrix.get(r, c) != goal.get(r, c)) {
                h++;
            }
        }
    }
    _heuristic = h;
}

std::unique_ptr<Node> Node::move_up () const {
    if (!_matrix.can_move_blank_up()) return std::unique_ptr<Node>{};
    std::unique_ptr<Node> node = std::make_unique<Node>(this, _matrix, _distance + 1);
    node->_matrix.move_blank_up();
    return node;
}

std::unique_ptr<Node> Node::move_down () const {
    if (!_matrix.can_move_blank_down()) return std::unique_ptr<Node>{};
    std::unique_ptr<Node> node = std::make_unique<Node>(this, _matrix, _distance + 1);
    node->_matrix.move_blank_down();
    return node;
}

std::unique_ptr<Node> Node::move_left () const {
    if (!_matrix.can_move_blank_left()) return std::unique_ptr<Node>{};
    std::unique_ptr<Node> node = std::make_unique<Node>(this, _matrix, _distance + 1);
    node->_matrix.move_blank_left();
    return node;
}

std::unique_ptr<Node> Node::move_right () const {
    if (!_matrix.can_move_blank_right()) return std::unique_ptr<Node>{};
    std::unique_ptr<Node> node = std::make_unique<Node>(this, _matrix, _distance + 1);
    node->_matrix.move_blank_right();
    return node;
}

void Node::print () const {
    _matrix.print();
    std::cout << " - dist = " << _distance << ", heuristic = " << _heuristic << std::endl;
    std::cout << " - cost = dist + heuristic = " << get_cost() << std::endl << std::endl;
}

int Node::print_path () const {
    int depth = 1;
    if (_parent != nullptr) {
        depth += _parent->print_path();
    }
    std::cout << ":: [Node #" << depth << "]" << std::endl;
    print();
    return depth;
}

} /* namespace eight_puzzle */
