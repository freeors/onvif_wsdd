#include "soapH.h"
#include "wsdd.nsmap"
 
#include "soapStub.h"
#include "wsddapi.h"

#define ONVIF_LISTEN_PORT 3702

int main(int argc,char ** argv)
{
	printf("[%s][%d][%s][%s] start \n", __FILE__, __LINE__, __TIME__, __func__);
 
	int count = 0;
	struct soap ServerSoap;
	struct ip_mreq mcast;
	
	soap_init1(&ServerSoap, SOAP_IO_UDP | SOAP_XML_IGNORENS);
	soap_set_namespaces(&ServerSoap,  namespaces);
	
	printf("[%s][%d][%s][%s] ServerSoap.version = %d \n", __FILE__, __LINE__, __TIME__, __func__, ServerSoap.version);
	
	if(!soap_valid_socket(soap_bind(&ServerSoap, NULL, ONVIF_LISTEN_PORT, 10)))
	{
		soap_print_fault(&ServerSoap, stderr);
		exit(1);
	}
	
	mcast.imr_multiaddr.s_addr = inet_addr("239.255.255.250");
	mcast.imr_interface.s_addr = htonl(INADDR_ANY);
 
	if(setsockopt(ServerSoap.master, IPPROTO_IP, IP_ADD_MEMBERSHIP, (char*)&mcast, sizeof(mcast)) < 0)
	{
	    	printf("setsockopt error! error code = %d,err string = %s\n",errno,strerror(errno));
		return 0;
	}
 
	for(;;)
	{
		if(soap_serve(&ServerSoap))
		{
			soap_print_fault(&ServerSoap, stderr);
		}
 
		soap_destroy(&ServerSoap);
		soap_end(&ServerSoap);
 
		//客户端的IP地址
		printf("RECEIVE count %d, connection from IP = %lu.%lu.%lu.%lu socket = %d \r\n", count, ((ServerSoap.ip)>>24)&0xFF, ((ServerSoap.ip)>>16)&0xFF, ((ServerSoap.ip)>>8)&0xFF,(ServerSoap.ip)&0xFF, (ServerSoap.socket));
		count++;
	}
 
	//分离运行时的环境
	soap_done(&ServerSoap);
 
	return 0;
}

SOAP_FMAC5 int SOAP_FMAC6 SOAP_ENV__Fault(struct soap* soap, char *faultcode, char *faultstring, char *faultactor,

                            struct SOAP_ENV__Detail *detail, struct SOAP_ENV__Code *SOAP_ENV__Code,

                            struct SOAP_ENV__Reason *SOAP_ENV__Reason,

                            char *SOAP_ENV__Node, char *SOAP_ENV__Role,

                            struct SOAP_ENV__Detail *SOAP_ENV__Detail )

{

    printf("%s,%d\n",__FUNCTION__, __LINE__);

    return 0;

}

SOAP_FMAC5 int SOAP_FMAC6 SOAP_ENV__Fault_alex(struct soap* soap, char *faultcode, char *faultstring, char *faultactor, struct SOAP_ENV__Detail *detail, struct SOAP_ENV__Code *SOAP_ENV__Code, struct SOAP_ENV__Reason *SOAP_ENV__Reason, char *SOAP_ENV__Node, char *SOAP_ENV__Role, struct SOAP_ENV__Detail *SOAP_ENV__Detail)
{
    printf("%s,%d\n",__FUNCTION__, __LINE__);
    return 0;
}

void wsdd_event_Hello(struct soap *soap, unsigned int InstanceId, const char *SequenceId, unsigned int MessageNumber, const char *MessageID, const char *RelatesTo, const char *EndpointReference, const char *Types, const char *Scopes, const char *MatchBy, const char *XAddrs, unsigned int MetadataVersion)
{
    printf("%s,%d\n",__FUNCTION__, __LINE__);
}

 

void wsdd_event_Bye(struct soap *soap, unsigned int InstanceId, const char *SequenceId, unsigned int MessageNumber, const char *MessageID, const char *RelatesTo, const char *EndpointReference, const char *Types, const char *Scopes, const char *MatchBy, const char *XAddrs, unsigned int *MetadataVersion)

{

    printf("%s,%d\n",__FUNCTION__, __LINE__);
}

soap_wsdd_mode wsdd_event_Probe(struct soap *soap, const char *MessageID, const char *ReplyTo, const char *Types, const char *Scopes, const char *MatchBy, struct wsdd__ProbeMatchesType *matches)

{

    printf("%s,%d\n",__FUNCTION__, __LINE__);

    printf("MessageID:%s\n", MessageID);

    printf("ReplyTo:%s\n",ReplyTo);

    printf("Types:%s\n",Types);

    printf("Scopes:%s\n",Scopes);

    printf("MatchBy:%s\n",MatchBy); 

   

    //测试代码

    soap_wsdd_init_ProbeMatches(soap,matches);

    soap_wsdd_add_ProbeMatch(soap,matches,

        "urn:uuid:464A4854-4656-5242-4530-313035394100",

        "ns1:NetworkVideoTransmitter",

        "onvif://www.onvif.org/type/video_encoder onvif://www.onvif.org/type/audio_encoder onvif://www.onvif.org/hardware/IPC-model onvif://www.onvif.org/name/IPC-model",

        NULL,

        "http://192.168.0.243/onvif/device_service",10);

    return 0;

}

 

void wsdd_event_ProbeMatches(struct soap *soap, unsigned int InstanceId, const char *SequenceId, unsigned int MessageNumber, const char *MessageID, const char *RelatesTo, struct wsdd__ProbeMatchesType *matches)

{

    printf("%s,%d\n",__FUNCTION__, __LINE__);
}

soap_wsdd_mode wsdd_event_Resolve(struct soap *soap, const char *MessageID, const char *ReplyTo, const char *EndpointReference, struct wsdd__ResolveMatchType *match)

{

    printf("%s,%d\n",__FUNCTION__, __LINE__);

    return 0;

}

 

void wsdd_event_ResolveMatches(struct soap *soap, unsigned int InstanceId, const char *SequenceId, unsigned int MessageNumber, const char *MessageID, const char *RelatesTo, struct wsdd__ResolveMatchType *match)

{
    printf("%s,%d\n",__FUNCTION__, __LINE__);
}



//
//
//
/** Web service operation '__ns3__GetSupportedActions' implementation, should return SOAP_OK or error code */
SOAP_FMAC5 int SOAP_FMAC6 __ns3__GetSupportedActions(struct soap* soap, struct _ns3__GetSupportedActions *ns3__GetSupportedActions, struct _ns3__GetSupportedActionsResponse *ns3__GetSupportedActionsResponse)
{
    printf("%s,%d\n",__FUNCTION__, __LINE__);
	return 0;
}

/** Web service operation '__ns3__GetActions' implementation, should return SOAP_OK or error code */
SOAP_FMAC5 int SOAP_FMAC6 __ns3__GetActions(struct soap* soap, struct _ns3__GetActions *ns3__GetActions, struct _ns3__GetActionsResponse *ns3__GetActionsResponse)
{
    printf("%s,%d\n",__FUNCTION__, __LINE__);
	return 0;
}
/** Web service operation '__ns3__CreateActions' implementation, should return SOAP_OK or error code */
SOAP_FMAC5 int SOAP_FMAC6 __ns3__CreateActions(struct soap* soap, struct _ns3__CreateActions *ns3__CreateActions, struct _ns3__CreateActionsResponse *ns3__CreateActionsResponse)
{
    printf("%s,%d\n",__FUNCTION__, __LINE__);
	return 0;
}
/** Web service operation '__ns3__DeleteActions' implementation, should return SOAP_OK or error code */
SOAP_FMAC5 int SOAP_FMAC6 __ns3__DeleteActions(struct soap* soap, struct _ns3__DeleteActions *ns3__DeleteActions, struct _ns3__DeleteActionsResponse *ns3__DeleteActionsResponse)
{
    printf("%s,%d\n",__FUNCTION__, __LINE__);
	return 0;
}
/** Web service operation '__ns3__ModifyActions' implementation, should return SOAP_OK or error code */
SOAP_FMAC5 int SOAP_FMAC6 __ns3__ModifyActions(struct soap* soap, struct _ns3__ModifyActions *ns3__ModifyActions, struct _ns3__ModifyActionsResponse *ns3__ModifyActionsResponse)
{
    printf("%s,%d\n",__FUNCTION__, __LINE__);
	return 0;
}
/** Web service operation '__ns3__GetServiceCapabilities' implementation, should return SOAP_OK or error code */
SOAP_FMAC5 int SOAP_FMAC6 __ns3__GetServiceCapabilities(struct soap* soap, struct _ns3__GetServiceCapabilities *ns3__GetServiceCapabilities, struct _ns3__GetServiceCapabilitiesResponse *ns3__GetServiceCapabilitiesResponse)
{
    printf("%s,%d\n",__FUNCTION__, __LINE__);
	return 0;
}
/** Web service operation '__ns3__GetActionTriggers' implementation, should return SOAP_OK or error code */
SOAP_FMAC5 int SOAP_FMAC6 __ns3__GetActionTriggers(struct soap* soap, struct _ns3__GetActionTriggers *ns3__GetActionTriggers, struct _ns3__GetActionTriggersResponse *ns3__GetActionTriggersResponse)
{
    printf("%s,%d\n",__FUNCTION__, __LINE__);
	return 0;
}
/** Web service operation '__ns3__CreateActionTriggers' implementation, should return SOAP_OK or error code */
SOAP_FMAC5 int SOAP_FMAC6 __ns3__CreateActionTriggers(struct soap* soap, struct _ns3__CreateActionTriggers *ns3__CreateActionTriggers, struct _ns3__CreateActionTriggersResponse *ns3__CreateActionTriggersResponse)
{
    printf("%s,%d\n",__FUNCTION__, __LINE__);
	return 0;
}
/** Web service operation '__ns3__DeleteActionTriggers' implementation, should return SOAP_OK or error code */
SOAP_FMAC5 int SOAP_FMAC6 __ns3__DeleteActionTriggers(struct soap* soap, struct _ns3__DeleteActionTriggers *ns3__DeleteActionTriggers, struct _ns3__DeleteActionTriggersResponse *ns3__DeleteActionTriggersResponse)
{
    printf("%s,%d\n",__FUNCTION__, __LINE__);
	return 0;
}
/** Web service operation '__ns3__ModifyActionTriggers' implementation, should return SOAP_OK or error code */
SOAP_FMAC5 int SOAP_FMAC6 __ns3__ModifyActionTriggers(struct soap* soap, struct _ns3__ModifyActionTriggers *ns3__ModifyActionTriggers, struct _ns3__ModifyActionTriggersResponse *ns3__ModifyActionTriggersResponse)
{
    printf("%s,%d\n",__FUNCTION__, __LINE__);
	return 0;
}
/** Web service operation '__ns4__GetServiceCapabilities' implementation, should return SOAP_OK or error code */
SOAP_FMAC5 int SOAP_FMAC6 __ns4__GetServiceCapabilities(struct soap* soap, struct _ns4__GetServiceCapabilities *ns4__GetServiceCapabilities, struct _ns4__GetServiceCapabilitiesResponse *ns4__GetServiceCapabilitiesResponse)
{
    printf("%s,%d\n",__FUNCTION__, __LINE__);
	return 0;
}
/** Web service operation '__ns4__GetAccessPointInfoList' implementation, should return SOAP_OK or error code */
SOAP_FMAC5 int SOAP_FMAC6 __ns4__GetAccessPointInfoList(struct soap* soap, struct _ns4__GetAccessPointInfoList *ns4__GetAccessPointInfoList, struct _ns4__GetAccessPointInfoListResponse *ns4__GetAccessPointInfoListResponse)
{
    printf("%s,%d\n",__FUNCTION__, __LINE__);
	return 0;
}
/** Web service operation '__ns4__GetAccessPointInfo' implementation, should return SOAP_OK or error code */
SOAP_FMAC5 int SOAP_FMAC6 __ns4__GetAccessPointInfo(struct soap* soap, struct _ns4__GetAccessPointInfo *ns4__GetAccessPointInfo, struct _ns4__GetAccessPointInfoResponse *ns4__GetAccessPointInfoResponse){
    printf("%s,%d\n",__FUNCTION__, __LINE__);
	return 0;
}
/** Web service operation '__ns4__GetAccessPointList' implementation, should return SOAP_OK or error code */
SOAP_FMAC5 int SOAP_FMAC6 __ns4__GetAccessPointList(struct soap* soap, struct _ns4__GetAccessPointList *ns4__GetAccessPointList, struct _ns4__GetAccessPointListResponse *ns4__GetAccessPointListResponse)
{
    printf("%s,%d\n",__FUNCTION__, __LINE__);
	return 0;
}
/** Web service operation '__ns4__GetAccessPoints' implementation, should return SOAP_OK or error code */
SOAP_FMAC5 int SOAP_FMAC6 __ns4__GetAccessPoints(struct soap* soap, struct _ns4__GetAccessPoints *ns4__GetAccessPoints, struct _ns4__GetAccessPointsResponse *ns4__GetAccessPointsResponse)
{
    printf("%s,%d\n",__FUNCTION__, __LINE__);
	return 0;
}
/** Web service operation '__ns4__CreateAccessPoint' implementation, should return SOAP_OK or error code */
SOAP_FMAC5 int SOAP_FMAC6 __ns4__CreateAccessPoint(struct soap* soap, struct _ns4__CreateAccessPoint *ns4__CreateAccessPoint, struct _ns4__CreateAccessPointResponse *ns4__CreateAccessPointResponse)
{
    printf("%s,%d\n",__FUNCTION__, __LINE__);
	return 0;
}
/** Web service operation '__ns4__SetAccessPoint' implementation, should return SOAP_OK or error code */
SOAP_FMAC5 int SOAP_FMAC6 __ns4__SetAccessPoint(struct soap* soap, struct _ns4__SetAccessPoint *ns4__SetAccessPoint, struct _ns4__SetAccessPointResponse *ns4__SetAccessPointResponse)
{
    printf("%s,%d\n",__FUNCTION__, __LINE__);
	return 0;
}
/** Web service operation '__ns4__ModifyAccessPoint' implementation, should return SOAP_OK or error code */
SOAP_FMAC5 int SOAP_FMAC6 __ns4__ModifyAccessPoint(struct soap* soap, struct _ns4__ModifyAccessPoint *ns4__ModifyAccessPoint, struct _ns4__ModifyAccessPointResponse *ns4__ModifyAccessPointResponse)
{
    printf("%s,%d\n",__FUNCTION__, __LINE__);
	return 0;
}
/** Web service operation '__ns4__DeleteAccessPoint' implementation, should return SOAP_OK or error code */
SOAP_FMAC5 int SOAP_FMAC6 __ns4__DeleteAccessPoint(struct soap* soap, struct _ns4__DeleteAccessPoint *ns4__DeleteAccessPoint, struct _ns4__DeleteAccessPointResponse *ns4__DeleteAccessPointResponse)
{
    printf("%s,%d\n",__FUNCTION__, __LINE__);
	return 0;
}
/** Web service operation '__ns4__SetAccessPointAuthenticationProfile' implementation, should return SOAP_OK or error code */
SOAP_FMAC5 int SOAP_FMAC6 __ns4__SetAccessPointAuthenticationProfile(struct soap* soap, struct _ns4__SetAccessPointAuthenticationProfile *ns4__SetAccessPointAuthenticationProfile, struct _ns4__SetAccessPointAuthenticationProfileResponse *ns4__SetAccessPointAuthenticationProfileResponse)
{
    printf("%s,%d\n",__FUNCTION__, __LINE__);
	return 0;
}
/** Web service operation '__ns4__DeleteAccessPointAuthenticationProfile' implementation, should return SOAP_OK or error code */
SOAP_FMAC5 int SOAP_FMAC6 __ns4__DeleteAccessPointAuthenticationProfile(struct soap* soap, struct _ns4__DeleteAccessPointAuthenticationProfile *ns4__DeleteAccessPointAuthenticationProfile, struct _ns4__DeleteAccessPointAuthenticationProfileResponse *ns4__DeleteAccessPointAuthenticationProfileResponse)
{
    printf("%s,%d\n",__FUNCTION__, __LINE__);
	return 0;
}
/** Web service operation '__ns4__GetAreaInfoList' implementation, should return SOAP_OK or error code */
SOAP_FMAC5 int SOAP_FMAC6 __ns4__GetAreaInfoList(struct soap* soap, struct _ns4__GetAreaInfoList *ns4__GetAreaInfoList, struct _ns4__GetAreaInfoListResponse *ns4__GetAreaInfoListResponse)
{
    printf("%s,%d\n",__FUNCTION__, __LINE__);
	return 0;
}
/** Web service operation '__ns4__GetAreaInfo' implementation, should return SOAP_OK or error code */
SOAP_FMAC5 int SOAP_FMAC6 __ns4__GetAreaInfo(struct soap* soap, struct _ns4__GetAreaInfo *ns4__GetAreaInfo, struct _ns4__GetAreaInfoResponse *ns4__GetAreaInfoResponse)
{
    printf("%s,%d\n",__FUNCTION__, __LINE__);
	return 0;
}
/** Web service operation '__ns4__GetAreaList' implementation, should return SOAP_OK or error code */
SOAP_FMAC5 int SOAP_FMAC6 __ns4__GetAreaList(struct soap* soap, struct _ns4__GetAreaList *ns4__GetAreaList, struct _ns4__GetAreaListResponse *ns4__GetAreaListResponse)
{
    printf("%s,%d\n",__FUNCTION__, __LINE__);
	return 0;
}
/** Web service operation '__ns4__GetAreas' implementation, should return SOAP_OK or error code */
SOAP_FMAC5 int SOAP_FMAC6 __ns4__GetAreas(struct soap* soap, struct _ns4__GetAreas *ns4__GetAreas, struct _ns4__GetAreasResponse *ns4__GetAreasResponse)
{
    printf("%s,%d\n",__FUNCTION__, __LINE__);
	return 0;
}
/** Web service operation '__ns4__CreateArea' implementation, should return SOAP_OK or error code */
SOAP_FMAC5 int SOAP_FMAC6 __ns4__CreateArea(struct soap* soap, struct _ns4__CreateArea *ns4__CreateArea, struct _ns4__CreateAreaResponse *ns4__CreateAreaResponse)
{
    printf("%s,%d\n",__FUNCTION__, __LINE__);
	return 0;
}
/** Web service operation '__ns4__SetArea' implementation, should return SOAP_OK or error code */
SOAP_FMAC5 int SOAP_FMAC6 __ns4__SetArea(struct soap* soap, struct _ns4__SetArea *ns4__SetArea, struct _ns4__SetAreaResponse *ns4__SetAreaResponse)
{
    printf("%s,%d\n",__FUNCTION__, __LINE__);
	return 0;
}
/** Web service operation '__ns4__ModifyArea' implementation, should return SOAP_OK or error code */
SOAP_FMAC5 int SOAP_FMAC6 __ns4__ModifyArea(struct soap* soap, struct _ns4__ModifyArea *ns4__ModifyArea, struct _ns4__ModifyAreaResponse *ns4__ModifyAreaResponse)
{
    printf("%s,%d\n",__FUNCTION__, __LINE__);
	return 0;
}
/** Web service operation '__ns4__DeleteArea' implementation, should return SOAP_OK or error code */
SOAP_FMAC5 int SOAP_FMAC6 __ns4__DeleteArea(struct soap* soap, struct _ns4__DeleteArea *ns4__DeleteArea, struct _ns4__DeleteAreaResponse *ns4__DeleteAreaResponse)
{
    printf("%s,%d\n",__FUNCTION__, __LINE__);
	return 0;
}
/** Web service operation '__ns4__GetAccessPointState' implementation, should return SOAP_OK or error code */
SOAP_FMAC5 int SOAP_FMAC6 __ns4__GetAccessPointState(struct soap* soap, struct _ns4__GetAccessPointState *ns4__GetAccessPointState, struct _ns4__GetAccessPointStateResponse *ns4__GetAccessPointStateResponse)
{
    printf("%s,%d\n",__FUNCTION__, __LINE__);
	return 0;
}
/** Web service operation '__ns4__EnableAccessPoint' implementation, should return SOAP_OK or error code */
SOAP_FMAC5 int SOAP_FMAC6 __ns4__EnableAccessPoint(struct soap* soap, struct _ns4__EnableAccessPoint *ns4__EnableAccessPoint, struct _ns4__EnableAccessPointResponse *ns4__EnableAccessPointResponse)
{
    printf("%s,%d\n",__FUNCTION__, __LINE__);
	return 0;
}
/** Web service operation '__ns4__DisableAccessPoint' implementation, should return SOAP_OK or error code */
SOAP_FMAC5 int SOAP_FMAC6 __ns4__DisableAccessPoint(struct soap* soap, struct _ns4__DisableAccessPoint *ns4__DisableAccessPoint, struct _ns4__DisableAccessPointResponse *ns4__DisableAccessPointResponse)
{
    printf("%s,%d\n",__FUNCTION__, __LINE__);
	return 0;
}
/** Web service operation '__ns4__ExternalAuthorization' implementation, should return SOAP_OK or error code */
SOAP_FMAC5 int SOAP_FMAC6 __ns4__ExternalAuthorization(struct soap* soap, struct _ns4__ExternalAuthorization *ns4__ExternalAuthorization, struct _ns4__ExternalAuthorizationResponse *ns4__ExternalAuthorizationResponse)
{
    printf("%s,%d\n",__FUNCTION__, __LINE__);
	return 0;
}
/** Web service operation '__ns6__GetServiceCapabilities' implementation, should return SOAP_OK or error code */
SOAP_FMAC5 int SOAP_FMAC6 __ns6__GetServiceCapabilities(struct soap* soap, struct _ns6__GetServiceCapabilities *ns6__GetServiceCapabilities, struct _ns6__GetServiceCapabilitiesResponse *ns6__GetServiceCapabilitiesResponse)
{
    printf("%s,%d\n",__FUNCTION__, __LINE__);
	return 0;
}
/** Web service operation '__ns6__GetDoorInfoList' implementation, should return SOAP_OK or error code */
SOAP_FMAC5 int SOAP_FMAC6 __ns6__GetDoorInfoList(struct soap* soap, struct _ns6__GetDoorInfoList *ns6__GetDoorInfoList, struct _ns6__GetDoorInfoListResponse *ns6__GetDoorInfoListResponse)
{
    printf("%s,%d\n",__FUNCTION__, __LINE__);
	return 0;
}
/** Web service operation '__ns6__GetDoorInfo' implementation, should return SOAP_OK or error code */
SOAP_FMAC5 int SOAP_FMAC6 __ns6__GetDoorInfo(struct soap* soap, struct _ns6__GetDoorInfo *ns6__GetDoorInfo, struct _ns6__GetDoorInfoResponse *ns6__GetDoorInfoResponse) { printf("%s,%d\n",__FUNCTION__, __LINE__); return 0; }
/** Web service operation '__ns6__GetDoorList' implementation, should return SOAP_OK or error code */
SOAP_FMAC5 int SOAP_FMAC6 __ns6__GetDoorList(struct soap* soap, struct _ns6__GetDoorList *ns6__GetDoorList, struct _ns6__GetDoorListResponse *ns6__GetDoorListResponse) { printf("%s,%d\n",__FUNCTION__, __LINE__); return 0; }
/** Web service operation '__ns6__GetDoors' implementation, should return SOAP_OK or error code */
SOAP_FMAC5 int SOAP_FMAC6 __ns6__GetDoors(struct soap* soap, struct _ns6__GetDoors *ns6__GetDoors, struct _ns6__GetDoorsResponse *ns6__GetDoorsResponse) { printf("%s,%d\n",__FUNCTION__, __LINE__); return 0; }
/** Web service operation '__ns6__CreateDoor' implementation, should return SOAP_OK or error code */
SOAP_FMAC5 int SOAP_FMAC6 __ns6__CreateDoor(struct soap* soap, struct _ns6__CreateDoor *ns6__CreateDoor, struct _ns6__CreateDoorResponse *ns6__CreateDoorResponse) { printf("%s,%d\n",__FUNCTION__, __LINE__); return 0; }
/** Web service operation '__ns6__SetDoor' implementation, should return SOAP_OK or error code */
SOAP_FMAC5 int SOAP_FMAC6 __ns6__SetDoor(struct soap* soap, struct _ns6__SetDoor *ns6__SetDoor, struct _ns6__SetDoorResponse *ns6__SetDoorResponse) { printf("%s,%d\n",__FUNCTION__, __LINE__); return 0; }
/** Web service operation '__ns6__ModifyDoor' implementation, should return SOAP_OK or error code */
SOAP_FMAC5 int SOAP_FMAC6 __ns6__ModifyDoor(struct soap* soap, struct _ns6__ModifyDoor *ns6__ModifyDoor, struct _ns6__ModifyDoorResponse *ns6__ModifyDoorResponse) { printf("%s,%d\n",__FUNCTION__, __LINE__); return 0; }
/** Web service operation '__ns6__DeleteDoor' implementation, should return SOAP_OK or error code */
SOAP_FMAC5 int SOAP_FMAC6 __ns6__DeleteDoor(struct soap* soap, struct _ns6__DeleteDoor *ns6__DeleteDoor, struct _ns6__DeleteDoorResponse *ns6__DeleteDoorResponse) { printf("%s,%d\n",__FUNCTION__, __LINE__); return 0; }
/** Web service operation '__ns6__GetDoorState' implementation, should return SOAP_OK or error code */
SOAP_FMAC5 int SOAP_FMAC6 __ns6__GetDoorState(struct soap* soap, struct _ns6__GetDoorState *ns6__GetDoorState, struct _ns6__GetDoorStateResponse *ns6__GetDoorStateResponse) { printf("%s,%d\n",__FUNCTION__, __LINE__); return 0; }
/** Web service operation '__ns6__AccessDoor' implementation, should return SOAP_OK or error code */
SOAP_FMAC5 int SOAP_FMAC6 __ns6__AccessDoor(struct soap* soap, struct _ns6__AccessDoor *ns6__AccessDoor, struct _ns6__AccessDoorResponse *ns6__AccessDoorResponse) { printf("%s,%d\n",__FUNCTION__, __LINE__); return 0; }
/** Web service operation '__ns6__LockDoor' implementation, should return SOAP_OK or error code */
SOAP_FMAC5 int SOAP_FMAC6 __ns6__LockDoor(struct soap* soap, struct _ns6__LockDoor *ns6__LockDoor, struct _ns6__LockDoorResponse *ns6__LockDoorResponse) { printf("%s,%d\n",__FUNCTION__, __LINE__); return 0; }
/** Web service operation '__ns6__UnlockDoor' implementation, should return SOAP_OK or error code */
SOAP_FMAC5 int SOAP_FMAC6 __ns6__UnlockDoor(struct soap* soap, struct _ns6__UnlockDoor *ns6__UnlockDoor, struct _ns6__UnlockDoorResponse *ns6__UnlockDoorResponse) { printf("%s,%d\n",__FUNCTION__, __LINE__); return 0; }
/** Web service operation '__ns6__BlockDoor' implementation, should return SOAP_OK or error code */
SOAP_FMAC5 int SOAP_FMAC6 __ns6__BlockDoor(struct soap* soap, struct _ns6__BlockDoor *ns6__BlockDoor, struct _ns6__BlockDoorResponse *ns6__BlockDoorResponse) { printf("%s,%d\n",__FUNCTION__, __LINE__); return 0; }
/** Web service operation '__ns6__LockDownDoor' implementation, should return SOAP_OK or error code */
SOAP_FMAC5 int SOAP_FMAC6 __ns6__LockDownDoor(struct soap* soap, struct _ns6__LockDownDoor *ns6__LockDownDoor, struct _ns6__LockDownDoorResponse *ns6__LockDownDoorResponse) { printf("%s,%d\n",__FUNCTION__, __LINE__); return 0; }
/** Web service operation '__ns6__LockDownReleaseDoor' implementation, should return SOAP_OK or error code */
SOAP_FMAC5 int SOAP_FMAC6 __ns6__LockDownReleaseDoor(struct soap* soap, struct _ns6__LockDownReleaseDoor *ns6__LockDownReleaseDoor, struct _ns6__LockDownReleaseDoorResponse *ns6__LockDownReleaseDoorResponse) { printf("%s,%d\n",__FUNCTION__, __LINE__); return 0; }
/** Web service operation '__ns6__LockOpenDoor' implementation, should return SOAP_OK or error code */
SOAP_FMAC5 int SOAP_FMAC6 __ns6__LockOpenDoor(struct soap* soap, struct _ns6__LockOpenDoor *ns6__LockOpenDoor, struct _ns6__LockOpenDoorResponse *ns6__LockOpenDoorResponse) { printf("%s,%d\n",__FUNCTION__, __LINE__); return 0; }
/** Web service operation '__ns6__LockOpenReleaseDoor' implementation, should return SOAP_OK or error code */
SOAP_FMAC5 int SOAP_FMAC6 __ns6__LockOpenReleaseDoor(struct soap* soap, struct _ns6__LockOpenReleaseDoor *ns6__LockOpenReleaseDoor, struct _ns6__LockOpenReleaseDoorResponse *ns6__LockOpenReleaseDoorResponse) { printf("%s,%d\n",__FUNCTION__, __LINE__); return 0; }
/** Web service operation '__ns6__DoubleLockDoor' implementation, should return SOAP_OK or error code */
SOAP_FMAC5 int SOAP_FMAC6 __ns6__DoubleLockDoor(struct soap* soap, struct _ns6__DoubleLockDoor *ns6__DoubleLockDoor, struct _ns6__DoubleLockDoorResponse *ns6__DoubleLockDoorResponse) { printf("%s,%d\n",__FUNCTION__, __LINE__); return 0; }
/** Web service operation '__tad__GetServiceCapabilities' implementation, should return SOAP_OK or error code */
SOAP_FMAC5 int SOAP_FMAC6 __tad__GetServiceCapabilities(struct soap* soap, struct _tad__GetServiceCapabilities *tad__GetServiceCapabilities, struct _tad__GetServiceCapabilitiesResponse *tad__GetServiceCapabilitiesResponse) { printf("%s,%d\n",__FUNCTION__, __LINE__); return 0; }
/** Web service operation '__tad__DeleteAnalyticsEngineControl' implementation, should return SOAP_OK or error code */
SOAP_FMAC5 int SOAP_FMAC6 __tad__DeleteAnalyticsEngineControl(struct soap* soap, struct _tad__DeleteAnalyticsEngineControl *tad__DeleteAnalyticsEngineControl, struct _tad__DeleteAnalyticsEngineControlResponse *tad__DeleteAnalyticsEngineControlResponse) { printf("%s,%d\n",__FUNCTION__, __LINE__); return 0; }
/** Web service operation '__tad__CreateAnalyticsEngineControl' implementation, should return SOAP_OK or error code */
SOAP_FMAC5 int SOAP_FMAC6 __tad__CreateAnalyticsEngineControl(struct soap* soap, struct _tad__CreateAnalyticsEngineControl *tad__CreateAnalyticsEngineControl, struct _tad__CreateAnalyticsEngineControlResponse *tad__CreateAnalyticsEngineControlResponse) { printf("%s,%d\n",__FUNCTION__, __LINE__); return 0; }
/** Web service operation '__tad__SetAnalyticsEngineControl' implementation, should return SOAP_OK or error code */
SOAP_FMAC5 int SOAP_FMAC6 __tad__SetAnalyticsEngineControl(struct soap* soap, struct _tad__SetAnalyticsEngineControl *tad__SetAnalyticsEngineControl, struct _tad__SetAnalyticsEngineControlResponse *tad__SetAnalyticsEngineControlResponse) { printf("%s,%d\n",__FUNCTION__, __LINE__); return 0; }
/** Web service operation '__tad__GetAnalyticsEngineControl' implementation, should return SOAP_OK or error code */
SOAP_FMAC5 int SOAP_FMAC6 __tad__GetAnalyticsEngineControl(struct soap* soap, struct _tad__GetAnalyticsEngineControl *tad__GetAnalyticsEngineControl, struct _tad__GetAnalyticsEngineControlResponse *tad__GetAnalyticsEngineControlResponse) { printf("%s,%d\n",__FUNCTION__, __LINE__); return 0; }
/** Web service operation '__tad__GetAnalyticsEngineControls' implementation, should return SOAP_OK or error code */
SOAP_FMAC5 int SOAP_FMAC6 __tad__GetAnalyticsEngineControls(struct soap* soap, struct _tad__GetAnalyticsEngineControls *tad__GetAnalyticsEngineControls, struct _tad__GetAnalyticsEngineControlsResponse *tad__GetAnalyticsEngineControlsResponse) { printf("%s,%d\n",__FUNCTION__, __LINE__); return 0; }
/** Web service operation '__tad__GetAnalyticsEngine' implementation, should return SOAP_OK or error code */
SOAP_FMAC5 int SOAP_FMAC6 __tad__GetAnalyticsEngine(struct soap* soap, struct _tad__GetAnalyticsEngine *tad__GetAnalyticsEngine, struct _tad__GetAnalyticsEngineResponse *tad__GetAnalyticsEngineResponse) { printf("%s,%d\n",__FUNCTION__, __LINE__); return 0; }
/** Web service operation '__tad__GetAnalyticsEngines' implementation, should return SOAP_OK or error code */
SOAP_FMAC5 int SOAP_FMAC6 __tad__GetAnalyticsEngines(struct soap* soap, struct _tad__GetAnalyticsEngines *tad__GetAnalyticsEngines, struct _tad__GetAnalyticsEnginesResponse *tad__GetAnalyticsEnginesResponse) { printf("%s,%d\n",__FUNCTION__, __LINE__); return 0; }
/** Web service operation '__tad__SetVideoAnalyticsConfiguration' implementation, should return SOAP_OK or error code */
SOAP_FMAC5 int SOAP_FMAC6 __tad__SetVideoAnalyticsConfiguration(struct soap* soap, struct _tad__SetVideoAnalyticsConfiguration *tad__SetVideoAnalyticsConfiguration, struct _tad__SetVideoAnalyticsConfigurationResponse *tad__SetVideoAnalyticsConfigurationResponse) { printf("%s,%d\n",__FUNCTION__, __LINE__); return 0; }
/** Web service operation '__tad__SetAnalyticsEngineInput' implementation, should return SOAP_OK or error code */
SOAP_FMAC5 int SOAP_FMAC6 __tad__SetAnalyticsEngineInput(struct soap* soap, struct _tad__SetAnalyticsEngineInput *tad__SetAnalyticsEngineInput, struct _tad__SetAnalyticsEngineInputResponse *tad__SetAnalyticsEngineInputResponse) { printf("%s,%d\n",__FUNCTION__, __LINE__); return 0; }
/** Web service operation '__tad__GetAnalyticsEngineInput' implementation, should return SOAP_OK or error code */
SOAP_FMAC5 int SOAP_FMAC6 __tad__GetAnalyticsEngineInput(struct soap* soap, struct _tad__GetAnalyticsEngineInput *tad__GetAnalyticsEngineInput, struct _tad__GetAnalyticsEngineInputResponse *tad__GetAnalyticsEngineInputResponse) { printf("%s,%d\n",__FUNCTION__, __LINE__); return 0; }
/** Web service operation '__tad__GetAnalyticsEngineInputs' implementation, should return SOAP_OK or error code */
SOAP_FMAC5 int SOAP_FMAC6 __tad__GetAnalyticsEngineInputs(struct soap* soap, struct _tad__GetAnalyticsEngineInputs *tad__GetAnalyticsEngineInputs, struct _tad__GetAnalyticsEngineInputsResponse *tad__GetAnalyticsEngineInputsResponse) { printf("%s,%d\n",__FUNCTION__, __LINE__); return 0; }
/** Web service operation '__tad__GetAnalyticsDeviceStreamUri' implementation, should return SOAP_OK or error code */
SOAP_FMAC5 int SOAP_FMAC6 __tad__GetAnalyticsDeviceStreamUri(struct soap* soap, struct _tad__GetAnalyticsDeviceStreamUri *tad__GetAnalyticsDeviceStreamUri, struct _tad__GetAnalyticsDeviceStreamUriResponse *tad__GetAnalyticsDeviceStreamUriResponse) { printf("%s,%d\n",__FUNCTION__, __LINE__); return 0; }
/** Web service operation '__tad__GetVideoAnalyticsConfiguration' implementation, should return SOAP_OK or error code */
SOAP_FMAC5 int SOAP_FMAC6 __tad__GetVideoAnalyticsConfiguration(struct soap* soap, struct _tad__GetVideoAnalyticsConfiguration *tad__GetVideoAnalyticsConfiguration, struct _tad__GetVideoAnalyticsConfigurationResponse *tad__GetVideoAnalyticsConfigurationResponse) { printf("%s,%d\n",__FUNCTION__, __LINE__); return 0; }
/** Web service operation '__tad__CreateAnalyticsEngineInputs' implementation, should return SOAP_OK or error code */
SOAP_FMAC5 int SOAP_FMAC6 __tad__CreateAnalyticsEngineInputs(struct soap* soap, struct _tad__CreateAnalyticsEngineInputs *tad__CreateAnalyticsEngineInputs, struct _tad__CreateAnalyticsEngineInputsResponse *tad__CreateAnalyticsEngineInputsResponse) { printf("%s,%d\n",__FUNCTION__, __LINE__); return 0; }
/** Web service operation '__tad__DeleteAnalyticsEngineInputs' implementation, should return SOAP_OK or error code */
SOAP_FMAC5 int SOAP_FMAC6 __tad__DeleteAnalyticsEngineInputs(struct soap* soap, struct _tad__DeleteAnalyticsEngineInputs *tad__DeleteAnalyticsEngineInputs, struct _tad__DeleteAnalyticsEngineInputsResponse *tad__DeleteAnalyticsEngineInputsResponse) { printf("%s,%d\n",__FUNCTION__, __LINE__); return 0; }
/** Web service operation '__tad__GetAnalyticsState' implementation, should return SOAP_OK or error code */
SOAP_FMAC5 int SOAP_FMAC6 __tad__GetAnalyticsState(struct soap* soap, struct _tad__GetAnalyticsState *tad__GetAnalyticsState, struct _tad__GetAnalyticsStateResponse *tad__GetAnalyticsStateResponse) { printf("%s,%d\n",__FUNCTION__, __LINE__); return 0; }
/** Web service operation '__tan__GetSupportedRules' implementation, should return SOAP_OK or error code */
SOAP_FMAC5 int SOAP_FMAC6 __tan__GetSupportedRules(struct soap* soap, struct _tan__GetSupportedRules *tan__GetSupportedRules, struct _tan__GetSupportedRulesResponse *tan__GetSupportedRulesResponse) { printf("%s,%d\n",__FUNCTION__, __LINE__); return 0; }
/** Web service operation '__tan__CreateRules' implementation, should return SOAP_OK or error code */
SOAP_FMAC5 int SOAP_FMAC6 __tan__CreateRules(struct soap* soap, struct _tan__CreateRules *tan__CreateRules, struct _tan__CreateRulesResponse *tan__CreateRulesResponse) { printf("%s,%d\n",__FUNCTION__, __LINE__); return 0; }
/** Web service operation '__tan__DeleteRules' implementation, should return SOAP_OK or error code */
SOAP_FMAC5 int SOAP_FMAC6 __tan__DeleteRules(struct soap* soap, struct _tan__DeleteRules *tan__DeleteRules, struct _tan__DeleteRulesResponse *tan__DeleteRulesResponse) { printf("%s,%d\n",__FUNCTION__, __LINE__); return 0; }
/** Web service operation '__tan__GetRules' implementation, should return SOAP_OK or error code */
SOAP_FMAC5 int SOAP_FMAC6 __tan__GetRules(struct soap* soap, struct _tan__GetRules *tan__GetRules, struct _tan__GetRulesResponse *tan__GetRulesResponse) { printf("%s,%d\n",__FUNCTION__, __LINE__); return 0; }
/** Web service operation '__tan__GetRuleOptions' implementation, should return SOAP_OK or error code */
SOAP_FMAC5 int SOAP_FMAC6 __tan__GetRuleOptions(struct soap* soap, struct _tan__GetRuleOptions *tan__GetRuleOptions, struct _tan__GetRuleOptionsResponse *tan__GetRuleOptionsResponse) { printf("%s,%d\n",__FUNCTION__, __LINE__); return 0; }
/** Web service operation '__tan__ModifyRules' implementation, should return SOAP_OK or error code */
SOAP_FMAC5 int SOAP_FMAC6 __tan__ModifyRules(struct soap* soap, struct _tan__ModifyRules *tan__ModifyRules, struct _tan__ModifyRulesResponse *tan__ModifyRulesResponse) { printf("%s,%d\n",__FUNCTION__, __LINE__); return 0; }
/** Web service operation '__tan__GetServiceCapabilities' implementation, should return SOAP_OK or error code */
SOAP_FMAC5 int SOAP_FMAC6 __tan__GetServiceCapabilities(struct soap* soap, struct _tan__GetServiceCapabilities *tan__GetServiceCapabilities, struct _tan__GetServiceCapabilitiesResponse *tan__GetServiceCapabilitiesResponse) { printf("%s,%d\n",__FUNCTION__, __LINE__); return 0; }
/** Web service operation '__tan__GetSupportedAnalyticsModules' implementation, should return SOAP_OK or error code */
SOAP_FMAC5 int SOAP_FMAC6 __tan__GetSupportedAnalyticsModules(struct soap* soap, struct _tan__GetSupportedAnalyticsModules *tan__GetSupportedAnalyticsModules, struct _tan__GetSupportedAnalyticsModulesResponse *tan__GetSupportedAnalyticsModulesResponse) { printf("%s,%d\n",__FUNCTION__, __LINE__); return 0; }
/** Web service operation '__tan__CreateAnalyticsModules' implementation, should return SOAP_OK or error code */
SOAP_FMAC5 int SOAP_FMAC6 __tan__CreateAnalyticsModules(struct soap* soap, struct _tan__CreateAnalyticsModules *tan__CreateAnalyticsModules, struct _tan__CreateAnalyticsModulesResponse *tan__CreateAnalyticsModulesResponse) { printf("%s,%d\n",__FUNCTION__, __LINE__); return 0; }
/** Web service operation '__tan__DeleteAnalyticsModules' implementation, should return SOAP_OK or error code */
SOAP_FMAC5 int SOAP_FMAC6 __tan__DeleteAnalyticsModules(struct soap* soap, struct _tan__DeleteAnalyticsModules *tan__DeleteAnalyticsModules, struct _tan__DeleteAnalyticsModulesResponse *tan__DeleteAnalyticsModulesResponse) { printf("%s,%d\n",__FUNCTION__, __LINE__); return 0; }
/** Web service operation '__tan__GetAnalyticsModules' implementation, should return SOAP_OK or error code */
SOAP_FMAC5 int SOAP_FMAC6 __tan__GetAnalyticsModules(struct soap* soap, struct _tan__GetAnalyticsModules *tan__GetAnalyticsModules, struct _tan__GetAnalyticsModulesResponse *tan__GetAnalyticsModulesResponse) { printf("%s,%d\n",__FUNCTION__, __LINE__); return 0; }
/** Web service operation '__tan__GetAnalyticsModuleOptions' implementation, should return SOAP_OK or error code */
SOAP_FMAC5 int SOAP_FMAC6 __tan__GetAnalyticsModuleOptions(struct soap* soap, struct _tan__GetAnalyticsModuleOptions *tan__GetAnalyticsModuleOptions, struct _tan__GetAnalyticsModuleOptionsResponse *tan__GetAnalyticsModuleOptionsResponse) { printf("%s,%d\n",__FUNCTION__, __LINE__); return 0; }
/** Web service operation '__tan__ModifyAnalyticsModules' implementation, should return SOAP_OK or error code */
SOAP_FMAC5 int SOAP_FMAC6 __tan__ModifyAnalyticsModules(struct soap* soap, struct _tan__ModifyAnalyticsModules *tan__ModifyAnalyticsModules, struct _tan__ModifyAnalyticsModulesResponse *tan__ModifyAnalyticsModulesResponse) { printf("%s,%d\n",__FUNCTION__, __LINE__); return 0; }
/** Web service operation '__tan__GetSupportedMetadata' implementation, should return SOAP_OK or error code */
SOAP_FMAC5 int SOAP_FMAC6 __tan__GetSupportedMetadata(struct soap* soap, struct _tan__GetSupportedMetadata *tan__GetSupportedMetadata, struct _tan__GetSupportedMetadataResponse *tan__GetSupportedMetadataResponse) { printf("%s,%d\n",__FUNCTION__, __LINE__); return 0; }
/** Web service operation '__tdn__Hello' implementation, should return SOAP_OK or error code */
SOAP_FMAC5 int SOAP_FMAC6 __tdn__Hello(struct soap* soap, struct wsdd__HelloType tdn__Hello, struct wsdd__ResolveType *tdn__HelloResponse) { printf("%s,%d\n",__FUNCTION__, __LINE__); return 0; }
/** Web service operation '__tdn__Bye' implementation, should return SOAP_OK or error code */
SOAP_FMAC5 int SOAP_FMAC6 __tdn__Bye(struct soap* soap, struct wsdd__ByeType tdn__Bye, struct wsdd__ResolveType *tdn__ByeResponse) { printf("%s,%d\n",__FUNCTION__, __LINE__); return 0; }
/** Web service operation '__tdn__Probe' implementation, should return SOAP_OK or error code */
SOAP_FMAC5 int SOAP_FMAC6 __tdn__Probe(struct soap* soap, struct wsdd__ProbeType tdn__Probe, struct wsdd__ProbeMatchesType *tdn__ProbeResponse) { printf("%s,%d\n",__FUNCTION__, __LINE__); return 0; }
/** Web service operation '__tds__GetServices' implementation, should return SOAP_OK or error code */
SOAP_FMAC5 int SOAP_FMAC6 __tds__GetServices(struct soap* soap, struct _tds__GetServices *tds__GetServices, struct _tds__GetServicesResponse *tds__GetServicesResponse) { printf("%s,%d\n",__FUNCTION__, __LINE__); return 0; }
/** Web service operation '__tds__GetServiceCapabilities' implementation, should return SOAP_OK or error code */
SOAP_FMAC5 int SOAP_FMAC6 __tds__GetServiceCapabilities(struct soap* soap, struct _tds__GetServiceCapabilities *tds__GetServiceCapabilities, struct _tds__GetServiceCapabilitiesResponse *tds__GetServiceCapabilitiesResponse) { printf("%s,%d\n",__FUNCTION__, __LINE__); return 0; }
/** Web service operation '__tds__GetDeviceInformation' implementation, should return SOAP_OK or error code */
SOAP_FMAC5 int SOAP_FMAC6 __tds__GetDeviceInformation(struct soap* soap, struct _tds__GetDeviceInformation *tds__GetDeviceInformation, struct _tds__GetDeviceInformationResponse *tds__GetDeviceInformationResponse) { printf("%s,%d\n",__FUNCTION__, __LINE__); return 0; }
/** Web service operation '__tds__SetSystemDateAndTime' implementation, should return SOAP_OK or error code */
SOAP_FMAC5 int SOAP_FMAC6 __tds__SetSystemDateAndTime(struct soap* soap, struct _tds__SetSystemDateAndTime *tds__SetSystemDateAndTime, struct _tds__SetSystemDateAndTimeResponse *tds__SetSystemDateAndTimeResponse) { printf("%s,%d\n",__FUNCTION__, __LINE__); return 0; }
/** Web service operation '__tds__GetSystemDateAndTime' implementation, should return SOAP_OK or error code */
SOAP_FMAC5 int SOAP_FMAC6 __tds__GetSystemDateAndTime(struct soap* soap, struct _tds__GetSystemDateAndTime *tds__GetSystemDateAndTime, struct _tds__GetSystemDateAndTimeResponse *tds__GetSystemDateAndTimeResponse) { printf("%s,%d\n",__FUNCTION__, __LINE__); return 0; }
/** Web service operation '__tds__SetSystemFactoryDefault' implementation, should return SOAP_OK or error code */
SOAP_FMAC5 int SOAP_FMAC6 __tds__SetSystemFactoryDefault(struct soap* soap, struct _tds__SetSystemFactoryDefault *tds__SetSystemFactoryDefault, struct _tds__SetSystemFactoryDefaultResponse *tds__SetSystemFactoryDefaultResponse) { printf("%s,%d\n",__FUNCTION__, __LINE__); return 0; }
/** Web service operation '__tds__UpgradeSystemFirmware' implementation, should return SOAP_OK or error code */
SOAP_FMAC5 int SOAP_FMAC6 __tds__UpgradeSystemFirmware(struct soap* soap, struct _tds__UpgradeSystemFirmware *tds__UpgradeSystemFirmware, struct _tds__UpgradeSystemFirmwareResponse *tds__UpgradeSystemFirmwareResponse) { printf("%s,%d\n",__FUNCTION__, __LINE__); return 0; }
/** Web service operation '__tds__SystemReboot' implementation, should return SOAP_OK or error code */
SOAP_FMAC5 int SOAP_FMAC6 __tds__SystemReboot(struct soap* soap, struct _tds__SystemReboot *tds__SystemReboot, struct _tds__SystemRebootResponse *tds__SystemRebootResponse) { printf("%s,%d\n",__FUNCTION__, __LINE__); return 0; }
/** Web service operation '__tds__RestoreSystem' implementation, should return SOAP_OK or error code */
SOAP_FMAC5 int SOAP_FMAC6 __tds__RestoreSystem(struct soap* soap, struct _tds__RestoreSystem *tds__RestoreSystem, struct _tds__RestoreSystemResponse *tds__RestoreSystemResponse) { printf("%s,%d\n",__FUNCTION__, __LINE__); return 0; }
/** Web service operation '__tds__GetSystemBackup' implementation, should return SOAP_OK or error code */
SOAP_FMAC5 int SOAP_FMAC6 __tds__GetSystemBackup(struct soap* soap, struct _tds__GetSystemBackup *tds__GetSystemBackup, struct _tds__GetSystemBackupResponse *tds__GetSystemBackupResponse) { printf("%s,%d\n",__FUNCTION__, __LINE__); return 0; }
/** Web service operation '__tds__GetSystemLog' implementation, should return SOAP_OK or error code */
SOAP_FMAC5 int SOAP_FMAC6 __tds__GetSystemLog(struct soap* soap, struct _tds__GetSystemLog *tds__GetSystemLog, struct _tds__GetSystemLogResponse *tds__GetSystemLogResponse) { printf("%s,%d\n",__FUNCTION__, __LINE__); return 0; }
/** Web service operation '__tds__GetSystemSupportInformation' implementation, should return SOAP_OK or error code */
SOAP_FMAC5 int SOAP_FMAC6 __tds__GetSystemSupportInformation(struct soap* soap, struct _tds__GetSystemSupportInformation *tds__GetSystemSupportInformation, struct _tds__GetSystemSupportInformationResponse *tds__GetSystemSupportInformationResponse) { printf("%s,%d\n",__FUNCTION__, __LINE__); return 0; }
/** Web service operation '__tds__GetScopes' implementation, should return SOAP_OK or error code */
SOAP_FMAC5 int SOAP_FMAC6 __tds__GetScopes(struct soap* soap, struct _tds__GetScopes *tds__GetScopes, struct _tds__GetScopesResponse *tds__GetScopesResponse) { printf("%s,%d\n",__FUNCTION__, __LINE__); return 0; }
/** Web service operation '__tds__SetScopes' implementation, should return SOAP_OK or error code */
SOAP_FMAC5 int SOAP_FMAC6 __tds__SetScopes(struct soap* soap, struct _tds__SetScopes *tds__SetScopes, struct _tds__SetScopesResponse *tds__SetScopesResponse) { printf("%s,%d\n",__FUNCTION__, __LINE__); return 0; }
/** Web service operation '__tds__AddScopes' implementation, should return SOAP_OK or error code */
SOAP_FMAC5 int SOAP_FMAC6 __tds__AddScopes(struct soap* soap, struct _tds__AddScopes *tds__AddScopes, struct _tds__AddScopesResponse *tds__AddScopesResponse) { printf("%s,%d\n",__FUNCTION__, __LINE__); return 0; }
/** Web service operation '__tds__RemoveScopes' implementation, should return SOAP_OK or error code */
SOAP_FMAC5 int SOAP_FMAC6 __tds__RemoveScopes(struct soap* soap, struct _tds__RemoveScopes *tds__RemoveScopes, struct _tds__RemoveScopesResponse *tds__RemoveScopesResponse) { printf("%s,%d\n",__FUNCTION__, __LINE__); return 0; }
/** Web service operation '__tds__GetDiscoveryMode' implementation, should return SOAP_OK or error code */
SOAP_FMAC5 int SOAP_FMAC6 __tds__GetDiscoveryMode(struct soap* soap, struct _tds__GetDiscoveryMode *tds__GetDiscoveryMode, struct _tds__GetDiscoveryModeResponse *tds__GetDiscoveryModeResponse) { printf("%s,%d\n",__FUNCTION__, __LINE__); return 0; }
/** Web service operation '__tds__SetDiscoveryMode' implementation, should return SOAP_OK or error code */
SOAP_FMAC5 int SOAP_FMAC6 __tds__SetDiscoveryMode(struct soap* soap, struct _tds__SetDiscoveryMode *tds__SetDiscoveryMode, struct _tds__SetDiscoveryModeResponse *tds__SetDiscoveryModeResponse) { printf("%s,%d\n",__FUNCTION__, __LINE__); return 0; }
/** Web service operation '__tds__GetRemoteDiscoveryMode' implementation, should return SOAP_OK or error code */
SOAP_FMAC5 int SOAP_FMAC6 __tds__GetRemoteDiscoveryMode(struct soap* soap, struct _tds__GetRemoteDiscoveryMode *tds__GetRemoteDiscoveryMode, struct _tds__GetRemoteDiscoveryModeResponse *tds__GetRemoteDiscoveryModeResponse) { printf("%s,%d\n",__FUNCTION__, __LINE__); return 0; }
/** Web service operation '__tds__SetRemoteDiscoveryMode' implementation, should return SOAP_OK or error code */
SOAP_FMAC5 int SOAP_FMAC6 __tds__SetRemoteDiscoveryMode(struct soap* soap, struct _tds__SetRemoteDiscoveryMode *tds__SetRemoteDiscoveryMode, struct _tds__SetRemoteDiscoveryModeResponse *tds__SetRemoteDiscoveryModeResponse) { printf("%s,%d\n",__FUNCTION__, __LINE__); return 0; }
/** Web service operation '__tds__GetDPAddresses' implementation, should return SOAP_OK or error code */
SOAP_FMAC5 int SOAP_FMAC6 __tds__GetDPAddresses(struct soap* soap, struct _tds__GetDPAddresses *tds__GetDPAddresses, struct _tds__GetDPAddressesResponse *tds__GetDPAddressesResponse) { printf("%s,%d\n",__FUNCTION__, __LINE__); return 0; }
/** Web service operation '__tds__GetEndpointReference' implementation, should return SOAP_OK or error code */
SOAP_FMAC5 int SOAP_FMAC6 __tds__GetEndpointReference(struct soap* soap, struct _tds__GetEndpointReference *tds__GetEndpointReference, struct _tds__GetEndpointReferenceResponse *tds__GetEndpointReferenceResponse) { printf("%s,%d\n",__FUNCTION__, __LINE__); return 0; }
/** Web service operation '__tds__GetRemoteUser' implementation, should return SOAP_OK or error code */
SOAP_FMAC5 int SOAP_FMAC6 __tds__GetRemoteUser(struct soap* soap, struct _tds__GetRemoteUser *tds__GetRemoteUser, struct _tds__GetRemoteUserResponse *tds__GetRemoteUserResponse) { printf("%s,%d\n",__FUNCTION__, __LINE__); return 0; }
/** Web service operation '__tds__SetRemoteUser' implementation, should return SOAP_OK or error code */
SOAP_FMAC5 int SOAP_FMAC6 __tds__SetRemoteUser(struct soap* soap, struct _tds__SetRemoteUser *tds__SetRemoteUser, struct _tds__SetRemoteUserResponse *tds__SetRemoteUserResponse) { printf("%s,%d\n",__FUNCTION__, __LINE__); return 0; }
/** Web service operation '__tds__GetUsers' implementation, should return SOAP_OK or error code */
SOAP_FMAC5 int SOAP_FMAC6 __tds__GetUsers(struct soap* soap, struct _tds__GetUsers *tds__GetUsers, struct _tds__GetUsersResponse *tds__GetUsersResponse) { printf("%s,%d\n",__FUNCTION__, __LINE__); return 0; }
/** Web service operation '__tds__CreateUsers' implementation, should return SOAP_OK or error code */
SOAP_FMAC5 int SOAP_FMAC6 __tds__CreateUsers(struct soap* soap, struct _tds__CreateUsers *tds__CreateUsers, struct _tds__CreateUsersResponse *tds__CreateUsersResponse) { printf("%s,%d\n",__FUNCTION__, __LINE__); return 0; }
/** Web service operation '__tds__DeleteUsers' implementation, should return SOAP_OK or error code */
SOAP_FMAC5 int SOAP_FMAC6 __tds__DeleteUsers(struct soap* soap, struct _tds__DeleteUsers *tds__DeleteUsers, struct _tds__DeleteUsersResponse *tds__DeleteUsersResponse) { printf("%s,%d\n",__FUNCTION__, __LINE__); return 0; }
/** Web service operation '__tds__SetUser' implementation, should return SOAP_OK or error code */
SOAP_FMAC5 int SOAP_FMAC6 __tds__SetUser(struct soap* soap, struct _tds__SetUser *tds__SetUser, struct _tds__SetUserResponse *tds__SetUserResponse) { printf("%s,%d\n",__FUNCTION__, __LINE__); return 0; }
/** Web service operation '__tds__GetWsdlUrl' implementation, should return SOAP_OK or error code */
SOAP_FMAC5 int SOAP_FMAC6 __tds__GetWsdlUrl(struct soap* soap, struct _tds__GetWsdlUrl *tds__GetWsdlUrl, struct _tds__GetWsdlUrlResponse *tds__GetWsdlUrlResponse) { printf("%s,%d\n",__FUNCTION__, __LINE__); return 0; }
/** Web service operation '__tds__GetCapabilities' implementation, should return SOAP_OK or error code */
SOAP_FMAC5 int SOAP_FMAC6 __tds__GetCapabilities(struct soap* soap, struct _tds__GetCapabilities *tds__GetCapabilities, struct _tds__GetCapabilitiesResponse *tds__GetCapabilitiesResponse) { printf("%s,%d\n",__FUNCTION__, __LINE__); return 0; }
/** Web service operation '__tds__SetDPAddresses' implementation, should return SOAP_OK or error code */
SOAP_FMAC5 int SOAP_FMAC6 __tds__SetDPAddresses(struct soap* soap, struct _tds__SetDPAddresses *tds__SetDPAddresses, struct _tds__SetDPAddressesResponse *tds__SetDPAddressesResponse) { printf("%s,%d\n",__FUNCTION__, __LINE__); return 0; }
/** Web service operation '__tds__GetHostname' implementation, should return SOAP_OK or error code */
SOAP_FMAC5 int SOAP_FMAC6 __tds__GetHostname(struct soap* soap, struct _tds__GetHostname *tds__GetHostname, struct _tds__GetHostnameResponse *tds__GetHostnameResponse) { printf("%s,%d\n",__FUNCTION__, __LINE__); return 0; }
/** Web service operation '__tds__SetHostname' implementation, should return SOAP_OK or error code */
SOAP_FMAC5 int SOAP_FMAC6 __tds__SetHostname(struct soap* soap, struct _tds__SetHostname *tds__SetHostname, struct _tds__SetHostnameResponse *tds__SetHostnameResponse) { printf("%s,%d\n",__FUNCTION__, __LINE__); return 0; }
/** Web service operation '__tds__SetHostnameFromDHCP' implementation, should return SOAP_OK or error code */
SOAP_FMAC5 int SOAP_FMAC6 __tds__SetHostnameFromDHCP(struct soap* soap, struct _tds__SetHostnameFromDHCP *tds__SetHostnameFromDHCP, struct _tds__SetHostnameFromDHCPResponse *tds__SetHostnameFromDHCPResponse) { printf("%s,%d\n",__FUNCTION__, __LINE__); return 0; }
/** Web service operation '__tds__GetDNS' implementation, should return SOAP_OK or error code */
SOAP_FMAC5 int SOAP_FMAC6 __tds__GetDNS(struct soap* soap, struct _tds__GetDNS *tds__GetDNS, struct _tds__GetDNSResponse *tds__GetDNSResponse) { printf("%s,%d\n",__FUNCTION__, __LINE__); return 0; }
/** Web service operation '__tds__SetDNS' implementation, should return SOAP_OK or error code */
SOAP_FMAC5 int SOAP_FMAC6 __tds__SetDNS(struct soap* soap, struct _tds__SetDNS *tds__SetDNS, struct _tds__SetDNSResponse *tds__SetDNSResponse) { printf("%s,%d\n",__FUNCTION__, __LINE__); return 0; }
/** Web service operation '__tds__GetNTP' implementation, should return SOAP_OK or error code */
SOAP_FMAC5 int SOAP_FMAC6 __tds__GetNTP(struct soap* soap, struct _tds__GetNTP *tds__GetNTP, struct _tds__GetNTPResponse *tds__GetNTPResponse) { printf("%s,%d\n",__FUNCTION__, __LINE__); return 0; }
/** Web service operation '__tds__SetNTP' implementation, should return SOAP_OK or error code */
SOAP_FMAC5 int SOAP_FMAC6 __tds__SetNTP(struct soap* soap, struct _tds__SetNTP *tds__SetNTP, struct _tds__SetNTPResponse *tds__SetNTPResponse) { printf("%s,%d\n",__FUNCTION__, __LINE__); return 0; }
/** Web service operation '__tds__GetDynamicDNS' implementation, should return SOAP_OK or error code */
SOAP_FMAC5 int SOAP_FMAC6 __tds__GetDynamicDNS(struct soap* soap, struct _tds__GetDynamicDNS *tds__GetDynamicDNS, struct _tds__GetDynamicDNSResponse *tds__GetDynamicDNSResponse) { printf("%s,%d\n",__FUNCTION__, __LINE__); return 0; }
/** Web service operation '__tds__SetDynamicDNS' implementation, should return SOAP_OK or error code */
SOAP_FMAC5 int SOAP_FMAC6 __tds__SetDynamicDNS(struct soap* soap, struct _tds__SetDynamicDNS *tds__SetDynamicDNS, struct _tds__SetDynamicDNSResponse *tds__SetDynamicDNSResponse) { printf("%s,%d\n",__FUNCTION__, __LINE__); return 0; }
/** Web service operation '__tds__GetNetworkInterfaces' implementation, should return SOAP_OK or error code */
SOAP_FMAC5 int SOAP_FMAC6 __tds__GetNetworkInterfaces(struct soap* soap, struct _tds__GetNetworkInterfaces *tds__GetNetworkInterfaces, struct _tds__GetNetworkInterfacesResponse *tds__GetNetworkInterfacesResponse) { printf("%s,%d\n",__FUNCTION__, __LINE__); return 0; }
/** Web service operation '__tds__SetNetworkInterfaces' implementation, should return SOAP_OK or error code */
SOAP_FMAC5 int SOAP_FMAC6 __tds__SetNetworkInterfaces(struct soap* soap, struct _tds__SetNetworkInterfaces *tds__SetNetworkInterfaces, struct _tds__SetNetworkInterfacesResponse *tds__SetNetworkInterfacesResponse) { printf("%s,%d\n",__FUNCTION__, __LINE__); return 0; }
/** Web service operation '__tds__GetNetworkProtocols' implementation, should return SOAP_OK or error code */
SOAP_FMAC5 int SOAP_FMAC6 __tds__GetNetworkProtocols(struct soap* soap, struct _tds__GetNetworkProtocols *tds__GetNetworkProtocols, struct _tds__GetNetworkProtocolsResponse *tds__GetNetworkProtocolsResponse) { printf("%s,%d\n",__FUNCTION__, __LINE__); return 0; }
/** Web service operation '__tds__SetNetworkProtocols' implementation, should return SOAP_OK or error code */
SOAP_FMAC5 int SOAP_FMAC6 __tds__SetNetworkProtocols(struct soap* soap, struct _tds__SetNetworkProtocols *tds__SetNetworkProtocols, struct _tds__SetNetworkProtocolsResponse *tds__SetNetworkProtocolsResponse) { printf("%s,%d\n",__FUNCTION__, __LINE__); return 0; }
/** Web service operation '__tds__GetNetworkDefaultGateway' implementation, should return SOAP_OK or error code */
SOAP_FMAC5 int SOAP_FMAC6 __tds__GetNetworkDefaultGateway(struct soap* soap, struct _tds__GetNetworkDefaultGateway *tds__GetNetworkDefaultGateway, struct _tds__GetNetworkDefaultGatewayResponse *tds__GetNetworkDefaultGatewayResponse) { printf("%s,%d\n",__FUNCTION__, __LINE__); return 0; }
/** Web service operation '__tds__SetNetworkDefaultGateway' implementation, should return SOAP_OK or error code */
SOAP_FMAC5 int SOAP_FMAC6 __tds__SetNetworkDefaultGateway(struct soap* soap, struct _tds__SetNetworkDefaultGateway *tds__SetNetworkDefaultGateway, struct _tds__SetNetworkDefaultGatewayResponse *tds__SetNetworkDefaultGatewayResponse) { printf("%s,%d\n",__FUNCTION__, __LINE__); return 0; }
/** Web service operation '__tds__GetZeroConfiguration' implementation, should return SOAP_OK or error code */
SOAP_FMAC5 int SOAP_FMAC6 __tds__GetZeroConfiguration(struct soap* soap, struct _tds__GetZeroConfiguration *tds__GetZeroConfiguration, struct _tds__GetZeroConfigurationResponse *tds__GetZeroConfigurationResponse) { printf("%s,%d\n",__FUNCTION__, __LINE__); return 0; }
/** Web service operation '__tds__SetZeroConfiguration' implementation, should return SOAP_OK or error code */
SOAP_FMAC5 int SOAP_FMAC6 __tds__SetZeroConfiguration(struct soap* soap, struct _tds__SetZeroConfiguration *tds__SetZeroConfiguration, struct _tds__SetZeroConfigurationResponse *tds__SetZeroConfigurationResponse) { printf("%s,%d\n",__FUNCTION__, __LINE__); return 0; }
/** Web service operation '__tds__GetIPAddressFilter' implementation, should return SOAP_OK or error code */
SOAP_FMAC5 int SOAP_FMAC6 __tds__GetIPAddressFilter(struct soap* soap, struct _tds__GetIPAddressFilter *tds__GetIPAddressFilter, struct _tds__GetIPAddressFilterResponse *tds__GetIPAddressFilterResponse) { printf("%s,%d\n",__FUNCTION__, __LINE__); return 0; }
/** Web service operation '__tds__SetIPAddressFilter' implementation, should return SOAP_OK or error code */
SOAP_FMAC5 int SOAP_FMAC6 __tds__SetIPAddressFilter(struct soap* soap, struct _tds__SetIPAddressFilter *tds__SetIPAddressFilter, struct _tds__SetIPAddressFilterResponse *tds__SetIPAddressFilterResponse) { printf("%s,%d\n",__FUNCTION__, __LINE__); return 0; }
/** Web service operation '__tds__AddIPAddressFilter' implementation, should return SOAP_OK or error code */
SOAP_FMAC5 int SOAP_FMAC6 __tds__AddIPAddressFilter(struct soap* soap, struct _tds__AddIPAddressFilter *tds__AddIPAddressFilter, struct _tds__AddIPAddressFilterResponse *tds__AddIPAddressFilterResponse) { printf("%s,%d\n",__FUNCTION__, __LINE__); return 0; }
/** Web service operation '__tds__RemoveIPAddressFilter' implementation, should return SOAP_OK or error code */
SOAP_FMAC5 int SOAP_FMAC6 __tds__RemoveIPAddressFilter(struct soap* soap, struct _tds__RemoveIPAddressFilter *tds__RemoveIPAddressFilter, struct _tds__RemoveIPAddressFilterResponse *tds__RemoveIPAddressFilterResponse) { printf("%s,%d\n",__FUNCTION__, __LINE__); return 0; }
/** Web service operation '__tds__GetAccessPolicy' implementation, should return SOAP_OK or error code */
SOAP_FMAC5 int SOAP_FMAC6 __tds__GetAccessPolicy(struct soap* soap, struct _tds__GetAccessPolicy *tds__GetAccessPolicy, struct _tds__GetAccessPolicyResponse *tds__GetAccessPolicyResponse) { printf("%s,%d\n",__FUNCTION__, __LINE__); return 0; }
/** Web service operation '__tds__SetAccessPolicy' implementation, should return SOAP_OK or error code */
SOAP_FMAC5 int SOAP_FMAC6 __tds__SetAccessPolicy(struct soap* soap, struct _tds__SetAccessPolicy *tds__SetAccessPolicy, struct _tds__SetAccessPolicyResponse *tds__SetAccessPolicyResponse) { printf("%s,%d\n",__FUNCTION__, __LINE__); return 0; }
/** Web service operation '__tds__CreateCertificate' implementation, should return SOAP_OK or error code */
SOAP_FMAC5 int SOAP_FMAC6 __tds__CreateCertificate(struct soap* soap, struct _tds__CreateCertificate *tds__CreateCertificate, struct _tds__CreateCertificateResponse *tds__CreateCertificateResponse) { printf("%s,%d\n",__FUNCTION__, __LINE__); return 0; }
/** Web service operation '__tds__GetCertificates' implementation, should return SOAP_OK or error code */
SOAP_FMAC5 int SOAP_FMAC6 __tds__GetCertificates(struct soap* soap, struct _tds__GetCertificates *tds__GetCertificates, struct _tds__GetCertificatesResponse *tds__GetCertificatesResponse) { printf("%s,%d\n",__FUNCTION__, __LINE__); return 0; }
/** Web service operation '__tds__GetCertificatesStatus' implementation, should return SOAP_OK or error code */
SOAP_FMAC5 int SOAP_FMAC6 __tds__GetCertificatesStatus(struct soap* soap, struct _tds__GetCertificatesStatus *tds__GetCertificatesStatus, struct _tds__GetCertificatesStatusResponse *tds__GetCertificatesStatusResponse) { printf("%s,%d\n",__FUNCTION__, __LINE__); return 0; }
/** Web service operation '__tds__SetCertificatesStatus' implementation, should return SOAP_OK or error code */
SOAP_FMAC5 int SOAP_FMAC6 __tds__SetCertificatesStatus(struct soap* soap, struct _tds__SetCertificatesStatus *tds__SetCertificatesStatus, struct _tds__SetCertificatesStatusResponse *tds__SetCertificatesStatusResponse) { printf("%s,%d\n",__FUNCTION__, __LINE__); return 0; }
/** Web service operation '__tds__DeleteCertificates' implementation, should return SOAP_OK or error code */
SOAP_FMAC5 int SOAP_FMAC6 __tds__DeleteCertificates(struct soap* soap, struct _tds__DeleteCertificates *tds__DeleteCertificates, struct _tds__DeleteCertificatesResponse *tds__DeleteCertificatesResponse) { printf("%s,%d\n",__FUNCTION__, __LINE__); return 0; }
/** Web service operation '__tds__GetPkcs10Request' implementation, should return SOAP_OK or error code */
SOAP_FMAC5 int SOAP_FMAC6 __tds__GetPkcs10Request(struct soap* soap, struct _tds__GetPkcs10Request *tds__GetPkcs10Request, struct _tds__GetPkcs10RequestResponse *tds__GetPkcs10RequestResponse) { printf("%s,%d\n",__FUNCTION__, __LINE__); return 0; }
/** Web service operation '__tds__LoadCertificates' implementation, should return SOAP_OK or error code */
SOAP_FMAC5 int SOAP_FMAC6 __tds__LoadCertificates(struct soap* soap, struct _tds__LoadCertificates *tds__LoadCertificates, struct _tds__LoadCertificatesResponse *tds__LoadCertificatesResponse) { printf("%s,%d\n",__FUNCTION__, __LINE__); return 0; }
/** Web service operation '__tds__GetClientCertificateMode' implementation, should return SOAP_OK or error code */
SOAP_FMAC5 int SOAP_FMAC6 __tds__GetClientCertificateMode(struct soap* soap, struct _tds__GetClientCertificateMode *tds__GetClientCertificateMode, struct _tds__GetClientCertificateModeResponse *tds__GetClientCertificateModeResponse) { printf("%s,%d\n",__FUNCTION__, __LINE__); return 0; }
/** Web service operation '__tds__SetClientCertificateMode' implementation, should return SOAP_OK or error code */
SOAP_FMAC5 int SOAP_FMAC6 __tds__SetClientCertificateMode(struct soap* soap, struct _tds__SetClientCertificateMode *tds__SetClientCertificateMode, struct _tds__SetClientCertificateModeResponse *tds__SetClientCertificateModeResponse) { printf("%s,%d\n",__FUNCTION__, __LINE__); return 0; }
/** Web service operation '__tds__GetRelayOutputs' implementation, should return SOAP_OK or error code */
SOAP_FMAC5 int SOAP_FMAC6 __tds__GetRelayOutputs(struct soap* soap, struct _tds__GetRelayOutputs *tds__GetRelayOutputs, struct _tds__GetRelayOutputsResponse *tds__GetRelayOutputsResponse) { printf("%s,%d\n",__FUNCTION__, __LINE__); return 0; }
/** Web service operation '__tds__SetRelayOutputSettings' implementation, should return SOAP_OK or error code */
SOAP_FMAC5 int SOAP_FMAC6 __tds__SetRelayOutputSettings(struct soap* soap, struct _tds__SetRelayOutputSettings *tds__SetRelayOutputSettings, struct _tds__SetRelayOutputSettingsResponse *tds__SetRelayOutputSettingsResponse) { printf("%s,%d\n",__FUNCTION__, __LINE__); return 0; }
/** Web service operation '__tds__SetRelayOutputState' implementation, should return SOAP_OK or error code */
SOAP_FMAC5 int SOAP_FMAC6 __tds__SetRelayOutputState(struct soap* soap, struct _tds__SetRelayOutputState *tds__SetRelayOutputState, struct _tds__SetRelayOutputStateResponse *tds__SetRelayOutputStateResponse) { printf("%s,%d\n",__FUNCTION__, __LINE__); return 0; }
/** Web service operation '__tds__SendAuxiliaryCommand' implementation, should return SOAP_OK or error code */
SOAP_FMAC5 int SOAP_FMAC6 __tds__SendAuxiliaryCommand(struct soap* soap, struct _tds__SendAuxiliaryCommand *tds__SendAuxiliaryCommand, struct _tds__SendAuxiliaryCommandResponse *tds__SendAuxiliaryCommandResponse) { printf("%s,%d\n",__FUNCTION__, __LINE__); return 0; }
/** Web service operation '__tds__GetCACertificates' implementation, should return SOAP_OK or error code */
SOAP_FMAC5 int SOAP_FMAC6 __tds__GetCACertificates(struct soap* soap, struct _tds__GetCACertificates *tds__GetCACertificates, struct _tds__GetCACertificatesResponse *tds__GetCACertificatesResponse) { printf("%s,%d\n",__FUNCTION__, __LINE__); return 0; }
/** Web service operation '__tds__LoadCertificateWithPrivateKey' implementation, should return SOAP_OK or error code */
SOAP_FMAC5 int SOAP_FMAC6 __tds__LoadCertificateWithPrivateKey(struct soap* soap, struct _tds__LoadCertificateWithPrivateKey *tds__LoadCertificateWithPrivateKey, struct _tds__LoadCertificateWithPrivateKeyResponse *tds__LoadCertificateWithPrivateKeyResponse) { printf("%s,%d\n",__FUNCTION__, __LINE__); return 0; }
/** Web service operation '__tds__GetCertificateInformation' implementation, should return SOAP_OK or error code */
SOAP_FMAC5 int SOAP_FMAC6 __tds__GetCertificateInformation(struct soap* soap, struct _tds__GetCertificateInformation *tds__GetCertificateInformation, struct _tds__GetCertificateInformationResponse *tds__GetCertificateInformationResponse) { printf("%s,%d\n",__FUNCTION__, __LINE__); return 0; }
/** Web service operation '__tds__LoadCACertificates' implementation, should return SOAP_OK or error code */
SOAP_FMAC5 int SOAP_FMAC6 __tds__LoadCACertificates(struct soap* soap, struct _tds__LoadCACertificates *tds__LoadCACertificates, struct _tds__LoadCACertificatesResponse *tds__LoadCACertificatesResponse) { printf("%s,%d\n",__FUNCTION__, __LINE__); return 0; }
/** Web service operation '__tds__CreateDot1XConfiguration' implementation, should return SOAP_OK or error code */
SOAP_FMAC5 int SOAP_FMAC6 __tds__CreateDot1XConfiguration(struct soap* soap, struct _tds__CreateDot1XConfiguration *tds__CreateDot1XConfiguration, struct _tds__CreateDot1XConfigurationResponse *tds__CreateDot1XConfigurationResponse) { printf("%s,%d\n",__FUNCTION__, __LINE__); return 0; }
/** Web service operation '__tds__SetDot1XConfiguration' implementation, should return SOAP_OK or error code */
SOAP_FMAC5 int SOAP_FMAC6 __tds__SetDot1XConfiguration(struct soap* soap, struct _tds__SetDot1XConfiguration *tds__SetDot1XConfiguration, struct _tds__SetDot1XConfigurationResponse *tds__SetDot1XConfigurationResponse) { printf("%s,%d\n",__FUNCTION__, __LINE__); return 0; }
/** Web service operation '__tds__GetDot1XConfiguration' implementation, should return SOAP_OK or error code */
SOAP_FMAC5 int SOAP_FMAC6 __tds__GetDot1XConfiguration(struct soap* soap, struct _tds__GetDot1XConfiguration *tds__GetDot1XConfiguration, struct _tds__GetDot1XConfigurationResponse *tds__GetDot1XConfigurationResponse) { printf("%s,%d\n",__FUNCTION__, __LINE__); return 0; }
/** Web service operation '__tds__GetDot1XConfigurations' implementation, should return SOAP_OK or error code */
SOAP_FMAC5 int SOAP_FMAC6 __tds__GetDot1XConfigurations(struct soap* soap, struct _tds__GetDot1XConfigurations *tds__GetDot1XConfigurations, struct _tds__GetDot1XConfigurationsResponse *tds__GetDot1XConfigurationsResponse) { printf("%s,%d\n",__FUNCTION__, __LINE__); return 0; }
/** Web service operation '__tds__DeleteDot1XConfiguration' implementation, should return SOAP_OK or error code */
SOAP_FMAC5 int SOAP_FMAC6 __tds__DeleteDot1XConfiguration(struct soap* soap, struct _tds__DeleteDot1XConfiguration *tds__DeleteDot1XConfiguration, struct _tds__DeleteDot1XConfigurationResponse *tds__DeleteDot1XConfigurationResponse) { printf("%s,%d\n",__FUNCTION__, __LINE__); return 0; }
/** Web service operation '__tds__GetDot11Capabilities' implementation, should return SOAP_OK or error code */
SOAP_FMAC5 int SOAP_FMAC6 __tds__GetDot11Capabilities(struct soap* soap, struct _tds__GetDot11Capabilities *tds__GetDot11Capabilities, struct _tds__GetDot11CapabilitiesResponse *tds__GetDot11CapabilitiesResponse) { printf("%s,%d\n",__FUNCTION__, __LINE__); return 0; }
/** Web service operation '__tds__GetDot11Status' implementation, should return SOAP_OK or error code */
SOAP_FMAC5 int SOAP_FMAC6 __tds__GetDot11Status(struct soap* soap, struct _tds__GetDot11Status *tds__GetDot11Status, struct _tds__GetDot11StatusResponse *tds__GetDot11StatusResponse) { printf("%s,%d\n",__FUNCTION__, __LINE__); return 0; }
/** Web service operation '__tds__ScanAvailableDot11Networks' implementation, should return SOAP_OK or error code */
SOAP_FMAC5 int SOAP_FMAC6 __tds__ScanAvailableDot11Networks(struct soap* soap, struct _tds__ScanAvailableDot11Networks *tds__ScanAvailableDot11Networks, struct _tds__ScanAvailableDot11NetworksResponse *tds__ScanAvailableDot11NetworksResponse) { printf("%s,%d\n",__FUNCTION__, __LINE__); return 0; }
/** Web service operation '__tds__GetSystemUris' implementation, should return SOAP_OK or error code */
SOAP_FMAC5 int SOAP_FMAC6 __tds__GetSystemUris(struct soap* soap, struct _tds__GetSystemUris *tds__GetSystemUris, struct _tds__GetSystemUrisResponse *tds__GetSystemUrisResponse) { printf("%s,%d\n",__FUNCTION__, __LINE__); return 0; }
/** Web service operation '__tds__StartFirmwareUpgrade' implementation, should return SOAP_OK or error code */
SOAP_FMAC5 int SOAP_FMAC6 __tds__StartFirmwareUpgrade(struct soap* soap, struct _tds__StartFirmwareUpgrade *tds__StartFirmwareUpgrade, struct _tds__StartFirmwareUpgradeResponse *tds__StartFirmwareUpgradeResponse) { printf("%s,%d\n",__FUNCTION__, __LINE__); return 0; }
/** Web service operation '__tds__StartSystemRestore' implementation, should return SOAP_OK or error code */
SOAP_FMAC5 int SOAP_FMAC6 __tds__StartSystemRestore(struct soap* soap, struct _tds__StartSystemRestore *tds__StartSystemRestore, struct _tds__StartSystemRestoreResponse *tds__StartSystemRestoreResponse) { printf("%s,%d\n",__FUNCTION__, __LINE__); return 0; }
/** Web service operation '__tds__GetStorageConfigurations' implementation, should return SOAP_OK or error code */
SOAP_FMAC5 int SOAP_FMAC6 __tds__GetStorageConfigurations(struct soap* soap, struct _tds__GetStorageConfigurations *tds__GetStorageConfigurations, struct _tds__GetStorageConfigurationsResponse *tds__GetStorageConfigurationsResponse) { printf("%s,%d\n",__FUNCTION__, __LINE__); return 0; }
/** Web service operation '__tds__CreateStorageConfiguration' implementation, should return SOAP_OK or error code */
SOAP_FMAC5 int SOAP_FMAC6 __tds__CreateStorageConfiguration(struct soap* soap, struct _tds__CreateStorageConfiguration *tds__CreateStorageConfiguration, struct _tds__CreateStorageConfigurationResponse *tds__CreateStorageConfigurationResponse) { printf("%s,%d\n",__FUNCTION__, __LINE__); return 0; }
/** Web service operation '__tds__GetStorageConfiguration' implementation, should return SOAP_OK or error code */
SOAP_FMAC5 int SOAP_FMAC6 __tds__GetStorageConfiguration(struct soap* soap, struct _tds__GetStorageConfiguration *tds__GetStorageConfiguration, struct _tds__GetStorageConfigurationResponse *tds__GetStorageConfigurationResponse) { printf("%s,%d\n",__FUNCTION__, __LINE__); return 0; }
/** Web service operation '__tds__SetStorageConfiguration' implementation, should return SOAP_OK or error code */
SOAP_FMAC5 int SOAP_FMAC6 __tds__SetStorageConfiguration(struct soap* soap, struct _tds__SetStorageConfiguration *tds__SetStorageConfiguration, struct _tds__SetStorageConfigurationResponse *tds__SetStorageConfigurationResponse) { printf("%s,%d\n",__FUNCTION__, __LINE__); return 0; }
/** Web service operation '__tds__DeleteStorageConfiguration' implementation, should return SOAP_OK or error code */
SOAP_FMAC5 int SOAP_FMAC6 __tds__DeleteStorageConfiguration(struct soap* soap, struct _tds__DeleteStorageConfiguration *tds__DeleteStorageConfiguration, struct _tds__DeleteStorageConfigurationResponse *tds__DeleteStorageConfigurationResponse) { printf("%s,%d\n",__FUNCTION__, __LINE__); return 0; }
/** Web service operation '__tds__GetGeoLocation' implementation, should return SOAP_OK or error code */
SOAP_FMAC5 int SOAP_FMAC6 __tds__GetGeoLocation(struct soap* soap, struct _tds__GetGeoLocation *tds__GetGeoLocation, struct _tds__GetGeoLocationResponse *tds__GetGeoLocationResponse) { printf("%s,%d\n",__FUNCTION__, __LINE__); return 0; }
/** Web service operation '__tds__SetGeoLocation' implementation, should return SOAP_OK or error code */
SOAP_FMAC5 int SOAP_FMAC6 __tds__SetGeoLocation(struct soap* soap, struct _tds__SetGeoLocation *tds__SetGeoLocation, struct _tds__SetGeoLocationResponse *tds__SetGeoLocationResponse) { printf("%s,%d\n",__FUNCTION__, __LINE__); return 0; }
/** Web service operation '__tds__DeleteGeoLocation' implementation, should return SOAP_OK or error code */
SOAP_FMAC5 int SOAP_FMAC6 __tds__DeleteGeoLocation(struct soap* soap, struct _tds__DeleteGeoLocation *tds__DeleteGeoLocation, struct _tds__DeleteGeoLocationResponse *tds__DeleteGeoLocationResponse) { printf("%s,%d\n",__FUNCTION__, __LINE__); return 0; }
/** Web service operation '__tds__GetServices_' implementation, should return SOAP_OK or error code */
SOAP_FMAC5 int SOAP_FMAC6 __tds__GetServices_(struct soap* soap, struct _tds__GetServices *tds__GetServices, struct _tds__GetServicesResponse *tds__GetServicesResponse) { printf("%s,%d\n",__FUNCTION__, __LINE__); return 0; }
/** Web service operation '__tds__GetServiceCapabilities_' implementation, should return SOAP_OK or error code */
SOAP_FMAC5 int SOAP_FMAC6 __tds__GetServiceCapabilities_(struct soap* soap, struct _tds__GetServiceCapabilities *tds__GetServiceCapabilities, struct _tds__GetServiceCapabilitiesResponse *tds__GetServiceCapabilitiesResponse) { printf("%s,%d\n",__FUNCTION__, __LINE__); return 0; }
/** Web service operation '__tds__GetDeviceInformation_' implementation, should return SOAP_OK or error code */
SOAP_FMAC5 int SOAP_FMAC6 __tds__GetDeviceInformation_(struct soap* soap, struct _tds__GetDeviceInformation *tds__GetDeviceInformation, struct _tds__GetDeviceInformationResponse *tds__GetDeviceInformationResponse) { printf("%s,%d\n",__FUNCTION__, __LINE__); return 0; }
/** Web service operation '__tds__SetSystemDateAndTime_' implementation, should return SOAP_OK or error code */
SOAP_FMAC5 int SOAP_FMAC6 __tds__SetSystemDateAndTime_(struct soap* soap, struct _tds__SetSystemDateAndTime *tds__SetSystemDateAndTime, struct _tds__SetSystemDateAndTimeResponse *tds__SetSystemDateAndTimeResponse) { printf("%s,%d\n",__FUNCTION__, __LINE__); return 0; }
/** Web service operation '__tds__GetSystemDateAndTime_' implementation, should return SOAP_OK or error code */
SOAP_FMAC5 int SOAP_FMAC6 __tds__GetSystemDateAndTime_(struct soap* soap, struct _tds__GetSystemDateAndTime *tds__GetSystemDateAndTime, struct _tds__GetSystemDateAndTimeResponse *tds__GetSystemDateAndTimeResponse) { printf("%s,%d\n",__FUNCTION__, __LINE__); return 0; }
/** Web service operation '__tds__SetSystemFactoryDefault_' implementation, should return SOAP_OK or error code */
SOAP_FMAC5 int SOAP_FMAC6 __tds__SetSystemFactoryDefault_(struct soap* soap, struct _tds__SetSystemFactoryDefault *tds__SetSystemFactoryDefault, struct _tds__SetSystemFactoryDefaultResponse *tds__SetSystemFactoryDefaultResponse) { printf("%s,%d\n",__FUNCTION__, __LINE__); return 0; }
/** Web service operation '__tds__UpgradeSystemFirmware_' implementation, should return SOAP_OK or error code */
SOAP_FMAC5 int SOAP_FMAC6 __tds__UpgradeSystemFirmware_(struct soap* soap, struct _tds__UpgradeSystemFirmware *tds__UpgradeSystemFirmware, struct _tds__UpgradeSystemFirmwareResponse *tds__UpgradeSystemFirmwareResponse) { printf("%s,%d\n",__FUNCTION__, __LINE__); return 0; }
/** Web service operation '__tds__SystemReboot_' implementation, should return SOAP_OK or error code */
SOAP_FMAC5 int SOAP_FMAC6 __tds__SystemReboot_(struct soap* soap, struct _tds__SystemReboot *tds__SystemReboot, struct _tds__SystemRebootResponse *tds__SystemRebootResponse) { printf("%s,%d\n",__FUNCTION__, __LINE__); return 0; }
/** Web service operation '__tds__RestoreSystem_' implementation, should return SOAP_OK or error code */
SOAP_FMAC5 int SOAP_FMAC6 __tds__RestoreSystem_(struct soap* soap, struct _tds__RestoreSystem *tds__RestoreSystem, struct _tds__RestoreSystemResponse *tds__RestoreSystemResponse) { printf("%s,%d\n",__FUNCTION__, __LINE__); return 0; }
/** Web service operation '__tds__GetSystemBackup_' implementation, should return SOAP_OK or error code */
SOAP_FMAC5 int SOAP_FMAC6 __tds__GetSystemBackup_(struct soap* soap, struct _tds__GetSystemBackup *tds__GetSystemBackup, struct _tds__GetSystemBackupResponse *tds__GetSystemBackupResponse) { printf("%s,%d\n",__FUNCTION__, __LINE__); return 0; }
/** Web service operation '__tds__GetSystemLog_' implementation, should return SOAP_OK or error code */
SOAP_FMAC5 int SOAP_FMAC6 __tds__GetSystemLog_(struct soap* soap, struct _tds__GetSystemLog *tds__GetSystemLog, struct _tds__GetSystemLogResponse *tds__GetSystemLogResponse) { printf("%s,%d\n",__FUNCTION__, __LINE__); return 0; }
/** Web service operation '__tds__GetSystemSupportInformation_' implementation, should return SOAP_OK or error code */
SOAP_FMAC5 int SOAP_FMAC6 __tds__GetSystemSupportInformation_(struct soap* soap, struct _tds__GetSystemSupportInformation *tds__GetSystemSupportInformation, struct _tds__GetSystemSupportInformationResponse *tds__GetSystemSupportInformationResponse) { printf("%s,%d\n",__FUNCTION__, __LINE__); return 0; }
/** Web service operation '__tds__GetScopes_' implementation, should return SOAP_OK or error code */
SOAP_FMAC5 int SOAP_FMAC6 __tds__GetScopes_(struct soap* soap, struct _tds__GetScopes *tds__GetScopes, struct _tds__GetScopesResponse *tds__GetScopesResponse) { printf("%s,%d\n",__FUNCTION__, __LINE__); return 0; }
/** Web service operation '__tds__SetScopes_' implementation, should return SOAP_OK or error code */
SOAP_FMAC5 int SOAP_FMAC6 __tds__SetScopes_(struct soap* soap, struct _tds__SetScopes *tds__SetScopes, struct _tds__SetScopesResponse *tds__SetScopesResponse) { printf("%s,%d\n",__FUNCTION__, __LINE__); return 0; }
/** Web service operation '__tds__AddScopes_' implementation, should return SOAP_OK or error code */
SOAP_FMAC5 int SOAP_FMAC6 __tds__AddScopes_(struct soap* soap, struct _tds__AddScopes *tds__AddScopes, struct _tds__AddScopesResponse *tds__AddScopesResponse) { printf("%s,%d\n",__FUNCTION__, __LINE__); return 0; }
/** Web service operation '__tds__RemoveScopes_' implementation, should return SOAP_OK or error code */
SOAP_FMAC5 int SOAP_FMAC6 __tds__RemoveScopes_(struct soap* soap, struct _tds__RemoveScopes *tds__RemoveScopes, struct _tds__RemoveScopesResponse *tds__RemoveScopesResponse) { printf("%s,%d\n",__FUNCTION__, __LINE__); return 0; }
/** Web service operation '__tds__GetDiscoveryMode_' implementation, should return SOAP_OK or error code */
SOAP_FMAC5 int SOAP_FMAC6 __tds__GetDiscoveryMode_(struct soap* soap, struct _tds__GetDiscoveryMode *tds__GetDiscoveryMode, struct _tds__GetDiscoveryModeResponse *tds__GetDiscoveryModeResponse) { printf("%s,%d\n",__FUNCTION__, __LINE__); return 0; }
/** Web service operation '__tds__SetDiscoveryMode_' implementation, should return SOAP_OK or error code */
SOAP_FMAC5 int SOAP_FMAC6 __tds__SetDiscoveryMode_(struct soap* soap, struct _tds__SetDiscoveryMode *tds__SetDiscoveryMode, struct _tds__SetDiscoveryModeResponse *tds__SetDiscoveryModeResponse) { printf("%s,%d\n",__FUNCTION__, __LINE__); return 0; }
/** Web service operation '__tds__GetRemoteDiscoveryMode_' implementation, should return SOAP_OK or error code */
SOAP_FMAC5 int SOAP_FMAC6 __tds__GetRemoteDiscoveryMode_(struct soap* soap, struct _tds__GetRemoteDiscoveryMode *tds__GetRemoteDiscoveryMode, struct _tds__GetRemoteDiscoveryModeResponse *tds__GetRemoteDiscoveryModeResponse) { printf("%s,%d\n",__FUNCTION__, __LINE__); return 0; }
/** Web service operation '__tds__SetRemoteDiscoveryMode_' implementation, should return SOAP_OK or error code */
SOAP_FMAC5 int SOAP_FMAC6 __tds__SetRemoteDiscoveryMode_(struct soap* soap, struct _tds__SetRemoteDiscoveryMode *tds__SetRemoteDiscoveryMode, struct _tds__SetRemoteDiscoveryModeResponse *tds__SetRemoteDiscoveryModeResponse) { printf("%s,%d\n",__FUNCTION__, __LINE__); return 0; }
/** Web service operation '__tds__GetDPAddresses_' implementation, should return SOAP_OK or error code */
SOAP_FMAC5 int SOAP_FMAC6 __tds__GetDPAddresses_(struct soap* soap, struct _tds__GetDPAddresses *tds__GetDPAddresses, struct _tds__GetDPAddressesResponse *tds__GetDPAddressesResponse) { printf("%s,%d\n",__FUNCTION__, __LINE__); return 0; }
/** Web service operation '__tds__GetEndpointReference_' implementation, should return SOAP_OK or error code */
SOAP_FMAC5 int SOAP_FMAC6 __tds__GetEndpointReference_(struct soap* soap, struct _tds__GetEndpointReference *tds__GetEndpointReference, struct _tds__GetEndpointReferenceResponse *tds__GetEndpointReferenceResponse) { printf("%s,%d\n",__FUNCTION__, __LINE__); return 0; }
/** Web service operation '__tds__GetRemoteUser_' implementation, should return SOAP_OK or error code */
SOAP_FMAC5 int SOAP_FMAC6 __tds__GetRemoteUser_(struct soap* soap, struct _tds__GetRemoteUser *tds__GetRemoteUser, struct _tds__GetRemoteUserResponse *tds__GetRemoteUserResponse) { printf("%s,%d\n",__FUNCTION__, __LINE__); return 0; }
/** Web service operation '__tds__SetRemoteUser_' implementation, should return SOAP_OK or error code */
SOAP_FMAC5 int SOAP_FMAC6 __tds__SetRemoteUser_(struct soap* soap, struct _tds__SetRemoteUser *tds__SetRemoteUser, struct _tds__SetRemoteUserResponse *tds__SetRemoteUserResponse) { printf("%s,%d\n",__FUNCTION__, __LINE__); return 0; }
/** Web service operation '__tds__GetUsers_' implementation, should return SOAP_OK or error code */
SOAP_FMAC5 int SOAP_FMAC6 __tds__GetUsers_(struct soap* soap, struct _tds__GetUsers *tds__GetUsers, struct _tds__GetUsersResponse *tds__GetUsersResponse) { printf("%s,%d\n",__FUNCTION__, __LINE__); return 0; }
/** Web service operation '__tds__CreateUsers_' implementation, should return SOAP_OK or error code */
SOAP_FMAC5 int SOAP_FMAC6 __tds__CreateUsers_(struct soap* soap, struct _tds__CreateUsers *tds__CreateUsers, struct _tds__CreateUsersResponse *tds__CreateUsersResponse) { printf("%s,%d\n",__FUNCTION__, __LINE__); return 0; }
/** Web service operation '__tds__DeleteUsers_' implementation, should return SOAP_OK or error code */
SOAP_FMAC5 int SOAP_FMAC6 __tds__DeleteUsers_(struct soap* soap, struct _tds__DeleteUsers *tds__DeleteUsers, struct _tds__DeleteUsersResponse *tds__DeleteUsersResponse) { printf("%s,%d\n",__FUNCTION__, __LINE__); return 0; }
/** Web service operation '__tds__SetUser_' implementation, should return SOAP_OK or error code */
SOAP_FMAC5 int SOAP_FMAC6 __tds__SetUser_(struct soap* soap, struct _tds__SetUser *tds__SetUser, struct _tds__SetUserResponse *tds__SetUserResponse) { printf("%s,%d\n",__FUNCTION__, __LINE__); return 0; }
/** Web service operation '__tds__GetWsdlUrl_' implementation, should return SOAP_OK or error code */
SOAP_FMAC5 int SOAP_FMAC6 __tds__GetWsdlUrl_(struct soap* soap, struct _tds__GetWsdlUrl *tds__GetWsdlUrl, struct _tds__GetWsdlUrlResponse *tds__GetWsdlUrlResponse) { printf("%s,%d\n",__FUNCTION__, __LINE__); return 0; }
/** Web service operation '__tds__GetCapabilities_' implementation, should return SOAP_OK or error code */
SOAP_FMAC5 int SOAP_FMAC6 __tds__GetCapabilities_(struct soap* soap, struct _tds__GetCapabilities *tds__GetCapabilities, struct _tds__GetCapabilitiesResponse *tds__GetCapabilitiesResponse) { printf("%s,%d\n",__FUNCTION__, __LINE__); return 0; }
/** Web service operation '__tds__SetDPAddresses_' implementation, should return SOAP_OK or error code */
SOAP_FMAC5 int SOAP_FMAC6 __tds__SetDPAddresses_(struct soap* soap, struct _tds__SetDPAddresses *tds__SetDPAddresses, struct _tds__SetDPAddressesResponse *tds__SetDPAddressesResponse) { printf("%s,%d\n",__FUNCTION__, __LINE__); return 0; }
/** Web service operation '__tds__GetHostname_' implementation, should return SOAP_OK or error code */
SOAP_FMAC5 int SOAP_FMAC6 __tds__GetHostname_(struct soap* soap, struct _tds__GetHostname *tds__GetHostname, struct _tds__GetHostnameResponse *tds__GetHostnameResponse) { printf("%s,%d\n",__FUNCTION__, __LINE__); return 0; }
/** Web service operation '__tds__SetHostname_' implementation, should return SOAP_OK or error code */
SOAP_FMAC5 int SOAP_FMAC6 __tds__SetHostname_(struct soap* soap, struct _tds__SetHostname *tds__SetHostname, struct _tds__SetHostnameResponse *tds__SetHostnameResponse) { printf("%s,%d\n",__FUNCTION__, __LINE__); return 0; }
/** Web service operation '__tds__SetHostnameFromDHCP_' implementation, should return SOAP_OK or error code */
SOAP_FMAC5 int SOAP_FMAC6 __tds__SetHostnameFromDHCP_(struct soap* soap, struct _tds__SetHostnameFromDHCP *tds__SetHostnameFromDHCP, struct _tds__SetHostnameFromDHCPResponse *tds__SetHostnameFromDHCPResponse) { printf("%s,%d\n",__FUNCTION__, __LINE__); return 0; }
/** Web service operation '__tds__GetDNS_' implementation, should return SOAP_OK or error code */
SOAP_FMAC5 int SOAP_FMAC6 __tds__GetDNS_(struct soap* soap, struct _tds__GetDNS *tds__GetDNS, struct _tds__GetDNSResponse *tds__GetDNSResponse) { printf("%s,%d\n",__FUNCTION__, __LINE__); return 0; }
/** Web service operation '__tds__SetDNS_' implementation, should return SOAP_OK or error code */
SOAP_FMAC5 int SOAP_FMAC6 __tds__SetDNS_(struct soap* soap, struct _tds__SetDNS *tds__SetDNS, struct _tds__SetDNSResponse *tds__SetDNSResponse) { printf("%s,%d\n",__FUNCTION__, __LINE__); return 0; }
/** Web service operation '__tds__GetNTP_' implementation, should return SOAP_OK or error code */
SOAP_FMAC5 int SOAP_FMAC6 __tds__GetNTP_(struct soap* soap, struct _tds__GetNTP *tds__GetNTP, struct _tds__GetNTPResponse *tds__GetNTPResponse) { printf("%s,%d\n",__FUNCTION__, __LINE__); return 0; }
/** Web service operation '__tds__SetNTP_' implementation, should return SOAP_OK or error code */
SOAP_FMAC5 int SOAP_FMAC6 __tds__SetNTP_(struct soap* soap, struct _tds__SetNTP *tds__SetNTP, struct _tds__SetNTPResponse *tds__SetNTPResponse) { printf("%s,%d\n",__FUNCTION__, __LINE__); return 0; }
/** Web service operation '__tds__GetDynamicDNS_' implementation, should return SOAP_OK or error code */
SOAP_FMAC5 int SOAP_FMAC6 __tds__GetDynamicDNS_(struct soap* soap, struct _tds__GetDynamicDNS *tds__GetDynamicDNS, struct _tds__GetDynamicDNSResponse *tds__GetDynamicDNSResponse) { printf("%s,%d\n",__FUNCTION__, __LINE__); return 0; }
/** Web service operation '__tds__SetDynamicDNS_' implementation, should return SOAP_OK or error code */
SOAP_FMAC5 int SOAP_FMAC6 __tds__SetDynamicDNS_(struct soap* soap, struct _tds__SetDynamicDNS *tds__SetDynamicDNS, struct _tds__SetDynamicDNSResponse *tds__SetDynamicDNSResponse) { printf("%s,%d\n",__FUNCTION__, __LINE__); return 0; }
/** Web service operation '__tds__GetNetworkInterfaces_' implementation, should return SOAP_OK or error code */
SOAP_FMAC5 int SOAP_FMAC6 __tds__GetNetworkInterfaces_(struct soap* soap, struct _tds__GetNetworkInterfaces *tds__GetNetworkInterfaces, struct _tds__GetNetworkInterfacesResponse *tds__GetNetworkInterfacesResponse) { printf("%s,%d\n",__FUNCTION__, __LINE__); return 0; }
/** Web service operation '__tds__SetNetworkInterfaces_' implementation, should return SOAP_OK or error code */
SOAP_FMAC5 int SOAP_FMAC6 __tds__SetNetworkInterfaces_(struct soap* soap, struct _tds__SetNetworkInterfaces *tds__SetNetworkInterfaces, struct _tds__SetNetworkInterfacesResponse *tds__SetNetworkInterfacesResponse) { printf("%s,%d\n",__FUNCTION__, __LINE__); return 0; }
/** Web service operation '__tds__GetNetworkProtocols_' implementation, should return SOAP_OK or error code */
SOAP_FMAC5 int SOAP_FMAC6 __tds__GetNetworkProtocols_(struct soap* soap, struct _tds__GetNetworkProtocols *tds__GetNetworkProtocols, struct _tds__GetNetworkProtocolsResponse *tds__GetNetworkProtocolsResponse) { printf("%s,%d\n",__FUNCTION__, __LINE__); return 0; }
/** Web service operation '__tds__SetNetworkProtocols_' implementation, should return SOAP_OK or error code */
SOAP_FMAC5 int SOAP_FMAC6 __tds__SetNetworkProtocols_(struct soap* soap, struct _tds__SetNetworkProtocols *tds__SetNetworkProtocols, struct _tds__SetNetworkProtocolsResponse *tds__SetNetworkProtocolsResponse) { printf("%s,%d\n",__FUNCTION__, __LINE__); return 0; }
/** Web service operation '__tds__GetNetworkDefaultGateway_' implementation, should return SOAP_OK or error code */
SOAP_FMAC5 int SOAP_FMAC6 __tds__GetNetworkDefaultGateway_(struct soap* soap, struct _tds__GetNetworkDefaultGateway *tds__GetNetworkDefaultGateway, struct _tds__GetNetworkDefaultGatewayResponse *tds__GetNetworkDefaultGatewayResponse) { printf("%s,%d\n",__FUNCTION__, __LINE__); return 0; }
/** Web service operation '__tds__SetNetworkDefaultGateway_' implementation, should return SOAP_OK or error code */
SOAP_FMAC5 int SOAP_FMAC6 __tds__SetNetworkDefaultGateway_(struct soap* soap, struct _tds__SetNetworkDefaultGateway *tds__SetNetworkDefaultGateway, struct _tds__SetNetworkDefaultGatewayResponse *tds__SetNetworkDefaultGatewayResponse) { printf("%s,%d\n",__FUNCTION__, __LINE__); return 0; }
/** Web service operation '__tds__GetZeroConfiguration_' implementation, should return SOAP_OK or error code */
SOAP_FMAC5 int SOAP_FMAC6 __tds__GetZeroConfiguration_(struct soap* soap, struct _tds__GetZeroConfiguration *tds__GetZeroConfiguration, struct _tds__GetZeroConfigurationResponse *tds__GetZeroConfigurationResponse) { printf("%s,%d\n",__FUNCTION__, __LINE__); return 0; }
/** Web service operation '__tds__SetZeroConfiguration_' implementation, should return SOAP_OK or error code */
SOAP_FMAC5 int SOAP_FMAC6 __tds__SetZeroConfiguration_(struct soap* soap, struct _tds__SetZeroConfiguration *tds__SetZeroConfiguration, struct _tds__SetZeroConfigurationResponse *tds__SetZeroConfigurationResponse) { printf("%s,%d\n",__FUNCTION__, __LINE__); return 0; }
/** Web service operation '__tds__GetIPAddressFilter_' implementation, should return SOAP_OK or error code */
SOAP_FMAC5 int SOAP_FMAC6 __tds__GetIPAddressFilter_(struct soap* soap, struct _tds__GetIPAddressFilter *tds__GetIPAddressFilter, struct _tds__GetIPAddressFilterResponse *tds__GetIPAddressFilterResponse) { printf("%s,%d\n",__FUNCTION__, __LINE__); return 0; }
/** Web service operation '__tds__SetIPAddressFilter_' implementation, should return SOAP_OK or error code */
SOAP_FMAC5 int SOAP_FMAC6 __tds__SetIPAddressFilter_(struct soap* soap, struct _tds__SetIPAddressFilter *tds__SetIPAddressFilter, struct _tds__SetIPAddressFilterResponse *tds__SetIPAddressFilterResponse) { printf("%s,%d\n",__FUNCTION__, __LINE__); return 0; }
/** Web service operation '__tds__AddIPAddressFilter_' implementation, should return SOAP_OK or error code */
SOAP_FMAC5 int SOAP_FMAC6 __tds__AddIPAddressFilter_(struct soap* soap, struct _tds__AddIPAddressFilter *tds__AddIPAddressFilter, struct _tds__AddIPAddressFilterResponse *tds__AddIPAddressFilterResponse) { printf("%s,%d\n",__FUNCTION__, __LINE__); return 0; }
/** Web service operation '__tds__RemoveIPAddressFilter_' implementation, should return SOAP_OK or error code */
SOAP_FMAC5 int SOAP_FMAC6 __tds__RemoveIPAddressFilter_(struct soap* soap, struct _tds__RemoveIPAddressFilter *tds__RemoveIPAddressFilter, struct _tds__RemoveIPAddressFilterResponse *tds__RemoveIPAddressFilterResponse) { printf("%s,%d\n",__FUNCTION__, __LINE__); return 0; }
/** Web service operation '__tds__GetAccessPolicy_' implementation, should return SOAP_OK or error code */
SOAP_FMAC5 int SOAP_FMAC6 __tds__GetAccessPolicy_(struct soap* soap, struct _tds__GetAccessPolicy *tds__GetAccessPolicy, struct _tds__GetAccessPolicyResponse *tds__GetAccessPolicyResponse) { printf("%s,%d\n",__FUNCTION__, __LINE__); return 0; }
/** Web service operation '__tds__SetAccessPolicy_' implementation, should return SOAP_OK or error code */
SOAP_FMAC5 int SOAP_FMAC6 __tds__SetAccessPolicy_(struct soap* soap, struct _tds__SetAccessPolicy *tds__SetAccessPolicy, struct _tds__SetAccessPolicyResponse *tds__SetAccessPolicyResponse) { printf("%s,%d\n",__FUNCTION__, __LINE__); return 0; }
/** Web service operation '__tds__CreateCertificate_' implementation, should return SOAP_OK or error code */
SOAP_FMAC5 int SOAP_FMAC6 __tds__CreateCertificate_(struct soap* soap, struct _tds__CreateCertificate *tds__CreateCertificate, struct _tds__CreateCertificateResponse *tds__CreateCertificateResponse) { printf("%s,%d\n",__FUNCTION__, __LINE__); return 0; }
/** Web service operation '__tds__GetCertificates_' implementation, should return SOAP_OK or error code */
SOAP_FMAC5 int SOAP_FMAC6 __tds__GetCertificates_(struct soap* soap, struct _tds__GetCertificates *tds__GetCertificates, struct _tds__GetCertificatesResponse *tds__GetCertificatesResponse) { printf("%s,%d\n",__FUNCTION__, __LINE__); return 0; }
/** Web service operation '__tds__GetCertificatesStatus_' implementation, should return SOAP_OK or error code */
SOAP_FMAC5 int SOAP_FMAC6 __tds__GetCertificatesStatus_(struct soap* soap, struct _tds__GetCertificatesStatus *tds__GetCertificatesStatus, struct _tds__GetCertificatesStatusResponse *tds__GetCertificatesStatusResponse) { printf("%s,%d\n",__FUNCTION__, __LINE__); return 0; }
/** Web service operation '__tds__SetCertificatesStatus_' implementation, should return SOAP_OK or error code */
SOAP_FMAC5 int SOAP_FMAC6 __tds__SetCertificatesStatus_(struct soap* soap, struct _tds__SetCertificatesStatus *tds__SetCertificatesStatus, struct _tds__SetCertificatesStatusResponse *tds__SetCertificatesStatusResponse) { printf("%s,%d\n",__FUNCTION__, __LINE__); return 0; }
/** Web service operation '__tds__DeleteCertificates_' implementation, should return SOAP_OK or error code */
SOAP_FMAC5 int SOAP_FMAC6 __tds__DeleteCertificates_(struct soap* soap, struct _tds__DeleteCertificates *tds__DeleteCertificates, struct _tds__DeleteCertificatesResponse *tds__DeleteCertificatesResponse) { printf("%s,%d\n",__FUNCTION__, __LINE__); return 0; }
/** Web service operation '__tds__GetPkcs10Request_' implementation, should return SOAP_OK or error code */
SOAP_FMAC5 int SOAP_FMAC6 __tds__GetPkcs10Request_(struct soap* soap, struct _tds__GetPkcs10Request *tds__GetPkcs10Request, struct _tds__GetPkcs10RequestResponse *tds__GetPkcs10RequestResponse) { printf("%s,%d\n",__FUNCTION__, __LINE__); return 0; }
/** Web service operation '__tds__LoadCertificates_' implementation, should return SOAP_OK or error code */
SOAP_FMAC5 int SOAP_FMAC6 __tds__LoadCertificates_(struct soap* soap, struct _tds__LoadCertificates *tds__LoadCertificates, struct _tds__LoadCertificatesResponse *tds__LoadCertificatesResponse) { printf("%s,%d\n",__FUNCTION__, __LINE__); return 0; }
/** Web service operation '__tds__GetClientCertificateMode_' implementation, should return SOAP_OK or error code */
SOAP_FMAC5 int SOAP_FMAC6 __tds__GetClientCertificateMode_(struct soap* soap, struct _tds__GetClientCertificateMode *tds__GetClientCertificateMode, struct _tds__GetClientCertificateModeResponse *tds__GetClientCertificateModeResponse) { printf("%s,%d\n",__FUNCTION__, __LINE__); return 0; }
/** Web service operation '__tds__SetClientCertificateMode_' implementation, should return SOAP_OK or error code */
SOAP_FMAC5 int SOAP_FMAC6 __tds__SetClientCertificateMode_(struct soap* soap, struct _tds__SetClientCertificateMode *tds__SetClientCertificateMode, struct _tds__SetClientCertificateModeResponse *tds__SetClientCertificateModeResponse) { printf("%s,%d\n",__FUNCTION__, __LINE__); return 0; }
/** Web service operation '__tds__GetRelayOutputs_' implementation, should return SOAP_OK or error code */
SOAP_FMAC5 int SOAP_FMAC6 __tds__GetRelayOutputs_(struct soap* soap, struct _tds__GetRelayOutputs *tds__GetRelayOutputs, struct _tds__GetRelayOutputsResponse *tds__GetRelayOutputsResponse) { printf("%s,%d\n",__FUNCTION__, __LINE__); return 0; }
/** Web service operation '__tds__SetRelayOutputSettings_' implementation, should return SOAP_OK or error code */
SOAP_FMAC5 int SOAP_FMAC6 __tds__SetRelayOutputSettings_(struct soap* soap, struct _tds__SetRelayOutputSettings *tds__SetRelayOutputSettings, struct _tds__SetRelayOutputSettingsResponse *tds__SetRelayOutputSettingsResponse) { printf("%s,%d\n",__FUNCTION__, __LINE__); return 0; }
/** Web service operation '__tds__SetRelayOutputState_' implementation, should return SOAP_OK or error code */
SOAP_FMAC5 int SOAP_FMAC6 __tds__SetRelayOutputState_(struct soap* soap, struct _tds__SetRelayOutputState *tds__SetRelayOutputState, struct _tds__SetRelayOutputStateResponse *tds__SetRelayOutputStateResponse) { printf("%s,%d\n",__FUNCTION__, __LINE__); return 0; }
/** Web service operation '__tds__SendAuxiliaryCommand_' implementation, should return SOAP_OK or error code */
SOAP_FMAC5 int SOAP_FMAC6 __tds__SendAuxiliaryCommand_(struct soap* soap, struct _tds__SendAuxiliaryCommand *tds__SendAuxiliaryCommand, struct _tds__SendAuxiliaryCommandResponse *tds__SendAuxiliaryCommandResponse) { printf("%s,%d\n",__FUNCTION__, __LINE__); return 0; }
/** Web service operation '__tds__GetCACertificates_' implementation, should return SOAP_OK or error code */
SOAP_FMAC5 int SOAP_FMAC6 __tds__GetCACertificates_(struct soap* soap, struct _tds__GetCACertificates *tds__GetCACertificates, struct _tds__GetCACertificatesResponse *tds__GetCACertificatesResponse) { printf("%s,%d\n",__FUNCTION__, __LINE__); return 0; }
/** Web service operation '__tds__LoadCertificateWithPrivateKey_' implementation, should return SOAP_OK or error code */
SOAP_FMAC5 int SOAP_FMAC6 __tds__LoadCertificateWithPrivateKey_(struct soap* soap, struct _tds__LoadCertificateWithPrivateKey *tds__LoadCertificateWithPrivateKey, struct _tds__LoadCertificateWithPrivateKeyResponse *tds__LoadCertificateWithPrivateKeyResponse) { printf("%s,%d\n",__FUNCTION__, __LINE__); return 0; }
/** Web service operation '__tds__GetCertificateInformation_' implementation, should return SOAP_OK or error code */
SOAP_FMAC5 int SOAP_FMAC6 __tds__GetCertificateInformation_(struct soap* soap, struct _tds__GetCertificateInformation *tds__GetCertificateInformation, struct _tds__GetCertificateInformationResponse *tds__GetCertificateInformationResponse) { printf("%s,%d\n",__FUNCTION__, __LINE__); return 0; }
/** Web service operation '__tds__LoadCACertificates_' implementation, should return SOAP_OK or error code */
SOAP_FMAC5 int SOAP_FMAC6 __tds__LoadCACertificates_(struct soap* soap, struct _tds__LoadCACertificates *tds__LoadCACertificates, struct _tds__LoadCACertificatesResponse *tds__LoadCACertificatesResponse) { printf("%s,%d\n",__FUNCTION__, __LINE__); return 0; }
/** Web service operation '__tds__CreateDot1XConfiguration_' implementation, should return SOAP_OK or error code */
SOAP_FMAC5 int SOAP_FMAC6 __tds__CreateDot1XConfiguration_(struct soap* soap, struct _tds__CreateDot1XConfiguration *tds__CreateDot1XConfiguration, struct _tds__CreateDot1XConfigurationResponse *tds__CreateDot1XConfigurationResponse) { printf("%s,%d\n",__FUNCTION__, __LINE__); return 0; }
/** Web service operation '__tds__SetDot1XConfiguration_' implementation, should return SOAP_OK or error code */
SOAP_FMAC5 int SOAP_FMAC6 __tds__SetDot1XConfiguration_(struct soap* soap, struct _tds__SetDot1XConfiguration *tds__SetDot1XConfiguration, struct _tds__SetDot1XConfigurationResponse *tds__SetDot1XConfigurationResponse) { printf("%s,%d\n",__FUNCTION__, __LINE__); return 0; }
/** Web service operation '__tds__GetDot1XConfiguration_' implementation, should return SOAP_OK or error code */
SOAP_FMAC5 int SOAP_FMAC6 __tds__GetDot1XConfiguration_(struct soap* soap, struct _tds__GetDot1XConfiguration *tds__GetDot1XConfiguration, struct _tds__GetDot1XConfigurationResponse *tds__GetDot1XConfigurationResponse) { printf("%s,%d\n",__FUNCTION__, __LINE__); return 0; }
/** Web service operation '__tds__GetDot1XConfigurations_' implementation, should return SOAP_OK or error code */
SOAP_FMAC5 int SOAP_FMAC6 __tds__GetDot1XConfigurations_(struct soap* soap, struct _tds__GetDot1XConfigurations *tds__GetDot1XConfigurations, struct _tds__GetDot1XConfigurationsResponse *tds__GetDot1XConfigurationsResponse) { printf("%s,%d\n",__FUNCTION__, __LINE__); return 0; }
/** Web service operation '__tds__DeleteDot1XConfiguration_' implementation, should return SOAP_OK or error code */
SOAP_FMAC5 int SOAP_FMAC6 __tds__DeleteDot1XConfiguration_(struct soap* soap, struct _tds__DeleteDot1XConfiguration *tds__DeleteDot1XConfiguration, struct _tds__DeleteDot1XConfigurationResponse *tds__DeleteDot1XConfigurationResponse) { printf("%s,%d\n",__FUNCTION__, __LINE__); return 0; }
/** Web service operation '__tds__GetDot11Capabilities_' implementation, should return SOAP_OK or error code */
SOAP_FMAC5 int SOAP_FMAC6 __tds__GetDot11Capabilities_(struct soap* soap, struct _tds__GetDot11Capabilities *tds__GetDot11Capabilities, struct _tds__GetDot11CapabilitiesResponse *tds__GetDot11CapabilitiesResponse) { printf("%s,%d\n",__FUNCTION__, __LINE__); return 0; }
/** Web service operation '__tds__GetDot11Status_' implementation, should return SOAP_OK or error code */
SOAP_FMAC5 int SOAP_FMAC6 __tds__GetDot11Status_(struct soap* soap, struct _tds__GetDot11Status *tds__GetDot11Status, struct _tds__GetDot11StatusResponse *tds__GetDot11StatusResponse) { printf("%s,%d\n",__FUNCTION__, __LINE__); return 0; }
/** Web service operation '__tds__ScanAvailableDot11Networks_' implementation, should return SOAP_OK or error code */
SOAP_FMAC5 int SOAP_FMAC6 __tds__ScanAvailableDot11Networks_(struct soap* soap, struct _tds__ScanAvailableDot11Networks *tds__ScanAvailableDot11Networks, struct _tds__ScanAvailableDot11NetworksResponse *tds__ScanAvailableDot11NetworksResponse) { printf("%s,%d\n",__FUNCTION__, __LINE__); return 0; }
/** Web service operation '__tds__GetSystemUris_' implementation, should return SOAP_OK or error code */
SOAP_FMAC5 int SOAP_FMAC6 __tds__GetSystemUris_(struct soap* soap, struct _tds__GetSystemUris *tds__GetSystemUris, struct _tds__GetSystemUrisResponse *tds__GetSystemUrisResponse) { printf("%s,%d\n",__FUNCTION__, __LINE__); return 0; }
/** Web service operation '__tds__StartFirmwareUpgrade_' implementation, should return SOAP_OK or error code */
SOAP_FMAC5 int SOAP_FMAC6 __tds__StartFirmwareUpgrade_(struct soap* soap, struct _tds__StartFirmwareUpgrade *tds__StartFirmwareUpgrade, struct _tds__StartFirmwareUpgradeResponse *tds__StartFirmwareUpgradeResponse) { printf("%s,%d\n",__FUNCTION__, __LINE__); return 0; }
/** Web service operation '__tds__StartSystemRestore_' implementation, should return SOAP_OK or error code */
SOAP_FMAC5 int SOAP_FMAC6 __tds__StartSystemRestore_(struct soap* soap, struct _tds__StartSystemRestore *tds__StartSystemRestore, struct _tds__StartSystemRestoreResponse *tds__StartSystemRestoreResponse) { printf("%s,%d\n",__FUNCTION__, __LINE__); return 0; }
/** Web service operation '__tds__GetStorageConfigurations_' implementation, should return SOAP_OK or error code */
SOAP_FMAC5 int SOAP_FMAC6 __tds__GetStorageConfigurations_(struct soap* soap, struct _tds__GetStorageConfigurations *tds__GetStorageConfigurations, struct _tds__GetStorageConfigurationsResponse *tds__GetStorageConfigurationsResponse) { printf("%s,%d\n",__FUNCTION__, __LINE__); return 0; }
/** Web service operation '__tds__CreateStorageConfiguration_' implementation, should return SOAP_OK or error code */
SOAP_FMAC5 int SOAP_FMAC6 __tds__CreateStorageConfiguration_(struct soap* soap, struct _tds__CreateStorageConfiguration *tds__CreateStorageConfiguration, struct _tds__CreateStorageConfigurationResponse *tds__CreateStorageConfigurationResponse) { printf("%s,%d\n",__FUNCTION__, __LINE__); return 0; }
/** Web service operation '__tds__GetStorageConfiguration_' implementation, should return SOAP_OK or error code */
SOAP_FMAC5 int SOAP_FMAC6 __tds__GetStorageConfiguration_(struct soap* soap, struct _tds__GetStorageConfiguration *tds__GetStorageConfiguration, struct _tds__GetStorageConfigurationResponse *tds__GetStorageConfigurationResponse) { printf("%s,%d\n",__FUNCTION__, __LINE__); return 0; }
/** Web service operation '__tds__SetStorageConfiguration_' implementation, should return SOAP_OK or error code */
SOAP_FMAC5 int SOAP_FMAC6 __tds__SetStorageConfiguration_(struct soap* soap, struct _tds__SetStorageConfiguration *tds__SetStorageConfiguration, struct _tds__SetStorageConfigurationResponse *tds__SetStorageConfigurationResponse) { printf("%s,%d\n",__FUNCTION__, __LINE__); return 0; }
/** Web service operation '__tds__DeleteStorageConfiguration_' implementation, should return SOAP_OK or error code */
SOAP_FMAC5 int SOAP_FMAC6 __tds__DeleteStorageConfiguration_(struct soap* soap, struct _tds__DeleteStorageConfiguration *tds__DeleteStorageConfiguration, struct _tds__DeleteStorageConfigurationResponse *tds__DeleteStorageConfigurationResponse) { printf("%s,%d\n",__FUNCTION__, __LINE__); return 0; }
/** Web service operation '__tds__GetGeoLocation_' implementation, should return SOAP_OK or error code */
SOAP_FMAC5 int SOAP_FMAC6 __tds__GetGeoLocation_(struct soap* soap, struct _tds__GetGeoLocation *tds__GetGeoLocation, struct _tds__GetGeoLocationResponse *tds__GetGeoLocationResponse) { printf("%s,%d\n",__FUNCTION__, __LINE__); return 0; }
/** Web service operation '__tds__SetGeoLocation_' implementation, should return SOAP_OK or error code */
SOAP_FMAC5 int SOAP_FMAC6 __tds__SetGeoLocation_(struct soap* soap, struct _tds__SetGeoLocation *tds__SetGeoLocation, struct _tds__SetGeoLocationResponse *tds__SetGeoLocationResponse) { printf("%s,%d\n",__FUNCTION__, __LINE__); return 0; }
/** Web service operation '__tds__DeleteGeoLocation_' implementation, should return SOAP_OK or error code */
SOAP_FMAC5 int SOAP_FMAC6 __tds__DeleteGeoLocation_(struct soap* soap, struct _tds__DeleteGeoLocation *tds__DeleteGeoLocation, struct _tds__DeleteGeoLocationResponse *tds__DeleteGeoLocationResponse) { printf("%s,%d\n",__FUNCTION__, __LINE__); return 0; }
/** Web service operation '__tev__PullMessages' implementation, should return SOAP_OK or error code */
SOAP_FMAC5 int SOAP_FMAC6 __tev__PullMessages(struct soap* soap, struct _tev__PullMessages *tev__PullMessages, struct _tev__PullMessagesResponse *tev__PullMessagesResponse) { printf("%s,%d\n",__FUNCTION__, __LINE__); return 0; }
/** Web service operation '__tev__Seek' implementation, should return SOAP_OK or error code */
SOAP_FMAC5 int SOAP_FMAC6 __tev__Seek(struct soap* soap, struct _tev__Seek *tev__Seek, struct _tev__SeekResponse *tev__SeekResponse) { printf("%s,%d\n",__FUNCTION__, __LINE__); return 0; }
/** Web service operation '__tev__SetSynchronizationPoint' implementation, should return SOAP_OK or error code */
SOAP_FMAC5 int SOAP_FMAC6 __tev__SetSynchronizationPoint(struct soap* soap, struct _tev__SetSynchronizationPoint *tev__SetSynchronizationPoint, struct _tev__SetSynchronizationPointResponse *tev__SetSynchronizationPointResponse) { printf("%s,%d\n",__FUNCTION__, __LINE__); return 0; }
/** Web service operation '__tev__Unsubscribe' implementation, should return SOAP_OK or error code */
SOAP_FMAC5 int SOAP_FMAC6 __tev__Unsubscribe(struct soap* soap, struct _wsnt__Unsubscribe *wsnt__Unsubscribe, struct _wsnt__UnsubscribeResponse *wsnt__UnsubscribeResponse) { printf("%s,%d\n",__FUNCTION__, __LINE__); return 0; }
/** Web service operation '__tev__GetServiceCapabilities' implementation, should return SOAP_OK or error code */
SOAP_FMAC5 int SOAP_FMAC6 __tev__GetServiceCapabilities(struct soap* soap, struct _tev__GetServiceCapabilities *tev__GetServiceCapabilities, struct _tev__GetServiceCapabilitiesResponse *tev__GetServiceCapabilitiesResponse) { printf("%s,%d\n",__FUNCTION__, __LINE__); return 0; }
/** Web service operation '__tev__CreatePullPointSubscription' implementation, should return SOAP_OK or error code */
SOAP_FMAC5 int SOAP_FMAC6 __tev__CreatePullPointSubscription(struct soap* soap, struct _tev__CreatePullPointSubscription *tev__CreatePullPointSubscription, struct _tev__CreatePullPointSubscriptionResponse *tev__CreatePullPointSubscriptionResponse) { printf("%s,%d\n",__FUNCTION__, __LINE__); return 0; }
/** Web service operation '__tev__GetEventProperties' implementation, should return SOAP_OK or error code */
SOAP_FMAC5 int SOAP_FMAC6 __tev__GetEventProperties(struct soap* soap, struct _tev__GetEventProperties *tev__GetEventProperties, struct _tev__GetEventPropertiesResponse *tev__GetEventPropertiesResponse) { printf("%s,%d\n",__FUNCTION__, __LINE__); return 0; }
/** Web service operation '__tev__Renew' implementation, should return SOAP_OK or error code */
SOAP_FMAC5 int SOAP_FMAC6 __tev__Renew(struct soap* soap, struct _wsnt__Renew *wsnt__Renew, struct _wsnt__RenewResponse *wsnt__RenewResponse) { printf("%s,%d\n",__FUNCTION__, __LINE__); return 0; }
/** Web service operation '__tev__Unsubscribe_' implementation, should return SOAP_OK or error code */
SOAP_FMAC5 int SOAP_FMAC6 __tev__Unsubscribe_(struct soap* soap, struct _wsnt__Unsubscribe *wsnt__Unsubscribe, struct _wsnt__UnsubscribeResponse *wsnt__UnsubscribeResponse) { printf("%s,%d\n",__FUNCTION__, __LINE__); return 0; }
/** Web service operation '__tev__Subscribe' implementation, should return SOAP_OK or error code */
SOAP_FMAC5 int SOAP_FMAC6 __tev__Subscribe(struct soap* soap, struct _wsnt__Subscribe *wsnt__Subscribe, struct _wsnt__SubscribeResponse *wsnt__SubscribeResponse) { printf("%s,%d\n",__FUNCTION__, __LINE__); return 0; }
/** Web service operation '__tev__GetCurrentMessage' implementation, should return SOAP_OK or error code */
SOAP_FMAC5 int SOAP_FMAC6 __tev__GetCurrentMessage(struct soap* soap, struct _wsnt__GetCurrentMessage *wsnt__GetCurrentMessage, struct _wsnt__GetCurrentMessageResponse *wsnt__GetCurrentMessageResponse) { printf("%s,%d\n",__FUNCTION__, __LINE__); return 0; }
/** Web service one-way operation '__tev__Notify' implementation, should return value of soap_send_empty_response() to send HTTP Accept acknowledgment, or return an error code, or return SOAP_OK to immediately return without sending an HTTP response message */
SOAP_FMAC5 int SOAP_FMAC6 __tev__Notify(struct soap* soap, struct _wsnt__Notify *wsnt__Notify) { printf("%s,%d\n",__FUNCTION__, __LINE__); return 0; }
/** Web service operation '__tev__GetMessages' implementation, should return SOAP_OK or error code */
SOAP_FMAC5 int SOAP_FMAC6 __tev__GetMessages(struct soap* soap, struct _wsnt__GetMessages *wsnt__GetMessages, struct _wsnt__GetMessagesResponse *wsnt__GetMessagesResponse) { printf("%s,%d\n",__FUNCTION__, __LINE__); return 0; }
/** Web service operation '__tev__DestroyPullPoint' implementation, should return SOAP_OK or error code */
SOAP_FMAC5 int SOAP_FMAC6 __tev__DestroyPullPoint(struct soap* soap, struct _wsnt__DestroyPullPoint *wsnt__DestroyPullPoint, struct _wsnt__DestroyPullPointResponse *wsnt__DestroyPullPointResponse) { printf("%s,%d\n",__FUNCTION__, __LINE__); return 0; }
/** Web service one-way operation '__tev__Notify_' implementation, should return value of soap_send_empty_response() to send HTTP Accept acknowledgment, or return an error code, or return SOAP_OK to immediately return without sending an HTTP response message */
SOAP_FMAC5 int SOAP_FMAC6 __tev__Notify_(struct soap* soap, struct _wsnt__Notify *wsnt__Notify) { printf("%s,%d\n",__FUNCTION__, __LINE__); return 0; }
/** Web service operation '__tev__CreatePullPoint' implementation, should return SOAP_OK or error code */
SOAP_FMAC5 int SOAP_FMAC6 __tev__CreatePullPoint(struct soap* soap, struct _wsnt__CreatePullPoint *wsnt__CreatePullPoint, struct _wsnt__CreatePullPointResponse *wsnt__CreatePullPointResponse) { printf("%s,%d\n",__FUNCTION__, __LINE__); return 0; }
/** Web service operation '__tev__Renew_' implementation, should return SOAP_OK or error code */
SOAP_FMAC5 int SOAP_FMAC6 __tev__Renew_(struct soap* soap, struct _wsnt__Renew *wsnt__Renew, struct _wsnt__RenewResponse *wsnt__RenewResponse) { printf("%s,%d\n",__FUNCTION__, __LINE__); return 0; }
/** Web service operation '__tev__Unsubscribe__' implementation, should return SOAP_OK or error code */
SOAP_FMAC5 int SOAP_FMAC6 __tev__Unsubscribe__(struct soap* soap, struct _wsnt__Unsubscribe *wsnt__Unsubscribe, struct _wsnt__UnsubscribeResponse *wsnt__UnsubscribeResponse) { printf("%s,%d\n",__FUNCTION__, __LINE__); return 0; }
/** Web service operation '__tev__PauseSubscription' implementation, should return SOAP_OK or error code */
SOAP_FMAC5 int SOAP_FMAC6 __tev__PauseSubscription(struct soap* soap, struct _wsnt__PauseSubscription *wsnt__PauseSubscription, struct _wsnt__PauseSubscriptionResponse *wsnt__PauseSubscriptionResponse) { printf("%s,%d\n",__FUNCTION__, __LINE__); return 0; }
/** Web service operation '__tev__ResumeSubscription' implementation, should return SOAP_OK or error code */
SOAP_FMAC5 int SOAP_FMAC6 __tev__ResumeSubscription(struct soap* soap, struct _wsnt__ResumeSubscription *wsnt__ResumeSubscription, struct _wsnt__ResumeSubscriptionResponse *wsnt__ResumeSubscriptionResponse) { printf("%s,%d\n",__FUNCTION__, __LINE__); return 0; }
/** Web service operation '__timg__GetServiceCapabilities' implementation, should return SOAP_OK or error code */
SOAP_FMAC5 int SOAP_FMAC6 __timg__GetServiceCapabilities(struct soap* soap, struct _timg__GetServiceCapabilities *timg__GetServiceCapabilities, struct _timg__GetServiceCapabilitiesResponse *timg__GetServiceCapabilitiesResponse) { printf("%s,%d\n",__FUNCTION__, __LINE__); return 0; }
/** Web service operation '__timg__GetImagingSettings' implementation, should return SOAP_OK or error code */
SOAP_FMAC5 int SOAP_FMAC6 __timg__GetImagingSettings(struct soap* soap, struct _timg__GetImagingSettings *timg__GetImagingSettings, struct _timg__GetImagingSettingsResponse *timg__GetImagingSettingsResponse) { printf("%s,%d\n",__FUNCTION__, __LINE__); return 0; }
/** Web service operation '__timg__SetImagingSettings' implementation, should return SOAP_OK or error code */
SOAP_FMAC5 int SOAP_FMAC6 __timg__SetImagingSettings(struct soap* soap, struct _timg__SetImagingSettings *timg__SetImagingSettings, struct _timg__SetImagingSettingsResponse *timg__SetImagingSettingsResponse) { printf("%s,%d\n",__FUNCTION__, __LINE__); return 0; }
/** Web service operation '__timg__GetOptions' implementation, should return SOAP_OK or error code */
SOAP_FMAC5 int SOAP_FMAC6 __timg__GetOptions(struct soap* soap, struct _timg__GetOptions *timg__GetOptions, struct _timg__GetOptionsResponse *timg__GetOptionsResponse) { printf("%s,%d\n",__FUNCTION__, __LINE__); return 0; }
/** Web service operation '__timg__Move' implementation, should return SOAP_OK or error code */
SOAP_FMAC5 int SOAP_FMAC6 __timg__Move(struct soap* soap, struct _timg__Move *timg__Move, struct _timg__MoveResponse *timg__MoveResponse) { printf("%s,%d\n",__FUNCTION__, __LINE__); return 0; }
/** Web service operation '__timg__Stop' implementation, should return SOAP_OK or error code */
SOAP_FMAC5 int SOAP_FMAC6 __timg__Stop(struct soap* soap, struct _timg__Stop *timg__Stop, struct _timg__StopResponse *timg__StopResponse) { printf("%s,%d\n",__FUNCTION__, __LINE__); return 0; }
/** Web service operation '__timg__GetStatus' implementation, should return SOAP_OK or error code */
SOAP_FMAC5 int SOAP_FMAC6 __timg__GetStatus(struct soap* soap, struct _timg__GetStatus *timg__GetStatus, struct _timg__GetStatusResponse *timg__GetStatusResponse) { printf("%s,%d\n",__FUNCTION__, __LINE__); return 0; }
/** Web service operation '__timg__GetMoveOptions' implementation, should return SOAP_OK or error code */
SOAP_FMAC5 int SOAP_FMAC6 __timg__GetMoveOptions(struct soap* soap, struct _timg__GetMoveOptions *timg__GetMoveOptions, struct _timg__GetMoveOptionsResponse *timg__GetMoveOptionsResponse) { printf("%s,%d\n",__FUNCTION__, __LINE__); return 0; }
/** Web service operation '__timg__GetPresets' implementation, should return SOAP_OK or error code */
SOAP_FMAC5 int SOAP_FMAC6 __timg__GetPresets(struct soap* soap, struct _timg__GetPresets *timg__GetPresets, struct _timg__GetPresetsResponse *timg__GetPresetsResponse) { printf("%s,%d\n",__FUNCTION__, __LINE__); return 0; }
/** Web service operation '__timg__GetCurrentPreset' implementation, should return SOAP_OK or error code */
SOAP_FMAC5 int SOAP_FMAC6 __timg__GetCurrentPreset(struct soap* soap, struct _timg__GetCurrentPreset *timg__GetCurrentPreset, struct _timg__GetCurrentPresetResponse *timg__GetCurrentPresetResponse) { printf("%s,%d\n",__FUNCTION__, __LINE__); return 0; }
/** Web service operation '__timg__SetCurrentPreset' implementation, should return SOAP_OK or error code */
SOAP_FMAC5 int SOAP_FMAC6 __timg__SetCurrentPreset(struct soap* soap, struct _timg__SetCurrentPreset *timg__SetCurrentPreset, struct _timg__SetCurrentPresetResponse *timg__SetCurrentPresetResponse) { printf("%s,%d\n",__FUNCTION__, __LINE__); return 0; }
/** Web service operation '__tls__GetServiceCapabilities' implementation, should return SOAP_OK or error code */
SOAP_FMAC5 int SOAP_FMAC6 __tls__GetServiceCapabilities(struct soap* soap, struct _tls__GetServiceCapabilities *tls__GetServiceCapabilities, struct _tls__GetServiceCapabilitiesResponse *tls__GetServiceCapabilitiesResponse) { printf("%s,%d\n",__FUNCTION__, __LINE__); return 0; }
/** Web service operation '__tls__GetLayout' implementation, should return SOAP_OK or error code */
SOAP_FMAC5 int SOAP_FMAC6 __tls__GetLayout(struct soap* soap, struct _tls__GetLayout *tls__GetLayout, struct _tls__GetLayoutResponse *tls__GetLayoutResponse) { printf("%s,%d\n",__FUNCTION__, __LINE__); return 0; }
/** Web service operation '__tls__SetLayout' implementation, should return SOAP_OK or error code */
SOAP_FMAC5 int SOAP_FMAC6 __tls__SetLayout(struct soap* soap, struct _tls__SetLayout *tls__SetLayout, struct _tls__SetLayoutResponse *tls__SetLayoutResponse) { printf("%s,%d\n",__FUNCTION__, __LINE__); return 0; }
/** Web service operation '__tls__GetDisplayOptions' implementation, should return SOAP_OK or error code */
SOAP_FMAC5 int SOAP_FMAC6 __tls__GetDisplayOptions(struct soap* soap, struct _tls__GetDisplayOptions *tls__GetDisplayOptions, struct _tls__GetDisplayOptionsResponse *tls__GetDisplayOptionsResponse) { printf("%s,%d\n",__FUNCTION__, __LINE__); return 0; }
/** Web service operation '__tls__GetPaneConfigurations' implementation, should return SOAP_OK or error code */
SOAP_FMAC5 int SOAP_FMAC6 __tls__GetPaneConfigurations(struct soap* soap, struct _tls__GetPaneConfigurations *tls__GetPaneConfigurations, struct _tls__GetPaneConfigurationsResponse *tls__GetPaneConfigurationsResponse) { printf("%s,%d\n",__FUNCTION__, __LINE__); return 0; }
/** Web service operation '__tls__GetPaneConfiguration' implementation, should return SOAP_OK or error code */
SOAP_FMAC5 int SOAP_FMAC6 __tls__GetPaneConfiguration(struct soap* soap, struct _tls__GetPaneConfiguration *tls__GetPaneConfiguration, struct _tls__GetPaneConfigurationResponse *tls__GetPaneConfigurationResponse) { printf("%s,%d\n",__FUNCTION__, __LINE__); return 0; }
/** Web service operation '__tls__SetPaneConfigurations' implementation, should return SOAP_OK or error code */
SOAP_FMAC5 int SOAP_FMAC6 __tls__SetPaneConfigurations(struct soap* soap, struct _tls__SetPaneConfigurations *tls__SetPaneConfigurations, struct _tls__SetPaneConfigurationsResponse *tls__SetPaneConfigurationsResponse) { printf("%s,%d\n",__FUNCTION__, __LINE__); return 0; }
/** Web service operation '__tls__SetPaneConfiguration' implementation, should return SOAP_OK or error code */
SOAP_FMAC5 int SOAP_FMAC6 __tls__SetPaneConfiguration(struct soap* soap, struct _tls__SetPaneConfiguration *tls__SetPaneConfiguration, struct _tls__SetPaneConfigurationResponse *tls__SetPaneConfigurationResponse) { printf("%s,%d\n",__FUNCTION__, __LINE__); return 0; }
/** Web service operation '__tls__CreatePaneConfiguration' implementation, should return SOAP_OK or error code */
SOAP_FMAC5 int SOAP_FMAC6 __tls__CreatePaneConfiguration(struct soap* soap, struct _tls__CreatePaneConfiguration *tls__CreatePaneConfiguration, struct _tls__CreatePaneConfigurationResponse *tls__CreatePaneConfigurationResponse) { printf("%s,%d\n",__FUNCTION__, __LINE__); return 0; }
/** Web service operation '__tls__DeletePaneConfiguration' implementation, should return SOAP_OK or error code */
SOAP_FMAC5 int SOAP_FMAC6 __tls__DeletePaneConfiguration(struct soap* soap, struct _tls__DeletePaneConfiguration *tls__DeletePaneConfiguration, struct _tls__DeletePaneConfigurationResponse *tls__DeletePaneConfigurationResponse) { printf("%s,%d\n",__FUNCTION__, __LINE__); return 0; }
/** Web service operation '__tmd__GetServiceCapabilities' implementation, should return SOAP_OK or error code */
SOAP_FMAC5 int SOAP_FMAC6 __tmd__GetServiceCapabilities(struct soap* soap, struct _tmd__GetServiceCapabilities *tmd__GetServiceCapabilities, struct _tmd__GetServiceCapabilitiesResponse *tmd__GetServiceCapabilitiesResponse) { printf("%s,%d\n",__FUNCTION__, __LINE__); return 0; }
/** Web service operation '__tmd__GetRelayOutputOptions' implementation, should return SOAP_OK or error code */
SOAP_FMAC5 int SOAP_FMAC6 __tmd__GetRelayOutputOptions(struct soap* soap, struct _tmd__GetRelayOutputOptions *tmd__GetRelayOutputOptions, struct _tmd__GetRelayOutputOptionsResponse *tmd__GetRelayOutputOptionsResponse) { printf("%s,%d\n",__FUNCTION__, __LINE__); return 0; }
/** Web service operation '__tmd__GetAudioSources' implementation, should return SOAP_OK or error code */
SOAP_FMAC5 int SOAP_FMAC6 __tmd__GetAudioSources(struct soap* soap, struct tmd__Get *tmd__GetAudioSources, struct tmd__GetResponse *tmd__GetAudioSourcesResponse) { printf("%s,%d\n",__FUNCTION__, __LINE__); return 0; }
/** Web service operation '__tmd__GetAudioOutputs' implementation, should return SOAP_OK or error code */
SOAP_FMAC5 int SOAP_FMAC6 __tmd__GetAudioOutputs(struct soap* soap, struct tmd__Get *tmd__GetAudioOutputs, struct tmd__GetResponse *tmd__GetAudioOutputsResponse) { printf("%s,%d\n",__FUNCTION__, __LINE__); return 0; }
/** Web service operation '__tmd__GetVideoSources' implementation, should return SOAP_OK or error code */
SOAP_FMAC5 int SOAP_FMAC6 __tmd__GetVideoSources(struct soap* soap, struct tmd__Get *tmd__GetVideoSources, struct tmd__GetResponse *tmd__GetVideoSourcesResponse) { printf("%s,%d\n",__FUNCTION__, __LINE__); return 0; }
/** Web service operation '__tmd__GetVideoOutputs' implementation, should return SOAP_OK or error code */
SOAP_FMAC5 int SOAP_FMAC6 __tmd__GetVideoOutputs(struct soap* soap, struct _tmd__GetVideoOutputs *tmd__GetVideoOutputs, struct _tmd__GetVideoOutputsResponse *tmd__GetVideoOutputsResponse) { printf("%s,%d\n",__FUNCTION__, __LINE__); return 0; }
/** Web service operation '__tmd__GetVideoSourceConfiguration' implementation, should return SOAP_OK or error code */
SOAP_FMAC5 int SOAP_FMAC6 __tmd__GetVideoSourceConfiguration(struct soap* soap, struct _tmd__GetVideoSourceConfiguration *tmd__GetVideoSourceConfiguration, struct _tmd__GetVideoSourceConfigurationResponse *tmd__GetVideoSourceConfigurationResponse) { printf("%s,%d\n",__FUNCTION__, __LINE__); return 0; }
/** Web service operation '__tmd__GetVideoOutputConfiguration' implementation, should return SOAP_OK or error code */
SOAP_FMAC5 int SOAP_FMAC6 __tmd__GetVideoOutputConfiguration(struct soap* soap, struct _tmd__GetVideoOutputConfiguration *tmd__GetVideoOutputConfiguration, struct _tmd__GetVideoOutputConfigurationResponse *tmd__GetVideoOutputConfigurationResponse) { printf("%s,%d\n",__FUNCTION__, __LINE__); return 0; }
/** Web service operation '__tmd__GetAudioSourceConfiguration' implementation, should return SOAP_OK or error code */
SOAP_FMAC5 int SOAP_FMAC6 __tmd__GetAudioSourceConfiguration(struct soap* soap, struct _tmd__GetAudioSourceConfiguration *tmd__GetAudioSourceConfiguration, struct _tmd__GetAudioSourceConfigurationResponse *tmd__GetAudioSourceConfigurationResponse) { printf("%s,%d\n",__FUNCTION__, __LINE__); return 0; }
/** Web service operation '__tmd__GetAudioOutputConfiguration' implementation, should return SOAP_OK or error code */
SOAP_FMAC5 int SOAP_FMAC6 __tmd__GetAudioOutputConfiguration(struct soap* soap, struct _tmd__GetAudioOutputConfiguration *tmd__GetAudioOutputConfiguration, struct _tmd__GetAudioOutputConfigurationResponse *tmd__GetAudioOutputConfigurationResponse) { printf("%s,%d\n",__FUNCTION__, __LINE__); return 0; }
/** Web service operation '__tmd__SetVideoSourceConfiguration' implementation, should return SOAP_OK or error code */
SOAP_FMAC5 int SOAP_FMAC6 __tmd__SetVideoSourceConfiguration(struct soap* soap, struct _tmd__SetVideoSourceConfiguration *tmd__SetVideoSourceConfiguration, struct _tmd__SetVideoSourceConfigurationResponse *tmd__SetVideoSourceConfigurationResponse) { printf("%s,%d\n",__FUNCTION__, __LINE__); return 0; }
/** Web service operation '__tmd__SetVideoOutputConfiguration' implementation, should return SOAP_OK or error code */
SOAP_FMAC5 int SOAP_FMAC6 __tmd__SetVideoOutputConfiguration(struct soap* soap, struct _tmd__SetVideoOutputConfiguration *tmd__SetVideoOutputConfiguration, struct _tmd__SetVideoOutputConfigurationResponse *tmd__SetVideoOutputConfigurationResponse) { printf("%s,%d\n",__FUNCTION__, __LINE__); return 0; }
/** Web service operation '__tmd__SetAudioSourceConfiguration' implementation, should return SOAP_OK or error code */
SOAP_FMAC5 int SOAP_FMAC6 __tmd__SetAudioSourceConfiguration(struct soap* soap, struct _tmd__SetAudioSourceConfiguration *tmd__SetAudioSourceConfiguration, struct _tmd__SetAudioSourceConfigurationResponse *tmd__SetAudioSourceConfigurationResponse) { printf("%s,%d\n",__FUNCTION__, __LINE__); return 0; }
/** Web service operation '__tmd__SetAudioOutputConfiguration' implementation, should return SOAP_OK or error code */
SOAP_FMAC5 int SOAP_FMAC6 __tmd__SetAudioOutputConfiguration(struct soap* soap, struct _tmd__SetAudioOutputConfiguration *tmd__SetAudioOutputConfiguration, struct _tmd__SetAudioOutputConfigurationResponse *tmd__SetAudioOutputConfigurationResponse) { printf("%s,%d\n",__FUNCTION__, __LINE__); return 0; }
/** Web service operation '__tmd__GetVideoSourceConfigurationOptions' implementation, should return SOAP_OK or error code */
SOAP_FMAC5 int SOAP_FMAC6 __tmd__GetVideoSourceConfigurationOptions(struct soap* soap, struct _tmd__GetVideoSourceConfigurationOptions *tmd__GetVideoSourceConfigurationOptions, struct _tmd__GetVideoSourceConfigurationOptionsResponse *tmd__GetVideoSourceConfigurationOptionsResponse) { printf("%s,%d\n",__FUNCTION__, __LINE__); return 0; }
/** Web service operation '__tmd__GetVideoOutputConfigurationOptions' implementation, should return SOAP_OK or error code */
SOAP_FMAC5 int SOAP_FMAC6 __tmd__GetVideoOutputConfigurationOptions(struct soap* soap, struct _tmd__GetVideoOutputConfigurationOptions *tmd__GetVideoOutputConfigurationOptions, struct _tmd__GetVideoOutputConfigurationOptionsResponse *tmd__GetVideoOutputConfigurationOptionsResponse) { printf("%s,%d\n",__FUNCTION__, __LINE__); return 0; }
/** Web service operation '__tmd__GetAudioSourceConfigurationOptions' implementation, should return SOAP_OK or error code */
SOAP_FMAC5 int SOAP_FMAC6 __tmd__GetAudioSourceConfigurationOptions(struct soap* soap, struct _tmd__GetAudioSourceConfigurationOptions *tmd__GetAudioSourceConfigurationOptions, struct _tmd__GetAudioSourceConfigurationOptionsResponse *tmd__GetAudioSourceConfigurationOptionsResponse) { printf("%s,%d\n",__FUNCTION__, __LINE__); return 0; }
/** Web service operation '__tmd__GetAudioOutputConfigurationOptions' implementation, should return SOAP_OK or error code */
SOAP_FMAC5 int SOAP_FMAC6 __tmd__GetAudioOutputConfigurationOptions(struct soap* soap, struct _tmd__GetAudioOutputConfigurationOptions *tmd__GetAudioOutputConfigurationOptions, struct _tmd__GetAudioOutputConfigurationOptionsResponse *tmd__GetAudioOutputConfigurationOptionsResponse) { printf("%s,%d\n",__FUNCTION__, __LINE__); return 0; }
/** Web service operation '__tmd__GetRelayOutputs' implementation, should return SOAP_OK or error code */
SOAP_FMAC5 int SOAP_FMAC6 __tmd__GetRelayOutputs(struct soap* soap, struct _tds__GetRelayOutputs *tds__GetRelayOutputs, struct _tds__GetRelayOutputsResponse *tds__GetRelayOutputsResponse) { printf("%s,%d\n",__FUNCTION__, __LINE__); return 0; }
/** Web service operation '__tmd__SetRelayOutputSettings' implementation, should return SOAP_OK or error code */
SOAP_FMAC5 int SOAP_FMAC6 __tmd__SetRelayOutputSettings(struct soap* soap, struct _tmd__SetRelayOutputSettings *tmd__SetRelayOutputSettings, struct _tmd__SetRelayOutputSettingsResponse *tmd__SetRelayOutputSettingsResponse) { printf("%s,%d\n",__FUNCTION__, __LINE__); return 0; }
/** Web service operation '__tmd__SetRelayOutputState' implementation, should return SOAP_OK or error code */
SOAP_FMAC5 int SOAP_FMAC6 __tmd__SetRelayOutputState(struct soap* soap, struct _tds__SetRelayOutputState *tds__SetRelayOutputState, struct _tds__SetRelayOutputStateResponse *tds__SetRelayOutputStateResponse) { printf("%s,%d\n",__FUNCTION__, __LINE__); return 0; }
/** Web service operation '__tmd__GetDigitalInputs' implementation, should return SOAP_OK or error code */
SOAP_FMAC5 int SOAP_FMAC6 __tmd__GetDigitalInputs(struct soap* soap, struct _tmd__GetDigitalInputs *tmd__GetDigitalInputs, struct _tmd__GetDigitalInputsResponse *tmd__GetDigitalInputsResponse) { printf("%s,%d\n",__FUNCTION__, __LINE__); return 0; }
/** Web service operation '__tmd__GetDigitalInputConfigurationOptions' implementation, should return SOAP_OK or error code */
SOAP_FMAC5 int SOAP_FMAC6 __tmd__GetDigitalInputConfigurationOptions(struct soap* soap, struct _tmd__GetDigitalInputConfigurationOptions *tmd__GetDigitalInputConfigurationOptions, struct _tmd__GetDigitalInputConfigurationOptionsResponse *tmd__GetDigitalInputConfigurationOptionsResponse) { printf("%s,%d\n",__FUNCTION__, __LINE__); return 0; }
/** Web service operation '__tmd__SetDigitalInputConfigurations' implementation, should return SOAP_OK or error code */
SOAP_FMAC5 int SOAP_FMAC6 __tmd__SetDigitalInputConfigurations(struct soap* soap, struct _tmd__SetDigitalInputConfigurations *tmd__SetDigitalInputConfigurations, struct _tmd__SetDigitalInputConfigurationsResponse *tmd__SetDigitalInputConfigurationsResponse) { printf("%s,%d\n",__FUNCTION__, __LINE__); return 0; }
/** Web service operation '__tmd__GetSerialPorts' implementation, should return SOAP_OK or error code */
SOAP_FMAC5 int SOAP_FMAC6 __tmd__GetSerialPorts(struct soap* soap, struct _tmd__GetSerialPorts *tmd__GetSerialPorts, struct _tmd__GetSerialPortsResponse *tmd__GetSerialPortsResponse) { printf("%s,%d\n",__FUNCTION__, __LINE__); return 0; }
/** Web service operation '__tmd__GetSerialPortConfiguration' implementation, should return SOAP_OK or error code */
SOAP_FMAC5 int SOAP_FMAC6 __tmd__GetSerialPortConfiguration(struct soap* soap, struct _tmd__GetSerialPortConfiguration *tmd__GetSerialPortConfiguration, struct _tmd__GetSerialPortConfigurationResponse *tmd__GetSerialPortConfigurationResponse) { printf("%s,%d\n",__FUNCTION__, __LINE__); return 0; }
/** Web service operation '__tmd__SetSerialPortConfiguration' implementation, should return SOAP_OK or error code */
SOAP_FMAC5 int SOAP_FMAC6 __tmd__SetSerialPortConfiguration(struct soap* soap, struct _tmd__SetSerialPortConfiguration *tmd__SetSerialPortConfiguration, struct _tmd__SetSerialPortConfigurationResponse *tmd__SetSerialPortConfigurationResponse) { printf("%s,%d\n",__FUNCTION__, __LINE__); return 0; }
/** Web service operation '__tmd__GetSerialPortConfigurationOptions' implementation, should return SOAP_OK or error code */
SOAP_FMAC5 int SOAP_FMAC6 __tmd__GetSerialPortConfigurationOptions(struct soap* soap, struct _tmd__GetSerialPortConfigurationOptions *tmd__GetSerialPortConfigurationOptions, struct _tmd__GetSerialPortConfigurationOptionsResponse *tmd__GetSerialPortConfigurationOptionsResponse) { printf("%s,%d\n",__FUNCTION__, __LINE__); return 0; }
/** Web service operation '__tmd__SendReceiveSerialCommand' implementation, should return SOAP_OK or error code */
SOAP_FMAC5 int SOAP_FMAC6 __tmd__SendReceiveSerialCommand(struct soap* soap, struct _tmd__SendReceiveSerialCommand *tmd__SendReceiveSerialCommand, struct _tmd__SendReceiveSerialCommandResponse *tmd__SendReceiveSerialCommandResponse) { printf("%s,%d\n",__FUNCTION__, __LINE__); return 0; }
/** Web service operation '__tptz__GetServiceCapabilities' implementation, should return SOAP_OK or error code */
SOAP_FMAC5 int SOAP_FMAC6 __tptz__GetServiceCapabilities(struct soap* soap, struct _tptz__GetServiceCapabilities *tptz__GetServiceCapabilities, struct _tptz__GetServiceCapabilitiesResponse *tptz__GetServiceCapabilitiesResponse) { printf("%s,%d\n",__FUNCTION__, __LINE__); return 0; }
/** Web service operation '__tptz__GetConfigurations' implementation, should return SOAP_OK or error code */
SOAP_FMAC5 int SOAP_FMAC6 __tptz__GetConfigurations(struct soap* soap, struct _tptz__GetConfigurations *tptz__GetConfigurations, struct _tptz__GetConfigurationsResponse *tptz__GetConfigurationsResponse) { printf("%s,%d\n",__FUNCTION__, __LINE__); return 0; }
/** Web service operation '__tptz__GetPresets' implementation, should return SOAP_OK or error code */
SOAP_FMAC5 int SOAP_FMAC6 __tptz__GetPresets(struct soap* soap, struct _tptz__GetPresets *tptz__GetPresets, struct _tptz__GetPresetsResponse *tptz__GetPresetsResponse) { printf("%s,%d\n",__FUNCTION__, __LINE__); return 0; }
/** Web service operation '__tptz__SetPreset' implementation, should return SOAP_OK or error code */
SOAP_FMAC5 int SOAP_FMAC6 __tptz__SetPreset(struct soap* soap, struct _tptz__SetPreset *tptz__SetPreset, struct _tptz__SetPresetResponse *tptz__SetPresetResponse) { printf("%s,%d\n",__FUNCTION__, __LINE__); return 0; }
/** Web service operation '__tptz__RemovePreset' implementation, should return SOAP_OK or error code */
SOAP_FMAC5 int SOAP_FMAC6 __tptz__RemovePreset(struct soap* soap, struct _tptz__RemovePreset *tptz__RemovePreset, struct _tptz__RemovePresetResponse *tptz__RemovePresetResponse) { printf("%s,%d\n",__FUNCTION__, __LINE__); return 0; }
/** Web service operation '__tptz__GotoPreset' implementation, should return SOAP_OK or error code */
SOAP_FMAC5 int SOAP_FMAC6 __tptz__GotoPreset(struct soap* soap, struct _tptz__GotoPreset *tptz__GotoPreset, struct _tptz__GotoPresetResponse *tptz__GotoPresetResponse) { printf("%s,%d\n",__FUNCTION__, __LINE__); return 0; }
/** Web service operation '__tptz__GetStatus' implementation, should return SOAP_OK or error code */
SOAP_FMAC5 int SOAP_FMAC6 __tptz__GetStatus(struct soap* soap, struct _tptz__GetStatus *tptz__GetStatus, struct _tptz__GetStatusResponse *tptz__GetStatusResponse) { printf("%s,%d\n",__FUNCTION__, __LINE__); return 0; }
/** Web service operation '__tptz__GetConfiguration' implementation, should return SOAP_OK or error code */
SOAP_FMAC5 int SOAP_FMAC6 __tptz__GetConfiguration(struct soap* soap, struct _tptz__GetConfiguration *tptz__GetConfiguration, struct _tptz__GetConfigurationResponse *tptz__GetConfigurationResponse) { printf("%s,%d\n",__FUNCTION__, __LINE__); return 0; }
/** Web service operation '__tptz__GetNodes' implementation, should return SOAP_OK or error code */
SOAP_FMAC5 int SOAP_FMAC6 __tptz__GetNodes(struct soap* soap, struct _tptz__GetNodes *tptz__GetNodes, struct _tptz__GetNodesResponse *tptz__GetNodesResponse) { printf("%s,%d\n",__FUNCTION__, __LINE__); return 0; }
/** Web service operation '__tptz__GetNode' implementation, should return SOAP_OK or error code */
SOAP_FMAC5 int SOAP_FMAC6 __tptz__GetNode(struct soap* soap, struct _tptz__GetNode *tptz__GetNode, struct _tptz__GetNodeResponse *tptz__GetNodeResponse) { printf("%s,%d\n",__FUNCTION__, __LINE__); return 0; }
/** Web service operation '__tptz__SetConfiguration' implementation, should return SOAP_OK or error code */
SOAP_FMAC5 int SOAP_FMAC6 __tptz__SetConfiguration(struct soap* soap, struct _tptz__SetConfiguration *tptz__SetConfiguration, struct _tptz__SetConfigurationResponse *tptz__SetConfigurationResponse) { printf("%s,%d\n",__FUNCTION__, __LINE__); return 0; }
/** Web service operation '__tptz__GetConfigurationOptions' implementation, should return SOAP_OK or error code */
SOAP_FMAC5 int SOAP_FMAC6 __tptz__GetConfigurationOptions(struct soap* soap, struct _tptz__GetConfigurationOptions *tptz__GetConfigurationOptions, struct _tptz__GetConfigurationOptionsResponse *tptz__GetConfigurationOptionsResponse) { printf("%s,%d\n",__FUNCTION__, __LINE__); return 0; }
/** Web service operation '__tptz__GotoHomePosition' implementation, should return SOAP_OK or error code */
SOAP_FMAC5 int SOAP_FMAC6 __tptz__GotoHomePosition(struct soap* soap, struct _tptz__GotoHomePosition *tptz__GotoHomePosition, struct _tptz__GotoHomePositionResponse *tptz__GotoHomePositionResponse) { printf("%s,%d\n",__FUNCTION__, __LINE__); return 0; }
/** Web service operation '__tptz__SetHomePosition' implementation, should return SOAP_OK or error code */
SOAP_FMAC5 int SOAP_FMAC6 __tptz__SetHomePosition(struct soap* soap, struct _tptz__SetHomePosition *tptz__SetHomePosition, struct _tptz__SetHomePositionResponse *tptz__SetHomePositionResponse) { printf("%s,%d\n",__FUNCTION__, __LINE__); return 0; }
/** Web service operation '__tptz__ContinuousMove' implementation, should return SOAP_OK or error code */
SOAP_FMAC5 int SOAP_FMAC6 __tptz__ContinuousMove(struct soap* soap, struct _tptz__ContinuousMove *tptz__ContinuousMove, struct _tptz__ContinuousMoveResponse *tptz__ContinuousMoveResponse) { printf("%s,%d\n",__FUNCTION__, __LINE__); return 0; }
/** Web service operation '__tptz__RelativeMove' implementation, should return SOAP_OK or error code */
SOAP_FMAC5 int SOAP_FMAC6 __tptz__RelativeMove(struct soap* soap, struct _tptz__RelativeMove *tptz__RelativeMove, struct _tptz__RelativeMoveResponse *tptz__RelativeMoveResponse) { printf("%s,%d\n",__FUNCTION__, __LINE__); return 0; }
/** Web service operation '__tptz__SendAuxiliaryCommand' implementation, should return SOAP_OK or error code */
SOAP_FMAC5 int SOAP_FMAC6 __tptz__SendAuxiliaryCommand(struct soap* soap, struct _tptz__SendAuxiliaryCommand *tptz__SendAuxiliaryCommand, struct _tptz__SendAuxiliaryCommandResponse *tptz__SendAuxiliaryCommandResponse) { printf("%s,%d\n",__FUNCTION__, __LINE__); return 0; }
/** Web service operation '__tptz__AbsoluteMove' implementation, should return SOAP_OK or error code */
SOAP_FMAC5 int SOAP_FMAC6 __tptz__AbsoluteMove(struct soap* soap, struct _tptz__AbsoluteMove *tptz__AbsoluteMove, struct _tptz__AbsoluteMoveResponse *tptz__AbsoluteMoveResponse) { printf("%s,%d\n",__FUNCTION__, __LINE__); return 0; }
/** Web service operation '__tptz__GeoMove' implementation, should return SOAP_OK or error code */
SOAP_FMAC5 int SOAP_FMAC6 __tptz__GeoMove(struct soap* soap, struct _tptz__GeoMove *tptz__GeoMove, struct _tptz__GeoMoveResponse *tptz__GeoMoveResponse) { printf("%s,%d\n",__FUNCTION__, __LINE__); return 0; }
/** Web service operation '__tptz__Stop' implementation, should return SOAP_OK or error code */
SOAP_FMAC5 int SOAP_FMAC6 __tptz__Stop(struct soap* soap, struct _tptz__Stop *tptz__Stop, struct _tptz__StopResponse *tptz__StopResponse) { printf("%s,%d\n",__FUNCTION__, __LINE__); return 0; }
/** Web service operation '__tptz__GetPresetTours' implementation, should return SOAP_OK or error code */
SOAP_FMAC5 int SOAP_FMAC6 __tptz__GetPresetTours(struct soap* soap, struct _tptz__GetPresetTours *tptz__GetPresetTours, struct _tptz__GetPresetToursResponse *tptz__GetPresetToursResponse) { printf("%s,%d\n",__FUNCTION__, __LINE__); return 0; }
/** Web service operation '__tptz__GetPresetTour' implementation, should return SOAP_OK or error code */
SOAP_FMAC5 int SOAP_FMAC6 __tptz__GetPresetTour(struct soap* soap, struct _tptz__GetPresetTour *tptz__GetPresetTour, struct _tptz__GetPresetTourResponse *tptz__GetPresetTourResponse) { printf("%s,%d\n",__FUNCTION__, __LINE__); return 0; }
/** Web service operation '__tptz__GetPresetTourOptions' implementation, should return SOAP_OK or error code */
SOAP_FMAC5 int SOAP_FMAC6 __tptz__GetPresetTourOptions(struct soap* soap, struct _tptz__GetPresetTourOptions *tptz__GetPresetTourOptions, struct _tptz__GetPresetTourOptionsResponse *tptz__GetPresetTourOptionsResponse) { printf("%s,%d\n",__FUNCTION__, __LINE__); return 0; }
/** Web service operation '__tptz__CreatePresetTour' implementation, should return SOAP_OK or error code */
SOAP_FMAC5 int SOAP_FMAC6 __tptz__CreatePresetTour(struct soap* soap, struct _tptz__CreatePresetTour *tptz__CreatePresetTour, struct _tptz__CreatePresetTourResponse *tptz__CreatePresetTourResponse) { printf("%s,%d\n",__FUNCTION__, __LINE__); return 0; }
/** Web service operation '__tptz__ModifyPresetTour' implementation, should return SOAP_OK or error code */
SOAP_FMAC5 int SOAP_FMAC6 __tptz__ModifyPresetTour(struct soap* soap, struct _tptz__ModifyPresetTour *tptz__ModifyPresetTour, struct _tptz__ModifyPresetTourResponse *tptz__ModifyPresetTourResponse) { printf("%s,%d\n",__FUNCTION__, __LINE__); return 0; }
/** Web service operation '__tptz__OperatePresetTour' implementation, should return SOAP_OK or error code */
SOAP_FMAC5 int SOAP_FMAC6 __tptz__OperatePresetTour(struct soap* soap, struct _tptz__OperatePresetTour *tptz__OperatePresetTour, struct _tptz__OperatePresetTourResponse *tptz__OperatePresetTourResponse) { printf("%s,%d\n",__FUNCTION__, __LINE__); return 0; }
/** Web service operation '__tptz__RemovePresetTour' implementation, should return SOAP_OK or error code */
SOAP_FMAC5 int SOAP_FMAC6 __tptz__RemovePresetTour(struct soap* soap, struct _tptz__RemovePresetTour *tptz__RemovePresetTour, struct _tptz__RemovePresetTourResponse *tptz__RemovePresetTourResponse) { printf("%s,%d\n",__FUNCTION__, __LINE__); return 0; }
/** Web service operation '__tptz__GetCompatibleConfigurations' implementation, should return SOAP_OK or error code */
SOAP_FMAC5 int SOAP_FMAC6 __tptz__GetCompatibleConfigurations(struct soap* soap, struct _tptz__GetCompatibleConfigurations *tptz__GetCompatibleConfigurations, struct _tptz__GetCompatibleConfigurationsResponse *tptz__GetCompatibleConfigurationsResponse) { printf("%s,%d\n",__FUNCTION__, __LINE__); return 0; }
/** Web service operation '__trc__GetServiceCapabilities' implementation, should return SOAP_OK or error code */
SOAP_FMAC5 int SOAP_FMAC6 __trc__GetServiceCapabilities(struct soap* soap, struct _trc__GetServiceCapabilities *trc__GetServiceCapabilities, struct _trc__GetServiceCapabilitiesResponse *trc__GetServiceCapabilitiesResponse) { printf("%s,%d\n",__FUNCTION__, __LINE__); return 0; }
/** Web service operation '__trc__CreateRecording' implementation, should return SOAP_OK or error code */
SOAP_FMAC5 int SOAP_FMAC6 __trc__CreateRecording(struct soap* soap, struct _trc__CreateRecording *trc__CreateRecording, struct _trc__CreateRecordingResponse *trc__CreateRecordingResponse) { printf("%s,%d\n",__FUNCTION__, __LINE__); return 0; }
/** Web service operation '__trc__DeleteRecording' implementation, should return SOAP_OK or error code */
SOAP_FMAC5 int SOAP_FMAC6 __trc__DeleteRecording(struct soap* soap, struct _trc__DeleteRecording *trc__DeleteRecording, struct _trc__DeleteRecordingResponse *trc__DeleteRecordingResponse) { printf("%s,%d\n",__FUNCTION__, __LINE__); return 0; }
/** Web service operation '__trc__GetRecordings' implementation, should return SOAP_OK or error code */
SOAP_FMAC5 int SOAP_FMAC6 __trc__GetRecordings(struct soap* soap, struct _trc__GetRecordings *trc__GetRecordings, struct _trc__GetRecordingsResponse *trc__GetRecordingsResponse) { printf("%s,%d\n",__FUNCTION__, __LINE__); return 0; }
/** Web service operation '__trc__SetRecordingConfiguration' implementation, should return SOAP_OK or error code */
SOAP_FMAC5 int SOAP_FMAC6 __trc__SetRecordingConfiguration(struct soap* soap, struct _trc__SetRecordingConfiguration *trc__SetRecordingConfiguration, struct _trc__SetRecordingConfigurationResponse *trc__SetRecordingConfigurationResponse) { printf("%s,%d\n",__FUNCTION__, __LINE__); return 0; }
/** Web service operation '__trc__GetRecordingConfiguration' implementation, should return SOAP_OK or error code */
SOAP_FMAC5 int SOAP_FMAC6 __trc__GetRecordingConfiguration(struct soap* soap, struct _trc__GetRecordingConfiguration *trc__GetRecordingConfiguration, struct _trc__GetRecordingConfigurationResponse *trc__GetRecordingConfigurationResponse) { printf("%s,%d\n",__FUNCTION__, __LINE__); return 0; }
/** Web service operation '__trc__GetRecordingOptions' implementation, should return SOAP_OK or error code */
SOAP_FMAC5 int SOAP_FMAC6 __trc__GetRecordingOptions(struct soap* soap, struct _trc__GetRecordingOptions *trc__GetRecordingOptions, struct _trc__GetRecordingOptionsResponse *trc__GetRecordingOptionsResponse) { printf("%s,%d\n",__FUNCTION__, __LINE__); return 0; }
/** Web service operation '__trc__CreateTrack' implementation, should return SOAP_OK or error code */
SOAP_FMAC5 int SOAP_FMAC6 __trc__CreateTrack(struct soap* soap, struct _trc__CreateTrack *trc__CreateTrack, struct _trc__CreateTrackResponse *trc__CreateTrackResponse) { printf("%s,%d\n",__FUNCTION__, __LINE__); return 0; }
/** Web service operation '__trc__DeleteTrack' implementation, should return SOAP_OK or error code */
SOAP_FMAC5 int SOAP_FMAC6 __trc__DeleteTrack(struct soap* soap, struct _trc__DeleteTrack *trc__DeleteTrack, struct _trc__DeleteTrackResponse *trc__DeleteTrackResponse) { printf("%s,%d\n",__FUNCTION__, __LINE__); return 0; }
/** Web service operation '__trc__GetTrackConfiguration' implementation, should return SOAP_OK or error code */
SOAP_FMAC5 int SOAP_FMAC6 __trc__GetTrackConfiguration(struct soap* soap, struct _trc__GetTrackConfiguration *trc__GetTrackConfiguration, struct _trc__GetTrackConfigurationResponse *trc__GetTrackConfigurationResponse) { printf("%s,%d\n",__FUNCTION__, __LINE__); return 0; }
/** Web service operation '__trc__SetTrackConfiguration' implementation, should return SOAP_OK or error code */
SOAP_FMAC5 int SOAP_FMAC6 __trc__SetTrackConfiguration(struct soap* soap, struct _trc__SetTrackConfiguration *trc__SetTrackConfiguration, struct _trc__SetTrackConfigurationResponse *trc__SetTrackConfigurationResponse) { printf("%s,%d\n",__FUNCTION__, __LINE__); return 0; }
/** Web service operation '__trc__CreateRecordingJob' implementation, should return SOAP_OK or error code */
SOAP_FMAC5 int SOAP_FMAC6 __trc__CreateRecordingJob(struct soap* soap, struct _trc__CreateRecordingJob *trc__CreateRecordingJob, struct _trc__CreateRecordingJobResponse *trc__CreateRecordingJobResponse) { printf("%s,%d\n",__FUNCTION__, __LINE__); return 0; }
/** Web service operation '__trc__DeleteRecordingJob' implementation, should return SOAP_OK or error code */
SOAP_FMAC5 int SOAP_FMAC6 __trc__DeleteRecordingJob(struct soap* soap, struct _trc__DeleteRecordingJob *trc__DeleteRecordingJob, struct _trc__DeleteRecordingJobResponse *trc__DeleteRecordingJobResponse) { printf("%s,%d\n",__FUNCTION__, __LINE__); return 0; }
/** Web service operation '__trc__GetRecordingJobs' implementation, should return SOAP_OK or error code */
SOAP_FMAC5 int SOAP_FMAC6 __trc__GetRecordingJobs(struct soap* soap, struct _trc__GetRecordingJobs *trc__GetRecordingJobs, struct _trc__GetRecordingJobsResponse *trc__GetRecordingJobsResponse) { printf("%s,%d\n",__FUNCTION__, __LINE__); return 0; }
/** Web service operation '__trc__SetRecordingJobConfiguration' implementation, should return SOAP_OK or error code */
SOAP_FMAC5 int SOAP_FMAC6 __trc__SetRecordingJobConfiguration(struct soap* soap, struct _trc__SetRecordingJobConfiguration *trc__SetRecordingJobConfiguration, struct _trc__SetRecordingJobConfigurationResponse *trc__SetRecordingJobConfigurationResponse) { printf("%s,%d\n",__FUNCTION__, __LINE__); return 0; }
/** Web service operation '__trc__GetRecordingJobConfiguration' implementation, should return SOAP_OK or error code */
SOAP_FMAC5 int SOAP_FMAC6 __trc__GetRecordingJobConfiguration(struct soap* soap, struct _trc__GetRecordingJobConfiguration *trc__GetRecordingJobConfiguration, struct _trc__GetRecordingJobConfigurationResponse *trc__GetRecordingJobConfigurationResponse) { printf("%s,%d\n",__FUNCTION__, __LINE__); return 0; }
/** Web service operation '__trc__SetRecordingJobMode' implementation, should return SOAP_OK or error code */
SOAP_FMAC5 int SOAP_FMAC6 __trc__SetRecordingJobMode(struct soap* soap, struct _trc__SetRecordingJobMode *trc__SetRecordingJobMode, struct _trc__SetRecordingJobModeResponse *trc__SetRecordingJobModeResponse) { printf("%s,%d\n",__FUNCTION__, __LINE__); return 0; }
/** Web service operation '__trc__GetRecordingJobState' implementation, should return SOAP_OK or error code */
SOAP_FMAC5 int SOAP_FMAC6 __trc__GetRecordingJobState(struct soap* soap, struct _trc__GetRecordingJobState *trc__GetRecordingJobState, struct _trc__GetRecordingJobStateResponse *trc__GetRecordingJobStateResponse) { printf("%s,%d\n",__FUNCTION__, __LINE__); return 0; }
/** Web service operation '__trc__ExportRecordedData' implementation, should return SOAP_OK or error code */
SOAP_FMAC5 int SOAP_FMAC6 __trc__ExportRecordedData(struct soap* soap, struct _trc__ExportRecordedData *trc__ExportRecordedData, struct _trc__ExportRecordedDataResponse *trc__ExportRecordedDataResponse) { printf("%s,%d\n",__FUNCTION__, __LINE__); return 0; }
/** Web service operation '__trc__StopExportRecordedData' implementation, should return SOAP_OK or error code */
SOAP_FMAC5 int SOAP_FMAC6 __trc__StopExportRecordedData(struct soap* soap, struct _trc__StopExportRecordedData *trc__StopExportRecordedData, struct _trc__StopExportRecordedDataResponse *trc__StopExportRecordedDataResponse) { printf("%s,%d\n",__FUNCTION__, __LINE__); return 0; }
/** Web service operation '__trc__GetExportRecordedDataState' implementation, should return SOAP_OK or error code */
SOAP_FMAC5 int SOAP_FMAC6 __trc__GetExportRecordedDataState(struct soap* soap, struct _trc__GetExportRecordedDataState *trc__GetExportRecordedDataState, struct _trc__GetExportRecordedDataStateResponse *trc__GetExportRecordedDataStateResponse) { printf("%s,%d\n",__FUNCTION__, __LINE__); return 0; }
/** Web service operation '__trp__GetServiceCapabilities' implementation, should return SOAP_OK or error code */
SOAP_FMAC5 int SOAP_FMAC6 __trp__GetServiceCapabilities(struct soap* soap, struct _trp__GetServiceCapabilities *trp__GetServiceCapabilities, struct _trp__GetServiceCapabilitiesResponse *trp__GetServiceCapabilitiesResponse) { printf("%s,%d\n",__FUNCTION__, __LINE__); return 0; }
/** Web service operation '__trp__GetReplayUri' implementation, should return SOAP_OK or error code */
SOAP_FMAC5 int SOAP_FMAC6 __trp__GetReplayUri(struct soap* soap, struct _trp__GetReplayUri *trp__GetReplayUri, struct _trp__GetReplayUriResponse *trp__GetReplayUriResponse) { printf("%s,%d\n",__FUNCTION__, __LINE__); return 0; }
/** Web service operation '__trp__GetReplayConfiguration' implementation, should return SOAP_OK or error code */
SOAP_FMAC5 int SOAP_FMAC6 __trp__GetReplayConfiguration(struct soap* soap, struct _trp__GetReplayConfiguration *trp__GetReplayConfiguration, struct _trp__GetReplayConfigurationResponse *trp__GetReplayConfigurationResponse) { printf("%s,%d\n",__FUNCTION__, __LINE__); return 0; }
/** Web service operation '__trp__SetReplayConfiguration' implementation, should return SOAP_OK or error code */
SOAP_FMAC5 int SOAP_FMAC6 __trp__SetReplayConfiguration(struct soap* soap, struct _trp__SetReplayConfiguration *trp__SetReplayConfiguration, struct _trp__SetReplayConfigurationResponse *trp__SetReplayConfigurationResponse) { printf("%s,%d\n",__FUNCTION__, __LINE__); return 0; }
/** Web service operation '__trt__GetServiceCapabilities' implementation, should return SOAP_OK or error code */
SOAP_FMAC5 int SOAP_FMAC6 __trt__GetServiceCapabilities(struct soap* soap, struct _trt__GetServiceCapabilities *trt__GetServiceCapabilities, struct _trt__GetServiceCapabilitiesResponse *trt__GetServiceCapabilitiesResponse) { printf("%s,%d\n",__FUNCTION__, __LINE__); return 0; }
/** Web service operation '__trt__GetVideoSources' implementation, should return SOAP_OK or error code */
SOAP_FMAC5 int SOAP_FMAC6 __trt__GetVideoSources(struct soap* soap, struct _trt__GetVideoSources *trt__GetVideoSources, struct _trt__GetVideoSourcesResponse *trt__GetVideoSourcesResponse) { printf("%s,%d\n",__FUNCTION__, __LINE__); return 0; }
/** Web service operation '__trt__GetAudioSources' implementation, should return SOAP_OK or error code */
SOAP_FMAC5 int SOAP_FMAC6 __trt__GetAudioSources(struct soap* soap, struct _trt__GetAudioSources *trt__GetAudioSources, struct _trt__GetAudioSourcesResponse *trt__GetAudioSourcesResponse) { printf("%s,%d\n",__FUNCTION__, __LINE__); return 0; }
/** Web service operation '__trt__GetAudioOutputs' implementation, should return SOAP_OK or error code */
SOAP_FMAC5 int SOAP_FMAC6 __trt__GetAudioOutputs(struct soap* soap, struct _trt__GetAudioOutputs *trt__GetAudioOutputs, struct _trt__GetAudioOutputsResponse *trt__GetAudioOutputsResponse) { printf("%s,%d\n",__FUNCTION__, __LINE__); return 0; }
/** Web service operation '__trt__CreateProfile' implementation, should return SOAP_OK or error code */
SOAP_FMAC5 int SOAP_FMAC6 __trt__CreateProfile(struct soap* soap, struct _trt__CreateProfile *trt__CreateProfile, struct _trt__CreateProfileResponse *trt__CreateProfileResponse) { printf("%s,%d\n",__FUNCTION__, __LINE__); return 0; }
/** Web service operation '__trt__GetProfile' implementation, should return SOAP_OK or error code */
SOAP_FMAC5 int SOAP_FMAC6 __trt__GetProfile(struct soap* soap, struct _trt__GetProfile *trt__GetProfile, struct _trt__GetProfileResponse *trt__GetProfileResponse) { printf("%s,%d\n",__FUNCTION__, __LINE__); return 0; }
/** Web service operation '__trt__GetProfiles' implementation, should return SOAP_OK or error code */
SOAP_FMAC5 int SOAP_FMAC6 __trt__GetProfiles(struct soap* soap, struct _trt__GetProfiles *trt__GetProfiles, struct _trt__GetProfilesResponse *trt__GetProfilesResponse) { printf("%s,%d\n",__FUNCTION__, __LINE__); return 0; }
/** Web service operation '__trt__AddVideoEncoderConfiguration' implementation, should return SOAP_OK or error code */
SOAP_FMAC5 int SOAP_FMAC6 __trt__AddVideoEncoderConfiguration(struct soap* soap, struct _trt__AddVideoEncoderConfiguration *trt__AddVideoEncoderConfiguration, struct _trt__AddVideoEncoderConfigurationResponse *trt__AddVideoEncoderConfigurationResponse) { printf("%s,%d\n",__FUNCTION__, __LINE__); return 0; }
/** Web service operation '__trt__AddVideoSourceConfiguration' implementation, should return SOAP_OK or error code */
SOAP_FMAC5 int SOAP_FMAC6 __trt__AddVideoSourceConfiguration(struct soap* soap, struct _trt__AddVideoSourceConfiguration *trt__AddVideoSourceConfiguration, struct _trt__AddVideoSourceConfigurationResponse *trt__AddVideoSourceConfigurationResponse) { printf("%s,%d\n",__FUNCTION__, __LINE__); return 0; }
/** Web service operation '__trt__AddAudioEncoderConfiguration' implementation, should return SOAP_OK or error code */
SOAP_FMAC5 int SOAP_FMAC6 __trt__AddAudioEncoderConfiguration(struct soap* soap, struct _trt__AddAudioEncoderConfiguration *trt__AddAudioEncoderConfiguration, struct _trt__AddAudioEncoderConfigurationResponse *trt__AddAudioEncoderConfigurationResponse) { printf("%s,%d\n",__FUNCTION__, __LINE__); return 0; }
/** Web service operation '__trt__AddAudioSourceConfiguration' implementation, should return SOAP_OK or error code */
SOAP_FMAC5 int SOAP_FMAC6 __trt__AddAudioSourceConfiguration(struct soap* soap, struct _trt__AddAudioSourceConfiguration *trt__AddAudioSourceConfiguration, struct _trt__AddAudioSourceConfigurationResponse *trt__AddAudioSourceConfigurationResponse) { printf("%s,%d\n",__FUNCTION__, __LINE__); return 0; }
/** Web service operation '__trt__AddPTZConfiguration' implementation, should return SOAP_OK or error code */
SOAP_FMAC5 int SOAP_FMAC6 __trt__AddPTZConfiguration(struct soap* soap, struct _trt__AddPTZConfiguration *trt__AddPTZConfiguration, struct _trt__AddPTZConfigurationResponse *trt__AddPTZConfigurationResponse) { printf("%s,%d\n",__FUNCTION__, __LINE__); return 0; }
/** Web service operation '__trt__AddVideoAnalyticsConfiguration' implementation, should return SOAP_OK or error code */
SOAP_FMAC5 int SOAP_FMAC6 __trt__AddVideoAnalyticsConfiguration(struct soap* soap, struct _trt__AddVideoAnalyticsConfiguration *trt__AddVideoAnalyticsConfiguration, struct _trt__AddVideoAnalyticsConfigurationResponse *trt__AddVideoAnalyticsConfigurationResponse) { printf("%s,%d\n",__FUNCTION__, __LINE__); return 0; }
/** Web service operation '__trt__AddMetadataConfiguration' implementation, should return SOAP_OK or error code */
SOAP_FMAC5 int SOAP_FMAC6 __trt__AddMetadataConfiguration(struct soap* soap, struct _trt__AddMetadataConfiguration *trt__AddMetadataConfiguration, struct _trt__AddMetadataConfigurationResponse *trt__AddMetadataConfigurationResponse) { printf("%s,%d\n",__FUNCTION__, __LINE__); return 0; }
/** Web service operation '__trt__AddAudioOutputConfiguration' implementation, should return SOAP_OK or error code */
SOAP_FMAC5 int SOAP_FMAC6 __trt__AddAudioOutputConfiguration(struct soap* soap, struct _trt__AddAudioOutputConfiguration *trt__AddAudioOutputConfiguration, struct _trt__AddAudioOutputConfigurationResponse *trt__AddAudioOutputConfigurationResponse) { printf("%s,%d\n",__FUNCTION__, __LINE__); return 0; }
/** Web service operation '__trt__AddAudioDecoderConfiguration' implementation, should return SOAP_OK or error code */
SOAP_FMAC5 int SOAP_FMAC6 __trt__AddAudioDecoderConfiguration(struct soap* soap, struct _trt__AddAudioDecoderConfiguration *trt__AddAudioDecoderConfiguration, struct _trt__AddAudioDecoderConfigurationResponse *trt__AddAudioDecoderConfigurationResponse) { printf("%s,%d\n",__FUNCTION__, __LINE__); return 0; }
/** Web service operation '__trt__RemoveVideoEncoderConfiguration' implementation, should return SOAP_OK or error code */
SOAP_FMAC5 int SOAP_FMAC6 __trt__RemoveVideoEncoderConfiguration(struct soap* soap, struct _trt__RemoveVideoEncoderConfiguration *trt__RemoveVideoEncoderConfiguration, struct _trt__RemoveVideoEncoderConfigurationResponse *trt__RemoveVideoEncoderConfigurationResponse) { printf("%s,%d\n",__FUNCTION__, __LINE__); return 0; }
/** Web service operation '__trt__RemoveVideoSourceConfiguration' implementation, should return SOAP_OK or error code */
SOAP_FMAC5 int SOAP_FMAC6 __trt__RemoveVideoSourceConfiguration(struct soap* soap, struct _trt__RemoveVideoSourceConfiguration *trt__RemoveVideoSourceConfiguration, struct _trt__RemoveVideoSourceConfigurationResponse *trt__RemoveVideoSourceConfigurationResponse) { printf("%s,%d\n",__FUNCTION__, __LINE__); return 0; }
/** Web service operation '__trt__RemoveAudioEncoderConfiguration' implementation, should return SOAP_OK or error code */
SOAP_FMAC5 int SOAP_FMAC6 __trt__RemoveAudioEncoderConfiguration(struct soap* soap, struct _trt__RemoveAudioEncoderConfiguration *trt__RemoveAudioEncoderConfiguration, struct _trt__RemoveAudioEncoderConfigurationResponse *trt__RemoveAudioEncoderConfigurationResponse) { printf("%s,%d\n",__FUNCTION__, __LINE__); return 0; }
/** Web service operation '__trt__RemoveAudioSourceConfiguration' implementation, should return SOAP_OK or error code */
SOAP_FMAC5 int SOAP_FMAC6 __trt__RemoveAudioSourceConfiguration(struct soap* soap, struct _trt__RemoveAudioSourceConfiguration *trt__RemoveAudioSourceConfiguration, struct _trt__RemoveAudioSourceConfigurationResponse *trt__RemoveAudioSourceConfigurationResponse) { printf("%s,%d\n",__FUNCTION__, __LINE__); return 0; }
/** Web service operation '__trt__RemovePTZConfiguration' implementation, should return SOAP_OK or error code */
SOAP_FMAC5 int SOAP_FMAC6 __trt__RemovePTZConfiguration(struct soap* soap, struct _trt__RemovePTZConfiguration *trt__RemovePTZConfiguration, struct _trt__RemovePTZConfigurationResponse *trt__RemovePTZConfigurationResponse) { printf("%s,%d\n",__FUNCTION__, __LINE__); return 0; }
/** Web service operation '__trt__RemoveVideoAnalyticsConfiguration' implementation, should return SOAP_OK or error code */
SOAP_FMAC5 int SOAP_FMAC6 __trt__RemoveVideoAnalyticsConfiguration(struct soap* soap, struct _trt__RemoveVideoAnalyticsConfiguration *trt__RemoveVideoAnalyticsConfiguration, struct _trt__RemoveVideoAnalyticsConfigurationResponse *trt__RemoveVideoAnalyticsConfigurationResponse) { printf("%s,%d\n",__FUNCTION__, __LINE__); return 0; }
/** Web service operation '__trt__RemoveMetadataConfiguration' implementation, should return SOAP_OK or error code */
SOAP_FMAC5 int SOAP_FMAC6 __trt__RemoveMetadataConfiguration(struct soap* soap, struct _trt__RemoveMetadataConfiguration *trt__RemoveMetadataConfiguration, struct _trt__RemoveMetadataConfigurationResponse *trt__RemoveMetadataConfigurationResponse) { printf("%s,%d\n",__FUNCTION__, __LINE__); return 0; }
/** Web service operation '__trt__RemoveAudioOutputConfiguration' implementation, should return SOAP_OK or error code */
SOAP_FMAC5 int SOAP_FMAC6 __trt__RemoveAudioOutputConfiguration(struct soap* soap, struct _trt__RemoveAudioOutputConfiguration *trt__RemoveAudioOutputConfiguration, struct _trt__RemoveAudioOutputConfigurationResponse *trt__RemoveAudioOutputConfigurationResponse) { printf("%s,%d\n",__FUNCTION__, __LINE__); return 0; }
/** Web service operation '__trt__RemoveAudioDecoderConfiguration' implementation, should return SOAP_OK or error code */
SOAP_FMAC5 int SOAP_FMAC6 __trt__RemoveAudioDecoderConfiguration(struct soap* soap, struct _trt__RemoveAudioDecoderConfiguration *trt__RemoveAudioDecoderConfiguration, struct _trt__RemoveAudioDecoderConfigurationResponse *trt__RemoveAudioDecoderConfigurationResponse) { printf("%s,%d\n",__FUNCTION__, __LINE__); return 0; }
/** Web service operation '__trt__DeleteProfile' implementation, should return SOAP_OK or error code */
SOAP_FMAC5 int SOAP_FMAC6 __trt__DeleteProfile(struct soap* soap, struct _trt__DeleteProfile *trt__DeleteProfile, struct _trt__DeleteProfileResponse *trt__DeleteProfileResponse) { printf("%s,%d\n",__FUNCTION__, __LINE__); return 0; }
/** Web service operation '__trt__GetVideoSourceConfigurations' implementation, should return SOAP_OK or error code */
SOAP_FMAC5 int SOAP_FMAC6 __trt__GetVideoSourceConfigurations(struct soap* soap, struct _trt__GetVideoSourceConfigurations *trt__GetVideoSourceConfigurations, struct _trt__GetVideoSourceConfigurationsResponse *trt__GetVideoSourceConfigurationsResponse) { printf("%s,%d\n",__FUNCTION__, __LINE__); return 0; }
/** Web service operation '__trt__GetVideoEncoderConfigurations' implementation, should return SOAP_OK or error code */
SOAP_FMAC5 int SOAP_FMAC6 __trt__GetVideoEncoderConfigurations(struct soap* soap, struct _trt__GetVideoEncoderConfigurations *trt__GetVideoEncoderConfigurations, struct _trt__GetVideoEncoderConfigurationsResponse *trt__GetVideoEncoderConfigurationsResponse) { printf("%s,%d\n",__FUNCTION__, __LINE__); return 0; }
/** Web service operation '__trt__GetAudioSourceConfigurations' implementation, should return SOAP_OK or error code */
SOAP_FMAC5 int SOAP_FMAC6 __trt__GetAudioSourceConfigurations(struct soap* soap, struct _trt__GetAudioSourceConfigurations *trt__GetAudioSourceConfigurations, struct _trt__GetAudioSourceConfigurationsResponse *trt__GetAudioSourceConfigurationsResponse) { printf("%s,%d\n",__FUNCTION__, __LINE__); return 0; }
/** Web service operation '__trt__GetAudioEncoderConfigurations' implementation, should return SOAP_OK or error code */
SOAP_FMAC5 int SOAP_FMAC6 __trt__GetAudioEncoderConfigurations(struct soap* soap, struct _trt__GetAudioEncoderConfigurations *trt__GetAudioEncoderConfigurations, struct _trt__GetAudioEncoderConfigurationsResponse *trt__GetAudioEncoderConfigurationsResponse) { printf("%s,%d\n",__FUNCTION__, __LINE__); return 0; }
/** Web service operation '__trt__GetVideoAnalyticsConfigurations' implementation, should return SOAP_OK or error code */
SOAP_FMAC5 int SOAP_FMAC6 __trt__GetVideoAnalyticsConfigurations(struct soap* soap, struct _trt__GetVideoAnalyticsConfigurations *trt__GetVideoAnalyticsConfigurations, struct _trt__GetVideoAnalyticsConfigurationsResponse *trt__GetVideoAnalyticsConfigurationsResponse) { printf("%s,%d\n",__FUNCTION__, __LINE__); return 0; }
/** Web service operation '__trt__GetMetadataConfigurations' implementation, should return SOAP_OK or error code */
SOAP_FMAC5 int SOAP_FMAC6 __trt__GetMetadataConfigurations(struct soap* soap, struct _trt__GetMetadataConfigurations *trt__GetMetadataConfigurations, struct _trt__GetMetadataConfigurationsResponse *trt__GetMetadataConfigurationsResponse) { printf("%s,%d\n",__FUNCTION__, __LINE__); return 0; }
/** Web service operation '__trt__GetAudioOutputConfigurations' implementation, should return SOAP_OK or error code */
SOAP_FMAC5 int SOAP_FMAC6 __trt__GetAudioOutputConfigurations(struct soap* soap, struct _trt__GetAudioOutputConfigurations *trt__GetAudioOutputConfigurations, struct _trt__GetAudioOutputConfigurationsResponse *trt__GetAudioOutputConfigurationsResponse) { printf("%s,%d\n",__FUNCTION__, __LINE__); return 0; }
/** Web service operation '__trt__GetAudioDecoderConfigurations' implementation, should return SOAP_OK or error code */
SOAP_FMAC5 int SOAP_FMAC6 __trt__GetAudioDecoderConfigurations(struct soap* soap, struct _trt__GetAudioDecoderConfigurations *trt__GetAudioDecoderConfigurations, struct _trt__GetAudioDecoderConfigurationsResponse *trt__GetAudioDecoderConfigurationsResponse) { printf("%s,%d\n",__FUNCTION__, __LINE__); return 0; }
/** Web service operation '__trt__GetVideoSourceConfiguration' implementation, should return SOAP_OK or error code */
SOAP_FMAC5 int SOAP_FMAC6 __trt__GetVideoSourceConfiguration(struct soap* soap, struct _trt__GetVideoSourceConfiguration *trt__GetVideoSourceConfiguration, struct _trt__GetVideoSourceConfigurationResponse *trt__GetVideoSourceConfigurationResponse) { printf("%s,%d\n",__FUNCTION__, __LINE__); return 0; }
/** Web service operation '__trt__GetVideoEncoderConfiguration' implementation, should return SOAP_OK or error code */
SOAP_FMAC5 int SOAP_FMAC6 __trt__GetVideoEncoderConfiguration(struct soap* soap, struct _trt__GetVideoEncoderConfiguration *trt__GetVideoEncoderConfiguration, struct _trt__GetVideoEncoderConfigurationResponse *trt__GetVideoEncoderConfigurationResponse) { printf("%s,%d\n",__FUNCTION__, __LINE__); return 0; }
/** Web service operation '__trt__GetAudioSourceConfiguration' implementation, should return SOAP_OK or error code */
SOAP_FMAC5 int SOAP_FMAC6 __trt__GetAudioSourceConfiguration(struct soap* soap, struct _trt__GetAudioSourceConfiguration *trt__GetAudioSourceConfiguration, struct _trt__GetAudioSourceConfigurationResponse *trt__GetAudioSourceConfigurationResponse) { printf("%s,%d\n",__FUNCTION__, __LINE__); return 0; }
/** Web service operation '__trt__GetAudioEncoderConfiguration' implementation, should return SOAP_OK or error code */
SOAP_FMAC5 int SOAP_FMAC6 __trt__GetAudioEncoderConfiguration(struct soap* soap, struct _trt__GetAudioEncoderConfiguration *trt__GetAudioEncoderConfiguration, struct _trt__GetAudioEncoderConfigurationResponse *trt__GetAudioEncoderConfigurationResponse) { printf("%s,%d\n",__FUNCTION__, __LINE__); return 0; }
/** Web service operation '__trt__GetVideoAnalyticsConfiguration' implementation, should return SOAP_OK or error code */
SOAP_FMAC5 int SOAP_FMAC6 __trt__GetVideoAnalyticsConfiguration(struct soap* soap, struct _trt__GetVideoAnalyticsConfiguration *trt__GetVideoAnalyticsConfiguration, struct _trt__GetVideoAnalyticsConfigurationResponse *trt__GetVideoAnalyticsConfigurationResponse) { printf("%s,%d\n",__FUNCTION__, __LINE__); return 0; }
/** Web service operation '__trt__GetMetadataConfiguration' implementation, should return SOAP_OK or error code */
SOAP_FMAC5 int SOAP_FMAC6 __trt__GetMetadataConfiguration(struct soap* soap, struct _trt__GetMetadataConfiguration *trt__GetMetadataConfiguration, struct _trt__GetMetadataConfigurationResponse *trt__GetMetadataConfigurationResponse) { printf("%s,%d\n",__FUNCTION__, __LINE__); return 0; }
/** Web service operation '__trt__GetAudioOutputConfiguration' implementation, should return SOAP_OK or error code */
SOAP_FMAC5 int SOAP_FMAC6 __trt__GetAudioOutputConfiguration(struct soap* soap, struct _trt__GetAudioOutputConfiguration *trt__GetAudioOutputConfiguration, struct _trt__GetAudioOutputConfigurationResponse *trt__GetAudioOutputConfigurationResponse) { printf("%s,%d\n",__FUNCTION__, __LINE__); return 0; }
/** Web service operation '__trt__GetAudioDecoderConfiguration' implementation, should return SOAP_OK or error code */
SOAP_FMAC5 int SOAP_FMAC6 __trt__GetAudioDecoderConfiguration(struct soap* soap, struct _trt__GetAudioDecoderConfiguration *trt__GetAudioDecoderConfiguration, struct _trt__GetAudioDecoderConfigurationResponse *trt__GetAudioDecoderConfigurationResponse) { printf("%s,%d\n",__FUNCTION__, __LINE__); return 0; }
/** Web service operation '__trt__GetCompatibleVideoEncoderConfigurations' implementation, should return SOAP_OK or error code */
SOAP_FMAC5 int SOAP_FMAC6 __trt__GetCompatibleVideoEncoderConfigurations(struct soap* soap, struct _trt__GetCompatibleVideoEncoderConfigurations *trt__GetCompatibleVideoEncoderConfigurations, struct _trt__GetCompatibleVideoEncoderConfigurationsResponse *trt__GetCompatibleVideoEncoderConfigurationsResponse) { printf("%s,%d\n",__FUNCTION__, __LINE__); return 0; }
/** Web service operation '__trt__GetCompatibleVideoSourceConfigurations' implementation, should return SOAP_OK or error code */
SOAP_FMAC5 int SOAP_FMAC6 __trt__GetCompatibleVideoSourceConfigurations(struct soap* soap, struct _trt__GetCompatibleVideoSourceConfigurations *trt__GetCompatibleVideoSourceConfigurations, struct _trt__GetCompatibleVideoSourceConfigurationsResponse *trt__GetCompatibleVideoSourceConfigurationsResponse) { printf("%s,%d\n",__FUNCTION__, __LINE__); return 0; }
/** Web service operation '__trt__GetCompatibleAudioEncoderConfigurations' implementation, should return SOAP_OK or error code */
SOAP_FMAC5 int SOAP_FMAC6 __trt__GetCompatibleAudioEncoderConfigurations(struct soap* soap, struct _trt__GetCompatibleAudioEncoderConfigurations *trt__GetCompatibleAudioEncoderConfigurations, struct _trt__GetCompatibleAudioEncoderConfigurationsResponse *trt__GetCompatibleAudioEncoderConfigurationsResponse) { printf("%s,%d\n",__FUNCTION__, __LINE__); return 0; }
/** Web service operation '__trt__GetCompatibleAudioSourceConfigurations' implementation, should return SOAP_OK or error code */
SOAP_FMAC5 int SOAP_FMAC6 __trt__GetCompatibleAudioSourceConfigurations(struct soap* soap, struct _trt__GetCompatibleAudioSourceConfigurations *trt__GetCompatibleAudioSourceConfigurations, struct _trt__GetCompatibleAudioSourceConfigurationsResponse *trt__GetCompatibleAudioSourceConfigurationsResponse) { printf("%s,%d\n",__FUNCTION__, __LINE__); return 0; }
/** Web service operation '__trt__GetCompatibleVideoAnalyticsConfigurations' implementation, should return SOAP_OK or error code */
SOAP_FMAC5 int SOAP_FMAC6 __trt__GetCompatibleVideoAnalyticsConfigurations(struct soap* soap, struct _trt__GetCompatibleVideoAnalyticsConfigurations *trt__GetCompatibleVideoAnalyticsConfigurations, struct _trt__GetCompatibleVideoAnalyticsConfigurationsResponse *trt__GetCompatibleVideoAnalyticsConfigurationsResponse) { printf("%s,%d\n",__FUNCTION__, __LINE__); return 0; }
/** Web service operation '__trt__GetCompatibleMetadataConfigurations' implementation, should return SOAP_OK or error code */
SOAP_FMAC5 int SOAP_FMAC6 __trt__GetCompatibleMetadataConfigurations(struct soap* soap, struct _trt__GetCompatibleMetadataConfigurations *trt__GetCompatibleMetadataConfigurations, struct _trt__GetCompatibleMetadataConfigurationsResponse *trt__GetCompatibleMetadataConfigurationsResponse) { printf("%s,%d\n",__FUNCTION__, __LINE__); return 0; }
/** Web service operation '__trt__GetCompatibleAudioOutputConfigurations' implementation, should return SOAP_OK or error code */
SOAP_FMAC5 int SOAP_FMAC6 __trt__GetCompatibleAudioOutputConfigurations(struct soap* soap, struct _trt__GetCompatibleAudioOutputConfigurations *trt__GetCompatibleAudioOutputConfigurations, struct _trt__GetCompatibleAudioOutputConfigurationsResponse *trt__GetCompatibleAudioOutputConfigurationsResponse) { printf("%s,%d\n",__FUNCTION__, __LINE__); return 0; }
/** Web service operation '__trt__GetCompatibleAudioDecoderConfigurations' implementation, should return SOAP_OK or error code */
SOAP_FMAC5 int SOAP_FMAC6 __trt__GetCompatibleAudioDecoderConfigurations(struct soap* soap, struct _trt__GetCompatibleAudioDecoderConfigurations *trt__GetCompatibleAudioDecoderConfigurations, struct _trt__GetCompatibleAudioDecoderConfigurationsResponse *trt__GetCompatibleAudioDecoderConfigurationsResponse) { printf("%s,%d\n",__FUNCTION__, __LINE__); return 0; }
/** Web service operation '__trt__SetVideoSourceConfiguration' implementation, should return SOAP_OK or error code */
SOAP_FMAC5 int SOAP_FMAC6 __trt__SetVideoSourceConfiguration(struct soap* soap, struct _trt__SetVideoSourceConfiguration *trt__SetVideoSourceConfiguration, struct _trt__SetVideoSourceConfigurationResponse *trt__SetVideoSourceConfigurationResponse) { printf("%s,%d\n",__FUNCTION__, __LINE__); return 0; }
/** Web service operation '__trt__SetVideoEncoderConfiguration' implementation, should return SOAP_OK or error code */
SOAP_FMAC5 int SOAP_FMAC6 __trt__SetVideoEncoderConfiguration(struct soap* soap, struct _trt__SetVideoEncoderConfiguration *trt__SetVideoEncoderConfiguration, struct _trt__SetVideoEncoderConfigurationResponse *trt__SetVideoEncoderConfigurationResponse) { printf("%s,%d\n",__FUNCTION__, __LINE__); return 0; }
/** Web service operation '__trt__SetAudioSourceConfiguration' implementation, should return SOAP_OK or error code */
SOAP_FMAC5 int SOAP_FMAC6 __trt__SetAudioSourceConfiguration(struct soap* soap, struct _trt__SetAudioSourceConfiguration *trt__SetAudioSourceConfiguration, struct _trt__SetAudioSourceConfigurationResponse *trt__SetAudioSourceConfigurationResponse) { printf("%s,%d\n",__FUNCTION__, __LINE__); return 0; }
/** Web service operation '__trt__SetAudioEncoderConfiguration' implementation, should return SOAP_OK or error code */
SOAP_FMAC5 int SOAP_FMAC6 __trt__SetAudioEncoderConfiguration(struct soap* soap, struct _trt__SetAudioEncoderConfiguration *trt__SetAudioEncoderConfiguration, struct _trt__SetAudioEncoderConfigurationResponse *trt__SetAudioEncoderConfigurationResponse) { printf("%s,%d\n",__FUNCTION__, __LINE__); return 0; }
/** Web service operation '__trt__SetVideoAnalyticsConfiguration' implementation, should return SOAP_OK or error code */
SOAP_FMAC5 int SOAP_FMAC6 __trt__SetVideoAnalyticsConfiguration(struct soap* soap, struct _trt__SetVideoAnalyticsConfiguration *trt__SetVideoAnalyticsConfiguration, struct _trt__SetVideoAnalyticsConfigurationResponse *trt__SetVideoAnalyticsConfigurationResponse) { printf("%s,%d\n",__FUNCTION__, __LINE__); return 0; }
/** Web service operation '__trt__SetMetadataConfiguration' implementation, should return SOAP_OK or error code */
SOAP_FMAC5 int SOAP_FMAC6 __trt__SetMetadataConfiguration(struct soap* soap, struct _trt__SetMetadataConfiguration *trt__SetMetadataConfiguration, struct _trt__SetMetadataConfigurationResponse *trt__SetMetadataConfigurationResponse) { printf("%s,%d\n",__FUNCTION__, __LINE__); return 0; }
/** Web service operation '__trt__SetAudioOutputConfiguration' implementation, should return SOAP_OK or error code */
SOAP_FMAC5 int SOAP_FMAC6 __trt__SetAudioOutputConfiguration(struct soap* soap, struct _trt__SetAudioOutputConfiguration *trt__SetAudioOutputConfiguration, struct _trt__SetAudioOutputConfigurationResponse *trt__SetAudioOutputConfigurationResponse) { printf("%s,%d\n",__FUNCTION__, __LINE__); return 0; }
/** Web service operation '__trt__SetAudioDecoderConfiguration' implementation, should return SOAP_OK or error code */
SOAP_FMAC5 int SOAP_FMAC6 __trt__SetAudioDecoderConfiguration(struct soap* soap, struct _trt__SetAudioDecoderConfiguration *trt__SetAudioDecoderConfiguration, struct _trt__SetAudioDecoderConfigurationResponse *trt__SetAudioDecoderConfigurationResponse) { printf("%s,%d\n",__FUNCTION__, __LINE__); return 0; }
/** Web service operation '__trt__GetVideoSourceConfigurationOptions' implementation, should return SOAP_OK or error code */
SOAP_FMAC5 int SOAP_FMAC6 __trt__GetVideoSourceConfigurationOptions(struct soap* soap, struct _trt__GetVideoSourceConfigurationOptions *trt__GetVideoSourceConfigurationOptions, struct _trt__GetVideoSourceConfigurationOptionsResponse *trt__GetVideoSourceConfigurationOptionsResponse) { printf("%s,%d\n",__FUNCTION__, __LINE__); return 0; }
/** Web service operation '__trt__GetVideoEncoderConfigurationOptions' implementation, should return SOAP_OK or error code */
SOAP_FMAC5 int SOAP_FMAC6 __trt__GetVideoEncoderConfigurationOptions(struct soap* soap, struct _trt__GetVideoEncoderConfigurationOptions *trt__GetVideoEncoderConfigurationOptions, struct _trt__GetVideoEncoderConfigurationOptionsResponse *trt__GetVideoEncoderConfigurationOptionsResponse) { printf("%s,%d\n",__FUNCTION__, __LINE__); return 0; }
/** Web service operation '__trt__GetAudioSourceConfigurationOptions' implementation, should return SOAP_OK or error code */
SOAP_FMAC5 int SOAP_FMAC6 __trt__GetAudioSourceConfigurationOptions(struct soap* soap, struct _trt__GetAudioSourceConfigurationOptions *trt__GetAudioSourceConfigurationOptions, struct _trt__GetAudioSourceConfigurationOptionsResponse *trt__GetAudioSourceConfigurationOptionsResponse) { printf("%s,%d\n",__FUNCTION__, __LINE__); return 0; }
/** Web service operation '__trt__GetAudioEncoderConfigurationOptions' implementation, should return SOAP_OK or error code */
SOAP_FMAC5 int SOAP_FMAC6 __trt__GetAudioEncoderConfigurationOptions(struct soap* soap, struct _trt__GetAudioEncoderConfigurationOptions *trt__GetAudioEncoderConfigurationOptions, struct _trt__GetAudioEncoderConfigurationOptionsResponse *trt__GetAudioEncoderConfigurationOptionsResponse) { printf("%s,%d\n",__FUNCTION__, __LINE__); return 0; }
/** Web service operation '__trt__GetMetadataConfigurationOptions' implementation, should return SOAP_OK or error code */
SOAP_FMAC5 int SOAP_FMAC6 __trt__GetMetadataConfigurationOptions(struct soap* soap, struct _trt__GetMetadataConfigurationOptions *trt__GetMetadataConfigurationOptions, struct _trt__GetMetadataConfigurationOptionsResponse *trt__GetMetadataConfigurationOptionsResponse) { printf("%s,%d\n",__FUNCTION__, __LINE__); return 0; }
/** Web service operation '__trt__GetAudioOutputConfigurationOptions' implementation, should return SOAP_OK or error code */
SOAP_FMAC5 int SOAP_FMAC6 __trt__GetAudioOutputConfigurationOptions(struct soap* soap, struct _trt__GetAudioOutputConfigurationOptions *trt__GetAudioOutputConfigurationOptions, struct _trt__GetAudioOutputConfigurationOptionsResponse *trt__GetAudioOutputConfigurationOptionsResponse) { printf("%s,%d\n",__FUNCTION__, __LINE__); return 0; }
/** Web service operation '__trt__GetAudioDecoderConfigurationOptions' implementation, should return SOAP_OK or error code */
SOAP_FMAC5 int SOAP_FMAC6 __trt__GetAudioDecoderConfigurationOptions(struct soap* soap, struct _trt__GetAudioDecoderConfigurationOptions *trt__GetAudioDecoderConfigurationOptions, struct _trt__GetAudioDecoderConfigurationOptionsResponse *trt__GetAudioDecoderConfigurationOptionsResponse) { printf("%s,%d\n",__FUNCTION__, __LINE__); return 0; }
/** Web service operation '__trt__GetGuaranteedNumberOfVideoEncoderInstances' implementation, should return SOAP_OK or error code */
SOAP_FMAC5 int SOAP_FMAC6 __trt__GetGuaranteedNumberOfVideoEncoderInstances(struct soap* soap, struct _trt__GetGuaranteedNumberOfVideoEncoderInstances *trt__GetGuaranteedNumberOfVideoEncoderInstances, struct _trt__GetGuaranteedNumberOfVideoEncoderInstancesResponse *trt__GetGuaranteedNumberOfVideoEncoderInstancesResponse) { printf("%s,%d\n",__FUNCTION__, __LINE__); return 0; }
/** Web service operation '__trt__GetStreamUri' implementation, should return SOAP_OK or error code */
SOAP_FMAC5 int SOAP_FMAC6 __trt__GetStreamUri(struct soap* soap, struct _trt__GetStreamUri *trt__GetStreamUri, struct _trt__GetStreamUriResponse *trt__GetStreamUriResponse) { printf("%s,%d\n",__FUNCTION__, __LINE__); return 0; }
/** Web service operation '__trt__StartMulticastStreaming' implementation, should return SOAP_OK or error code */
SOAP_FMAC5 int SOAP_FMAC6 __trt__StartMulticastStreaming(struct soap* soap, struct _trt__StartMulticastStreaming *trt__StartMulticastStreaming, struct _trt__StartMulticastStreamingResponse *trt__StartMulticastStreamingResponse) { printf("%s,%d\n",__FUNCTION__, __LINE__); return 0; }
/** Web service operation '__trt__StopMulticastStreaming' implementation, should return SOAP_OK or error code */
SOAP_FMAC5 int SOAP_FMAC6 __trt__StopMulticastStreaming(struct soap* soap, struct _trt__StopMulticastStreaming *trt__StopMulticastStreaming, struct _trt__StopMulticastStreamingResponse *trt__StopMulticastStreamingResponse) { printf("%s,%d\n",__FUNCTION__, __LINE__); return 0; }
/** Web service operation '__trt__SetSynchronizationPoint' implementation, should return SOAP_OK or error code */
SOAP_FMAC5 int SOAP_FMAC6 __trt__SetSynchronizationPoint(struct soap* soap, struct _trt__SetSynchronizationPoint *trt__SetSynchronizationPoint, struct _trt__SetSynchronizationPointResponse *trt__SetSynchronizationPointResponse) { printf("%s,%d\n",__FUNCTION__, __LINE__); return 0; }
/** Web service operation '__trt__GetSnapshotUri' implementation, should return SOAP_OK or error code */
SOAP_FMAC5 int SOAP_FMAC6 __trt__GetSnapshotUri(struct soap* soap, struct _trt__GetSnapshotUri *trt__GetSnapshotUri, struct _trt__GetSnapshotUriResponse *trt__GetSnapshotUriResponse) { printf("%s,%d\n",__FUNCTION__, __LINE__); return 0; }
/** Web service operation '__trt__GetVideoSourceModes' implementation, should return SOAP_OK or error code */
SOAP_FMAC5 int SOAP_FMAC6 __trt__GetVideoSourceModes(struct soap* soap, struct _trt__GetVideoSourceModes *trt__GetVideoSourceModes, struct _trt__GetVideoSourceModesResponse *trt__GetVideoSourceModesResponse) { printf("%s,%d\n",__FUNCTION__, __LINE__); return 0; }
/** Web service operation '__trt__SetVideoSourceMode' implementation, should return SOAP_OK or error code */
SOAP_FMAC5 int SOAP_FMAC6 __trt__SetVideoSourceMode(struct soap* soap, struct _trt__SetVideoSourceMode *trt__SetVideoSourceMode, struct _trt__SetVideoSourceModeResponse *trt__SetVideoSourceModeResponse) { printf("%s,%d\n",__FUNCTION__, __LINE__); return 0; }
/** Web service operation '__trt__GetOSDs' implementation, should return SOAP_OK or error code */
SOAP_FMAC5 int SOAP_FMAC6 __trt__GetOSDs(struct soap* soap, struct _trt__GetOSDs *trt__GetOSDs, struct _trt__GetOSDsResponse *trt__GetOSDsResponse) { printf("%s,%d\n",__FUNCTION__, __LINE__); return 0; }
/** Web service operation '__trt__GetOSD' implementation, should return SOAP_OK or error code */
SOAP_FMAC5 int SOAP_FMAC6 __trt__GetOSD(struct soap* soap, struct _trt__GetOSD *trt__GetOSD, struct _trt__GetOSDResponse *trt__GetOSDResponse) { printf("%s,%d\n",__FUNCTION__, __LINE__); return 0; }
/** Web service operation '__trt__GetOSDOptions' implementation, should return SOAP_OK or error code */
SOAP_FMAC5 int SOAP_FMAC6 __trt__GetOSDOptions(struct soap* soap, struct _trt__GetOSDOptions *trt__GetOSDOptions, struct _trt__GetOSDOptionsResponse *trt__GetOSDOptionsResponse) { printf("%s,%d\n",__FUNCTION__, __LINE__); return 0; }
/** Web service operation '__trt__SetOSD' implementation, should return SOAP_OK or error code */
SOAP_FMAC5 int SOAP_FMAC6 __trt__SetOSD(struct soap* soap, struct _trt__SetOSD *trt__SetOSD, struct _trt__SetOSDResponse *trt__SetOSDResponse) { printf("%s,%d\n",__FUNCTION__, __LINE__); return 0; }
/** Web service operation '__trt__CreateOSD' implementation, should return SOAP_OK or error code */
SOAP_FMAC5 int SOAP_FMAC6 __trt__CreateOSD(struct soap* soap, struct _trt__CreateOSD *trt__CreateOSD, struct _trt__CreateOSDResponse *trt__CreateOSDResponse) { printf("%s,%d\n",__FUNCTION__, __LINE__); return 0; }
/** Web service operation '__trt__DeleteOSD' implementation, should return SOAP_OK or error code */
SOAP_FMAC5 int SOAP_FMAC6 __trt__DeleteOSD(struct soap* soap, struct _trt__DeleteOSD *trt__DeleteOSD, struct _trt__DeleteOSDResponse *trt__DeleteOSDResponse) { printf("%s,%d\n",__FUNCTION__, __LINE__); return 0; }
/** Web service operation '__trv__GetServiceCapabilities' implementation, should return SOAP_OK or error code */
SOAP_FMAC5 int SOAP_FMAC6 __trv__GetServiceCapabilities(struct soap* soap, struct _trv__GetServiceCapabilities *trv__GetServiceCapabilities, struct _trv__GetServiceCapabilitiesResponse *trv__GetServiceCapabilitiesResponse) { printf("%s,%d\n",__FUNCTION__, __LINE__); return 0; }
/** Web service operation '__trv__GetReceivers' implementation, should return SOAP_OK or error code */
SOAP_FMAC5 int SOAP_FMAC6 __trv__GetReceivers(struct soap* soap, struct _trv__GetReceivers *trv__GetReceivers, struct _trv__GetReceiversResponse *trv__GetReceiversResponse) { printf("%s,%d\n",__FUNCTION__, __LINE__); return 0; }
/** Web service operation '__trv__GetReceiver' implementation, should return SOAP_OK or error code */
SOAP_FMAC5 int SOAP_FMAC6 __trv__GetReceiver(struct soap* soap, struct _trv__GetReceiver *trv__GetReceiver, struct _trv__GetReceiverResponse *trv__GetReceiverResponse) { printf("%s,%d\n",__FUNCTION__, __LINE__); return 0; }
/** Web service operation '__trv__CreateReceiver' implementation, should return SOAP_OK or error code */
SOAP_FMAC5 int SOAP_FMAC6 __trv__CreateReceiver(struct soap* soap, struct _trv__CreateReceiver *trv__CreateReceiver, struct _trv__CreateReceiverResponse *trv__CreateReceiverResponse) { printf("%s,%d\n",__FUNCTION__, __LINE__); return 0; }
/** Web service operation '__trv__DeleteReceiver' implementation, should return SOAP_OK or error code */
SOAP_FMAC5 int SOAP_FMAC6 __trv__DeleteReceiver(struct soap* soap, struct _trv__DeleteReceiver *trv__DeleteReceiver, struct _trv__DeleteReceiverResponse *trv__DeleteReceiverResponse) { printf("%s,%d\n",__FUNCTION__, __LINE__); return 0; }
/** Web service operation '__trv__ConfigureReceiver' implementation, should return SOAP_OK or error code */
SOAP_FMAC5 int SOAP_FMAC6 __trv__ConfigureReceiver(struct soap* soap, struct _trv__ConfigureReceiver *trv__ConfigureReceiver, struct _trv__ConfigureReceiverResponse *trv__ConfigureReceiverResponse) { printf("%s,%d\n",__FUNCTION__, __LINE__); return 0; }
/** Web service operation '__trv__SetReceiverMode' implementation, should return SOAP_OK or error code */
SOAP_FMAC5 int SOAP_FMAC6 __trv__SetReceiverMode(struct soap* soap, struct _trv__SetReceiverMode *trv__SetReceiverMode, struct _trv__SetReceiverModeResponse *trv__SetReceiverModeResponse) { printf("%s,%d\n",__FUNCTION__, __LINE__); return 0; }
/** Web service operation '__trv__GetReceiverState' implementation, should return SOAP_OK or error code */
SOAP_FMAC5 int SOAP_FMAC6 __trv__GetReceiverState(struct soap* soap, struct _trv__GetReceiverState *trv__GetReceiverState, struct _trv__GetReceiverStateResponse *trv__GetReceiverStateResponse) { printf("%s,%d\n",__FUNCTION__, __LINE__); return 0; }
/** Web service operation '__tse__GetServiceCapabilities' implementation, should return SOAP_OK or error code */
SOAP_FMAC5 int SOAP_FMAC6 __tse__GetServiceCapabilities(struct soap* soap, struct _tse__GetServiceCapabilities *tse__GetServiceCapabilities, struct _tse__GetServiceCapabilitiesResponse *tse__GetServiceCapabilitiesResponse) { printf("%s,%d\n",__FUNCTION__, __LINE__); return 0; }
/** Web service operation '__tse__GetRecordingSummary' implementation, should return SOAP_OK or error code */
SOAP_FMAC5 int SOAP_FMAC6 __tse__GetRecordingSummary(struct soap* soap, struct _tse__GetRecordingSummary *tse__GetRecordingSummary, struct _tse__GetRecordingSummaryResponse *tse__GetRecordingSummaryResponse) { printf("%s,%d\n",__FUNCTION__, __LINE__); return 0; }
/** Web service operation '__tse__GetRecordingInformation' implementation, should return SOAP_OK or error code */
SOAP_FMAC5 int SOAP_FMAC6 __tse__GetRecordingInformation(struct soap* soap, struct _tse__GetRecordingInformation *tse__GetRecordingInformation, struct _tse__GetRecordingInformationResponse *tse__GetRecordingInformationResponse) { printf("%s,%d\n",__FUNCTION__, __LINE__); return 0; }
/** Web service operation '__tse__GetMediaAttributes' implementation, should return SOAP_OK or error code */
SOAP_FMAC5 int SOAP_FMAC6 __tse__GetMediaAttributes(struct soap* soap, struct _tse__GetMediaAttributes *tse__GetMediaAttributes, struct _tse__GetMediaAttributesResponse *tse__GetMediaAttributesResponse) { printf("%s,%d\n",__FUNCTION__, __LINE__); return 0; }
/** Web service operation '__tse__FindRecordings' implementation, should return SOAP_OK or error code */
SOAP_FMAC5 int SOAP_FMAC6 __tse__FindRecordings(struct soap* soap, struct _tse__FindRecordings *tse__FindRecordings, struct _tse__FindRecordingsResponse *tse__FindRecordingsResponse) { printf("%s,%d\n",__FUNCTION__, __LINE__); return 0; }
/** Web service operation '__tse__GetRecordingSearchResults' implementation, should return SOAP_OK or error code */
SOAP_FMAC5 int SOAP_FMAC6 __tse__GetRecordingSearchResults(struct soap* soap, struct _tse__GetRecordingSearchResults *tse__GetRecordingSearchResults, struct _tse__GetRecordingSearchResultsResponse *tse__GetRecordingSearchResultsResponse) { printf("%s,%d\n",__FUNCTION__, __LINE__); return 0; }
/** Web service operation '__tse__FindEvents' implementation, should return SOAP_OK or error code */
SOAP_FMAC5 int SOAP_FMAC6 __tse__FindEvents(struct soap* soap, struct _tse__FindEvents *tse__FindEvents, struct _tse__FindEventsResponse *tse__FindEventsResponse) { printf("%s,%d\n",__FUNCTION__, __LINE__); return 0; }
/** Web service operation '__tse__GetEventSearchResults' implementation, should return SOAP_OK or error code */
SOAP_FMAC5 int SOAP_FMAC6 __tse__GetEventSearchResults(struct soap* soap, struct _tse__GetEventSearchResults *tse__GetEventSearchResults, struct _tse__GetEventSearchResultsResponse *tse__GetEventSearchResultsResponse) { printf("%s,%d\n",__FUNCTION__, __LINE__); return 0; }
/** Web service operation '__tse__FindPTZPosition' implementation, should return SOAP_OK or error code */
SOAP_FMAC5 int SOAP_FMAC6 __tse__FindPTZPosition(struct soap* soap, struct _tse__FindPTZPosition *tse__FindPTZPosition, struct _tse__FindPTZPositionResponse *tse__FindPTZPositionResponse) { printf("%s,%d\n",__FUNCTION__, __LINE__); return 0; }
/** Web service operation '__tse__GetPTZPositionSearchResults' implementation, should return SOAP_OK or error code */
SOAP_FMAC5 int SOAP_FMAC6 __tse__GetPTZPositionSearchResults(struct soap* soap, struct _tse__GetPTZPositionSearchResults *tse__GetPTZPositionSearchResults, struct _tse__GetPTZPositionSearchResultsResponse *tse__GetPTZPositionSearchResultsResponse) { printf("%s,%d\n",__FUNCTION__, __LINE__); return 0; }
/** Web service operation '__tse__GetSearchState' implementation, should return SOAP_OK or error code */
SOAP_FMAC5 int SOAP_FMAC6 __tse__GetSearchState(struct soap* soap, struct _tse__GetSearchState *tse__GetSearchState, struct _tse__GetSearchStateResponse *tse__GetSearchStateResponse) { printf("%s,%d\n",__FUNCTION__, __LINE__); return 0; }
/** Web service operation '__tse__EndSearch' implementation, should return SOAP_OK or error code */
SOAP_FMAC5 int SOAP_FMAC6 __tse__EndSearch(struct soap* soap, struct _tse__EndSearch *tse__EndSearch, struct _tse__EndSearchResponse *tse__EndSearchResponse) { printf("%s,%d\n",__FUNCTION__, __LINE__); return 0; }
/** Web service operation '__tse__FindMetadata' implementation, should return SOAP_OK or error code */
SOAP_FMAC5 int SOAP_FMAC6 __tse__FindMetadata(struct soap* soap, struct _tse__FindMetadata *tse__FindMetadata, struct _tse__FindMetadataResponse *tse__FindMetadataResponse) { printf("%s,%d\n",__FUNCTION__, __LINE__); return 0; }
/** Web service operation '__tse__GetMetadataSearchResults' implementation, should return SOAP_OK or error code */
SOAP_FMAC5 int SOAP_FMAC6 __tse__GetMetadataSearchResults(struct soap* soap, struct _tse__GetMetadataSearchResults *tse__GetMetadataSearchResults, struct _tse__GetMetadataSearchResultsResponse *tse__GetMetadataSearchResultsResponse) { printf("%s,%d\n",__FUNCTION__, __LINE__); return 0; }