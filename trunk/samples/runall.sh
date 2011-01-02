#!/bin/sh
echo "Hello world sample:"
./compile.sh samples/hello.lsk -o bin/hello && ./bin/hello
echo "'echo' sample:"
./compile.sh samples/echo.lsk -o bin/echo && ./bin/echo Hello\,\ World\!
echo "Quine sample:"
./compile.sh samples/quine.lsk -o bin/quine && ./bin/quine
echo "'cat' sample:"
./compile.sh samples/cat.lsk -o bin/cat && ./bin/cat < samples/cat.lsk
echo "Capitalize sample:"
./compile.sh samples/capitalize.lsk -o bin/capitalize && ./bin/capitalize < samples/capitalize.lsk
echo "'wc' sample:"
./compile.sh samples/wc.lsk -o bin/wc && ./bin/wc < samples/wc.lsk
