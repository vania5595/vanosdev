# Исходные объектные модули
SOURCES=multiboot.o main.o terminal.o ramdisk.o fs.o memory.o voe.o

# Флаги компилятора языка C
CFLAGS=-nostdlib -nostdinc -fno-builtin -fno-stack-protector -m32 -g

# Флаги компоновщика
LDFLAGS=-T link.ld -m elf_i386

# Флаги ассемблера
ASFLAGS=--32

# Правило сборки
all: $(SOURCES) link

# Правило очистки
clean:
	-rm *.o kernel  

# Правило компоновки
link:
	ld $(LDFLAGS) -o kernel $(SOURCES)
