# ============================================================
#  Makefile: Enterprise Concurrent Signal Broadcast Framework
# ============================================================
#  Description:
#  This Makefile defines the build configuration for the
#  Enterprise Concurrent Signal Broadcast Framework (ECSBF).
#
#  It supports:
#   - Independent compilation of Core Engine and Client
#   - Centralized compiler configuration
#   - Clean separation of source, include, and binary outputs
#
#  The build system is intentionally simple and transparent
#  to ensure portability, maintainability, and ease of review.
# ============================================================


# ------------------------------------------------------------
#  Compiler Configuration
# ------------------------------------------------------------
#  CXX      : C++ compiler
#  CXXFLAGS : Compiler flags including language standard,
#             warnings, and include directories
# ------------------------------------------------------------
CXX = g++
CXXFLAGS = -std=c++17 -Wall \
	-Iinclude \
	-Iinclude/core \
	-Iinclude/client \
	-Iinclude/logging \
	-Iinclude/network \
	-Iinclude/registry \
	-Iinclude/security


# ------------------------------------------------------------
#  Output Binaries
# ------------------------------------------------------------
#  ENGINE_BIN : Output binary for ECSBF Core Engine
#  CLIENT_BIN : Output binary for ECSBF Client
# ------------------------------------------------------------
ENGINE_BIN = apps/engine/engine
CLIENT_BIN = apps/client/client


# ------------------------------------------------------------
#  ECSBF Core Engine Source Files
# ------------------------------------------------------------
#  Includes:
#   - Engine entry point
#   - Core engine logic
#   - Session management (FR-04)
#   - Logging, networking, and identity subsystems
# ------------------------------------------------------------
ENGINE_SRC = \
	apps/engine/main_engine.cpp \
	src/core/ECSBF_CoreEngine.cpp \
	src/session/Session.cpp \
	src/logging/Logger.cpp \
	src/network/NetworkUtil.cpp \
	src/registry/IdentityRegistry.cpp \
	src/security/NodeIdentity.cpp \
	src/security/CryptoUtil.cpp


# ------------------------------------------------------------
#  ECSBF Client Source Files
# ------------------------------------------------------------
#  Includes:
#   - Client entry point
#   - Client networking and threading logic
#   - Shared logging and networking utilities
# ------------------------------------------------------------
CLIENT_SRC = \
	apps/client/main_client.cpp \
	src/client/Client.cpp \
	src/logging/Logger.cpp \
	src/network/NetworkUtil.cpp \
	src/security/CryptoUtil.cpp


# ------------------------------------------------------------
#  Default Build Target
# ------------------------------------------------------------
#  Builds both the ECSBF Core Engine and Client binaries
# ------------------------------------------------------------
all: engine client


# ------------------------------------------------------------
#  Build ECSBF Core Engine
# ------------------------------------------------------------
#  - Ensures output directory exists
#  - Compiles and links all engine-related source files
# ------------------------------------------------------------
engine:
	@mkdir -p apps/engine
	@echo "Building ECSBF Engine..."
	$(CXX) $(CXXFLAGS) $(ENGINE_SRC) -o $(ENGINE_BIN)


# ------------------------------------------------------------
#  Build ECSBF Client
# ------------------------------------------------------------
#  - Ensures output directory exists
#  - Compiles and links all client-related source files
# ------------------------------------------------------------
client:
	@mkdir -p apps/client
	@echo "Building ECSBF Client..."
	$(CXX) $(CXXFLAGS) $(CLIENT_SRC) -o $(CLIENT_BIN)


# ------------------------------------------------------------
#  Clean Target
# ------------------------------------------------------------
#  Removes generated binaries without touching source files
# ------------------------------------------------------------
clean:
	@echo "Cleaning binaries..."
	rm -f $(ENGINE_BIN) $(CLIENT_BIN)


# ------------------------------------------------------------
#  Rebuild Target
# ------------------------------------------------------------
#  Forces a full rebuild by cleaning and recompiling
# ------------------------------------------------------------
rebuild: clean all
