### 向浏览器输入URL会发生什么？
#### 第1步：DNS域名解析
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;浏览器先解析自身域名，然后操作系统再解析主机域名，查找hosts文件，在向域名服务器发送请求。  
#### 第2步：浏览器和服务器建立TCP连接
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;原理参考三次握手。
#### 第3步：浏览器向服务器发送HTTP请求
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;请求报文中包含报文首部、空行、和报文主体。   
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;报文首部有：请求方法、url和http版本等信息。  
![图1 HTTP GET请求报文格式](https://img-blog.csdnimg.cn/20181206141548360.jpg?x-oss-process=image/watermark,type_ZmFuZ3poZW5naGVpdGk,shadow_10,text_aHR0cHM6Ly9ibG9nLmNzZG4ubmV0L3FxXzM1NjQxNDE5,size_16,color_FFFFFF,t_70)
#### 第4步：服务器解析客户请求
#### 第5步：服务器向浏览器返回响应结果
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;响应报文中有响应行（附带响应码）、状态行，在响应头后携带响应体。如下图：
![图二 HTTP响应报文格式](https://img-blog.csdnimg.cn/20181206142916326.png?x-oss-process=image/watermark,type_ZmFuZ3poZW5naGVpdGk,shadow_10,text_aHR0cHM6Ly9ibG9nLmNzZG4ubmV0L3FxXzM1NjQxNDE5,size_16,color_FFFFFF,t_70)
#### 第6步：浏览器解析响应体中的html，并且进行渲染
### 为了方便理解，这里附上下图
_此图转载：https://www.jianshu.com/p/c1dfc6caa520_
![在这里插入图片描述](https://img-blog.csdnimg.cn/20181206143732787.png?x-oss-process=image/watermark,type_ZmFuZ3poZW5naGVpdGk,shadow_10,text_aHR0cHM6Ly9ibG9nLmNzZG4ubmV0L3FxXzM1NjQxNDE5,size_16,color_FFFFFF,t_70)



