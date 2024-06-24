

# 头文件
CFLAGS += -Imodule2/inc

#其他目录下的.c
SRCS += $(wildcard module2/src/*.c)

# 生成其他目录下的目标文件
$(OBJ_DIR)/%.o: module2/src/%.c | $(OBJ_DIR)
	$(CC) $(CFLAGS) -c $< -o $@