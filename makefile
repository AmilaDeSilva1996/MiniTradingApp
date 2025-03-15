# Compiler
CXX = g++
CXXFLAGS = -std=c++17 -Wall -Wextra -O2
LDFLAGS = -lws2_32  # Link Windows Sockets library (if needed)

# Directories
FRONTEND_DIR = FE
GATE_DIR = GW
ENGINE_DIR = Engine
BUILD_DIR = build

# Source Files
FRONTEND_SRCS = $(wildcard $(FRONTEND_DIR)/*.cpp)
GATE_SRCS = $(wildcard $(GATE_DIR)/*.cpp)
ENGINE_SRCS = $(wildcard $(ENGINE_DIR)/*.cpp)

# Object Files
FRONTEND_OBJS = $(patsubst $(FRONTEND_DIR)/%.cpp, $(BUILD_DIR)/$(FRONTEND_DIR)/%.o, $(FRONTEND_SRCS))
GATE_OBJS = $(patsubst $(GATE_DIR)/%.cpp, $(BUILD_DIR)/$(GATE_DIR)/%.o, $(GATE_SRCS))
ENGINE_OBJS = $(patsubst $(ENGINE_DIR)/%.cpp, $(BUILD_DIR)/$(ENGINE_DIR)/%.o, $(ENGINE_SRCS))

# Executables
FRONTEND_EXE = frontend.exe
GATE_EXE = gate.exe
ENGINE_EXE = engine.exe

# Default target
all: $(FRONTEND_EXE) $(GATE_EXE) $(ENGINE_EXE)

# Compile Frontend
$(FRONTEND_EXE): $(FRONTEND_OBJS) | $(BUILD_DIR)/$(FRONTEND_DIR)
	$(CXX) $(CXXFLAGS) -o $@ $(FRONTEND_OBJS) $(LDFLAGS)

# Compile Gate
$(GATE_EXE): $(GATE_OBJS) | $(BUILD_DIR)/$(GATE_DIR)
	$(CXX) $(CXXFLAGS) -o $@ $(GATE_OBJS) $(LDFLAGS)

# Compile Engine
$(ENGINE_EXE): $(ENGINE_OBJS) | $(BUILD_DIR)/$(ENGINE_DIR)
	$(CXX) $(CXXFLAGS) -o $@ $(ENGINE_OBJS) $(LDFLAGS)

# Compile Frontend object files
$(BUILD_DIR)/$(FRONTEND_DIR)/%.o: $(FRONTEND_DIR)/%.cpp | $(BUILD_DIR)/$(FRONTEND_DIR)
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Compile Gate object files
$(BUILD_DIR)/$(GATE_DIR)/%.o: $(GATE_DIR)/%.cpp | $(BUILD_DIR)/$(GATE_DIR)
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Compile Engine object files
$(BUILD_DIR)/$(ENGINE_DIR)/%.o: $(ENGINE_DIR)/%.cpp | $(BUILD_DIR)/$(ENGINE_DIR)
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Create build directories if they don't exist
$(BUILD_DIR)/$(FRONTEND_DIR):
	mkdir -p $(BUILD_DIR)/$(FRONTEND_DIR)

$(BUILD_DIR)/$(GATE_DIR):
	mkdir -p $(BUILD_DIR)/$(GATE_DIR)

$(BUILD_DIR)/$(ENGINE_DIR):
	mkdir -p $(BUILD_DIR)/$(ENGINE_DIR)

# Clean build files
clean:
	rm -rf $(BUILD_DIR) $(FRONTEND_EXE) $(GATE_EXE) $(ENGINE_EXE)

.PHONY: all clean