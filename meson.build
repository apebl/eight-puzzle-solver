project('eight-puzzle', 'cpp',
    version: '0.1.0',
    license: 'MIT',
    meson_version: '>=0.53.0',
    default_options: ['cpp_std=c++17'])

cc = meson.get_compiler('cpp')

sources = files(
    'eight_puzzle/matrix.cpp',
    'eight_puzzle/matrix.hpp',
    'eight_puzzle/node.cpp',
    'eight_puzzle/node.hpp',
    'eight_puzzle/solver.cpp',
    'eight_puzzle/solver.hpp',
    'eight_puzzle/main.cpp'
)

executable('eight-puzzle', sources)
