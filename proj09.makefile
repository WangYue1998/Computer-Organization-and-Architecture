proj09: proj09.support.o proj09.driver.o
	gcc -Wall  proj09.support.o proj09.driver.o -o proj09

proj09.driver.o: proj09.driver.c # /user/cse320/Projects/proj09.support.h
	gcc -Wall -c proj09.driver.c

proj09.support.o: proj09.support.s 
	gcc -march=native -c  proj09.support.s
