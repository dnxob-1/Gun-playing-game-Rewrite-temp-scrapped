CC = g++
CFLAGS = -I include -Wall -Wextra -O2

$(shell mkdir -p build)

TARGET = build/run

SRCS = main.cpp givePlayers.cpp wavePlayer1.cpp wavePlayer2.cpp wave.cpp 
OBJS = $(SRCS:.c=.o)

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) -o $(TARGET) $(OBJS)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(TARGET)
