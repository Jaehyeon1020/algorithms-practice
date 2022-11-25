report3 : main.o rbTree.o reservation.o linkedList.o graph.o
	gcc -o report3 main.o rbTree.o reservation.o linkedList.o graph.o

main.o : main.c
	gcc -c main.c main.o

rbTree.o : rbTree.c
	gcc -c rbTree.c rbTree.o

reservation.o : reservation.c
	gcc -c reservation.c reservation.o

linkedList.o : linkedList.c
	gcc -c linkedList.c	 linkedList.o

graph.o : graph.c
	gcc -c graph.c graph.o

clean:
	rm *.o report3