myas : main.o trans.o check.o
	gcc -o myas main.o trans.o check.o
main.o : main.c
	gcc -c -o main.o main.c
trans.o : trans.c
	gcc -c -o trans.o trans.c
check.o : check.c
	gcc -c -o check.o check.c
clean :
	rm *.o myas
