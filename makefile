SHELL=cmd.exe
OBJS=main.o person.o josephus.o file_reader.o
main: $(OBJS)
		gcc -o main $(OBJS)
main.o:
		gcc -c main.c
person.o:
		gcc -c src/person.c
josephus.o:
		gcc -c src/josephus.c
file_reader.o:
		gcc -c src/file_reader.c
.PHONY: clean
clean:
		del $(OBJS)