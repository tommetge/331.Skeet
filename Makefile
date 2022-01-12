TARGET_EXEC := $(shell basename $(CURDIR))
TARGET_TEST_EXEC := test_runner

BUILD_DIR := build
SRC_DIR := .
TEST_SRC_DIR := test

SRCS := $(shell find $(SRC_DIR) -name '*.cpp' \
	-not -path src/combined.cpp \
	-not -path src/scratch.cpp)
HDRS := $(shell find $(SRC_DIR) -name '*.hpp' -or -name '*.h')
OBJS := $(SRCS:%=$(BUILD_DIR)/%.o)
DEPS := $(OBJS:%.o=%.d)
SRCS_NO_MAIN := $(shell find $(SRC_DIR) -name '*.cpp' \
	-not -path src/main.cpp \
	-not -path src/combined.cpp \
	-not -path src/scratch.cpp\
	-not -path src/ui.cpp)
OBJS_NO_MAIN := $(SRCS_NO_MAIN:%=$(BUILD_DIR)/%.o)
TEST_SRCS := $(shell find $(TEST_SRC_DIR) -name 'test-*.cpp')
TEST_OBJS := $(TEST_SRCS:%=$(BUILD_DIR)/%.o)

INC_DIRS :=
INC_FLAGS := $(addprefix -I,$(INC_DIRS)) -Ilib

FRAMEWORKS := OpenGL GLUT
FRAMEWORK_FLAGS := $(addprefix -framework ,$(FRAMEWORKS))

LIBS := 
LIB_FLAGS := $(addprefix -l,$(LIBS))

CPPFLAGS := $(INC_FLAGS) -std=c++17 -MMD -g # -Weverything
LDFLAGS := $(FRAMEWORK_FLAGS) $(LIB_FLAGS)

-include $(DEPS)

.DEFAULT_GOAL := all

$(BUILD_DIR)/$(TARGET_EXEC): $(OBJS)
	$(CXX) $(CPPFLAGS) $(LDFLAGS) -o $@ $^

$(BUILD_DIR)/$(TARGET_TEST_EXEC): $(TEST_OBJS) $(OBJS_NO_MAIN)
	$(CXX) $(CPPFLAGS) -o $@ $^

$(BUILD_DIR)/%.cpp.o: %.cpp
	mkdir -p $(dir $@)
	$(CXX) $(CPPFLAGS) -c $< -o $@

all : $(BUILD_DIR)/$(TARGET_EXEC)

test: $(BUILD_DIR)/$(TARGET_TEST_EXEC)
	$(BUILD_DIR)/$(TARGET_TEST_EXEC)

$(SRC_DIR)/combined.cpp: $(SRCS) $(HDRS)
ifdef HDRS
		cat $(HDRS) > $@
else
		echo "" > $@
endif
	cat $(SRCS) >> $@
	echo "\n\n/* TESTS */\n\n" >> $@
	echo "/*\n" >> $@
	cat $(TEST_SRCS) >> $@
	echo "*/\n" >> $@

$(BUILD_DIR)/combined: $(SRC_DIR)/combined.cpp
	$(CXX) $(CPPFLAGS) $(SRC_DIR)/combined.cpp -o $@

combined : $(BUILD_DIR)/combined

$(BUILD_DIR)/scratch.cpp.o: $(SRC_DIR)/scratch.cpp
	$(CXX) $(CPPFLAGS) -c $< -o $@

$(BUILD_DIR)/scratch: $(BUILD_DIR)/scratch.cpp.o
	$(CXX) -g $(BUILD_DIR)/scratch.cpp.o -o $@

scratch : $(BUILD_DIR)/scratch

analyze :
	scan-build make

.PHONY: clean
clean :
	rm -rf build/*
