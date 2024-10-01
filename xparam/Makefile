NAME	= rush01

SRCS	:= \
	main.c \
	utils.c \
	dup_tab.c \
	pre_fill.c \
	init_tab.c \
	print_tab.c \
	is_valid_param.c \

BUILD_DIR	:= .build
OBJS		:= $(SRCS:%.c=$(BUILD_DIR)/%.o)
DEPS		:= $(OBJS:.o=.d)
INCS 		:= -I includes

CC			:= cc
CFLAGS		:= -Wall -Wextra -Werror
CPPFLAGS    := -MMD -MP -I .

RM          := rm -f
RMDIR       += -r
MAKEFLAGS   += --no-print-directory
DIR_DUP     = mkdir -p $(BUILD_DIR)



all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(CPPFLAGS) $(OBJS) -o $(NAME) $(INCS)
	@echo "CREATED $@"

$(BUILD_DIR)/%.o: %.c | $(BUILD_DIR)
	$(CC) $(CFLAGS) $(CPPFLAGS) -c -o $@ $<

$(BUILD_DIR):
	$(DIR_DUP)
	@echo "CREATED $(BUILD_DIR) directory"

-include $(DEPS)

clean:
	$(RM) $(OBJS) $(DEPS)
	@echo "DELETED OBJS and DEPS"

fclean: clean
	$(RM) $(RMDIR) $(NAME) $(BUILD_DIR)

re: fclean all

.PHONY: all clean fclean re
.SILENT:
