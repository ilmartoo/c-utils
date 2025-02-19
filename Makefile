#
# Project config
#
PROJECT_NAME = c-utils
CC           = gcc

# Define compiler flags:
#  -Wall                this enables all the warnings about constructions that some users consider questionable, and that are easy to avoid (or modify to prevent the warning), even in conjunction with macros
#  -Wextra              this enables some extra warning flags that are not enabled by -Wall
#  -Werror              make all warnings into errors 
#
#  -Wfloat-equal        warn if floating-point values are used in equality comparisons
#  -Wuninitialized      warn if an object with automatic or allocated storage duration is used without having been initialized
#  -Winit-self          warn about uninitialized variables that are initialized with themselves
#
#  -std=c99             defines C language mode (standard C from 1999 revision)
#  -std=gnu99           defines C language mode (GNU C from 1999 revision)
#  -std=c++14           defines C++ language mode (standard C++ from 2014 revision)
#  -std=c17             defines C language mode (standard C from 2017 revision)
#
CFLAGS = -Wall -Werror -Wextra -Wfloat-equal -Wuninitialized -Winit-self -Wno-missing-braces -std=c99

#
# Directories
#
SRC_DIR   = src
FILE_DIRS = $(addprefix $(SRC_DIR)/,. arena) #single_linked_list
BIN_DIR   = bin
INC_DIRS  = $(FILE_DIRS)
# LIB_DIR   = libs
 
#
# Files
#
SOURCES    = $(foreach DIR,$(FILE_DIRS),$(wildcard $(DIR)/*.c))
OBJECTS    = $(foreach SRC,$(SOURCES),$(addprefix $(BIN_DIR)/,$(notdir $(SRC:%.c=%.o))))
EXECUTABLE = $(PROJECT_NAME)


#
# Includes and libs (must be put AFTER source files)
#
INC_PATHS = $(addprefix -I ,$(INC_DIRS))
# LIB_PATHS = $(addprefix -L ,$(LIB_DIR))
# LIBS      = -lm

#
# Tests
#
TESTS_DIR = tests

TT_NAME       = tests
TT_DIRS       = $(FILE_DIRS) $(TESTS_DIR)
TT_EXECUTABLE = $(BIN_DIR)/$(EXECUTABLE)-$(TT_NAME)
#
# Flags:
#  -00      no optimization
#  -g       include debug information on compilation
#  -DDEBUG  defines the DEBUG macro

TT_FLAGS = -O0 -g -DDEBUG

TT_INC_DIRS  = $(TT_DIRS)
TT_INC_PATHS = $(addprefix -I ,$(TT_DIRS))

TT_SOURCES = $(foreach DIR,$(TT_DIRS),$(wildcard $(DIR)/*.c))
TT_OBJECTS = $(foreach SRC,$(TT_SOURCES),$(addprefix $(BIN_DIR)/,$(notdir $(SRC:%.c=%.o))))

VPATH = $(TT_DIRS)

.PHONY: clean prep build run

#
# Tests build
#
build: prep $(TT_EXECUTABLE)

$(TT_EXECUTABLE): $(TT_OBJECTS)
#	$(CC) $(CFLAGS) $(TT_FLAGS) -o $@ $^ $(TT_INC_PATHS) $(LIB_PATHS) $(LIBS)
	$(CC) $(CFLAGS) $(TT_FLAGS) -o $@ $^ $(TT_INC_PATHS)

$(BIN_DIR)/%.o: %.c
#	$(CC) $(CFLAGS) $(TT_FLAGS) -c -o $@ $< $(TT_INC_PATHS) $(LIB_PATHS) $(LIBS)
	$(CC) $(CFLAGS) $(TT_FLAGS) -c -o $@ $< $(TT_INC_PATHS)

#
# Execute tests
#
run:
	$(TT_EXECUTABLE)

#
# Other rules
#
prep:
	mkdir -p $(BIN_DIR)


clean:
  rm -rf $(BIN_DIR)
