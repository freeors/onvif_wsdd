windows下的onvif之设备发现(wsdd)。

一、项目描述
sln文件是onvif_new.sln，生成它的版本是Visual Studio 2019(16.6.3)。编译时，“Active solution configuration”选Debug，“Active solution platform”选x86。

onvif_new.sln既可以是client、也可以是server，不同模式时需选择不一样的c文件。1）client。额外onvif_client.c。对照project_client.png。2）server。额外onvif_server.c、soapServer.c、wsaapi.c、wsddapi.c。对照project_server.png。

server时，为让网卡能收到组播请求可能需要做些设置。如果遇到不能接收，或许可按这里写的试下，“Win10组播不能正常收发信息(https://blog.csdn.net/qq_32660003/article/details/107152372)”。


二、wsdd基本流程
假设192.168.1.103是wsdd client，192.168.1.180是wsdd server。
----------------------------
1)192.168.1.103 ---> 239.255.255.250:3702。发送Probe请求

2)192.168.1.180:3702 ---> 192.168.1.103。发送Probe应答

综合来说，1）192.168.1.180侦听239.255.255.250:3702。2）192.168.1.103向239.255.255.250:3702发Probe请求。3）192.168.1.180侦听到这个请求，向192.168.1.103发Probe应答。发应答时，源是192.168.1.180。


三、如何生成sln
虽然给的sln已直接就能用，这里还是写下如何由gsoap生成。网上已有较多介绍如何使用gsoap生成ovvif的文章，像“onvif开发之设备发现功能的实现”(https://blog.csdn.net/love_xjhu/article/details/11821037)。
第一步：生成onvif.h
wsdl2h -o onvif.h -c -s -t ./typemap.dat http://www.onvif.org/onvif/ver10/device/wsdl/devicemgmt.wsdl http://www.onvif.org/onvif/ver10/media/wsdl/media.wsdl http://www.onvif.org/onvif/ver10/event/wsdl/event.wsdl http://www.onvif.org/onvif/ver10/display.wsdl http://www.onvif.org/onvif/ver10/deviceio.wsdl http://www.onvif.org/onvif/ver20/imaging/wsdl/imaging.wsdl http://www.onvif.org/onvif/ver20/ptz/wsdl/ptz.wsdl http://www.onvif.org/onvif/ver10/receiver.wsdl http://www.onvif.org/onvif/ver10/recording.wsdl http://www.onvif.org/onvif/ver10/search.wsdl http://www.onvif.org/onvif/ver10/network/wsdl/remotediscovery.wsdl http://www.onvif.org/onvif/ver10/replay.wsdl http://www.onvif.org/onvif/ver20/analytics/wsdl/analytics.wsdl http://www.onvif.org/onvif/ver10/analyticsdevice.wsdl http://www.onvif.org/ver10/actionengine.wsdl http://www.onvif.org/ver10/pacs/accesscontrol.wsdl http://www.onvif.org/ver10/pacs/doorcontrol.wsdl

各个wsdl之间用空格隔开。上面用的是在线生成（即不是把*.wsdl下载到本地），实际下载时会转去https，为此gsoap自带的wsdl2h.exe是不行的，需要重编译出个支持ssl的wsdl2h.exe。如何编译？打开<gsoap-2.8>/gsoap/VisualStudio2005/wsdl2h/wsdl2h.sln，加上预定义宏：WITH_OPENSSL。遇到什么时间，因地解决。onvif_new下有个wsdl2h.exe，是我当前编译出的支持ssl的debug版本。

第二步：由onvif.h生成项目需要的源文件
soapcpp2 -c onvif.h -x -L -I C:\movie\gsoap-2.8\gsoap\import

生成时可能会遇到以下错误。
wsa5.h(288): **ERROR**: service operation name clash: struct/class 'SOAP_ENV__Fault' already declared at wsa.h:2731
——修改import/wsa5.h文件，将int SOAP_ENV__Fault修改为int SOAP_ENV__Fault_alex，再次使用soapcpp2工具生成就成功了。

第三：新建sln，编译
threads.c、wsaapi.c、wsddapi.c复制自<gsoap-2.8>/gsoap/plugin

编译可能会遇到以下错误。
convif_new\wsddapi.c(525,7): error C2039: 'wsa5__EndpointReference': is not a member of 'wsdd__HelloType'
onvif_new\soapStub.h(3841): message : see declaration of 'wsdd__HelloType'
——注释掉onvif_new\soapStub.h中的“#define SOAP_WSA_2005”
