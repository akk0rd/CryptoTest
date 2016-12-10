all:
	g++ lab1.cpp -o Tester -std=c++11
install:
	install Tester /usr/bin/ 
uninstall:
	rm /usr/bin/Tester
clean:
	rm Tester
