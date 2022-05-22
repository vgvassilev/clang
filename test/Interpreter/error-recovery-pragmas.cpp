// RUN: cat %s | clang-repl -Xcc -Xclang -Xcc -verify
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wmultichar"
// Reset should not delete #pragmas
error; // expected-error {{use of undeclared identifier}}
void no_diag_multichar( void ) { char c = (char) 'ab'; }
