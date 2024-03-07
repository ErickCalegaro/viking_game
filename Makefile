include config.mk

# Project
PROJECT		:= ${APP_NAME}

# Toolchain
CC 			:= gcc
AS			:= gcc
AR			:= ar
LINK		:= clang
RANLIB		:= ranlib
OBJCOPY		:= objcopy
STRIP		:= strip
OBJDUMP		:= objdump
MKDIR		:= /bin/mkdir -p
ECHO		:= echo
DEL			:= rm
CP 			:= cp
MV			:= mv

# Directories
OUTPUT_DIR 	:= output
BUILD_DIR 	:= build
LIB_DIR 	:= lib
INC_DIR 	:= inc
SRC_DIR 	:= src
RES_DIR 	:= res

# Defines
DEFS		:= -DAPP_NAME=\"${PROJECT}\" -DVERSION=\"${APP_VERSION}\"

# Flags
CFLAGS := -Wall -Wextra -I$(INC_DIR) ${DEFS}
LDFLAGS := -L$(LIB_DIR) -lSDL2 -lSDL2_ttf

# Files
SRC_FILES := $(wildcard $(SRC_DIR)/*.c)
OBJ_FILES := $(patsubst $(SRC_DIR)/%.c,$(BUILD_DIR)/%.o,$(SRC_FILES))

# Targets
all: $(BUILD_DIR)/${PROJECT}
	@${ECHO} ""
	@${ECHO} "+---------------------------------------------------"
	@${ECHO} "|"
	@${ECHO} "|   Finished building target: ${PROJECT} [${APP_VERSION}]"
	@${ECHO} "|"
	@${ECHO} "+---------------------------------------------------"
	@$(MKDIR) $(OUTPUT_DIR)
	@$(CP) $(RES_DIR)/* $(OUTPUT_DIR)
	@$(MV) $(BUILD_DIR)/$(PROJECT) $(OUTPUT_DIR)/$(PROJECT)_$(APP_VERSION)

$(BUILD_DIR)/${PROJECT}: $(OBJ_FILES) | $(BUILD_DIR)
	$(CC) $^ -o $@.exe $(LDFLAGS)

$(BUILD_DIR)/%.o: $(SRC_DIR)/%.c | $(BUILD_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

$(BUILD_DIR):
	$(MKDIR) $@

clean:
	$(DEL) -rf $(BUILD_DIR)

.PHONY: all clean
