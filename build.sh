#!/bin/sh
clang++ -O2 -fno-plt -fno-semantic-interposition -Wl,-z,now -Wl,-z,relro -Wl,--as-needed -Wl,-Bsymbolic -o x-wait-indefinitely x-wait-indefinitely.cpp -lxcb
