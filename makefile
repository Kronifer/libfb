libfb.a : px.o buffer.o draw.o 
	mkdir -p bin
	ar -cvq bin/libfb.a px.o buffer.o draw.o
	rm px.o buffer.o draw.o

px.o : 
	gcc -c src/px.c

buffer.o : 
	gcc -c src/buffer.c

draw.o : 
	gcc -c src/draw.c

clean : 
	rm -rf bin/
