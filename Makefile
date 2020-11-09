#Aquí se agregan los objetos para compilar
OBJS = main.o Truck.o Node.o Day.o Round.o ProblemInstance.o FileHandler.o
#Para poner opciones de la versión de C++ a ocupar 
FLAGS = -O3

#Que genere el archivo llamado así
all: MOPDebris

#Que se va a hacer cada vez que se llame al archivo
MOPDebris: $(OBJS)
	g++ -o MOPDebris $(OBJS) $(FLAGS)
  
#Para generar cualquier punto .o necesito cualquier punto .cpp
%.o: %.cpp %.h
	g++ -c $(FLAGS) $< -o $@

#Para que me lea el archivo de las instancias 

# nombreAlgoritmo nombreArchivo semilla itExt itInt

exe:
	./MOPDebris Instancias/instancia.txt 10
  
clean: 
	rm -rf *.o MOPDebris