/************************************************************************
 * file:	bx_sdk_dual.h
 * brief:	Header file of bxDual_5E_6Q API
 * author:	fantx
 * date:	2018-12-18
 ***********************************************************************/
/*! ********************************************************************
***                  
*** 注意事项：
*** 如果是6代控制器独用函数或结构体等等会用_G6注明
*** 如果是5代6代公用函数或结构体等等都用_G56注明
*** 没有注明_G6/_G56或者注明为_G5都是5代控制器接口
/*! ********************************************************************/
#ifndef _BXSDKDUAL_H
#define _BXSDKDUAL_H

#include "bx_dual_sdk.h"

#ifdef _WIN32
#define    InitSdk                                        bxDual_InitSdk                                                  
#define    ReleaseSdk                                     bxDual_ReleaseSdk        
#endif

#define    cmd_AT_getWifiSsidPwd                          bxDual_cmd_AT_getWifiSsidPwd                                            
#define    cmd_AT_setWifiSsidPwd                          bxDual_cmd_AT_setWifiSsidPwd                                            
#define    cmd_battieTime                                 bxDual_cmd_battieTime                                                   
#define    cmd_cancelTimingOnOff                          bxDual_cmd_cancelTimingOnOff                                            
#define    cmd_check_controllerStatus                     bxDual_cmd_check_controllerStatus                                       
#define    cmd_check_time                                 bxDual_cmd_check_time                                                   
#define    cmd_coerceOnOff                                bxDual_cmd_coerceOnOff                                                  
#define    cmd_confDeleteFormatFile                       bxDual_cmd_confDeleteFormatFile                                         
#define    cmd_confReedFileBlock                          bxDual_cmd_confReedFileBlock                                            
#define    cmd_confStartReedFile                          bxDual_cmd_confStartReedFile                                            
#define    cmd_confWriteFile                              bxDual_cmd_confWriteFile                                                
#define    cmd_deletePassword                             bxDual_cmd_deletePassword                                               
#define    cmd_firmwareActivate                           bxDual_cmd_firmwareActivate                                             
#define    cmd_getFileAttr                                bxDual_cmd_getFileAttr                                                  
#define    cmd_getSensorBrightnessValue                   bxDual_cmd_getSensorBrightnessValue                                     
#define    cmd_getStopwatch                               bxDual_cmd_getStopwatch                                                 
#define    cmd_ofsDeleteFormatFile                        bxDual_cmd_ofsDeleteFormatFile                                          
#define    cmd_ofsEndFileTransf                           bxDual_cmd_ofsEndFileTransf                                             
#define    cmd_ofsFormat                                  bxDual_cmd_ofsFormat                                                    
#define    cmd_ofsGetMemoryVolume                         bxDual_cmd_ofsGetMemoryVolume                                           
#define    cmd_ofsGetTransStatus                          bxDual_cmd_ofsGetTransStatus                                            
#define    cmd_ofsReedDirBlock                            bxDual_cmd_ofsReedDirBlock                                              
#define    cmd_ofsReedFileBlock                           bxDual_cmd_ofsReedFileBlock                                             
#define    cmd_ofsStartFileTransf                         bxDual_cmd_ofsStartFileTransf                                           
#define    cmd_ofsStartReedFile                           bxDual_cmd_ofsStartReedFile                                             
#define    cmd_ofsWriteFile                               bxDual_cmd_ofsWriteFile                                                 
#define    cmd_ofs_freeDirBlock                           bxDual_cmd_ofs_freeDirBlock                                             
#define    cmd_programLock                                bxDual_cmd_programLock                                                  
#define    cmd_readControllerID                           bxDual_cmd_readControllerID                                             
#define    cmd_screenLock                                 bxDual_cmd_screenLock                                                   
#define    cmd_searchController                           bxDual_cmd_searchController                                             
#define    cmd_sendConfigFile                             bxDual_cmd_sendConfigFile                                               
#define    cmd_sendConfigFile_G6                          bxDual_cmd_sendConfigFile_G6                                            
#define    cmd_setBrightness                              bxDual_cmd_setBrightness                                                
#define    cmd_setBtnFunc                                 bxDual_cmd_setBtnFunc                                                   
#define    cmd_setDelayTime                               bxDual_cmd_setDelayTime                                                 
#define    cmd_setDispMode                                bxDual_cmd_setDispMode                                                  
#define    cmd_setPassword                                bxDual_cmd_setPassword                                                  
#define    cmd_setScreenAddress                           bxDual_cmd_setScreenAddress                                             
#define    cmd_setSpeedAdjust                             bxDual_cmd_setSpeedAdjust                                               
#define    cmd_setTimingReset                             bxDual_cmd_setTimingReset                                               
#define    cmd_sysReset                                   bxDual_cmd_sysReset                                                     
#define    cmd_tcpNetworkSearch_6G                        bxDual_cmd_tcpNetworkSearch_6G                                          
#define    cmd_tcpNetworkSearch_6G_Web                    bxDual_cmd_tcpNetworkSearch_6G_Web                                      
#define    cmd_tcpPing                                    bxDual_cmd_tcpPing                                                      
#define    cmd_timingOnOff                                bxDual_cmd_timingOnOff                                                  
#define    cmd_uart_confDeleteFormatFile                  bxDual_cmd_uart_confDeleteFormatFile                                    
#define    cmd_uart_confReedFileBlock                     bxDual_cmd_uart_confReedFileBlock                                       
#define    cmd_uart_confStartReedFile                     bxDual_cmd_uart_confStartReedFile                                       
#define    cmd_uart_confWriteFile                         bxDual_cmd_uart_confWriteFile                                           
#define    cmd_uart_ofsDeleteFormatFile                   bxDual_cmd_uart_ofsDeleteFormatFile                                     
#define    cmd_uart_ofsEndFileTransf                      bxDual_cmd_uart_ofsEndFileTransf                                        
#define    cmd_uart_ofsFormat                             bxDual_cmd_uart_ofsFormat                                               
#define    cmd_uart_ofsFreeDirBlock                       bxDual_cmd_uart_ofsFreeDirBlock                                         
#define    cmd_uart_ofsGetMemoryVolume                    bxDual_cmd_uart_ofsGetMemoryVolume                                      
#define    cmd_uart_ofsGetTransStatus                     bxDual_cmd_uart_ofsGetTransStatus                                       
#define    cmd_uart_ofsReedDirBlock                       bxDual_cmd_uart_ofsReedDirBlock                                         
#define    cmd_uart_ofsReedFileBlock                      bxDual_cmd_uart_ofsReedFileBlock                                        
#define    cmd_uart_ofsStartFileTransf                    bxDual_cmd_uart_ofsStartFileTransf                                      
#define    cmd_uart_ofsStartReedFile                      bxDual_cmd_uart_ofsStartReedFile                                        
#define    cmd_uart_ofsWriteFile                          bxDual_cmd_uart_ofsWriteFile                                            
#define    cmd_uart_programLock                           bxDual_cmd_uart_programLock                                             
#define    cmd_uart_programLock_6G                        bxDual_cmd_uart_programLock_6G                                          
#define    cmd_uart_searchController                      bxDual_cmd_uart_searchController                                        
#define    cmd_uart_search_Net_6G                         bxDual_cmd_uart_search_Net_6G                                           
#define    cmd_uart_search_Net_6G_Web                     bxDual_cmd_uart_search_Net_6G_Web                                       
#define    cmd_uart_sendConfigFile                        bxDual_cmd_uart_sendConfigFile                                          
#define    cmd_udpNetworkSearch                           bxDual_cmd_udpNetworkSearch                                             
#define    cmd_udpNetworkSearch_6G                        bxDual_cmd_udpNetworkSearch_6G                                          
#define    cmd_udpNetworkSearch_6G_Web                    bxDual_cmd_udpNetworkSearch_6G_Web                                      
#define    cmd_udpPing                                    bxDual_cmd_udpPing                                                      
#define    cmd_udpSetIP                                   bxDual_cmd_udpSetIP                                                     
#define    cmd_udpSetMac                                  bxDual_cmd_udpSetMac                                                    
#define    dynamicAreaS_AddAreaPic_6G                     bxDual_dynamicAreaS_AddAreaPic_6G                                       
#define    dynamicAreaS_AddAreaPic_WithProgram_6G         bxDual_dynamicAreaS_AddAreaPic_WithProgram_6G                           
#define    dynamicAreaS_AddTxtDetails_6G                  bxDual_dynamicAreaS_AddTxtDetails_6G                                    
#define    dynamicAreaS_AddTxtDetails_WithProgram_6G      bxDual_dynamicAreaS_AddTxtDetails_WithProgram_6G                        
#define    dynamicArea_AddAreaInfos_5G                    bxDual_dynamicArea_AddAreaInfos_5G                                      
#define    dynamicArea_AddAreaPic_6G                      bxDual_dynamicArea_AddAreaPic_6G                                        
#define    dynamicArea_AddAreaPic_WithProgram_6G          bxDual_dynamicArea_AddAreaPic_WithProgram_6G                            
#define    dynamicArea_AddAreaTxtDetails_6G               bxDual_dynamicArea_AddAreaTxtDetails_6G                                 
#define    dynamicArea_AddAreaTxtDetails_WithProgram_6G   bxDual_dynamicArea_AddAreaTxtDetails_WithProgram_6G                     
#define    dynamicArea_AddAreaTxt_6G                      bxDual_dynamicArea_AddAreaTxt_6G                                        
#define    dynamicArea_AddAreaWithPic_5G                  bxDual_dynamicArea_AddAreaWithPic_5G                                    
#define    dynamicArea_AddAreaWithTxt_5G                  bxDual_dynamicArea_AddAreaWithTxt_5G                                    
#define    dynamicArea_DelAreaS_5G                        bxDual_dynamicArea_DelAreaS_5G                                          
#define    dynamicArea_DelArea_5G                         bxDual_dynamicArea_DelArea_5G                                           
#define    dynamicArea_DelArea_6G                         bxDual_dynamicArea_DelArea_6G                                           
#define    dynamicArea_DelAreas_6G                        bxDual_dynamicArea_DelAreas_6G                                          
#define    dynamicArea_InsertSoundIndepend                bxDual_dynamicArea_InsertSoundIndepend                                  
#define    dynamicArea_UpdateSoundIndepend                bxDual_dynamicArea_UpdateSoundIndepend                                  
#define    get_crc16                                      bxDual_get_crc16                                                        
#define    get_crc32                                      bxDual_get_crc32                                                        
#define    program_AddArea                                bxDual_program_AddArea                                                  
#define    program_IntegrateProgramFile                   bxDual_program_IntegrateProgramFile                                     
#define    program_IntegrateProgramFile_G6                bxDual_program_IntegrateProgramFile_G6                                  
#define    program_MoveArea                               bxDual_program_MoveArea                                                 
#define    program_MoveArea_G6                            bxDual_program_MoveArea_G6                                              
#define    program_addArea_G6                             bxDual_program_addArea_G6                                               
#define    program_addFrame                               bxDual_program_addFrame                                                 
#define    program_addFrame_G6                            bxDual_program_addFrame_G6                                              
#define    program_addPlayPeriodGrp                       bxDual_program_addPlayPeriodGrp                                         
#define    program_addPlayPeriodGrp_G6                    bxDual_program_addPlayPeriodGrp_G6                                      
#define    program_addProgram                             bxDual_program_addProgram                                               
#define    program_addProgram_G6                          bxDual_program_addProgram_G6                                            
#define    program_backGroundColor_G6                     bxDual_program_backGroundColor_G6                                       
#define    program_backGroundPic_G6                       bxDual_program_backGroundPic_G6                                         
#define    program_changeFrame                            bxDual_program_changeFrame                                              
#define    program_changeFrame_G6                         bxDual_program_changeFrame_G6                                           
#define    program_changeProgramParams                    bxDual_program_changeProgramParams                                      
#define    program_changeProgramParams_G6                 bxDual_program_changeProgramParams_G6                                   
#define    program_deleteArea                             bxDual_program_deleteArea                                               
#define    program_deleteArea_G6                          bxDual_program_deleteArea_G6                                            
#define    program_deleteProgram                          bxDual_program_deleteProgram                                            
#define    program_deleteProgram_G6                       bxDual_program_deleteProgram_G6                                         
#define    program_fontPath_picturesAreaAddTxt            bxDual_program_fontPath_picturesAreaAddTxt                              
#define    program_fontPath_picturesAreaAddTxt_G6         bxDual_program_fontPath_picturesAreaAddTxt_G6                           
#define    program_fontPath_picturesAreaChangeTxt         bxDual_program_fontPath_picturesAreaChangeTxt                           
#define    program_fontPath_picturesAreaChangeTxt_G6      bxDual_program_fontPath_picturesAreaChangeTxt_G6                        
#define    program_fontPath_timeAreaAddContent            bxDual_program_fontPath_timeAreaAddContent                              
#define    program_fontPath_timeAreaAddContent_G6         bxDual_program_fontPath_timeAreaAddContent_G6                           
#define    program_freeBuffer                             bxDual_program_freeBuffer                                               
#define    program_freeBuffer_G6                          bxDual_program_freeBuffer_G6                                            
#define    program_pictureArea                            bxDual_program_pictureArea                                              
#define    program_pictureAreaAddPic                      bxDual_program_pictureAreaAddPic                                        
#define    program_pictureAreaAddPic_G6                   bxDual_program_pictureAreaAddPic_G6                                     
#define    program_pictureAreaChangePic_G6                bxDual_program_pictureAreaChangePic_G6                                  
#define    program_pictureAreaChangeSoundSettings_G6      bxDual_program_pictureAreaChangeSoundSettings_G6                        
#define    program_pictureAreaDisableSound_G6             bxDual_program_pictureAreaDisableSound_G6                               
#define    program_pictureAreaEnableSound_G6              bxDual_program_pictureAreaEnableSound_G6                                
#define    program_pictureAreaGetOnePage                  bxDual_program_pictureAreaGetOnePage                                    
#define    program_pictureAreaRemoveFrame                 bxDual_program_pictureAreaRemoveFrame                                   
#define    program_picturesAreaAddFrame                   bxDual_program_picturesAreaAddFrame
#define    program_picturesAreaAddFrame_G6                bxDual_program_picturesAreaAddFrame_G6
#define    program_picturesAreaAddTxt                     bxDual_program_picturesAreaAddTxt                                       
#define    program_picturesAreaAddTxt_G6                  bxDual_program_picturesAreaAddTxt_G6                                    
#define    program_picturesAreaChangeTxt                  bxDual_program_picturesAreaChangeTxt                                    
#define    program_picturesAreaChangeTxt_G6               bxDual_program_picturesAreaChangeTxt_G6                                 
#define    program_removeFrame                            bxDual_program_removeFrame                                              
#define    program_removeFrame_G6                         bxDual_program_removeFrame_G6                                           
#define    program_setScreenParams_G56                    bxDual_program_setScreenParams_G56                                      
#define    program_timeAreaAddAnalogClock                 bxDual_program_timeAreaAddAnalogClock                                   
#define    program_timeAreaAddAnalogClock_G6              bxDual_program_timeAreaAddAnalogClock_G6                                
#define    program_timeAreaAddContent                     bxDual_program_timeAreaAddContent                                       
#define    program_timeAreaAddContent_G6                  bxDual_program_timeAreaAddContent_G6                                    
#define    program_timeAreaCancleBattleTime_G6            bxDual_program_timeAreaCancleBattleTime_G6                              
#define    program_timeAreaChangeAnalogClock              bxDual_program_timeAreaChangeAnalogClock                                
#define    program_timeAreaChangeAnalogClock_G6           bxDual_program_timeAreaChangeAnalogClock_G6                             
#define    program_timeAreaChangeContent                  bxDual_program_timeAreaChangeContent                                    
#define    program_timeAreaChangeContent_G6               bxDual_program_timeAreaChangeContent_G6                                 
#define    program_timeAreaChangeDialPic                  bxDual_program_timeAreaChangeDialPic                                    
#define    program_timeAreaChangeDialPicAdd_G56           bxDual_program_timeAreaChangeDialPicAdd_G56                             
#define    program_timeAreaChangeDialPic_G6               bxDual_program_timeAreaChangeDialPic_G6                                 
#define    program_timeAreaGetOnePage                     bxDual_program_timeAreaGetOnePage                                       
#define    program_timeAreaRemoveDialPic                  bxDual_program_timeAreaRemoveDialPic                                    
#define    program_timeAreaRemoveDialPic_G6               bxDual_program_timeAreaRemoveDialPic_G6                                 
#define    program_timeAreaSetBattleTime_G6               bxDual_program_timeAreaSetBattleTime_G6                                 
#define    set_packetLen                                  bxDual_set_packetLen                                                    
#define    set_screenNum_G56                              bxDual_set_screenNum_G56                                        
           
#endif
