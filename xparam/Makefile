NAME	= rush-01

SRCS	:= \
	main.c \
	check.c \
	utils.c \
	solver.c \
	dup_tab.c \
	init_tab.c \
	is_valid.c \
	pre_fill.c \
	print_tab.c \
	pre_fill_min.c \
	pre_fill_max.c \
	is_valid_param.c \

BUILD_DIR	:= .build
OBJS		:= $(SRCS:%.c=$(BUILD_DIR)/%.o)
DEPS		:= $(OBJS:.o=.d)
INCS 		:= -I includes

RED         := \033[0;31m
GREEN       := \033[0;32m
YELLOW      := \033[0;33m
RESETC      := \033[0m

CC			:= cc
CFLAGS		:= -Wall -Wextra -Werror
CPPFLAGS    := -MMD -MP -I .

RM          := rm -f
RMDIR       += -r
MAKEFLAGS   += --no-print-directory
DIR_DUP     = mkdir -p $(BUILD_DIR)



all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(CPPFLAGS) $(OBJS) -o $(NAME) $(INCS) -O3
	@printf "$(GREEN)CREATED $@$(RESETC)"

$(BUILD_DIR)/%.o: %.c | $(BUILD_DIR)
	$(CC) $(CFLAGS) $(CPPFLAGS) -c -o $@ $<

$(BUILD_DIR):
	$(DIR_DUP)
	@printf "$(YELLOW)CREATED $(BUILD_DIR) directory$(RESETC)"

-include $(DEPS)

clean:
	$(RM) $(OBJS) $(DEPS)
	@printf "$(RED)DELETED OBJS and DEPS$(RESETC)"

fclean: clean
	$(RM) $(RMDIR) $(NAME) $(BUILD_DIR)

re: fclean all

.PHONY: all clean fclean re
.SILENT:
