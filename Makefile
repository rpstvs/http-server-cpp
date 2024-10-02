#
# GenPIS makefile v1.0.0
#

.DEFAULT_GOAL := HTTP-Server

INCS = \
-I ./inc/ \



OBJS+= \
./src/bindingSocket.o \
./src/socket.o \
./src/listenSocket.o \
./src/main.o




#All Target
all: clean HTTP-Server

%.o:%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: G++ Compiler'
	g++ -Wall -c -o "$@" "$<" $(INCS) $(LIBS) 
	@echo 'Finished building: $<'
	@echo ' '

HTTP-Server: $(OBJS) $(LIBS)
	@echo 'Building target: $@'
	@echo 'Invoking: G++ Linker'
	g++ -o $@ -Wall $(OBJS) $(LIBS) $(INCS)
	#@echo 'Finished building target: $@' 
	#@echo ' '

clean: 
	rm -rf $(OBJS) HTTP-Server