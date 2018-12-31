#### 转载声明
此文不是本人所写，希望你在转载时也像我一样注明原作，转载自https://blog.gtwang.org/linux/centos-7-firewalld-command-setup-tutorial_
这是一篇墙外的文章，对firewalld这个防火墙的使用介绍的比较详细，主要说明了这个软件的常用操作方式，基本上能够满足服务器的网络管理，上手firewalld之前浏览一遍这篇文章对你会有帮助。

#### firewalld简介
在旧版的CentOS Linux 中，防火墙都是以传统的iptables 来设定，而从CentOS 7 开始，则改用firewalld 来管理防火墙。  
传统的iptables 在每次修改防火墙时都要清除旧规则，重新套用一次新规则，使用上不是很方便，而新的firewalld 以区域（zone）的方式管理规则，并使用动态的方式执行，修改规则后可立即生效，也不需要重新启动系统的服务（service 或daemon），所以后来的RHEL、CentOS 与Fedora 都改用firewalld 了。  

__注意__：iptables 与firewalld 两个防火墙管理系统只能选用其中一种，不可以同时开启，否则会有冲突。

#### 安装
安装firewalld 之前，请先确认iptables 是否有被启用，若系统上原本就有运行iptables 的防火墙，一定要先将其关闭后，才能启用firewalld，否则会有问题：
```
# 检查iptables 服务是否正在运行
systemctl status iptables

# 停止正在执行的iptables 服务
systemctl stop iptables

#将iptables服务永久关闭 
systemctl mask iptables
```
firewalld在RHEL/CentOS 7与Fedora 21之中应该是预设就会安装好的，若您的系统上没有安装，可用yum安装：
```
sudo yum install firewalld
```
当firewalld 安装好之后，检查firewalld 服务是否有启动：
```
#检查firewalld服务状态 
systemctl status firewalld
```
若firewalld 没有启动，则手动启动它：
```
# 启动firewalld 服务
systemctl start firewalld

# 停止firewalld 服务
systemctl stop firewalld

#重新启动firewalld服务 
service firewalld restart
```
若要设定firewalld 在开机时自动启动，可执行：
```
#设定开机自动启动firewalld服务 
systemctl enable firewalld
```
#### 区域
firewalld 的区域（zone）可用来设定网络连接和网络接口所处的运行环境，对内使用的区域其防火墙规则会较为宽松，对外的区域其规则会较为严谨。

一条网络连接或一个网络接口只能隶属于一个区域，我们可以自订区域的设定，也可以直接从firewalld 预设的几个区域中选择：  

| 区域     | 描述                                                                                                                                         |
| -------- | -------------------------------------------------------------------------------------------------------------------------------------------- |
| drop     | 任何往内的封包都会被丢弃，只允许往外传送的封包。                                                                                             |
| block    | 任何来自于外部的连线都会被阻挡，只允许自己系统主动建立的连线。                                                                               |
| public   | 公开区域，预设不信任其他电脑与网路，只有被允许的连线才能进入。通常大部分的连线设定都会放在这里。                                             |
| external | 公开区域，适用于NAT 网络环境。                                                                                                               |
| dmz      | 非军事区域（demilitarized zone，有点像是放在外头的危险区域），允许外部的连线进入，但其对内的连线则有限制，只有被允许的连线才能连进内部网路。 |
| work     | 公司内部等工作区域，在此区域中不应该会有恶意的攻击者。只有被允许的连线可以进入。                                                             |
| home     | 家里头的网络区域，在此区域中不应该会有恶意的攻击者。只有被允许的连线可以进入。                                                               |
| internal | 内部网路区域，在此区域中不应该会有恶意的攻击者。只有被允许的连线可以进入。                                                                   |
| trusted  | 完全信任的区域，接受所有连线。                                                                                                               |         


#### 查询区域设定
firewalld都是透过firewall-cmd指令来操作的，若要列出firewalld中已经定义好的区域，可执行：
```
#列出所有的区域 
firewall-cmd --get-zones
```

```
block dmz drop external home internal public trusted work
```

列出所有的区域与其详细的设定内容
```
#列出所有的区域与内容 
sudo firewall-cmd --list-all-zones
```
若要查询特定区域的内部设定，可执行：
```
#列出指定的区域与内容 
sudo firewall-cmd --zone=public  --list-all
```
```
block
  target: %%REJECT%%
  icmp-block-inversion: no
  interfaces:
  sources:
  services:
  ports:
  protocols:
  masquerade: no
  forward-ports:
  source-ports:
  icmp-blocks:
  rich rules:
  ...
```
若要查询特定区域的内部设定，可执行：
```
#列出指定的区域与内容 
sudo firewall-cmd --zone=public  --list-all
```
```
public (active)
  target: default
  icmp-block-inversion: no
  interfaces: enp7s0d1 ib0
  sources:
  services: ssh dhcpv6-client rpc-bind https http tftp dhcp
  ports: 944/tcp 944/udp 945/tcp 945/udp 946/udp 8649/udp 8649/tcp 8651/tcp 8652/tcp 15001/tcp 15002/tcp 15003/tcp 15004/tcp 15007/tcp 17001/tcp 8080/tcp
  protocols:
  masquerade: no
  forward-ports:
  source-ports:
  icmp-blocks:
  rich rules:
```
上面这个查询方式所得到的结果是目前系统上执行的设定（runtime），若要查询写在硬盘中的永久设定，可以使用：
```
#查询永久设定值 
sudo firewall-cmd --zone=public  --list-all  --permanent
```

#### 预设区域
当网络接口或是连接没有指定区域时，就会直接纳入预设区域中。若要查询目前预设的区域，可执行：
```
#列出预设区域 
firewall-cmd --get-default-zone
```
```
public
```
若要更改firewalld 预设的区域，可以执行：
```
#设定预设区域 
firewall-cmd --set-default-zone=home
```
更改后，可再确认一次预设区域：
```
#列出预设区域 
firewall-cmd --get-default-zone
```
```
home
```
#### 网络接口所属区域
列出目前所有运行中的区域，以及各个网络接口所属的区域：
```
#查询运作中的区域 
firewall-cmd --get-active-zones
```
```
public
  interfaces: enp7s0d1 ib0
trusted
  interfaces: eno2
```
若要查询指定网络接口所属区域，可执行（enp7s0d1是网络接口）：
```
#查询网卡所属区域 
firewall-cmd --get-zone-of-interface=enp7s0d1
```
```
public
```
若要更改指定网络接口的所属区域，可以使用：
```
#将enp7s0d1网络接口设定到home区域中 
sudo firewall-cmd --zone=home  --change-interface=enp7s0d1
```
上面这种修改网络接口所属区域的方式只是暂时的，若要让系统重新开机后还可以维持这样的设定，就要直接更改/etc/sysconfig/network-scripts/底下的设定文档，以enp7s0d1这个网络接口来说，需要去修改ifcfg-enp7s0d1这个文件中的ZONE设定值：
```
ZONE =home
```
#### 区域服务
若要在防火墙上开启一些端口，让对外的服务可以使用，可以再区域设定中新增一些服务设定。firewalld 中有预先定义一些常用的服务名称，可以用下面这个指令查询：
```
#列出预先定义的服务名称 
firewall-cmd --get-services
```
```
RH-Satellite-6 amanda-client amanda-k5-client bacula bacula-client bitcoin bitcoin-rpc bitcoin-testnet bitcoin-testnet-rpc ceph ceph-mon cfengine condor-collector ctdb dhcp dhcpv6 dhcpv6-client dns docker-registry dropbox-lansync elasticsearch freeipa-ldap freeipa-ldaps freeipa-replication freeipa-trust ftp ganglia-client ganglia-master high-availability http https imap imaps ipp ipp-client ipsec iscsi-target kadmin kerberos kibana klogin kpasswd kshell ldap ldaps libvirt libvirt-tls managesieve mdns mosh mountd ms-wbt mssql mysql nfs nrpe ntp openvpn ovirt-imageio ovirt-storageconsole ovirt-vmconsole pmcd pmproxy pmwebapi pmwebapis pop3 pop3s postgresql privoxy proxy-dhcp ptp pulseaudio puppetmaster quassel radius rpc-bind rsh rsyncd samba samba-client sane sip sips smtp smtp- submission smtps snmp snmptrap spideroak-lansync squid ssh synergysyslog syslog-tls telnet tftp tftp-client tinc tor-socks transmission-client vdsm vnc-server wbem-https xmpp-bosh xmpp-client xmpp-local xmpp-server
```
大部分常见的网络服务都有在这个列表中，要将指定的服务新增至指定的区域中，可执行：
```
#将http服务新增至public区域中 
sudo firewall-cmd --zone=public  --add-service=http
```
上面那行指令只是暂时将http服务新增至public区域中，重新开机后这个设定就看不到了，通常在比较重要的服务器上，我们都会先使用暂时的设定先进行测试，若测试没问题，再将设定写入设定档，永久保存：
```
#永久将http服务新增至public区域中 
sudo firewall-cmd --zone=public  --permanent  --add-service=http
```
执行永久的设定之后，可再重新查询一次永久设定值，确认设定值是否正确：
```
#列出public区域永久的服务设定值 
sudo firewall-cmd --zone=public  --permanent  --list-services
```
这样设定好之后，在public这个区域就会开启网页的80端口，让外部网络可以连进我们的网站，现在的网站都会提供安全加密的网页，所以最好连HTTPS的443端口也一并开启，开启的方式大同小异：
```
#将https服务新增至public区域中 
sudo firewall-cmd --zone=public  --add-service=https

#永久将https服务新增至public区域中 
sudo firewall-cmd --zone=public  --permanent  --add-service=https
```
#### 设定连接端口
基本上firewalld有内定的服务都可以使用上面这种方式开启，如果我们想要开启的端口不在firewalld内建的服务名单中，也可以直接指定通讯协议（tcp或udp）与端口号：
```
#开启tcp的8080端口号
sudo firewall-cmd --zone=public  --add-port=8080/tcp

#永久开启tcp的8080端口号
sudo firewall-cmd --zone=public  --permanent  --add-port=8080/tcp
```
端口的部分也可以用范围的方式指定，一次开通多个端口号：
```
#开启udp的4990至4999端口号 
sudo firewall-cmd --zone=public  --add-port=4990-4999/udp

#永久开启udp的4990至4999端口号 
sudo firewall-cmd --zone=public  --permanent  --add-port=4990-4999/udp
```
#### 移除服务
若要将指定的服务从某个区域中移除，可以执行：
```
#将http服务从public区域中移除 
sudo firewall-cmd --zone=public  --remove-service=http

#永久将http服务从public区域中移除 
sudo firewall-cmd --zone=public  --permanent  --remove-service=http
```
如果是要移除自己设定的端口号，则执行：
```
#关闭tcp的8080端口
sudo firewall-cmd --zone=public  --remove-port=8080/tcp

#永久关闭tcp的8080端口 
sudo firewall-cmd --zone=public  --permanent  --remove-port=8080/tcp
```
#### 新增服务名称
除了直接指定通讯协议与端口号之外，我们也可以自订新的服务名称，加入firewalld 的服务名称表列中，这样就可以使用服务名称的方式来设定开启的服务。这样做的好处是可以让防火墙的设定看起来更容易理解，不会搞不清楚某些端口号的用途。

若要新增服务名称，可以在/etc/firewalld/services新增服务的XML设定档，XML设定档的语法可参考/usr/lib/firewalld/services/中的范例，例如http.xml就是定义http服务的设定档：
```
<? xml version = "1.0" encoding = "utf-8" ?> < service > < short > WWW (HTTP) </short> < description > HTTP is the protocol used to serve Web pages. If you plan to make your Web server publicly available, enable this option. This option is not required for viewing pages locally or developing Web pages. </description> < port protocol = "tcp" port = "80" /> </service>  
```
参考这些范例后，撰写自己的服务设定文档（若需要开启多个端口，可以自己新增，或是参考其他的范例档），然后另外储存成一个新的档案，放在/etc/firewalld/services目录下，档名要设定为服务的名称加上XML的附档名，例如my_service.xml，接着让firewalld重新载入设定：
```
#重新载入设定 
sudo firewall-cmd --reload
```
重新查询一次支援的服务名称，应该就可以看到新加入的my_service服务了：  
```
#列出预先定义的服务名称 
firewall-cmd --get-services
```

_转载：https://blog.gtwang.org/linux/centos-7-firewalld-command-setup-tutorial_