# 招新考核实验报告 - C 语言

### 实验环境的搭建

##### WSL

##### 虚拟机 Ubuntu 配置
- 使用 wsl 下载 Ubuntu 22.04 TLS 并进入 Ubuntu
  ```shell
  wsl --install Ubuntu-22.04
  wsl --distribution Ubuntu-22.04
  ```
  显示信息
  ```
  Welcome to Ubuntu 22.04.5 LTS (GNU/Linux 5.15.146.1-microsoft-standard-WSL2 x86_64)

   * Documentation:  https://help.ubuntu.com
   * Management:     https://landscape.canonical.com
   * Support:        https://ubuntu.com/pro

   System information as of Thu Oct 10 15:17:56 CST 2024

    System load:           0.15
    Usage of /:            0.1% of 1006.85GB
    Memory usage:          6%
    Swap usage:            44%
    Processes:             17
    Users logged in:       0
    IPv4 address for eth1: 192.168.134.175
    IPv6 address for eth1: 2409:8938:809:7f24:a9be:c367:5c3a:cc3a
    IPv6 address for eth1: 2409:8938:809:7f24:b48:f1b6:8196:2a9b

   This message is shown once a day. To disable it please create the
   /root/.hushlogin file.
  ```
- 配置用户
  ```bash
  # 首次进入默认是 root 用户
  passwd              # 修改 root 密码
  useradd misaka13906 # 创建用户
  passwd misaka13906  # 修改该用户密码
  adduser misaka13906 sudo          # 将用户添加到 sudoers 列表
  usermod -s /bin/bash misaka13906  # 修改该用户的登录 shell
  su misaka13906      # 切换到该用户
  ```
- 配置网络连接
  wsl 好像不用自己配？能 ping 通 github

##### C 语言开发环境搭建
- apt
  ```bash
  sudo apt update
  sudo apt upgrade
  ```
- 安装 gcc
  ```bash
  sudo apt install gcc
  ```
- 验证 gcc 安装成功
  ```bash
  gcc -v
  ```
  显示信息：
  ```
  Using built-in specs.
  COLLECT_GCC=gcc
  COLLECT_LTO_WRAPPER=/usr/lib/gcc/x86_64-linux-gnu/11/lto-wrapper
  OFFLOAD_TARGET_NAMES=nvptx-none:amdgcn-amdhsa
  OFFLOAD_TARGET_DEFAULT=1
  Target: x86_64-linux-gnu
  Configured with: ../src/configure -v --with-pkgversion='Ubuntu 11.4.0-1ubuntu1~22.04' --with-bugurl=file:///usr/share/doc/gcc-11/README.Bugs --enable-languages=c,ada,c++,go,brig,d,fortran,objc,obj-c++,m2 --prefix=/usr --with-gcc-major-version-only --program-suffix=-11 --program-prefix=x86_64-linux-gnu- --enable-shared --enable-linker-build-id --libexecdir=/usr/lib --without-included-gettext --enable-threads=posix --libdir=/usr/lib --enable-nls --enable-bootstrap --enable-clocale=gnu --enable-libstdcxx-debug --enable-libstdcxx-time=yes --with-default-libstdcxx-abi=new --enable-gnu-unique-object --disable-vtable-verify --enable-plugin --enable-default-pie --with-system-zlib --enable-libphobos-checking=release --with-target-system-zlib=auto --enable-objc-gc=auto --enable-multiarch --disable-werror --enable-cet --with-arch-32=i686 --with-abi=m64 --with-multilib-list=m32,m64,mx32 --enable-multilib --with-tune=generic --enable-offload-targets=nvptx-none=/build/gcc-11-XeT9lY/gcc-11-11.4.0/debian/tmp-nvptx/usr,amdgcn-amdhsa=/build/gcc-11-XeT9lY/gcc-11-11.4.0/debian/tmp-gcn/usr --without-cuda-driver --enable-checking=release --build=x86_64-linux-gnu --host=x86_64-linux-gnu --target=x86_64-linux-gnu --with-build-config=bootstrap-lto-lean --enable-link-serialization=2
  Thread model: posix
  Supported LTO compression algorithms: zlib zstd
  gcc version 11.4.0 (Ubuntu 11.4.0-1ubuntu1~22.04)
  ```

可直接用命令行进入 vim 编写代码，或者在宿主机使用 vscode remote 插件连接虚拟机内置的 vscode 服务器进行代码编写。

### 各排序算法的实现细节



### 测试数据生成



### 不同编译优化等级下的性能对比结果



### 数据可视化



### 实验过程中遇到的问题及解决方案

