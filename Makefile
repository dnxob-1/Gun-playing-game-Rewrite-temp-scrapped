CC = g++
CFLAGS = -I include -Wall -Wextra -O2

$(shell mkdir -p build)
$(shell mkdir -p data)

TARGET = build/run
dataDir = data

SRCS = main.cpp givePlayers.cpp waveFuncs/wavePlayer1.cpp waveFuncs/wavePlayer2.cpp waveFuncs/wave.cpp logRelated/findLog.cpp
OBJS = $(SRCS:.c=.o)

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) -o $(TARGET) $(OBJS)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(TARGET) $(dataDir)/*.txt
