PROJ_DIR := ../source
NAME := debug

BUILD_DIR := build

FTLIBC_DIR := ../../ftlibc/source/
FTLIBC := $(FTLIBC_DIR)/ftlibc.a

MLX_AUX_DIR := ../source
MLX_AUX := $(MLX_AUX_DIR)/mlx_aux.a

INCLUDES := -I/home/aspecky/Documents/Github/42cursus/mlx_aux/source/include
SRCS := $(wildcard *.c)
OBJS := $(SRCS:%.c=$(BUILD_DIR)/%.o)

CFLAGS := -Wall -Wextra -fsanitize=address -ggdb3 -O0
LDFLAGS := -lm

all: $(NAME)

$(NAME): $(OBJS) $(FTLIBC) $(MLX_AUX) | $(BUILD_DIR)
	$(CC) $(CFLAGS) $(LDFLAGS) $(OBJS) $(MLX_AUX) $(FTLIBC) -o $(NAME)

$(BUILD_DIR):
	mkdir -p $(BUILD_DIR)

$(BUILD_DIR)/%.o: %.c
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

$(FTLIBC): $(shell find $(FTLIBC_DIR) -name "*.[ch]")
	make -C $(FTLIBC_DIR) 'CFLAGS := $(CFLAGS)'

$(MLX_AUX): $(shell find -L $(MLX_AUX_DIR) -name '*.[ch]')
	make -C $(MLX_AUX_DIR) 'CFLAGS := $(CFLAGS)'

run: all
	./$(NAME)

.PHONY: clean
clean:
	make clean -C $(PROJ_DIR)
	rm -rf $(BUILD_DIR)

fclean: clean
	make fclean -C $(PROJ_DIR)
	rm -f $(NAME)

re: fclean all

print-%:
	@echo $($*)
