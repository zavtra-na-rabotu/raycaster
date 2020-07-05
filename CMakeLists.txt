cmake_minimum_required(VERSION 3.14)
project(wolf3d C)

set(CMAKE_C_STANDARD 99)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${CMAKE_CURRENT_LIST_DIR}")

# Directories where compiler will search for includes files
include_directories(includes)
include_directories(lib/libft/includes)
include_directories(lib/build/include/SDL2)

# Linux
add_executable(wolf3d includes/wolf3d.h includes/map.h src/main.c src/sdl.c src/map/validator.c src/error.c src/game.c src/map/parser.c src/map/sprite.c src/render/render.c src/event/event.c src/event/keyboard_event.c src/event/mouse_event.c src/player.c src/map/cleaner.c src/render/world/world.c src/texture/texture.c src/point.c src/render/stats.c src/font.c src/cleaner.c src/music.c src/render/sprite/sprite.c includes/point.h includes/game.h includes/player.h src/door.c src/interaction.c includes/door.h src/update/update.c src/collision.c includes/collision.h includes/texture.h src/clean/clean_doors.c includes/clean.h src/clean/clean_textures.c src/clean/clean_fonts.c includes/font.h src/clean/clean_map.c src/clean/clean_sprites.c src/clean/clean_buffer.c src/update/doors_update.c src/clean/clean_z_buffer.c includes/update.h src/update/player_update.c src/texture/wall_textures.c src/texture/door_textures.c src/texture/floor_textures.c src/texture/ceiling_textures.c src/texture/sprite_textures.c src/render/world/ray.c src/render/helpers.c src/render/world/door_hit.c src/render/world/floor_ceil.c src/render/world/walls.c src/render/sprite/helpers.c src/render/sprite/sort_sprites.c includes/sprite.h)

add_definitions(-Wall -Wextra -Werror -g)
# add_definitions(-Ofast)

# OSX./
#target_link_libraries(Fractol "-framework AppKit")
#target_link_libraries(Fractol "-framework OpenGL")
#target_link_libraries(Fractol mlx)
#target_link_libraries(Fractol ${CMAKE_SOURCE_DIR}/lib/minilibx_macos/libmlx.a)

# Linux
target_link_libraries(wolf3d ${CMAKE_SOURCE_DIR}/lib/libft/libft.a)
target_link_libraries(wolf3d SDL2)
target_link_libraries(wolf3d SDL2_image)
target_link_libraries(wolf3d SDL2_ttf)
target_link_libraries(wolf3d SDL2_mixer)
target_link_libraries(wolf3d m)
#target_link_libraries(wolf3d X11)
#target_link_libraries(wolf3d pthread)
