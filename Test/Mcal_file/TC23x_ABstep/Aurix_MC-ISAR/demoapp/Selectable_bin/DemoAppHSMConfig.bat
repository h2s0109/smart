
IF %HSM_AVAILABLE% == YES (
@ECHO Adding HSM module for compilation....
SET HSM_DELIVERY=STD_ON

@echo #ifndef  DEMOAPP_HSMCFG_H >> %SSC_ROOT%\demoapp\inc\DemoApp_Cfg.h
@echo #define  DEMOAPP_HSMCFG_H >> %SSC_ROOT%\demoapp\inc\DemoApp_Cfg.h
@echo #define HSM_DELIVERY                   STD_ON>> %SSC_ROOT%\demoapp\inc\DemoApp_Cfg.h
@echo #define HSM_DELIVERY_TYPE              PRE_COMPILE_DELIVERY>> %SSC_ROOT%\demoapp\inc\DemoApp_Cfg.h
@echo #endif /* DEMOAPP_HSMCFG_H */>> %SSC_ROOT%\demoapp\inc\DemoApp_Cfg.h
)
IF %HSM_AVAILABLE% == NO (
SET HSM_DELIVERY=STD_OFF

@echo #ifndef  DEMOAPP_HSMCFG_H >> %SSC_ROOT%\demoapp\inc\DemoApp_Cfg.h
@echo #define  DEMOAPP_HSMCFG_H >> %SSC_ROOT%\demoapp\inc\DemoApp_Cfg.h
@echo #define HSM_DELIVERY                   STD_OFF>> %SSC_ROOT%\demoapp\inc\DemoApp_Cfg.h
@echo #define HSM_DELIVERY_TYPE              PRE_COMPILE_DELIVERY>> %SSC_ROOT%\demoapp\inc\DemoApp_Cfg.h
@echo #endif /* DEMOAPP_HSMCFG_H */>> %SSC_ROOT%\demoapp\inc\DemoApp_Cfg.h
)

