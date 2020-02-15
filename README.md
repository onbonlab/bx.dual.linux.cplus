# 目录说明

lib64.tar.gz：库、依赖库、Demo可执行程序

lib32.tar.gz：库、依赖库、Demo可执行程序

demo：demo源码

include：依赖头文件；

allfonts： 存放字体文件；



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

