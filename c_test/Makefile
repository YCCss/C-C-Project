#Makefile
# 编译器
CC = gcc

# 编译选项
CFLAGS = -Wall

# 目标文件
TARGET = main
OBJ_DIR = build

# 源文件
# 当前目录下的.c
SRCS = $(wildcard *.c)
#其他目录下的.c
SRCS += $(wildcard module1/src/*.c)


# 头文件
CFLAGS += -Imodule1/inc
#CFLAGS += -Ipath/to/include2

# LIB
#CFLAGS += -Lpath/to/lib1
#CFLAGS += -Lpath/to/lib2

#添加宏定义
#CFLAGS += -DANDROID_OS

#添加其他模块的make文件
include ./module2/module.mk

# 对象文件和中间文件目录
# 将 SRCS 中的 .c 文件名转换为 $(OBJ_DIR)/%.o 格式的目标文件路径
OBJS = $(addprefix $(OBJ_DIR)/, $(notdir $(SRCS:.c=.o)))
#OBJS = $(patsubst %.c,$(OBJ_DIR)/%.o,$(notdir $(SRCS)))

# 默认构建目标
all: $(TARGET)

# 生成可执行文件 
$(TARGET): $(OBJS)
	$(CC) -o $@ $^

# 生成根目录下的目标文件
$(OBJ_DIR)/%.o: %.c | $(OBJ_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

# 生成其他目录下的目标文件
$(OBJ_DIR)/%.o: module1/src/%.c | $(OBJ_DIR)
	$(CC) $(CFLAGS) -c $< -o $@
	
# 创建中间文件目录
$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)


# 清理生成的文件
clean:
	rm -rf $(OBJ_DIR) $(TARGET)



