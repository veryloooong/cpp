tinyShell.exe : main.cpp function.cpp function.h
	g++ main.cpp function.cpp -o tinyShell.exe -Wall -std=c++17