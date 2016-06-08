##
## Auto Generated makefile by CodeLite IDE
## any manual changes will be erased      
##
## Debug
ProjectName            :=diplom
ConfigurationName      :=Debug
WorkspacePath          := "/home/dima/Documents/code"
ProjectPath            := "/home/dima/Documents/code/diplom"
IntermediateDirectory  :=./Debug
OutDir                 := $(IntermediateDirectory)
CurrentFileName        :=
CurrentFilePath        :=
CurrentFileFullPath    :=
User                   :=dima
Date                   :=08/06/16
CodeLitePath           :="/home/dima/.codelite"
LinkerName             :=/usr/bin/x86_64-linux-gnu-g++
SharedObjectLinkerName :=/usr/bin/x86_64-linux-gnu-g++ -shared -fPIC
ObjectSuffix           :=.o
DependSuffix           :=.o.d
PreprocessSuffix       :=.i
DebugSwitch            :=-g 
IncludeSwitch          :=-I
LibrarySwitch          :=-l
OutputSwitch           :=-o 
LibraryPathSwitch      :=-L
PreprocessorSwitch     :=-D
SourceSwitch           :=-c 
OutputFile             :=$(IntermediateDirectory)/$(ProjectName)
Preprocessors          :=
ObjectSwitch           :=-o 
ArchiveOutputSwitch    := 
PreprocessOnlySwitch   :=-E
ObjectsFileList        :="diplom.txt"
PCHCompileFlags        :=
MakeDirCommand         :=mkdir -p
LinkOptions            :=  `pkg-config --cflags --libs opencv`
IncludePath            :=  $(IncludeSwitch). $(IncludeSwitch). 
IncludePCH             := 
RcIncludePath          := 
Libs                   := 
ArLibs                 :=  
LibPath                := $(LibraryPathSwitch). 

##
## Common variables
## AR, CXX, CC, AS, CXXFLAGS and CFLAGS can be overriden using an environment variables
##
AR       := /usr/bin/x86_64-linux-gnu-ar rcu
CXX      := /usr/bin/x86_64-linux-gnu-g++
CC       := /usr/bin/x86_64-linux-gnu-gcc
CXXFLAGS :=  -g -O0 -std=c++11 -Wall $(Preprocessors)
CFLAGS   :=  -g -O0 -Wall $(Preprocessors)
ASFLAGS  := 
AS       := /usr/bin/x86_64-linux-gnu-as


##
## User defined environment variables
##
CodeLiteDir:=/usr/share/codelite
Objects0=$(IntermediateDirectory)/main.cpp$(ObjectSuffix) $(IntermediateDirectory)/console.cpp$(ObjectSuffix) $(IntermediateDirectory)/log.cpp$(ObjectSuffix) $(IntermediateDirectory)/path.cpp$(ObjectSuffix) $(IntermediateDirectory)/pathDrawer.cpp$(ObjectSuffix) $(IntermediateDirectory)/robomath.cpp$(ObjectSuffix) $(IntermediateDirectory)/serial.cpp$(ObjectSuffix) $(IntermediateDirectory)/settings.cpp$(ObjectSuffix) $(IntermediateDirectory)/video.cpp$(ObjectSuffix) $(IntermediateDirectory)/orb.cpp$(ObjectSuffix) \
	



Objects=$(Objects0) 

##
## Main Build Targets 
##
.PHONY: all clean PreBuild PrePreBuild PostBuild MakeIntermediateDirs
all: $(OutputFile)

$(OutputFile): $(IntermediateDirectory)/.d $(Objects) 
	@$(MakeDirCommand) $(@D)
	@echo "" > $(IntermediateDirectory)/.d
	@echo $(Objects0)  > $(ObjectsFileList)
	$(LinkerName) $(OutputSwitch)$(OutputFile) @$(ObjectsFileList) $(LibPath) $(Libs) $(LinkOptions)

MakeIntermediateDirs:
	@test -d ./Debug || $(MakeDirCommand) ./Debug


$(IntermediateDirectory)/.d:
	@test -d ./Debug || $(MakeDirCommand) ./Debug

PreBuild:


##
## Objects
##
$(IntermediateDirectory)/main.cpp$(ObjectSuffix): main.cpp $(IntermediateDirectory)/main.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "/home/dima/Documents/code/diplom/main.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/main.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/main.cpp$(DependSuffix): main.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/main.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/main.cpp$(DependSuffix) -MM "main.cpp"

$(IntermediateDirectory)/main.cpp$(PreprocessSuffix): main.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/main.cpp$(PreprocessSuffix) "main.cpp"

$(IntermediateDirectory)/console.cpp$(ObjectSuffix): console.cpp $(IntermediateDirectory)/console.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "/home/dima/Documents/code/diplom/console.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/console.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/console.cpp$(DependSuffix): console.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/console.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/console.cpp$(DependSuffix) -MM "console.cpp"

$(IntermediateDirectory)/console.cpp$(PreprocessSuffix): console.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/console.cpp$(PreprocessSuffix) "console.cpp"

$(IntermediateDirectory)/log.cpp$(ObjectSuffix): log.cpp $(IntermediateDirectory)/log.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "/home/dima/Documents/code/diplom/log.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/log.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/log.cpp$(DependSuffix): log.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/log.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/log.cpp$(DependSuffix) -MM "log.cpp"

$(IntermediateDirectory)/log.cpp$(PreprocessSuffix): log.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/log.cpp$(PreprocessSuffix) "log.cpp"

$(IntermediateDirectory)/path.cpp$(ObjectSuffix): path.cpp $(IntermediateDirectory)/path.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "/home/dima/Documents/code/diplom/path.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/path.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/path.cpp$(DependSuffix): path.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/path.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/path.cpp$(DependSuffix) -MM "path.cpp"

$(IntermediateDirectory)/path.cpp$(PreprocessSuffix): path.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/path.cpp$(PreprocessSuffix) "path.cpp"

$(IntermediateDirectory)/pathDrawer.cpp$(ObjectSuffix): pathDrawer.cpp $(IntermediateDirectory)/pathDrawer.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "/home/dima/Documents/code/diplom/pathDrawer.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/pathDrawer.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/pathDrawer.cpp$(DependSuffix): pathDrawer.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/pathDrawer.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/pathDrawer.cpp$(DependSuffix) -MM "pathDrawer.cpp"

$(IntermediateDirectory)/pathDrawer.cpp$(PreprocessSuffix): pathDrawer.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/pathDrawer.cpp$(PreprocessSuffix) "pathDrawer.cpp"

$(IntermediateDirectory)/robomath.cpp$(ObjectSuffix): robomath.cpp $(IntermediateDirectory)/robomath.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "/home/dima/Documents/code/diplom/robomath.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/robomath.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/robomath.cpp$(DependSuffix): robomath.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/robomath.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/robomath.cpp$(DependSuffix) -MM "robomath.cpp"

$(IntermediateDirectory)/robomath.cpp$(PreprocessSuffix): robomath.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/robomath.cpp$(PreprocessSuffix) "robomath.cpp"

$(IntermediateDirectory)/serial.cpp$(ObjectSuffix): serial.cpp $(IntermediateDirectory)/serial.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "/home/dima/Documents/code/diplom/serial.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/serial.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/serial.cpp$(DependSuffix): serial.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/serial.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/serial.cpp$(DependSuffix) -MM "serial.cpp"

$(IntermediateDirectory)/serial.cpp$(PreprocessSuffix): serial.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/serial.cpp$(PreprocessSuffix) "serial.cpp"

$(IntermediateDirectory)/settings.cpp$(ObjectSuffix): settings.cpp $(IntermediateDirectory)/settings.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "/home/dima/Documents/code/diplom/settings.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/settings.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/settings.cpp$(DependSuffix): settings.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/settings.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/settings.cpp$(DependSuffix) -MM "settings.cpp"

$(IntermediateDirectory)/settings.cpp$(PreprocessSuffix): settings.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/settings.cpp$(PreprocessSuffix) "settings.cpp"

$(IntermediateDirectory)/video.cpp$(ObjectSuffix): video.cpp $(IntermediateDirectory)/video.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "/home/dima/Documents/code/diplom/video.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/video.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/video.cpp$(DependSuffix): video.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/video.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/video.cpp$(DependSuffix) -MM "video.cpp"

$(IntermediateDirectory)/video.cpp$(PreprocessSuffix): video.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/video.cpp$(PreprocessSuffix) "video.cpp"

$(IntermediateDirectory)/orb.cpp$(ObjectSuffix): orb.cpp $(IntermediateDirectory)/orb.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "/home/dima/Documents/code/diplom/orb.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/orb.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/orb.cpp$(DependSuffix): orb.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/orb.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/orb.cpp$(DependSuffix) -MM "orb.cpp"

$(IntermediateDirectory)/orb.cpp$(PreprocessSuffix): orb.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/orb.cpp$(PreprocessSuffix) "orb.cpp"


-include $(IntermediateDirectory)/*$(DependSuffix)
##
## Clean
##
clean:
	$(RM) -r ./Debug/


