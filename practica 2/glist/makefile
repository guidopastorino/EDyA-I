# Nombre del ejecutable
TARGET = main

# Archivos fuente
SRCS = main.c glist.c

# Opciones para el compilador
CFLAGS = -Wall -Wextra

# Regla para compilar el programa
$(TARGET): $(SRCS)
	@gcc $(CFLAGS) $(SRCS) -o $(TARGET)

# Regla para limpiar los archivos generados
clean:
	@del $(TARGET).exe

# Regla por defecto: compilar el programa
all: $(TARGET)

# Regla para ejecutar el programa
run: $(TARGET)
	@$(TARGET).exe

# Indicamos que 'clean' y 'run' no son nombres de archivos
.PHONY: clean run
