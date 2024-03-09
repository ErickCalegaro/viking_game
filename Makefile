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
# SDL2: 		https://github.com/libsdl-org/SDL/releases/tag/release-2.30.1
# SDL2_ttf: 	https://github.com/libsdl-org/SDL_ttf/releases/tag/release-2.22.0
# SDL2_image: 	https://github.com/libsdl-org/SDL_image/releases/tag/release-2.8.2
# usar o pacote "SDL2_XXX_devel_V.V.V_mingw.zip" e a variante "x86_64-w64-mingw32"
LDFLAGS := -L$(LIB_DIR) -lSDL2 -lSDL2_ttf -lSDL2_image

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
	@$(CP) -r $(RES_DIR)/* $(OUTPUT_DIR)
	@$(MV) $(BUILD_DIR)/$(PROJECT) $(OUTPUT_DIR)/$(PROJECT)_$(APP_VERSION)

$(BUILD_DIR)/${PROJECT}: $(OBJ_FILES) | $(BUILD_DIR)
	$(CC) $^ -o $@.exe $(LDFLAGS)

$(BUILD_DIR)/%.o: $(SRC_DIR)/%.c | $(BUILD_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

$(BUILD_DIR):
	$(MKDIR) $@

clean:
	$(DEL) -rf $(BUILD_DIR) $(OUTPUT_DIR)

.PHONY: all clean
