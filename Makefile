TARGET		= wolf3d
OS			= $(shell uname)

# Directories
SRCS_DIR	= ./src
OBJS_DIR	= ./obj
FT_DIR		= ./lib/libft

# Sources
SRC_FILES	= error.c \
			  main.c \
			  game.c \
			  player.c \
			  sdl.c \
			  font.c \
			  cleaner.c \
			  point.c \
			  music.c \
			  interaction.c \
			  door.c \
			  collision.c \
			  map/cleaner.c \
			  map/parser.c \
			  map/sprite.c \
			  map/validator.c \
			  event/keyboard_event.c \
			  event/mouse_event.c \
			  event/event.c \
			  render/stats.c \
			  render/render.c \
			  render/helpers.c \
			  render/world/world.c \
			  render/world/ray.c \
			  render/world/walls.c \
			  render/world/floor_ceil.c \
			  render/world/door_hit.c \
			  render/sprite/helpers.c \
			  render/sprite/sprite.c \
			  render/sprite/sort_sprites.c \
			  update/update.c \
			  update/doors_update.c \
			  update/player_update.c \
			  clean/clean_doors.c \
			  clean/clean_fonts.c \
			  clean/clean_buffer.c \
			  clean/clean_map.c \
			  clean/clean_sprites.c \
			  clean/clean_textures.c \
			  clean/clean_z_buffer.c \
			  texture/ceiling_textures.c \
			  texture/door_textures.c \
			  texture/floor_textures.c \
			  texture/sprite_textures.c \
			  texture/wall_textures.c \
			  texture/texture.c

SRCS 		= $(addprefix $(SRCS_DIR)/, $(SRC_FILES))
OBJS		= $(addprefix $(OBJS_DIR)/, $(SRC_FILES:c=o))


# Includes
INCL		= -I ./includes
FT_INCL		= -I ./lib/libft/includes
LIBSINC		= -I ~/.brew/include

# Libraries
FT_LIB		= $(FT_DIR)/libft.a
LIBS_LINK	= -L $(FT_DIR) -lSDL2 -lSDL2_image -lSDL2_ttf -lSDL2_mixer -lft -lpthread -lm


# Compilation
COMPILER	= gcc
BUILD_FLAGS = -Wall -Wextra -Werror
DEBUG_FLAGS = $(BUILD_FLAGS) -g
O_FLAGS		= -Ofast


.PHONY: all clean fclean re

all: $(TARGET)

$(TARGET): $(which brew) $(FT_LIB) $(OBJS)
	@$(COMPILER) $(OBJS) $(LIBS_LINK) -o $(TARGET)
	@echo Relinking

$(FT_LIB):
	@make -C $(FT_DIR) > /dev/null
	@mkdir -p $(OBJS_DIR)
	@mkdir -p $(OBJS_DIR)/render/world
	@mkdir -p $(OBJS_DIR)/render/sprite
	@mkdir -p $(OBJS_DIR)/event
	@mkdir -p $(OBJS_DIR)/map
	@mkdir -p $(OBJS_DIR)/clean
	@mkdir -p $(OBJS_DIR)/update
	@mkdir -p $(OBJS_DIR)/texture

$(OBJS_DIR)/%.o:$(SRCS_DIR)/%.c
	@$(COMPILER) $(DEBUG_FLAGS) $(O_FLAGS) $(FT_INCL) $(LIBSINC) $(INCL) -o $@ -c $<
	@echo Recompiling $<

clean:
	@rm -rf $(OBJS_DIR) > /dev/null
	@make -C $(FT_DIR) clean > /dev/null

fclean: clean
	@rm -rf $(TARGET) > /dev/null
	@make -C $(FT_DIR) fclean > /dev/null

re: fclean all
