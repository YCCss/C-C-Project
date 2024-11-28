

# 头文件
CFLAGS += -Imodule2/inc

#其他目录下的.cpp
SRCS += $(wildcard module2/src/*.cpp)

# 生成其他目录下的目标文件
$(OBJ_DIR)/%.o: module2/src/%.cpp | $(OBJ_DIR)
	$(CC) $(CFLAGS) -c $< -o $@