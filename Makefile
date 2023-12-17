scanner:
	cc -o scanner -g main.c scan.c 

clean:
	rm -f scanner *.o
