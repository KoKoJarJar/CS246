CXX = g++
CXXFLAGS= -g -Wall -Wextra -pedantic -std=c++11 -MMD
OBJECTS= $(patsubst %.cpp, %.o, $(wildcard *.cpp))
DEPENDS=${OBJECTS:.o=.d}
EXEC = build

${EXEC} : ${OBJECTS}
	${CXX} ${OBJECTS} -o ${EXEC}

-include ${DEPENDS}

.PHONY : clean
clean:
	rm -rf ${DEPENDS} ${OBJECTS} ${EXEC}
