#### yum 语法
```
yum [options] [command] [package ...]
```
- options：可选，选项包括-h（帮助），-y（当安装过程提示选择全部为"yes"），-q（不显示安装的过程）等等。
- command：要进行的操作。
- package操作的对象。  

#### 常用命令
- 1.列出所有可更新的软件清单命令：yum check-update
- 2.更新所有软件命令：yum update
- 3.仅安装指定的软件命令：yum install <package_name>
- 4.仅更新指定的软件命令：yum update <package_name>
- 5.列出所有可安裝的软件清单命令：yum list
- 6.删除软件包命令：yum remove <package_name>
- 7.查找软件包 命令：yum search <keyword>
- 8.清除缓存命令:
 - yum clean packages: 清除缓存目录下的软件包
 - yum clean headers: 清除缓存目录下的 headers
 - yum clean oldheaders: 清除缓存目录下旧的 headers
 - yum clean, yum clean all (= yum clean packages; yum clean oldheaders) :清除缓存目录下的软件包及旧的headers

#### yum针对软件包操作常用命令
- 1.使用YUM查找软件包 命令：yum search 
- 2.列出所有可安装的软件包 命令：yum list 
- 3.列出所有可更新的软件包 命令：yum list updates 
- 4.列出所有已安装的软件包 命令：yum list installed 
- 5.列出所有已安装但不在 Yum Repository 内的软件包 命令：yum list extras 
- 6.列出所指定的软件包 命令：yum list 
- 7.使用YUM获取软件包信息 命令：yum info 
- 8.列出所有软件包的信息 命令：yum info 
- 9.列出所有可更新的软件包信息 命令：yum info updates 
- 10.列出所有已安装的软件包信息 命令：yum info installed 
- 11.列出所有已安装但不在 Yum Repository 内的软件包信息 命令：yum info extras 
- 12.列出软件包提供哪些文件 命令：yum provides
 
 
__参考：http://www.runoob.com/linux/linux-yum.html__  
__参考：https://www.cnblogs.com/AganRun/p/8118339.html__


