onvif_wsdd
=================
windows下的onvif之设备发现(wsdd)。

一、项目描述
---
sln文件是onvif_new.sln，生成它的版本是Visual Studio 2019(16.6.3)。编译时，“Active solution configuration”选Debug，“Active solution platform”选x86。

onvif_new.sln既可以是client、也可以是server，不同模式时需选择不一样的c文件。1）client。额外onvif_client.c。对照project_client.png。2）server。额外onvif_server.c、soapServer.c、wsaapi.c、wsddapi.c。对照project_server.png。

server时，为让网卡能收到组播请求可能需要做些设置。如果遇到不能接收，或许可按这里写的试下，“Win10组播不能正常收发信息(https://blog.csdn.net/qq_32660003/article/details/107152372)”。



更多内容见readme.txt
----