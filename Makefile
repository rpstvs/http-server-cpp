#
# GenPIS makefile v1.0.0
#

.DEFAULT_GOAL := HTTP-Server

INCS = \
-I ./server/inc \
-I ./socket/inc \
-I ./threadpool/inc \



OBJS+= \
./server/src/server.o \
./server/src/testServer.o \
./socket/src/bindingSocket.o \
./socket/src/socket.o \
./socket/src/listenSocket.o \
./threadpool/src/threadpool.o \
./server/src/main.o \




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