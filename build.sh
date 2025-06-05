echo "COMPILING MAIN"

echo "  > g++ -ggdb -DLOG_ERROR -Wall -Wextra main.cxx -o main"

g++ -ggdb -DLOG_ERROR -Wall -Wextra main.cxx -o main

if [[ $? != 0 ]]; then
	echo "FAILED TO COMPILE"
else
	echo "COMPILED: main"
fi
