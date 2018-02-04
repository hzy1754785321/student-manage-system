hzy:main.o student.o teacher.o tooler.o menu.o login.o
	gcc main.o student.o teacher.o tooler.o menu.o login.o -o hzy
main.o:main.c
	gcc -c main.c -o main.o
student.o:student.c
	gcc -c student.c -o student.o
teacher.o:teacher.c
	gcc -c teacher.c -o teacher.o
tooler.o:tooler.c
	gcc -c tooler.c -o tooler.o
menu.o:menu.c
	gcc -c menu.c -o menu.o
login.o:login.c
	gcc -c login.c -o login.o
clean:
	rm *.o 
