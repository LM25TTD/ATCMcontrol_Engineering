#automatically generated by C:\ATCMControl_SDK\GenWork\GenDir.tmp\4Control_R\gentools\make.pl: Version=$Revision: 1 $

!ifndef PROJECT_ROOT
!MESSAGE check environmemt: environment variable PROJECT_ROOT not defined
!ERROR PROJECT_ROOT must point to the project base directory
!endif

STATIC_RUNTIME = 0
!include <$(PROJECT_ROOT)\gentools\global.inc>
!if $(SUB)!=0
makemake:
	cd 4CVM
	perl $(PROJECT_ROOT)\gentools\make.pl 4CVM
	$(MAKE) -$(MAKEFLAGS) -f 4CVM.mak makemake SUB=1
	cd $(MAKEDIR)
makefirst oleclasses javaclasses precompile compile prelink link makelast:
	cd 4CVM
	$(MAKE) -$(MAKEFLAGS) -f 4CVM.mak $@ SUB=1 DEBUG=$(DEBUG)
	cd $(MAKEDIR)
clean::
	cd 4CVM
	$(MAKE) -$(MAKEFLAGS) -f 4CVM.mak clean SUB=1 DEBUG=$(DEBUG)
	cd $(MAKEDIR)
!endif
doxygen: CCG.doxy
	$(CP) $(PROJECT_ROOT)\gentools\4C_doxy.css .\4C_doxy.css
	doxygen CCG.doxy
CCG.doxy:
	$(CP) $(PROJECT_ROOT)\gentools\Sample.doxy .\CCG.doxy
