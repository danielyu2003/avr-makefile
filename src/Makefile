# Generic makefile for avr projects

# Your project structure should look like

# proj
# |_include
# |	|_some_header.h
# |_src
# | |_project
# | |_project.hex
# | |_project.c
# | |_some_header.c
# | |_Makefile
# | |_obj
# |   |_project.o
# |   |_some_header.o


CC=avr-gcc
# Consider including -S to observe the generated assembly 
CFLAGS=-Os -Wall -Wextra -Werror=implicit -I../include

SOURCES=$(wildcard *.c)
OBJECTS=$(addprefix obj/,$(notdir $(SOURCES:.c=.o)))

# to change project name
EXECUTABLE=blinky

MCU=atmega328p
PART=ATMEGA328P
CLOCKSPEED=16000000
PLATFORM=arduino
SERIAL=/dev/cu.usbmodem1101

BURNER=avrdude
ASSEMBLING_FLAGS=-DF_CPU=$(CLOCKSPEED) -mmcu=$(MCU) -c -o
LFLAGS=-mmcu=$(MCU)
BAUDRATE=115200
BURNERFLAGS=-F -V -c $(PLATFORM) -p $(PART) -P $(SERIAL) -b $(BAUDRATE)
MEMOP=-U flash:w:$(EXECUTABLE).hex

TOHEX=avr-objcopy
TOHEXFLAGS=-O ihex -R .eeprom

default: build

build: $(OBJECTS)
	$(CC) $(LFLAGS) $(OBJECTS) -o $(EXECUTABLE)
	$(TOHEX) $(TOHEXFLAGS) $(EXECUTABLE) $(EXECUTABLE).hex

obj/%.o: %.c
	$(CC) $(CFLAGS) $(ASSEMBLING_FLAGS) $@ $< 

burn:
	$(BURNER) $(BURNERFLAGS) $(MEMOP)

clean:
	rm -f $(OBJECTS) $(EXECUTABLE) $(EXECUTABLE).hex

.PHONY: burn clean build
