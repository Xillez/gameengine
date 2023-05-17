function Print-Separator {
    Write-Output "###############################################"
}

Print-Separator
Write-Output "\t\tSwitching to build directory: $((Get-Location).Path)\build"
Print-Separator

cd "$((Get-Location).Path)\build"

Print-Separator
Write-Output "\t\tRunning cmake...\n"
Print-Separator

cmake ..

Print-Separator
Write-Output "\t\tBuilding program...\n"
Print-Separator

mingw32-make

Print-Separator
Write-Output "\t\tRunning application...\n"
Print-Separator

./bin/ecs.exe

Print-Separator
Write-Output "\t\tSwitching back to working directory\n"
Print-Separator

cd "$((Get-Location).Path)"