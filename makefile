# Compiler
CXX = g++
CXXFLAGS = -std=c++17 -Wall -Wextra -O2
LDFLAGS = -lws2_32  # Link Windows Sockets library

# Directories
FRONTEND_DIR = FE
GATE_DIR = GW
ENGINE_DIR = Engine
BUILD_DIR = build

# Source Files
FRONTEND_SRCS = $(wildcard $(FRONTEND_DIR)/*.cpp)
GATE_SRCS = $(wildcard $(GATE_DIR)/*.cpp)
ENGINE_SRCS = $(wildcard $(ENGINE_DIR)/*.cpp)

FRONTEND_OBJS = $(patsubst %.cpp, $(BUILD_DIR)/%.o, $(notdir $(FRONTEND_SRCS)))
GATE_OBJS = $(patsubst %.cpp, $(BUILD_DIR)/%.o, $(notdir $(GATE_SRCS)))
ENGINE_OBJS = $(patsubst %.cpp, $(BUILD_DIR)/%.o, $(notdir $(ENGINE_SRCS)))

# Executables (for Windows, .exe extension)
FRONTEND_EXE = frontend.exe
GATE_EXE = gate.exe
ENGINE_EXE = engine.exe

# Default target
all: $(FRONTEND_EXE) $(GATE_EXE) $(ENGINE_EXE)

# Compile FrontEnd
$(FRONTEND_EXE): $(FRONTEND_OBJS) | $(BUILD_DIR)
	$(CXX) $(CXXFLAGS) -o $@ $(FRONTEND_OBJS) $(LDFLAGS)

# Compile Gate
$(GATE_EXE): $(GATE_OBJS) | $(BUILD_DIR)
	$(CXX) $(CXXFLAGS) -o $@ $(GATE_OBJS) $(LDFLAGS)

# Compile Engine
$(ENGINE_EXE): $(ENGINE_OBJS) | $(BUILD_DIR)
	$(CXX) $(CXXFLAGS) -o $@ $(ENGINE_OBJS) $(LDFLAGS)

# Compile object files
$(BUILD_DIR)/%.o: $(FRONTEND_DIR)/%.cpp | $(BUILD_DIR)
	$(CXX) $(CXXFLAGS) -c $< -o $@

$(BUILD_DIR)/%.o: $(GATE_DIR)/%.cpp | $(BUILD_DIR)
	$(CXX) $(CXXFLAGS) -c $< -o $@

$(BUILD_DIR)/%.o: $(ENGINE_DIR)/%.cpp | $(BUILD_DIR)
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Create build directory if not exists
$(BUILD_DIR):
	mkdir -p $(BUILD_DIR)

# Clean build files
clean:
	rm -rf $(BUILD_DIR) $(FRONTEND_EXE) $(GATE_EXE) $(ENGINE_EXE)
