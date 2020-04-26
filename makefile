.PHONY: build clean

build: enigma.cpp
        g++ enigma.cpp -o enigma

clean: enigma
        rm ./enigma
