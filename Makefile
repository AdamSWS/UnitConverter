OBJ_DIR := Object\ Files

output: $(OBJ_DIR)/main.o $(OBJ_DIR)/MenuFunctions.o $(OBJ_DIR)/UnitConverter.o $(OBJ_DIR)/User.o
	g++ $(OBJ_DIR)/main.o $(OBJ_DIR)/MenuFunctions.o $(OBJ_DIR)/UnitConverter.o $(OBJ_DIR)/User.o -o calculator

$(OBJ_DIR)/main.o: main.cpp | $(OBJ_DIR)
	g++ -c main.cpp -o $(OBJ_DIR)/main.o


$(OBJ_DIR)/MenuFunctions.o: MenuFunctions.cpp MenuFunctions.h | $(OBJ_DIR)
	g++ -c MenuFunctions.cpp -o $(OBJ_DIR)/MenuFunctions.o

$(OBJ_DIR)/UnitConverter.o: UnitConverter.cpp UnitConverter.h | $(OBJ_DIR)
	g++ -c UnitConverter.cpp -o $(OBJ_DIR)/UnitConverter.o

$(OBJ_DIR)/User.o: User.cpp User.h | $(OBJ_DIR)
	g++ -c User.cpp -o $(OBJ_DIR)/User.o

$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)

clean:
	rm -f $(OBJ_DIR)/*.o output