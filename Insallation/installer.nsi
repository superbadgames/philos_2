# The install assumes a 32 bit (x86) final exe
# TODO: Create a build process for 64 bit, and create an installer for that.
# name of the installer
Outfile "project_philos_installer.exe"

# TODO: Change later to something more reasonable
InstallDir "$DESKTOP\Philos"

Section "Visual Studio Runtime"
  SetOutPath "$INSTDIR"
  File "C:\Program Files (x86)\Microsoft Visual Studio\2019\Community\VC\Redist\MSVC\14.29.30133\vcredist_x86.exe"
  ExecWait "$INSTDIR\vcredist_x86.exe /install /passive"
  Delete "$INSTDIR\vcredist_x86.exe"
SectionEnd

Section
    SetOutPath $INSTDIR

    # This says copy this file into a zip file, which is what is installed
    file /r "..\Assets"
    # The contents of this fold need to be an update version of Builds/release
    file /r "Tower"

    # TODO later:
    # ask for an install directory from a pop up
    # create a shortcut
    # add art to the shortcut

    WriteUninstaller "$INSTDIR\uninstall.exe"


SectionEnd


Section "CreateShortcut"
    SetOutPath "$INSTDIR\Tower\zero\"

    SetShellVarContext all
    CreateShortcut "$DESKTOP\Project_Philos.lnk" "$INSTDIR\Tower\zero\project_philos.exe"
SectionEnd


Section "Uninstall"

SetOutPath $INSTDIR

Delete "$INSTDIR\Assets"
Delete "$INSTDIR\Tower"
Delete "$INSTDIR\uninstall.exe"

RMDir $INSTDIR
SectionEnd

# todo:
# add a new section for an uninstaller
# implement the uninstaller
