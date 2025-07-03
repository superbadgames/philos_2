# name of the installer
Outfile "project_philos_installer.exe"

# TODO: Change later to something more reasonable
InstallDir "$DESKTOP\Philos"

Section
    SetOutPath $INSTDIR

    # This says copy this file into a zip file, which is what is installed
    file /r "..\Assets"
    # The contents of this fold need to be an update version of Builds/release
    file /r "Tower"

    # TODO later:
    # Install msvc redistributable libraries (2019)
    # ask for an install directory from a pop up
    # create a shortcut
    # add art to the shortcut

SectionEnd

# todo:
# add a new section for an uninstaller
# implement the uninstaller
