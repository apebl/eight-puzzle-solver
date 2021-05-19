# 8-Puzzle Solver

A 8-puzzle solver written in C++.

See [REPORT.pdf](REPORT.pdf) for a detailed description.

## Build and run

### Using Meson

```sh
meson _build
meson compile -C _build
./_build/eight-puzzle
```

### Manual compile

```sh
g++ eight_puzzle/*.cpp eight_puzzle/*.hpp
./a.out
```
