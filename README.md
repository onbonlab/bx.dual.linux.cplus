# 目录说明

lib:

- lib64.tar.gz：64位、(GNU libc) 2.17、所有库文件及Demo可执行程序
- lib32.tar.gz：32位、(GNU libc) 2.5、所有库文件及Demo可执行程序

- lib-aarch64-himix100.tar：64bits、for aarch64-himix100-linux、gcc version 6.3.0(HC&C V100)


demo_samples：demo源码:

- allfonts： 存放字体文件；在调用发送动态区函数时，可以使用字体文件作为参数；
- DynamicAreaDemo: 动态区示例源码；

dist：可执行程序及相关依赖库/文件；

include：依赖头文件:

- bx_dual_sdk.h ：所有接口函数的声明和注释；

- bx_sdk_dual.h ：所有接口函数的别名，不是必须要包含的；

- Obasic_types.h：基本数据类型的定义






# 运行Demo可执行程序

- 解压lib64.tar.gz/lib32.tar.gz后，会得到相就的lib64/lib32文件夹；

  ```
  tar -zxvf lib64.tar.gz
  ```

- 进入库目录

  ```
  cd ./lib64
  或
  cd ./lib32
  ```

- 运行demo

  ```
  ./testmain8.exe 192.168.1.100 
  ```


*说明：192.168.1.100为LED控制卡的IP地址

