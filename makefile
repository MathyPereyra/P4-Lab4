# Objetivo predeterminado (no se necesita especificarlo al invocar `make').
all: principal

# Objetivos que no son archivos.
.PHONY: all entrega

MODULOS = ChatGPT DTFecha DTInfoEstudiante Estudiante Informacion Libro PaginaWeb

# directorios
HDIR    = include
CPPDIR  = src
ODIR    = obj

# extensión de los archivos
EXT = cpp
# compilador
CC = g++
LD = g++

CCFLAGS = -Wall -I$(HDIR) -g  -DNDEBUG

CCFLAGS += -std=c++11

HS   = $(MODULOS:%=$(HDIR)/%.h)
CPPS = $(MODULOS:%=$(CPPDIR)/%.$(EXT))
OS   = $(MODULOS:%=$(ODIR)/%.o)

PRINCIPAL=principal
EJECUTABLE=principal

$(ODIR)/$(PRINCIPAL).o:$(PRINCIPAL).$(EXT)
	@printf 'Compilando $(<) \n'; \
	$(CC) $(CCFLAGS) -c $< -o $@

# Compilador
$(ODIR)/%.o: $(CPPDIR)/%.$(EXT)  $(HDIR)/%.h
	$(CC) $(CCFLAGS) -c $< -o $@ ; \

# $^ se expande para tranformarse en todas las dependencias
$(EJECUTABLE):$(ODIR)/$(PRINCIPAL).o $(OS)
	@printf 'Compilando y enlazando $(@) \n'; \
	$(LD) $(CCFLAGS) $^ -o $@

clean:
	rm -f $(ODIR)/*.c $(ODIR)/*.o
