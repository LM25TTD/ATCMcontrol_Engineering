#automatically generated by C:\ATCMControl_SDK\GenWork\GenDir.tmp\4Control_R\gentools\make.pl: Version=$Revision: 1 $

!ifndef PROJECT_ROOT
!MESSAGE check environmemt: environment variable PROJECT_ROOT not defined
!ERROR PROJECT_ROOT must point to the project base directory
!endif

STATIC_RUNTIME = 0
!include <$(PROJECT_ROOT)\gentools\global.inc>
libname=HW119
make_lib: force
 xcopy $(MAKEDIR)\*.*     $(MAKEDIR)\eng\*.*	/Y
 $(4CG) $(MAKEDIR)\eng\$(libname).4cp  -ml:0 $(4CL_DIR)\eng\$(libname).4cl
 copy  $(4CL_DIR)\eng\$(libname).4cl    $(4CL_DIR)\$(libname).4cl	/Y
doxygen: HW119.doxy
	$(CP) $(PROJECT_ROOT)\gentools\4C_doxy.css .\4C_doxy.css
	doxygen HW119.doxy
HW119.doxy:
	$(CP) $(PROJECT_ROOT)\gentools\Sample.doxy .\HW119.doxy
