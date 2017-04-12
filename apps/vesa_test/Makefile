# Исходные объектные модули
SOURCES=main.o

# Флаги компилятора языка C
CFLAGS=-nostdlib -nostdinc -fno-builtin -fno-stack-protector -m32 -g -I ../../appframework/include

# Флаги компоновщика
LDFLAGS=-T  ../../appframework/link.ld -m elf_i386

# Флаги ассемблера
ASFLAGS=--32

# Правило сборки
all: $(SOURCES) link

# Правило очистки
clean:
	-rm *.o app

voe_init.o:
	as --32 ../../appframework/voe_init.s -o voe_init.o  

# Правило компоновки
link:
	ld $(LDFLAGS) -o app $(SOURCES)
