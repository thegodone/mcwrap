addpath('cpp_example1');

% Compile
mcwrap('cpp_example1/reverse_it.h');

% Run
X=[1,2,4,9,16];
reverse_it(length(X),X)
