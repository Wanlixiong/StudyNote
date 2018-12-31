## 1.RPM软件管理操作基础
__注：1.使用rpm命令必须要有root身份才行__  
__&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;2.RPM默认安装路径为/var/lib/rpm/，该目录下还会保存记录软件相关信息的数据库文件和数字信息等重要文件.__
### 1.1RPM查询
在软件安装之前最好先进行软件查询，了解本机上是否已经安装该软件等相关信息。  
命令格式：``rpm [参数] [软件名]``  
参数：  
__-q:查询软件是否已经安装__  
-qa：列出所有已经安装的软件名  
-qi：列出软件的开发商、版本和说明等信息  
-ql：列出软件的所有文件与目录名  
__-qc：列出软件的所有配置文件__  
-qd：列出所有帮助文件  
-qR：找出软件的相关依赖软件所包含的文件  
__-qf:在该参数后加文件名，查找该文件属于哪个已安装软件__  

以查找vsftpd软件为例：
```
[root@localhost doc]# rpm -q vsftpd   //未安装
未安装软件包 vsftpd

[root@localhost ~]# rpm -q vsftpd   //安装后
vsftpd-3.0.2-25.el7.x86_64

[root@localhost ~]# rpm -qc vsftpd
/etc/logrotate.d/vsftpd
/etc/pam.d/vsftpd
/etc/vsftpd/ftpusers
/etc/vsftpd/user_list
/etc/vsftpd/vsftpd.conf   //.conf格式的配置文件，配置软件常用文件
```

### 1.2安装命令
命令格式：``rpm [参数] [软件名/网络安装路径]``    
参数: -i：install的意思  
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;-v：查看详细安装信息
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;-h：显示安装进度

示例：
```
[root@localhost ~]#rpm -ivh vsftpd
//如果使用rpm中没有相应的软件包可以用yum安装方法或找网络路径安装包代替，我这里就遇到了这样的问题
[root@localhost ~]#yum -y install vsftpd
```
### 1.3升级更新
参数：-U：如果软件没有被安装过，直接安装最新版。如果是旧软件，则更新。  
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;-F：如果软件还没被安装，则不更新也不安装，如果软件已安装，则更新。
格式：``rpm -Uvh [文件名]``  

### 1.4查看软件的改动情况
参数：-V:将改动的文件列出，如果没有文件则未改动过。   
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;-Va:列出系统上被改动过的文件  
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;-Vf:查看文件是否被改动，参数后接文件名  
