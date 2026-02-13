###############################################################################
#  ECSBF Build Configuration
#  ---------------------------------------------------------------------------
#  Project : Enterprise Concurrent Signal Broadcast Framework (ECSBF)
#  Purpose : Builds Engine and Client applications
#  Standard: C++17
#
#  This Makefile compiles:
#   - ECSBF Core Engine (centralized concurrency server)
#   - ECSBF Client (endpoint node application)
#
#  Design Goals:
#   - Modular compilation
#   - Separate Engine and Client binaries
#   - Clean rebuild support
#   - Organized directory structure
###############################################################################

# ============================================================================
#  Compiler Configuration
# ============================================================================

CXX = g++
CXXFLAGS = -std=c++17 -Wall \
	-Iinclude \
	-Iinclude/core \
	-Iinclude/client \
	-Iinclude/logging \
	-Iinclude/network \
	-Iinclude/registry \
	-Iinclude/security


# ============================================================================
#  Output Binaries
# ============================================================================

ENGINE_BIN = apps/engine/engine
CLIENT_BIN = apps/client/client


# ============================================================================
#  Engine Source Files
# ============================================================================
# Includes:
# - Core Engine implementation
# - Session management
# - Logging subsystem
# - Network utilities
# - Identity registry
# - Security modules

ENGINE_SRC = \
	apps/engine/main_engine.cpp \
	src/core/ECSBF_CoreEngine.cpp \
	src/session/Session.cpp \
	src/logging/Logger.cpp \
	src/network/NetworkUtil.cpp \
	src/registry/IdentityRegistry.cpp \
	src/security/NodeIdentity.cpp \
	src/security/CryptoUtil.cpp


# ============================================================================
#  Client Source Files
# ============================================================================
# Includes:
# - Client runtime
# - Logging subsystem
# - Network utilities
# - Cryptographic utilities

CLIENT_SRC = \
	apps/client/main_client.cpp \
	src/client/Client.cpp \
	src/logging/Logger.cpp \
	src/network/NetworkUtil.cpp \
	src/security/CryptoUtil.cpp


# ============================================================================
#  Default Target
# ============================================================================

all: engine client


# ============================================================================
#  Build Engine
# ============================================================================
# Compiles the ECSBF Core Engine binary

engine:
	@mkdir -p apps/engine
	@echo "Building ECSBF Engine..."
	$(CXX) $(CXXFLAGS) $(ENGINE_SRC) -o $(ENGINE_BIN)


# ============================================================================
#  Build Client
# ============================================================================
# Compiles the ECSBF Client binary

client:
	@mkdir -p apps/client
	@echo "Building ECSBF Client..."
	$(CXX) $(CXXFLAGS) $(CLIENT_SRC) -o $(CLIENT_BIN)


# ============================================================================
#  Clean Target
# ============================================================================
# Removes compiled binaries without affecting source files

clean:
	@echo "Cleaning binaries..."
	rm -f $(ENGINE_BIN) $(CLIENT_BIN)


# ============================================================================
#  Rebuild Target
# ============================================================================
# Performs a full clean followed by fresh compilation

rebuild: clean all
