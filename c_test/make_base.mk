#Makefile
# make -f make_base.mk
# 编译器
CC = gcc

# 编译选项
CFLAGS = -Wall

# 目标文件
TARGET = myprogram

# 源文件
# 当前目录下的.c
SRCS = $(wildcard *.c)

# 头文件
INC = -Imodule1/inc
# INC += -Ipath/to/include2
CFLAGS += $(INC)

# LIB
# LIB = -Lpath/to/lib1
# LIB += -Lpath/to/lib2
# CFLAGS += $(LIB) 

#添加宏定义
# CFLAGS += -DANDROID_OS

#添加其他模块的make文件
# include /path/xxx/makefile

# 对象文件
OBJS = $(SRCS:.c=.o)

# 默认构建目标
all: $(TARGET)

# 生成可执行文件 
$(TARGET): $(OBJS)
	$(CC) -o $@ $^
	mkdir -p build && mv $(OBJS) build
	mkdir -p bin && mv $(TARGET) bin

# 生成目标文件
%.o: %.c
	$(CC) $(CFLAGS) -c $<

# 清理生成的文件
clean:
	rm -rf build bin