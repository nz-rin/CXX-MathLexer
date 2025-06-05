echo "COMPILING MAIN"

echo "  > g++ -DLOG_ERROR -Wall -Wextra main.cxx -o main"

g++ -DLOG_ERROR -Wall -Wextra main.cxx -o main

if [[ $? != 0 ]]; then
	echo "FAILED TO COMPILE"
else
	echo "COMPILED: main"
fi
