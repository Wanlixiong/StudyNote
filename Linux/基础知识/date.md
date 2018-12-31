1.时间查看  
date +%Y/%m/%d/%H:%M:%S（年月日时分秒）  
2.时间设置  
（1）固定设置  
date –s 月/日/年  
date –s 时/分/秒  
（2）自动更新设置  
a.修正本地时区及ntp服务  
```
[root@VM_0_13_centos ~]# yum -y install ntp  
[root@VM_0_13_centos ~]# rm -rf /etc/localtime  
[root@VM_0_13_centos ~]# ln -s /usr/share/zoneinfo/Asia/Shanghai /etc/localtime  
[root@VM_0_13_centos ~]# /usr/sbin/ntpdate -u pool.ntp.org  
```
b.自动同步时间  
#添加下面一段  
#表示每10分钟同步一次  
```
[root@VM_0_13_centos ~]# crontab -e  
*/10 * * * *  /usr/sbin/ntpdate -u pool.ntp.org >/dev/null 2>&1  
[root@VM_0_13_centos ~]# service crond restart #重启  
[root@VM_0_13_centos ~]# date #查看时间 
``` 
