# acl -- one advanced C/C++ lib for UNIX and WINDOWS

## 描述
acl 工程是一个跨平台（支持LINUX，WIN32，Solaris，MacOS，FreeBSD）的网络通信库及服务器编程框架，同时提供更多的实用功能库。通过该库，用户可以非常容易地编写支持多种模式(多线程、多进程、非阻塞、触发器、UDP方式)的服务器程序，WEB 应用程序，数据库应用程序。此外，该库还提供了常见应用的客户端通信库（如：HTTP、SMTP、ICMP、memcache、beanstalk），常见流式编解码库：XML/JSON/MIME/BASE64/UUCODE/QPCODE/RFC2047 etc。

本工程主要包含 5 个库及大量示例。5 个库的说明如下：
-    1) lib_acl: 该库是最基础的库，其它 4 个库均依赖于该库; 该库以 C 语言实现。
-    2) lib_protocol: 该库主要实现了 http 协议及 icmp/ping 协议; 该库以 C 语言实现。
-    3) lib_acl_cpp: 该库用 C++ 语言封装了 lib_acl/lib_protocol 两个库，同时增加了一些其它有价值的功能应用。
-    4) lib_dict: 该库主要实现了 KEY-VALUE 的字典式存储库，该库另外还依赖于 BDB, CDB 以及 tokyocabinet 库。
-    5) lib_tls: 该库封装了 openssl 库，使 lib_acl 的通信模式可以支持 ssl。

## 平台支持及编译
整个工程目前支持 Linux(AS4,5,6, CS4,5,6), Windows, MacOS, FreeBSD, Solaris。
* Linux/UNIX: 编译器为 gcc，直接在终端命令行方式下分别进入 lib_acl/lib_protocol/lib_acl_cpp/lib_dict/lib_tls 目录下，运行 make 命令即可。
* Windows: 可以用 VC2003/VC2008/VC2010/VC2012 进行编译。(如果需要用 VC6/VC2005 编译，可以参考 VC2003 的编译条件)。

当在 WIN32 环境下使用动态库时有几点需要注意：
* 使用 lib_acl 的动态库时，需要在用户的工程预定义: ACL_DLL;
* 使用 lib_protocol 动态库中的 HTTP 库或 ICMP 库时，需要在工程中预定义 HTTP_DLL 或 ICMP_DLL;
* 使用 lib_acl_cpp 的动态库时，需要在工程中预定义 ACL_CPP_DLL，如果您使用用 VC2003 编译环境则还需要预定义 VC2003;
* 使用 lib_dict 的动态库时，需要在工程中预定义 DICT_DLL;
* 使用 lib_tls 的动态库时，需要在工程中预定义 TLS_DLL。

## 目录结构说明

### lib_acl
-    1 init : 主要用于初始化 acl 基础库
-    2 stdlib : 是一些比较基础的功能函数库，在 stdlib/ 根目录下主要包括一些有关日志记录、网络/文件流处理、VSTRING缓冲操作等功能函数；在 stdlib/ 下还有二级目录，如下：
-    2.1 common : 该目录主要为一些常用的数据结构及算法的功能函数库，象哈希表、链表、队列、动态数组、堆栈、缓存、平衡二叉树、模式匹配树等；
-    2.2 memory : 该目录主要包含与内存操作相关的函数库，象内存基础分配与校验、内存池管理、内存切片管理等；
-    2.3 filedir : 该目录主要包含与目录遍历、目录创建等相关的库；
-    2.4 configure : 该目录主要包含配置文件的分析库；
-    2.5 iostuff : 该目录主要包含一些常用的IO操作的函数库，象读/写超时、设置IO句柄的阻塞模式等；
-    2.6 string : 该目录主要包含一些常用的字符串操作的库，提供了比标准C更灵活高效的字符串操作功能；
-    2.7 debug : 主要用于协助调试内存的泄露等功能；
-    2.8 sys : 主要是与不同操作系统平台相关的API的封装函数库；
-    **3 net: 是与网络操作相关的函数库，包含网络监听、网络连接、DNS查询、套接口参数设置等功能；**
-    3.1 connect : 主要是与网络连接相关的函数库，包含网络连接、域套接口连接等；
-    3.2 listen : 主要是与网络监听相关的函数库，包含网络监听、域套接口监听等；
-    3.3 dns : 主要是与DNS域名查询相关的函数库，包含对 gethostbyname 等接口的封装、按RFC1035标准直接发送UDP包方式进行查询等功能；
-    **4 event : 主要封装了 select/poll/epoll/iocp/win message/kqueue/devpoll 等系统API接口，使处理网络事件更加灵活、高效、简单，另外还包含定时器接口，acl 中的很多网络应用都会用到这些接口，象 aio、master 等模块；**
-    **5 aio : 主要包含网络异步操作的功能函数，该套函数库在处理高并发时有非常高的效率，而且提供了比基础API更为高级的调用方式，比使用象 libevent 之类的函数库更为简单，而且是线程安全的；**
-    6 msg : 主要包含了基于线程的消息事件及基于网络的消息事件功能；
-    7 thread : 主要是封装了各个OS平台下的基础线程API，使对外接口保持一致性，消除了平台的差异性，同时还提供了半驻留线程池的函数库，以及对于线程局部变量的扩展；
-    8 db : 主要是一些与数据库有关的功能库，定义了一个通用的数据库连接池的框架（并且实现了mysql的连接池实例）；一个简单的内存数据库（由哈希表、链表、平衡二叉树组合而成）；ZDB数据存储引擎，这是一个高效的基于数字键的存储引擎；
-    9 proctl : win32 平台下父子进程控制功能库；
-    10 code : 常见编码函数库，包括 base64编解码、URL编解码以及一些汉字字符集编码等；
-    11 unit_test : 包含有关进行 C 语言单元测试的功能库；
-    12 xml: 是一个流式的 xml 解析器及构造器，可以支持阻塞及阻塞式网络通信；
-    13 json: 是一个流式的 json 解析器及构造器，可以支持阻塞及阻塞式网络通信；
-    **14 master: 是在 UNIX 环境下支持多种服务器模式的服务器框架，目前主要支持多进程模式、多进程多线程模式、多进程非阻塞模式、多进程触发器模式及 UDP 通信模式；**

### lib_protocol
-    1 http: HTTP 协议相关的库，支持 HTTP/1.1，通讯方式支持同步/异步方式
-    2 icmp: icmp/ping 协议库，支持同步/异步通信方式
-    3 smtp: 邮件客户端发信协议库

### lib_acl_cpp
-    1 stdlib: 主要包含字符串处理类(string)，xml/json 解析库，zlib 压缩库(依赖于 zlib 库), 日志记录类, 字符集转码(在UNIX环境下需要 iconv 库), memcached 客户库, 互斥类(支持线程锁、文件锁);
-    **2 stream: 支持网络流/文件流，支持阻塞/非阻塞两种通信方式，在非阻塞模式下支持 select/poll/epoll/iocp/win32 message/kqueue/devpoll；支持 ssl 加密传输(阻塞及非阻塞方式，需要 polarssl库);**
-    3 ipc: 在非阻塞通信方式，提供了阻塞模块与非阻塞模块整合的方式;
-    **4 http: 比较完整的 HTTP 通信库及协议解析库，支持客户端及服务端模式，支持 ssl/gzip 传输方式; 支持类似于 Java HttpServlet 方式的大部分接口，方便编写 CGI 及 WEB 服务器程序；**
-    5 db: 封装了 MYSQL/SQLITE 库，支持数据库连接池；
-    6 hsocket: 实现了完整的 handler-socket 客户端通信库；
-    **7 mime: 支持完整的与邮件编码相关的库(邮件的 rfc2045-rfc2047/rfc822/base64/uucode 编码及解码库).**
-    **8 master: 封装了 C 库的服务器框架库**
-    9 beanstalk: 消息队列应用 beanstalkd 的客户端通信库
-    10 connpool: 通用的连接池库
-    11 hscoket: mysql 插件 handle-socket 的客户端通信库
-    12 memcache: memcached 应用的客户端库
-    13 queue: 磁盘文件队列操作库
-    14 ipc: 阻塞/非阻塞通信整合库
-    15 session: HTTP 会话库

### 图例
*    类索引图：
     ![类索引图](res/img/index.jpg)
*    异步 IO 类继承图
     ![异步 IO 类继承图](res/img/aio_inherit.jpg)
*    IO 流继承图
     ![IO 流继承图](res/img/stream_inherit.jpg)
*    接收上传文件的 CGI 程序：
     ![接收上传文件的 CGI 程序](res/img/cgi_upload.jpg)
*    文件下载客户端程序：
     ![文件下载客户端程序](res/img/http_download.jpg)
*    网页下载程序：
     ![网页下载程序](res/img/http_client.jpg)

### acl 库中有大量示例可供参考，请参考：[SAMPLES.md](SAMPLES.md)

## 其它
- WEB 站点: http://www.iteye.com
- Download: https://sourceforge.net/projects/acl
- QQ 群: 242722074
