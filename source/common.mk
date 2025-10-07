SRC_DIR := .
BUILD_DIR := ./build

INCLUDES := -I../include \
			-I/usr/local/include/ftlibc
HEADER := $(SRC_DIR)/$(NAME:.a=.h)
SRCS := $(wildcard $(SRC_DIR)/*.c)
OBJS := $(patsubst $(SRC_DIR)/%.c,$(BUILD_DIR)/%.o,$(SRCS))

CC := cc
CFLAGS := -Wall -Wextra -Werror

all: $(NAME)

$(NAME): $(OBJS)
	ar -rcs $(NAME) $(OBJS)

$(BUILD_DIR)/%.o: %.c $(HEADER)
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) $(LDFLAGS) $(INCLUDES) -c $< -o $@

.PHONY: clean
clean:
	rm -rf $(BUILD_DIR)

fclean: clean
	rm -f $(NAME)

re: fclean all

print-%:
	@echo $($*)
