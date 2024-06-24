#Makefile
# 编译器
CC = g++

# 编译选项
CFLAGS = -Wall

# 目标文件
TARGET = mp
OBJ_DIR = build

# 源文件
# 当前目录下的.cpp
SRCS = $(wildcard *.cpp)
#其他目录下的.cpp
SRCS += $(wildcard module1/src/*.cpp)
SRCS += $(wildcard module2/src/*.cpp)

# 头文件
CFLAGS += -Imodule1/inc
CFLAGS += -Imodule2/inc
CFLAGS += -g

# LIB
#CFLAGS += -Lpath/to/lib1
#CFLAGS += -Lpath/to/lib2

#添加宏定义
#CFLAGS += -DANDROID_OS

# 对象文件和中间文件目录
OBJS = $(SRCS:%.cpp=$(OBJ_DIR)/%.o)

# 默认构建目标
all: $(TARGET)

# 生成可执行文件 
$(TARGET): $(OBJS)
	$(CC) -o $@ $^

# 生成根目录下的目标文件
$(OBJ_DIR)/%.o: %.cpp | $(OBJ_DIR)
#创建文件夹很关键，不然会fail
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) -c $< -o $@

	
# 创建中间文件目录
$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)


# 清理生成的文件
clean:
	rm -rf $(OBJ_DIR) $(TARGET)



