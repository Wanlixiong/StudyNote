## 1.Linux文件与目录
### 1.1文件属性
文件属性查看:  ``ls -al``  
``drwx------. 16 wanlixiong wanlixiong 4096 11月 20 03:21 . ``  
``-rw-------.  1 wanlixiong wanlixiong 1082 11月 21 14:26 .bash_history``

![](https://i.imgur.com/dVSoUNx.jpg)
第一个字符表示文件类型  

1.  d 表示目录  
2.  - 表示文件  
3.  l 表示连接文件  
4.  b 表示设备文件里面的可存储的接口设备  
5.  c 表示设备文件里面的串行端口设备，如鼠标、键盘

### 1.2改变文件属性和权限
#### 1.2.1chgrp改变文件所属用户组  

``chgrp -R 用户组名 文件名``   
-R表示递归更改  

#### 1.2.2chown改变文件所有者  
``chown -R 用户名 文件或目录``   
也可以更改用户组  
``chown :root 文件或目录``  
``chown root:root 文件或目录``  

#### 1.2.3chmod改变文件的权限
1.各权限分数分别为：r:4 w:2 x:1  
如：``chmod -R xyz 文件或目录``  
&ensp;&ensp;&ensp;&ensp;``chmod 777 .bashrc``  
x表示owner的权限、y表示group的权限、z表示others的权限  

2.u=,g=,o=  
如：`` chmod ugo=rwx .bashrc``和``chmod 777 .bashrc``等价  
&ensp;&ensp;&ensp;&ensp;`` chmod u=rwx,go=rx .bashrc ``和``chmod 755 .bashrc``等价  

#### 1.2.4文件的默认权限
查看：``umask``或``umask -S``   
显示结果为 ：``0002``(数字后三位表示权限，2表示o没有w的权限，w的值为2)和``u=rwx,g=rx,o=rx``    
改：``umask 022``(表示go都没有w的权限)或``umask u=rwx,go=rx``  

**注：默认权限的修改只针对当前用户**




_转载：《鸟哥的Linux私房菜基础篇》_
