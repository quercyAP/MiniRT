# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tdechand <tdechand@student.42mulhouse.f    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/12/05 07:31:25 by tdechand          #+#    #+#              #
#    Updated: 2023/04/20 15:36:57 by tdechand         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


SRCS			= color/color_add.c \
				 color/color_dim.c \
				 color/color_mult.c \
				 color/new_color.c \
				 color/str_to_color.c \
				 debug/debug.c \
				 debug/print_amb_light.c \
				 debug/print_cam.c \
				 debug/print_cylinder.c \
				 debug/print_light.c \
				 debug/print_object.c \
				 debug/print_parser.c \
				 debug/print_plan.c \
				 debug/print_sphere.c \
				 debug/print_triangle.c \
				 debug/utils/print_angle.c \
				 debug/utils/print_color.c \
				 debug/utils/print_point3.c \
				 debug/utils/print_vec3.c \
				 free/free_d_pars.c \
				 free/free_data.c \
				 init/init.c \
				 init/init_all_pixel.c \
				 init/init_amb_light.c \
				 init/init_bg.c \
				 init/init_camera.c \
				 init/init_lights.c \
				 init/init_mlx.c \
				 init/init_object.c \
				 init/objects/init_cylinders.c \
				 init/objects/init_plans.c \
				 init/objects/init_spheres.c \
				 init/objects/init_triangles.c \
				 key_hook/key_hook.c \
				 key_hook/move_cam.c \
				 key_hook/rt_exit.c \
				 lights/amb_light/new_amb_light.c \
				 lights/light/is_lighted.c \
				 lights/light/is_shadowed.c \
				 lights/light/new_light.c \
				 main.c \
				 parser/check/amb_light_check.c \
				 parser/check/app_param_check.c \
				 parser/check/camera_check.c \
				 parser/check/cylinder_check.c \
				 parser/check/file_check.c \
				 parser/check/light_check.c \
				 parser/check/plan_check.c \
				 parser/check/sphere_check.c \
				 parser/check/token_check.c \
				 parser/check/triangle_check.c \
				 parser/check/utils/angle_check.c \
				 parser/check/utils/color_check.c \
				 parser/check/utils/coord_check.c \
				 parser/check/utils/float_check.c \
				 parser/check/utils/intensity_check.c \
				 parser/check/utils/vec_check.c \
				 parser/error/add_error.c \
				 parser/error/error_init.c \
				 parser/error/print_error.c \
				 parser/init/parser_init.c \
				 parser/parser.c \
				 parser/utils/find_pars_line.c \
				 parser/utils/splitter.c \
				 point/new_point3.c \
				 point/point_from_orig_vec.c \
				 point/str_to_point3.c \
				 put_all_pixels/draw.c \
				 put_all_pixels/get_hit_rec.c \
				 put_all_pixels/put_all_pixels.c \
				 put_all_pixels/specular.c \
				 ray/new_ray.c \
				 ray/new_ray_at_pixel.c \
				 ray/point_at_ray.c \
				 scene_object/camera/cam_vec_calc.c \
				 scene_object/camera/camera_rotate_x.c \
				 scene_object/camera/camera_rotate_z.c \
				 scene_object/camera/camera_translate.c \
				 scene_object/cylinder/hit_cylinder.c \
				 scene_object/cylinder/new_cylinder.c \
				 scene_object/plan/hit_plan.c \
				 scene_object/plan/new_plan.c \
				 scene_object/sphere/hit_sphere.c \
				 scene_object/sphere/new_sphere.c \
				 scene_object/triangle/hit_triangle.c \
				 scene_object/triangle/new_triangle.c \
				 vector/get_angle_axe_x.c \
				 vector/get_angle_axe_z.c \
				 vector/new_vec3.c \
				 vector/str_to_vec3.c \
				 vector/vector_add.c \
				 vector/vector_cross.c \
				 vector/vector_div.c \
				 vector/vector_dot.c \
				 vector/vector_from_2pts.c \
				 vector/vector_get_normale.c \
				 vector/vector_mult.c \
				 vector/vector_normalize.c \
				 vector/vector_rot_axe_x.c \
				 vector/vector_rot_axe_z.c \
				 vector/vector_sub.c \
				
SRC_DIR			=	./src/
SOURCES			=	$(addprefix $(SRC_DIR), $(SRCS))

OBJ_DIR			=	./obj/
OBJ_DIR_DEBUG	=	./obj_debug/
OBJ_FILE		=	$(patsubst %.c, %.o, $(SRCS))
OBJECTS			=	$(addprefix $(OBJ_DIR), $(OBJ_FILE))
OBJECTS_DEBUG	=	$(addprefix $(OBJ_DIR_DEBUG), $(OBJ_FILE))

NAME			=	miniRT
CC				=	gcc
CCFLAG			=	-Wall -Wextra -Werror

HDR_FLAGS		=	-I library/MLX42/include/MLX42\
					-I library/libft/includes\
				 -I includes \
				 -I includes/color \
				 -I includes/debug \
				 -I includes/debug/utils \
				 -I includes/free \
				 -I includes/init \
				 -I includes/init/objects \
				 -I includes/key_hook \
				 -I includes/lights \
				 -I includes/lights/amb_light \
				 -I includes/lights/light \
				 -I includes/parser \
				 -I includes/parser/check \
				 -I includes/parser/check/utils \
				 -I includes/parser/error \
				 -I includes/parser/init \
				 -I includes/parser/utils \
				 -I includes/point \
				 -I includes/put_all_pixels \
				 -I includes/ray \
				 -I includes/scene_object \
				 -I includes/scene_object/camera \
				 -I includes/scene_object/cylinder \
				 -I includes/scene_object/plan \
				 -I includes/scene_object/sphere \
				 -I includes/scene_object/triangle \
				 -I includes/vector \
				
LIB				=	-lmlx42 -lft -ldl -lglfw -lm -pthread
LIBMLX			=	./library/MLX42
LIBFT			=	./library/libft				
LIB_DIR			=	-L${LIBFT}  -L${LIBMLX} -L"/Users/$$USER/.brew/opt/glfw/lib/" -L"/Users/$$USER/goinfre/.brew/opt/glfw/lib/"
# LIBS			=	${LIBMLX}/libmlx42.a ${LIBFT}/libft.a -ldl -lglfw -pthread -lm
# LIBS			=	${LIBMLX}/libmlx42.a ${LIBFT}/libft.a -lglfw -L "/Users/$$USER/.brew/opt/glfw/lib/" -lm

all						:	$(NAME)

$(NAME)					:	obj lib $(OBJ_DIR) $(OBJECTS)
							@$(CC) $(CCFLAG) $(OBJECTS) $(HDR_FLAGS) $(LIB_DIR) $(LIB) -o $(NAME)
							@echo "\033[0;92m\n* $(NAME) program file was created *\033[0m"

$(OBJ_DIR)%.o 			: 	$(SRC_DIR)%.c
							@$(CC) $(CCFLAGS) $(HDR_FLAGS)-c $< -o $@
							@echo "\033[0;96m* $(notdir $<) -> $(notdir $@) * \033[0m: \033[0;92mOK\033[0m"

$(OBJ_DIR_DEBUG)%.o		: 	$(SRC_DIR)%.c
							@$(CC) -g $(CCFLAGS) $(HDR_FLAGS) -c $< -o $@
							@echo "\033[0;96m* $(notdir $<) -> $(notdir $@) * \033[0m: \033[0;93mOK (debug)\033[0m"


clean					:	cleanlib
							@rm -rf $(OBJ_DIR) && rm -rf $(OBJ_DIR_DEBUG)
							@echo "\033[0;91m* $(NAME) object files were deleted *\033[0m"

fclean					:	clean fcleanlib
							@rm -rf $(NAME)
							@echo "\033[0;91m* $(NAME) was deleted *\033[0m"

re						:	fclean $(NAME)

sanitize				:	fclean lib obj_debug $(OBJ_DIR_DEBUG) $(OBJECTS_DEBUG)
							@$(CC) -fsanitize=address -g3 $(CCFLAG) $(OBJECTS_DEBUG) $(LIB_DIR) $(LIB) -o $(NAME)
							@echo "\033[0;93m\n* $(NAME) program file was created in sanitize mode*\033[0m"

debug					:	fclean lib obj_debug $(OBJ_DIR_DEBUG) $(OBJECTS_DEBUG)
							@$(CC) -g $(CCFLAG) $(OBJECTS_DEBUG) $(LIB_DIR) $(LIB) -o $(NAME)
							@echo "\033[0;93m\n* $(NAME) program file was created in debug mode*\033[0m"

lib						:	
							@cd ${LIBFT} && make 
							@cd ${LIBMLX} && make 

cleanlib				:	
							@cd ${LIBFT} && make clean
							@cd ${LIBMLX} && make clean

fcleanlib				:	
							@cd ${LIBFT} && make fclean
							@cd ${LIBMLX} && make fclean


add						:
							@script="tools/update_srcs.sh"; \
							while [ ! -f $$script ] && [ ! $$PWD = "/" ]; do cd ..; done; \
							if [ -f $$script ]; then \
								./$$script "$(CURDIR)"; \
								echo "SRCS File added successfully."; \
							else \
								echo "update_srcs.sh not found in parent directories"; \
							fi

create					:
							@echo "Enter the names of your repertory and files (separated by spaces):"
							@read args; \
							./tools/new_c_h_creator.sh $$args; \
							make add

obj						:
							@mkdir -p obj
							@dirs=$$(find "src/" -type d | sed "s|^src/||"); \
							for dir in $$dirs; do \
								mkdir -p obj/$$dir; \
								echo "\033[0;92m* obj$$dir dir created *\033[0m"; \
							done

obj_debug				:
							@mkdir -p obj_debug
							@dirs=$$(find "src/" -type d | sed "s|^src/||"); \
							for dir in $$dirs; do \
								mkdir -p obj_debug/$$dir; \
								echo "\033[0;92m* obj_debug$$dir dir created *\033[0m"; \
							done



.PHONY					:	all clean fclean re sanitize debug obj obj_debug create add
