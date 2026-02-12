# Compiler
CXX = g++
CXXFLAGS = -std=c++17 -Wall \
	-Iinclude \
	-Iinclude/core \
	-Iinclude/client \
	-Iinclude/logging \
	-Iinclude/network \
	-Iinclude/registry \
	-Iinclude/security

# Output binaries
ENGINE_BIN = apps/engine/engine
CLIENT_BIN = apps/client/client

# Engine sources
ENGINE_SRC = \
	apps/engine/main_engine.cpp \
	src/core/ECSBF_CoreEngine.cpp \
	src/session/Session.cpp\
	src/logging/Logger.cpp \
	src/network/NetworkUtil.cpp \
	src/registry/IdentityRegistry.cpp \
	src/security/NodeIdentity.cpp

# Client sources
CLIENT_SRC = \
	apps/client/main_client.cpp \
	src/client/Client.cpp \
	src/logging/Logger.cpp \
	src/network/NetworkUtil.cpp

# Default target
all: engine client

# Build engine
engine:
	@mkdir -p apps/engine
	@echo "Building ECSBF Engine..."
	$(CXX) $(CXXFLAGS) $(ENGINE_SRC) -o $(ENGINE_BIN)

# Build client
client:
	@mkdir -p apps/client
	@echo "Building ECSBF Client..."
	$(CXX) $(CXXFLAGS) $(CLIENT_SRC) -o $(CLIENT_BIN)

# Clean
clean:
	@echo "Cleaning binaries..."
	rm -f $(ENGINE_BIN) $(CLIENT_BIN)

# Rebuild
rebuild: clean all
