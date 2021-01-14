#Aquí se agregan los objetos para compilar
OBJS = main.o Truck.o Node.o Day.o Round.o ProblemInstance.o FileHandler.o Solution.o Construction.o Pareto.o Movimiento.o 
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

# nombre Algoritmo 
# nombre Archivo 
# semilla 
# iteraciones externas 
# iteraciones internas
# temperatira inicial
# factor de enfriamiento
# vueltas a eliminar en una solucion
# cantidad de intentos para agregar vueltas en una solucion

exe:
	./MOPDebris Instancias/instancia4.txt 13 1000 1000 100 0.9

exe1:
	./MOPDebris Experimentos/Instancia1_N10_K2_D2_Depot1.txt 13 100 1000 100 0.9 2 6
  
clean: 
	rm -rf *.o MOPDebris
