#automatically generated by C:\ATCMControl_SDK\GenWork\GenDir.tmp\4Control_R\gentools\make.pl: Version=$Revision: 1 $

!ifndef PROJECT_ROOT
!MESSAGE check environmemt: environment variable PROJECT_ROOT not defined
!ERROR PROJECT_ROOT must point to the project base directory
!endif

STATIC_RUNTIME = 0
!include <$(PROJECT_ROOT)\gentools\global.inc>
makefirst:$(EXE_DIR)\Engineering\bin\ATHW119
$(EXE_DIR)\Engineering\bin\ATHW119:
  -md $@
doxygen: 4CVM.doxy
	$(CP) $(PROJECT_ROOT)\gentools\4C_doxy.css .\4C_doxy.css
	doxygen 4CVM.doxy
4CVM.doxy:
	$(CP) $(PROJECT_ROOT)\gentools\Sample.doxy .\4CVM.doxy
compile: $(OBJ)\4CVMAdapt.obj
$(OBJ)\4CVMAdapt.obj: 4CVMAdapt.cpp $(OBJ)
	@$(CXX) @<<
$(CXXFLAGS) -I..\..\inc -I..\..\res -I$(TARGET_BASE)\CCG\inc -I$(TARGET_BASE)\Kernel\inc -I$(TARGET_BASE)\CCG\4CVMLib -DINC_4C -Fo$(OBJ)\4CVMAdapt.obj -c $(MAKEDIR)\4CVMAdapt.cpp
<<
clean::
	-$(RM) $(OBJ)\4CVMAdapt.obj
clean::
	-$(RM) vc60.idb vc60.pdb
compile: $(OBJ)\4CVMResource.res
$(OBJ)\4CVMResource.res: 4CVMResource.rc $(OBJ)
	$(RC) $(RCFLAGS) -i ..\..\inc -i ..\..\res -i $(TARGET_BASE)\CCG\inc -i $(TARGET_BASE)\Kernel\inc -i $(TARGET_BASE)\CCG\4CVMLib -d INC_4C -fo$(OBJ)\4CVMResource.res 4CVMResource.rc
clean::
	-$(RM) $(OBJ)\4CVMResource.res
link: $(EXE_DIR)\Engineering\bin\ATHW119\4cvm.exe
$(EXE_DIR)\Engineering\bin\ATHW119\4cvm.exe: $(OBJ)\4CVMAdapt.obj $(OBJ)\4CVMResource.res $(TARGET_BASE)\Kernel\lib\fc_tools.lib $(TARGET_BASE)\Kernel\lib\fc_todebug.lib $(TARGET_BASE)\Kernel\lib\fc_util.lib $(TARGET_BASE)\Kernel\lib\cg_tools.lib $(TARGET_BASE)\lib\4cvm.lib 
	$(LNK) @<<
$(LFLAGS) -OUT:$(EXE_DIR)\Engineering\bin\ATHW119\4cvm.exe -SUBSYSTEM:CONSOLE -INCREMENTAL:NO
$(OBJ)\4CVMAdapt.obj 
$(OBJ)\4CVMResource.res
$(TARGET_BASE)\Kernel\lib\fc_tools.lib $(TARGET_BASE)\Kernel\lib\fc_todebug.lib $(TARGET_BASE)\Kernel\lib\fc_util.lib $(TARGET_BASE)\Kernel\lib\cg_tools.lib $(TARGET_BASE)\lib\4cvm.lib kernel32.lib user32.lib gdi32.lib advapi32.lib ole32.lib 
<<
clean::
	-$(RM) $(EXE_DIR)\Engineering\bin\ATHW119\4cvm.exe
	-$(RM) $(EXE_DIR)\Engineering\bin\ATHW119\4cvm.pdb