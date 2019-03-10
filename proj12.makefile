proj12: proj12.driver.o proj12.support.o
	gcc -Wall proj12.driver.o proj12.support.o -o proj12

proj12.driver.o: proj12.driver.c
	gcc -Wall -c proj12.driver.c

proj12.support.o: proj12.support.c
	gcc -Wall -c proj12.support.c
