CXX = g++
CXXFLAGS = -std=c++14 -Wall -MMD
OBJECTS = game.o player.o monster.o card.o model.o spellfunctions.o spell.o spellcards.o monstercards.o deckLoad.o modifier.o modifiercards.o ascii_graphics.o ASCIIdisplay.o
DEPENDS = ${OBJECTS:.o=.d}
EXEC = game

${EXEC}: ${OBJECTS}
	${CXX} ${OBJECTS} -o ${EXEC}

-include ${DEPENDS}

.PHONY: clean

clean:
	rm ${OBJECTS} ${EXEC} ${DEPENDS}