application_static: staticlib 
	gcc-10 Funktionsgenerator.c -lFunktionsgenerator_staticlib -o Funktionsgenerator.elf -lm
	
staticlib:
	gcc-10 Funktionsgenerator_staticlib.c -c
	ar -crs libFunktionsgenerator_staticlib.a Funktionsgenerator_staticlib.o
	sudo cp Funktionsgenerator_staticlib.h /usr/include
	sudo cp libFunktionsgenerator_staticlib.a /usr/lib
