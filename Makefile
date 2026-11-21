CXX      := g++
CXXFLAGS := -std=c++17 -Wall -Wextra -Wpedantic -O2
TARGET   := atm_sim
TEST_BIN := run_tests

SRCS     := main.cpp ContaBancaria.cpp
OBJS     := $(SRCS:.cpp=.o)
DEPS     := $(OBJS:.o=.d)

TEST_SRCS := tests.cpp ContaBancaria.cpp
TEST_OBJS := $(TEST_SRCS:.cpp=.o)

.PHONY: all run test clean distclean help

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $@ $^

# Compila arquivos .cpp em .o e gera dependencias (.d) dos headers
%.o: %.cpp
	$(CXX) $(CXXFLAGS) -MMD -MP -c $< -o $@

-include $(DEPS)

run: $(TARGET)
	./$(TARGET)

test: $(TEST_BIN)
	./$(TEST_BIN)

$(TEST_BIN): $(TEST_OBJS)
	$(CXX) $(CXXFLAGS) -o $@ $^

clean:
	rm -f $(OBJS) $(DEPS) $(TEST_OBJS) $(TEST_BIN) $(TARGET)

distclean: clean
	rm -f extrato.txt

help:
	@echo "Comandos disponiveis:"
	@echo "  make          - Compila o executavel ($(TARGET))"
	@echo "  make run      - Compila e executa o simulador"
	@echo "  make test     - Compila e executa os testes (requer tests.cpp)"
	@echo "  make clean    - Remove arquivos de compilacao e binarios"
	@echo "  make distclean- Remove binarios e tambem o extrato.txt gerado"