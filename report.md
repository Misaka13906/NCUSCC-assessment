# 招新考核实验报告 - C 语言

### 实验环境的搭建

##### WSL

- 开启虚拟化：进入 BIOS 模式开启虚拟化
- 在 “启用或关闭 windows 功能” 中启用 Hyper-V，虚拟机平台，适用于 windows 的 linux 子系统
  - 如果以上 3 个选项有缺失，则搜索方案 复制那段脚本 保存为.bat文件并以管理员权限运行

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

以下讲解按从小到大顺序排序为例，从大到小同理。

##### 冒泡排序

冒泡排序的原理是：内层循环从左到右依次比较相邻两数，每次比较将较大的数交换到后面，从而使最大的数像冒泡一样逐渐移动到最后面。因为剩下的数不会比最后的数大，所以对剩下的数继续执行相同的操作，将其中的最大值移到后面，循环直到全部有序。时间复杂度为 $O(n)$。

##### 堆排序

参考资料：https://www.cs.princeton.edu/courses/archive/spring21/cos226/lectures/24PriorityQueues.pdf

(二叉)大根堆是一种任意结点的值都大于其子节点的完全二叉树。

堆排序使用了二叉堆的 $O(log n)$ 的 insert 和 move maximum 操作。因为是完全二叉树，所以很适合使用数组下标计算寻找父节点和子节点，令根节点下标为 1，对于一个下标为 n 的结点，其父节点下标为 $\lfloor\frac{n}{2}\rfloor$，左儿子下标为 2n，右儿子下标为 2n+1。堆排序可原地排序。时间复杂度为 $O(n log n)$。

整体步骤是：先按序将 n 个节点 insert 进去，再进行 n-1 次 move maximum 操作。

- insert 就是将值插入堆的最后一个节点，而要保持堆的性质，需要将新插入节点进行“上浮”操作，即：如果此时该值比父节点大，则与父节点进行交换，循环进行此过程直到没有父节点或者父节点的值不比插入的值大。
- move maximum 是先将堆顶与堆的最后一个节点交换，并将最后一个节点看作已移出堆（有序区），再对交换到堆顶的元素进行“下沉”操作，即：找到该结点的较大的儿子进行交换，直到没有儿子或所有儿子都比该结点小，由此保持堆的性质。

##### 斐波那契堆排序

参考资料：https://www.cs.princeton.edu/~wayne/teaching/fibonacci-heap.pdf

斐波那契堆给人的第一印象是由一些(不一定二叉的)堆组成的集合，并维护这些堆的堆顶的最值；实际上是由二项式堆变式而来：它不像二项式堆那样在插入时立即进行巩固，而是将巩固推迟到下一次 delete minimum 时。

斐波那契堆排序只用到了 insert 操作和 delete minimum 操作。在本程序的实现中，堆顶之间用双向循环链表连接，堆中结点的兄弟之间也用双向循环链表连接（在排序这个应用中感觉双向有点多余）；每一个结点储存以下信息：value, rank, 父节点，某个子节点，左兄弟，右兄弟，其中 rank 为树的度数。需要一个 rankRoot 数组来维护特定度数对应的树根，以方便实现同度数树的合并操作。

整体步骤：将 n 个元素依次插入，然后循环 n 次 执行 先取出最小值存入结果数组 再 delete minimum 的操作。

- insert：直接将元素插入根节点的链表中，并更新最小根值。
- delete minimum 分为以下步骤：
  - 保存旧的最小根节点的信息；
  - 删除旧的最小根节点；
  - 遍历旧的最小根节点的儿子，将其依次插入根节点的链表中；
  - 更新最小根节点：遍历根节点链表找到最小根节点；
  - 遍历根节点链表，将度数相同的树进行合并，并更新 rankRoot 数组：
    - 如果对于当前树的 rank， $rankRoot_rank$ 为 NULL，则改为当前树；
    - 否则比较原树新树这两棵树根节点大小，以较小的根节点作为父节点进行合并：
      - 合并时，要先将较大根节点从原根节点链表删除，然后将其插入较小根节点的子节点的双向链表
      - 更新 rankRoot 数组

以此实现斐波那契堆排序。


### 测试数据生成

使用 C 语言生成测试数据，直接调用排序函数进行测试，并统计数据。

使用 `srand(time(0))` 设置随机种子，并调用 `rand()` 获取 0 ~ RAND_MAX 之间的随机数。
 
循环使用不同规模（$10^2, 10^3, 10^4, 10^5$）的数据并重复多次，然后将数据记录在 csv 文件中。
 
相应代码在源文件 src/main.c 中。 

### 不同编译优化等级下的性能对比结果



### 数据可视化



### 实验过程中遇到的问题及解决方案

- wsl Ubuntu-22.04 中遇到各种文件缺失和权限问题导致无法安装 vscode server，查了很多资料都未解决：重装（重装解决 99% 的问题）

- 堆排序理解错误和理解困难：重新寻找资料
  原资料：[堆排序](https://zhuanlan.zhihu.com/p/124885051)
  [斐波那契堆排序](https://www.geeksforgeeks.org/fibonacci-heap-insertion-and-union/?ref=oin_asr7)
  新资料：[斐波那契堆排序](https://www.cs.princeton.edu/~wayne/teaching/fibonacci-heap.pdf)（在上述 geeksforgeeks 的文章内的链接找到的）
  [堆排序](https://www.cs.princeton.edu/courses/archive/spring21/cos226/lectures/24PriorityQueues.pdf)
  （在上个链接的网站的课件中找到的）

- 斐波那契堆排序遇到的问题
  - 补上 merge 函数缺失的更新 rankRoot 的过程；
  - 死循环：通过输出 node 信息，发现循环体中的过程会修改循环迭代本来预期的变量的原值，因此使用临时变量储存这个值以供迭代使用；
  - 在多组测试数据下第二组数据始终死循环，由此发现数据未清零的问题，补上创建新堆和创建新节点时的数据清零过程，以及 rankRoot 使用前清零的过程；
  - 遍历根节点的双向循环链表进行 consolidate 过程的死循环：（临时方案）统计循环次数，超过 1e5 则跳出。

- 自动记录资源占用数据
  - 测试获取资源数据代码是否有效时，获取不到 pid：手动提供进程所有者后成功，所以是由获取进程所有者错误或失败导致。
  - 
