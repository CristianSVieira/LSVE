all: 
	gcc ../general/*.c ./*.c -I../general -I../maçã -o lsve 

desbraga: 
	leaks --atExit -- ./lsve ../../teste.lsve*
