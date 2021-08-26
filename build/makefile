SHELL := /bin/bash

# Directories relative paths.
ROOT_DIR := ../
INCLUDE_DIR := $(ROOT_DIR)include/
TEST_DIR := $(ROOT_DIR)test/
OBJ_DIR := $(ROOT_DIR)obj/
BIN_DIR := $(ROOT_DIR)bin/

# All of asterism's include fules, except for the build file.
ASTERISM_INCLUDES := $(shell find $(INCLUDE_DIR) -name *.hpp)

TEST_SRCS := $(wildcard $(TEST_DIR)*.cpp)
TEST_NAMES := $(basename $(notdir $(wildcard $(TEST_DIR)*.cpp)))
TEST_OBJS := $(join $(addsuffix /, \
	$(addprefix $(OBJ_DIR), $(TEST_NAMES))), $(addsuffix .o, $(TEST_NAMES)))
TEST_BINS := $(addprefix $(BIN_DIR), $(TEST_NAMES))

# Flags for build. Debug by default.
CXX ?= clang++
CXXFLAGS := -I$(INCLUDE_DIR) -std=c++17 -m64 -pthread -Wall -Wextra -D_CONSOLE
CXXFLAGS_DEBUG := -D _DEBUG -g -O0
CXXFLAGS_RELEASE := -D NDEBUG -Ofast
CXXFLAGS_INSTRUMENT :=
LDLIBS := -pthread -lresolv
LDLIBS_INSTRUMENT := -fsanitize=address,undefined,leak

# Default to DEBUG builds. Check if RELEASE=1 is set.
ifeq ($(RELEASE), 1)
  CXXFLAGS := $(CXXFLAGS) $(CXXFLAGS_RELEASE)
else
  CXXFLAGS := $(CXXFLAGS) $(CXXFLAGS_DEBUG)
endif

ifeq ($(INSTRUMENT), 1)
  CXXFLAGS := $(CXXFLAGS) $(CXXFLAGS_INSTRUMENT)
	LDLIBS := $(LDLIBS) $(LDLIBS_INSTRUMENT)
endif

# -lstdc++fs is included by default on MacOS and cannot be specified on the \
	command line.
UNAME_S := $(shell uname -s)
ifneq ($(UNAME_S), Darwin)
	LDLIBS := $(LDLIBS) -lstdc++fs
endif

# Keep intermediate and output files.
.SECONDARY: $(TEST_BINS) $(TEST_OBJS)

# Mark .PHONY for rules to avoid compiling files named the same as rules.

# Build and run all tests in order.
.PHONY: runall
runall: $(TEST_NAMES)
	@cd $(BIN_DIR); \
	for file in $(TEST_NAMES); do \
		printf "\n-------- $$file --------\n"; \
		./$$file; \
	done

# Run a single test whose name is specified by TEST.
.PHONY: run
run: $(TEST)
	@$(BIN_DIR)$(TEST) $(ARGS)

# Build all tests.
.PHONY: all
all: $(TEST_NAMES)

# Delete intermediate files.
.PHONY: clean
clean:
	@rm -rf $(OBJ_DIR) $(BIN_DIR)

# Rules for single tests just redirect to test binaries.
# Enable second expansion for some fancy pattern matching later.
.SECONDEXPANSION:
$(TEST_NAMES): $(BIN_DIR)$$@

# Static rules to nest one directory deep inside ../obj.
# Link rule.
$(TEST_BINS): $(BIN_DIR)% : $(OBJ_DIR)$$*/$$*.o
	@mkdir -p $(@D)
	$(CXX) $< $(LDLIBS) -o $@

# Compile rule. Stem % matches TEST_NAME/TEST_NAME, in which / is replaced \
	with a space and the first word is extracted for the cpp file name.
$(TEST_OBJS): $(OBJ_DIR)%.o : $(TEST_DIR)$$(firstword $$(subst /, ,$$*)).cpp \
	$(ASTERISM_INCLUDES)
	@mkdir -p $(@D)
	$(CXX) $(CXXFLAGS) -c $< -o $@
