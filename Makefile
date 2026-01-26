TARGET=RayBird.out
CC=g++
LD=g++
DEBUG=-s
OBJS=main.cpp ./code/objects/entity.cpp ./code/Window.cpp
WARN=-Wall
#CVER=-std=c99
RAY=-lraylib
IM=-lm
PTHREAD=-lpthread
LDL=-ldl
CCFLAGS=$(DEBUG) $(WARN) $(CVER) $(RAY) $(IM) $(PTHREAD) $(LDL)
RayppyBird:$(OBJS)
	$(LD) $(OBJS) -o $(TARGET) $(CCFLAGS)
