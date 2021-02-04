#ifdef _WIN32
#ifdef LEDEQSDK_EXPORTS
#define LEDEQSDK_API __declspec(dllexport)
#else
#define LEDEQSDK_API __declspec(dllimport)
#endif
#define _CALL_STD __stdcall
#ifndef _TEXT_CHAR
#define _TEXT_CHAR    wchar_t
#endif
#else
#ifdef  __linux
#define LEDEQSDK_API extern "C"
#else
#define LEDEQSDK_API
#endif
#ifndef _TEXT_CHAR
#define _TEXT_CHAR    char
#define _CALL_STD
#endif
#endif

#ifdef __cplusplus
extern "C" {
#endif

LEDEQSDK_API unsigned long _CALL_STD bxDual_Start_Server(int port);
LEDEQSDK_API void _CALL_STD bxDual_Stop_Server(unsigned long pServer);
LEDEQSDK_API int _CALL_STD bxDual_Get_Port_Barcode(char* barcode);
LEDEQSDK_API int _CALL_STD bxDual_Get_CardList(char* cards);

#ifdef __cplusplus
}
#endif