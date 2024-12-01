# コンパイラ設定
NAME = push_swap
CC = cc
RM = rm -f
FLAGS = -Wall -Wextra -Werror

# ヘッダーファイルの指定
HEADERS = includes/push_swap.h

# ソースファイルとオブジェクトファイル
SRCS := $(wildcard src/*.c)
OBJ = $(SRCS:src/%.c=obj/%.o)

# オブジェクトファイルのディレクトリを作成
OBJ_DIR = obj

all: $(OBJ_DIR) $(NAME)

$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)

$(NAME): $(OBJ)
	$(CC) $(FLAGS) $(OBJ) -o $(NAME)

$(OBJ_DIR)/%.o: src/%.c $(HEADERS)
	$(CC) $(FLAGS) -c $< -o $@

clean:
	$(RM) $(OBJ)
	$(RM) -r $(OBJ_DIR)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
