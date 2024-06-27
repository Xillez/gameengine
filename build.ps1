function Write-Separator {
    Write-Output "###############################################"
}

RETURN_DIRECTORY = $((Get-Location).Path)

Write-Separator
Write-Output "Switching to build directory: $RETURN_DIRECTORY\build"
Set-Location "$RETURN_DIRECTORY\build"

Write-Separator
Write-Output "Running cmake:"
cmake ..

Write-Separator
Write-Output "Building program:"
mingw32-make

Write-Separator
Write-Output "Running application:"
./bin/SkyForgeEngine.exe

Write-Separator
Write-Output "Switching back to working directory: $RETURN_DIRECTORY"
Set-Location "$RETURN_DIRECTORY"